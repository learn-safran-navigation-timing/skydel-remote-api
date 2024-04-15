using System;
using System.Collections.Generic;
using Sdx.Cmd;

namespace Sdx
{
  public enum DeprecatedMessageMode {ALL, LATCH, NONE}

  public class RemoteSimulator
  {
    public bool IsExceptionOnError { get; private set; }

    public bool IsVerbose
    {
      set
      {
        m_verbose = value;
        if (m_client != null)
          m_client.IsVerbose = value;
        if (m_hil != null)
          m_hil.IsVerbose = value;
      }
      get { return m_verbose; }
    }

    public bool IsHilStreamingCheckEnabled
    {
      set { m_hilStreamingCheckEnabled = value; }
      get { return m_hilStreamingCheckEnabled; }
    }

    public bool IsConnected
    {
      get
      {
        return m_client != null && m_client.IsConnected;
      }
    }

    public static int ClientApiVersion
    {
      get
      {
        return ApiInfo.COMMANDS_API_VERSION;
      }
    }

    public int ServerApiVersion
    {
      get
      {
        if (IsConnected)
        {
          return m_serverApiVersion;
        }
        else
        {
          throw new Exception("Server API Version unavailable. You must be connected to the server.");
        }
      }
    }

    public DeprecatedMessageMode DeprecatedMessageMode {
      get
      {
        return m_deprecatedMessageMode;
      }
      set
      {
        m_deprecatedMessageMode = value;
        m_latchDeprecated.Clear();
      }
    }

    private bool m_verbose = false;
    private bool m_hilStreamingCheckEnabled = true;
    private HilClient m_hil = null;
    private CmdClient m_client = null;
    private double m_checkRunningTime = 0.0;
    private bool m_beginTrack = false;
    private bool m_beginRoute = false;
    private HashSet<string> m_beginIntTxTrack = new HashSet<string>();
    private int m_serverApiVersion = 0;
    private DeprecatedMessageMode m_deprecatedMessageMode = DeprecatedMessageMode.LATCH;
    private HashSet<string> m_latchDeprecated = new HashSet<string>();

    public RemoteSimulator(bool isExceptionOnError = true)
    {
      IsExceptionOnError = isExceptionOnError;
      ResetTime();
    }

    private void ResetTime()
    {
      m_checkRunningTime = -999999999.9;
    }

    public static int SpooferInstance(int id) { return 128 + id; }

    public void Connect(string ip = "localhost", int id = 0, bool failIfApiVersionMsmatch = false)
    {
      if (IsConnected)
      {
        throw new Exception("Cannot connect. Already connected. Disconnect first.");
      }

      int port = 4820 + id;
      PrintLine("Connecting to " + ip + " port on " + port + "...");

      m_client = new CmdClient();
      m_client.Connect(ip, port);

      m_serverApiVersion = m_client.GetServerApiVersion();
      if (ClientApiVersion != m_serverApiVersion)
      {
        string msg = "Client Api Version (" + ClientApiVersion +
         ") != Server Api Version (" + m_serverApiVersion + ")";
        if (failIfApiVersionMsmatch)
        {
          throw new Exception(msg);
        }
        else
        {
          Console.WriteLine("Warning: " + msg);
        }
      }

      int hilPort = ((HilPortResult)CallCommand(new GetHilPort())).Port;
      m_hil = new HilClient();
      m_hil.Connect(ip, hilPort);

      m_hil.IsVerbose = IsVerbose;
      m_client.IsVerbose = IsVerbose;
    }

    public void Disconnect()
    {
      if (m_client != null)
      {
        PrintLine("Commands Client Disconnecting");

        m_client.Disconnect();
        m_client = null;

        if (m_hil != null)
        {
          m_hil.Disconnect();
          m_hil = null;
        }
      }
    }

    public bool Arm()
    {
      PrintLine("Arming simulation...");

      if (!CallCommand(new Arm()).IsSuccess)
      {
        PrintLine("Failed to arm simulation");
        return false;
      }
      ResetTime();

      PrintLine("Simulation armed");
      return true;
    }

    public bool Start()
    {
      PrintLine("Starting simulation...");

      if (!CallCommand(new Start()).IsSuccess)
      {
        PrintLine("Failed to start simulation");
        return false;
      }

      ResetTime();

      PrintLine("Simulation started");

      var result = CallCommand(new GetSimulatorState());
      if (result.GetType() != typeof(SimulatorStateResult))
        PrintLine("Failed to retrieve simulator state.");
      else if (((SimulatorStateResult)result).SubStateId == SimulatorSubState.Started_HILSync)
        PrintLine("HIL Mode: Please send positions");
      return true;
    }

    public void Stop()
    {
      ResetTime();
      CallCommand(new Stop());
      PrintLine("Simulation stopped.");
    }

    public void Stop(double timestamp)
    {
      ResetTime();

      CommandBase stopCmd = PostCommand(new Stop(), timestamp);

      PrintLine("Stopping simulation at " + timestamp + " seconds...");
      WaitCommand(stopCmd);
      PrintLine("Simulation stopped.");
    }

    private void CheckForbiddenPost(CommandBase cmd)
    {
      if (cmd.Name == "Start")
        throw new Exception("You cannot send a Start() command. Use RemoteSimulator.Start() instead.");
    }

    private void CheckForbiddenCall(CommandBase cmd)
    {
      if (cmd.Name == "Start")
        throw new Exception("You cannot send a Start() command. Use RemoteSimulator.Start() instead.");
      if (cmd.Name == "PushTrackEcef")
        throw new Exception("You cannot call a PushTrackEcef command. Post it or use RemoteSimulator.PushTrackEcef() or RemoteSimulator.PushTrackLla() instead.");
      if (cmd.Name == "PushTrackEcefNed")
        throw new Exception("You cannot call a PushTrackEcefNed command. Post it or use RemoteSimulator.PushTrackEcefNed() or RemoteSimulator.PushTrackEcefLlaNed() instead.");
      if (cmd.Name == "PushRouteEcef")
        throw new Exception("You cannot call a PushRouteNode command. Post it or use RemoteSimulator.PushRouteLla() or RemoteSimulator.PushRouteEcef() instead.");
      if (cmd.Name == "PushIntTxTrackEcef")
        throw new Exception("You cannot call a PushIntTxTrackEcef command. Post it or use RemoteSimulator.PushIntTxTrackEcef() or RemoteSimulator.PushIntTxTrackLla() instead.");
      if (cmd.Name == "PushIntTxTrackEcefNed")
        throw new Exception("You cannot call a PushIntTxTrackEcefNed command. Post it or use RemoteSimulator.PushIntTxTrackEcefNed() or RemoteSimulator.PushIntTxTrackLlaNed() instead.");
    }

    public bool CheckIfStreaming()
    {
      SimulatorStateResult stateResult = (SimulatorStateResult)CallCommand(new GetSimulatorState());

      if (stateResult.State == "Streaming RF")
        return true;

      string errorMsg;
      if (stateResult.State == "Error")
        errorMsg = "An error occured during simulation. Error message:\n" + stateResult.Error;
      else
        errorMsg = "Simulator is no more streaming. Current state is " + stateResult.State + ".";

      if (IsExceptionOnError)
        throw new Exception(errorMsg);

      PrintLine(errorMsg);
      return false;
    }

    public bool WaitState(string state, string failureState = "")
    {
      PrintLine("Waiting for simulator state ");

      SimulatorStateResult stateResult = (SimulatorStateResult)CallCommand(new WaitSimulatorState(state, failureState));

      string errorMsg;
      if (stateResult.State == state)
      {
        PrintLine("Simulator state is now to " + state);
        return true;
      }
      else if (stateResult.State == "Error")
      {
        errorMsg = "An error occured during simulation. Error message:\n" + stateResult.Error;
      }
      else
      {
        errorMsg = "Wrong simulator state. Expected " + state + " but received " + stateResult.State;
      }

      if (IsExceptionOnError)
        throw new Exception(errorMsg);

      PrintLine(errorMsg);
      return false;
    }

    public bool HasVehicleInfo()
    {
      return m_hil.HasRecvVehicleInfo(0, false);
    }

    public CommandResult BeginVehicleInfo()
    {
      return CallCommand(new BeginVehicleInfo());
    }

    public CommandResult EndVehicleInfo()
    {
      return CallCommand(new EndVehicleInfo());
    }

    public VehicleInfo NextVehicleInfo()
    {
      VehicleInfo vehicleInfo = new VehicleInfo();
      m_hil.RecvNextVehicleInfo(ref vehicleInfo);
      return vehicleInfo;

    }

    public VehicleInfo LastVehicleInfo()
    {
      VehicleInfo vehicleInfo = new VehicleInfo();
      m_hil.RecvLastVehicleInfo(ref vehicleInfo);
      return vehicleInfo;
    }

    public CommandResult BeginTrackDefinition()
    {
      CommandResult result = CallCommand(new BeginTrackDefinition());
      if (result.IsSuccess)
        m_beginTrack = true;
      return result;
    }

    public void PushTrackEcef(int elapsedTime, Ecef position)
    {
      if (!m_beginTrack)
        throw new Exception("You must call beginTrackDefinition first.");
      PostCommand(new PushTrackEcef(elapsedTime, position.X, position.Y, position.Z));
    }

    public void PushTrackEcefNed(int elapsedTime, Ecef position, Attitude attitude)
    {
      if (!m_beginTrack)
        throw new Exception("You must call beginTrackDefinition first.");
      PostCommand(new PushTrackEcefNed(elapsedTime, position.X, position.Y, position.Z,
                                 attitude.Yaw, attitude.Pitch, attitude.Roll));
    }

    public void PushTrackLla(int elapsedTime, Lla lla)
    {
      PushTrackEcef(elapsedTime, lla.ToEcef());
    }

    public void PushTrackLlaNed(int elapsedTime, Lla lla, Attitude attitude)
    {
      PushTrackEcefNed(elapsedTime, lla.ToEcef(), attitude);
    }

    public CommandResult EndTrackDefinition(out int numberOfNodesInTrack)
    {
      if (!m_beginTrack)
        throw new Exception("You must call beginTrackDefinition first and pushTrackEcef/pushTrackLla with all the Track nodes before calling endTrackDefinition.");
      m_beginTrack = false;
      CommandResult result = CallCommand(new EndTrackDefinition());
      if (result.IsSuccess)
      {
        EndTrackDefinitionResult TrackResult = (EndTrackDefinitionResult)result;
        numberOfNodesInTrack = TrackResult.Count;
      }
      else
      {
        numberOfNodesInTrack = 0;
      }
      return result;
    }


    public CommandResult BeginRouteDefinition()
    {
      CommandResult result = CallCommand(new BeginRouteDefinition());
      if (result.IsSuccess)
        m_beginRoute = true;
      return result;
    }

    public void PushRouteEcef(double speed, Ecef position)
    {
      if (!m_beginRoute)
        throw new Exception("You must call beginRouteDefinition first.");

      if (speed <= 0)
        throw new Exception("A route node must have a speed limit greater than zero.");

      PostCommand(new PushRouteEcef(speed, position.X, position.Y, position.Z));
    }

    public void PushRouteLla(double speed, Lla lla)
    {
      PushRouteEcef(speed, lla.ToEcef());
    }

    public CommandResult EndRouteDefinition(out int numberOfNodesInRoute)
    {
      if (!m_beginRoute)
        throw new Exception("You must call beginRouteDefinition first and pushRouteEcef/pushRouteLla with all the route nodes before calling endRouteDefinition.");
      m_beginRoute = false;
      CommandResult result = CallCommand(new EndRouteDefinition());
      if (result.IsSuccess)
      {
        EndRouteDefinitionResult routeResult = (EndRouteDefinitionResult)result;
        numberOfNodesInRoute = routeResult.Count;
      }
      else
      {
        numberOfNodesInRoute = 0;
      }
      return result;
    }

    public CommandResult BeginIntTxTrackDefinition(string id)
    {
      CommandResult result = CallCommand(new BeginIntTxTrackDefinition(id));
      if (result.IsSuccess)
      {
        m_beginIntTxTrack.Add(id);
        if (m_verbose)
          PrintLine("Begin Transmitter Track Definition...");
      }
      return result;
    }

    public void PushIntTxTrackEcef(int elapsedTime, Ecef position, string id)
    {
      if (!m_beginIntTxTrack.Contains(id))
        throw new Exception("You must call BeginIntTxTrackDefinition first.");

      PostCommand(new PushIntTxTrackEcef(elapsedTime, position.X, position.Y, position.Z, id));
    }

    public void PushIntTxTrackEcefNed(int elapsedTime, Ecef position, Attitude attitude, string id)
    {
      if (!m_beginIntTxTrack.Contains(id))
        throw new Exception("You must call BeginIntTxTrackDefinition first.");

      PostCommand(new PushIntTxTrackEcefNed(elapsedTime, position.X, position.Y, position.Z, attitude.Yaw, attitude.Pitch, attitude.Roll, id));
    }

    public void PushIntTxTrackLla(int elapsedTime, Lla lla, string id)
    {
      PushIntTxTrackEcef(elapsedTime, lla.ToEcef(), id);
    }

    public void PushIntTxTrackLlaNed(int elapsedTime, Lla lla, Attitude attitude, string id)
    {
      PushIntTxTrackEcefNed(elapsedTime, lla.ToEcef(), attitude, id);
    }

    public CommandResult EndIntTxTrackDefinition(string id, out int numberOfNodesInTrack)
    {
      if (!m_beginIntTxTrack.Contains(id))
        throw new Exception("You must call BeginIntTxTrackDefinition first.");
      m_beginIntTxTrack.Remove(id);
      CommandResult result = CallCommand(new EndIntTxTrackDefinition(id));
      if (result.IsSuccess)
      {
        EndIntTxTrackDefinitionResult trackResult = (EndIntTxTrackDefinitionResult)result;
        numberOfNodesInTrack = trackResult.Count;
      }
      else
      {
        numberOfNodesInTrack = 0;
      }

      if (m_verbose)
        PrintLine("End transmitter track contains " + numberOfNodesInTrack + " nodes.");

      return result;
    }

    private bool HilCheck(double elapsedTime)
    {
      if (m_checkRunningTime < 0.0)
        m_checkRunningTime = elapsedTime;

      if (elapsedTime - m_checkRunningTime >= 1000.0)
      {
        m_checkRunningTime = elapsedTime;
        if (m_hilStreamingCheckEnabled && !CheckIfStreaming())
        {
          ResetTime();
          return false;
        }

        PrintLine("Position sent at " + elapsedTime + " ms");
      }

      return true;
    }

    // Send Skydel an HIL timed position of the vehicle. The position is provided in the LLA coordinate system.
    //
    //  Parameter     Type               Units          Description
    //  -----------------------------------------------------------------------------------------------
    //  elapsedTime                      milliseconds   Time since the beginning of the simulation.
    //  position      lat, long, alt     rad and m      Position of the vehicle.
    //  name                                            If empty, sends the position for the vehicle. If set with a
    //                                                  jammerID, sends the position for the specified jammer's vehicle.
    //
    public bool PushLla(double elapsedTime, Lla lla, string name = "")
    {
      return PushEcef(elapsedTime, lla.ToEcef(), name);
    }

    // Send Skydel an HIL timed position of the vehicle. The position is provided in the ECEF coordinate system.
    //
    //  Parameter     Type      Units          Description
    //  -----------------------------------------------------------------------------------------------
    //  elapsedTime             milliseconds   Time since the beginning of the simulation.
    //  position      x, y, z   m              Position of the vehicle.
    //  name                                   If empty, sends the position for the vehicle. If set with a jammerID, sends
    //                                         the position for the specified jammer's vehicle.
    //
    public bool PushEcef(double elapsedTime, Ecef position, string name = "")
    {
      if (m_hil == null)
        throw new Exception("Cannot send position to simulator because you are not connected.");

      m_hil.PushEcef(elapsedTime, position, name);
      return HilCheck(elapsedTime);
    }

    // Send Skydel an HIL timed position and the associated dynamics of the vehicle. The position is provided in the ECEF
    // coordinate system.
    //
    //  Parameter     Type      Units          Description
    //  -----------------------------------------------------------------------------------------------
    //  elapsedTime             milliseconds   Time since the beginning of the simulation.
    //  position      x, y, z   m              Position of the vehicle.
    //  velocity      x, y, z   m/s            Velocity of the vehicle.
    //  name                                   If empty, sends the position for the vehicle. If set with a jammerID, sends
    //                                         the position for the specified jammer's vehicle.
    //
    public bool PushEcef(double elapsedTime, Ecef position, Ecef velocity, string name = "")
    {
      if (m_hil == null)
        throw new Exception("Cannot send position to simulator because you are not connected.");

      m_hil.PushEcef(elapsedTime, position, velocity, name);
      return HilCheck(elapsedTime);
    }

    // Send Skydel an HIL timed position and the associated dynamics of the vehicle. The position is provided in the ECEF
    // coordinate system.
    //
    //  Parameter      Type      Units          Description
    //  ------------------------------------------------------------------------------------------------
    //  elapsedTime              milliseconds   Time since the beginning of the simulation.
    //  position       x, y, z   m              Position of the vehicle.
    //  velocity       x, y, z   m/s            Velocity of the vehicle.
    //  acceleration   x, y, z   m/s²           Acceleration of the vehicle.
    //  name                                    If empty, sends the position for the vehicle. If set with a jammerID,
    //                                          sends the position for the specified jammer's vehicle.
    //
    public bool PushEcef(double elapsedTime, Ecef position, Ecef velocity, Ecef acceleration, string name = "")
    {
      if (m_hil == null)
        throw new Exception("Cannot send position to simulator because you are not connected.");

      m_hil.PushEcef(elapsedTime, position, velocity, acceleration, name);
      return HilCheck(elapsedTime);
    }

    // Send Skydel an HIL timed position and the associated dynamics of the vehicle. The position is provided in the ECEF
    // coordinate system.
    //
    //  Parameter      Type      Units          Description
    //  ------------------------------------------------------------------------------------------------
    //  elapsedTime              milliseconds   Time since the beginning of the simulation.
    //  position       x, y, z   m              Position of the vehicle.
    //  velocity       x, y, z   m/s            Velocity of the vehicle.
    //  acceleration   x, y, z   m/s²           Acceleration of the vehicle.
    //  jerk           x, y, z   m/s³           Jerk of the vehicle.
    //  name                                    If empty, sends the position for the vehicle. If set with a jammerID,
    //                                          sends the position for the specified jammer's vehicle.
    //
    public bool PushEcef(double elapsedTime, Ecef position, Ecef velocity, Ecef acceleration, Ecef jerk, string name = "")
    {
      if (m_hil == null)
        throw new Exception("Cannot send position to simulator because you are not connected.");

      m_hil.PushEcef(elapsedTime, position, velocity, acceleration, jerk, name);
      return HilCheck(elapsedTime);
    }

    // Send Skydel an HIL timed position and orientation of the vehicle. The position is provided in the LLA coordinate
    // system, while the body's orientation is specified relative to the local NED reference frame.
    //
    //  Parameter     Type               Units          Description
    //  -----------------------------------------------------------------------------------------------
    //  elapsedTime                      milliseconds   Time since the beginning of the simulation.
    //  position      lat, long, alt     rad and m      Position of the vehicle.
    //  attitude      yaw, pitch, roll   rad            Orientation of the vehicle's body.
    //  name                                            If empty, sends the position for the vehicle. If set with a
    //                                                  jammerID, sends the position for the specified jammer's vehicle.
    //
    public bool PushLlaNed(double elapsedTime, Lla lla, Attitude attitude, string name = "")
    {
      return PushEcefNed(elapsedTime, lla.ToEcef(), attitude, name);
    }

    // Send Skydel an HIL timed position and orientation of the vehicle. The position is provided in the LLA coordinate
    // system, while the body's orientation is specified relative to the local NED reference frame.
    //
    //  Parameter     Type               Units          Description
    //  -----------------------------------------------------------------------------------------------
    //  elapsedTime                      milliseconds   Time since the beginning of the simulation.
    //  position      lat, long, alt     rad and m      Position of the vehicle.
    //  attitude      yaw, pitch, roll   rad            Orientation of the vehicle's body.
    //  name                                            If empty, sends the position for the vehicle. If set with a
    //                                                  jammerID, sends the position for the specified jammer's vehicle.
    // 
    public bool PushEcefNed(double elapsedTime, Ecef position, Attitude attitude, string name = "")
    {
      if (m_hil == null)
        throw new Exception("Cannot send position to simulator because you are not connected.");

      m_hil.PushEcefNed(elapsedTime, position, attitude, name);
      return HilCheck(elapsedTime);
    }

    // Send Skydel an HIL timed position, orientation, and the associated dynamics of the vehicle. The position is
    // provided in the ECEF coordinate system, while the body's orientation is specified relative to the local NED
    // reference frame.
    //
    //  Parameter             Type               Units          Description
    //  -------------------------------------------------------------------------------------------------------
    //  elapsedTime                              milliseconds   Time since the beginning of the simulation.
    //  position              x, y, z            m              Position of the vehicle.
    //  attitude              yaw, pitch, roll   rad            Orientation of the vehicle's body.
    //  velocity              x, y, z            m/s            Velocity of the vehicle.
    //  angularVelocity       yaw, pitch, roll   rad/s          Rotational velocity of the vehicle's body.
    //  name                                                    If empty, sends the position for the vehicle. If set with
    //                                                          a jammerID, sends the position for the specified jammer's
    //                                                          vehicle.
    //
    public bool PushEcefNed(double elapsedTime, Ecef position, Attitude attitude, Ecef velocity, Attitude angularVelocity, string name = "")
    {
      if (m_hil == null)
        throw new Exception("Cannot send position to simulator because you are not connected.");

      m_hil.PushEcefNed(elapsedTime, position, attitude, velocity, angularVelocity, name);
      return HilCheck(elapsedTime);
    }

    // Send Skydel an HIL timed position, orientation, and the associated dynamics of the vehicle. The position is
    // provided in the ECEF coordinate system, while the body's orientation is specified relative to the local NED
    // reference frame.
    //
    //  Parameter             Type               Units          Description
    //  -------------------------------------------------------------------------------------------------------
    //  elapsedTime                              milliseconds   Time since the beginning of the simulation.
    //  position              x, y, z            m              Position of the vehicle.
    //  attitude              yaw, pitch, roll   rad            Orientation of the vehicle's body.
    //  velocity              x, y, z            m/s            Velocity of the vehicle.
    //  angularVelocity       yaw, pitch, roll   rad/s          Rotational velocity of the vehicle's body.
    //  acceleration          x, y, z            m/s²           Acceleration of the vehicle.
    //  angularAcceleration   yaw, pitch, roll   rad/s²         Rotational acceleration of the vehicle's body.
    //  name                                                    If empty, sends the position for the vehicle. If set with
    //                                                          a jammerID, sends the position for the specified jammer's
    //                                                          vehicle.
    //
    public bool PushEcefNed(double elapsedTime, Ecef position, Attitude attitude, Ecef velocity, Attitude angularVelocity, Ecef acceleration, Attitude angularAcceleration, string name = "")
    {
      if (m_hil == null)
        throw new Exception("Cannot send position to simulator because you are not connected.");

      m_hil.PushEcefNed(elapsedTime, position, attitude, velocity, angularVelocity, acceleration, angularAcceleration, name);
      return HilCheck(elapsedTime);
    }

    // Send Skydel an HIL timed position, orientation, and the associated dynamics of the vehicle. The position is
    // provided in the ECEF coordinate system, while the body's orientation is specified relative to the local NED
    // reference frame.
    //
    //  Parameter             Type               Units          Description
    //  -------------------------------------------------------------------------------------------------------
    //  elapsedTime                              milliseconds   Time since the beginning of the simulation.
    //  position              x, y, z            m              Position of the vehicle.
    //  attitude              yaw, pitch, roll   rad            Orientation of the vehicle's body.
    //  velocity              x, y, z            m/s            Velocity of the vehicle.
    //  angularVelocity       yaw, pitch, roll   rad/s          Rotational velocity of the vehicle's body.
    //  acceleration          x, y, z            m/s²           Acceleration of the vehicle.
    //  angularAcceleration   yaw, pitch, roll   rad/s²         Rotational acceleration of the vehicle's body.
    //  jerk                  x, y, z            m/s³           Jerk of the vehicle.
    //  angularJerk           yaw, pitch, roll   rad/s³         Rotational jerk of the vehicle's body.
    //  name                                                    If empty, sends the position for the vehicle. If set with
    //                                                          a jammerID, sends the position for the specified jammer's
    //                                                          vehicle.
    //
    public bool PushEcefNed(double elapsedTime, Ecef position, Attitude attitude, Ecef velocity, Attitude angularVelocity, Ecef acceleration, Attitude angularAcceleration, Ecef jerk, Attitude angularJerk, string name = "")
    {
      if (m_hil == null)
        throw new Exception("Cannot send position to simulator because you are not connected.");

      m_hil.PushEcefNed(elapsedTime, position, attitude, velocity, angularVelocity, acceleration, angularAcceleration, jerk, angularJerk, name);
      return HilCheck(elapsedTime);
    }

    private void HandleException(CommandResult result)
    {
      if (IsExceptionOnError && !result.IsSuccess)
      {
        SimulatorStateResult stateResult = (SimulatorStateResult)Call(new GetSimulatorState());

        string errorMsg = "";
        if (stateResult.State == "Error")
          errorMsg = "\nAn error occured during simulation. Error message:\n" + stateResult.Error;

        throw new CommandException(result, errorMsg);
      }

      if (IsVerbose && !result.IsSuccess)
        PrintLine(result.RelatedCommand.Name + " failed: " + result.Message);
    }

    private void Print(string msg)
    {
      if (IsVerbose)
        Console.Write(msg);
    }

    private void PrintLine(string msg)
    {
      if (IsVerbose)
        Console.WriteLine(msg);
    }

    private void PrintLine()
    {
      if (IsVerbose)
        Console.WriteLine();
    }

    public CommandBase Post(CommandBase cmd, double timestamp)
    {
      CheckForbiddenPost(cmd);
      Print("Post " + cmd.ToReadableCommand() + " at " + cmd.Timestamp + " secs");
      PostCommand(cmd, timestamp);
      return cmd;
    }

    public CommandBase Post(CommandBase cmd, DateTime gpsTimestamp)
    {
        CheckForbiddenPost(cmd);
        Print("Post " + cmd.ToReadableCommand() + " at " + gpsTimestamp);
        PostCommand(cmd, gpsTimestamp);
        return cmd;
    }

    public CommandBase Post(CommandBase cmd)
    {
      CheckForbiddenPost(cmd);
      PrintLine("Post " + cmd.ToReadableCommand());
      PostCommand(cmd);
      return cmd;
    }

    public CommandResult Wait(CommandBase cmd)
    {
      Print("Wait " + cmd.ToReadableCommand());
      CommandResult result = WaitCommand(cmd);
      PrintLine(" => " + result.Message);
      return result;
    }

    public CommandResult Call(CommandBase cmd, double timestamp)
    {
      CheckForbiddenCall(cmd);
      PostCommand(cmd, timestamp);
      Print("Call " + cmd.ToReadableCommand() + " at " + cmd.Timestamp + " secs");
      CommandResult result = WaitCommand(cmd);
      PrintLine(" => " + result.Message);
      return result;
    }

    public CommandResult Call(CommandBase cmd)
    {
      CheckForbiddenCall(cmd);
      PostCommand(cmd);
      Print("Call " + cmd.ToReadableCommand());
      CommandResult result = WaitCommand(cmd);
      PrintLine(" => " + result.Message);
      return result;
    }

    private void DeprecatedMessage(CommandBase cmd)
    {
      string deprecated = cmd.Deprecated;
      if (deprecated != null && (m_deprecatedMessageMode == DeprecatedMessageMode.ALL || (m_deprecatedMessageMode == DeprecatedMessageMode.LATCH && !m_latchDeprecated.Contains(cmd.Name))))
      {
        Console.WriteLine("Warning: " + deprecated);
        m_latchDeprecated.Add(cmd.Name);
      }
    }

    private CommandBase PostCommand(CommandBase cmd, double timestamp)
    {
      DeprecatedMessage(cmd);
      cmd.Timestamp = timestamp;
      m_client.SendCommand(cmd);
      return cmd;
    }

    private CommandBase PostCommand(CommandBase cmd, DateTime timestamp)
    {
        DeprecatedMessage(cmd);
        cmd.GpsTimestamp = timestamp;
        m_client.SendCommand(cmd);
        return cmd;
    }

    private CommandBase PostCommand(CommandBase cmd)
    {
      DeprecatedMessage(cmd);
      m_client.SendCommand(cmd);
      return cmd;
    }

    private CommandResult WaitCommand(CommandBase cmd)
    {
      CommandResult result = m_client.WaitCommand(cmd);
      HandleException(result);
      return result;
    }

    private CommandResult CallCommand(CommandBase cmd, double timestamp)
    {
      PostCommand(cmd, timestamp);
      return WaitCommand(cmd);
    }

    private CommandResult CallCommand(CommandBase cmd, DateTime gpsTimestamp)
    {
        PostCommand(cmd, gpsTimestamp);
        return WaitCommand(cmd);
    }

    private CommandResult CallCommand(CommandBase cmd)
    {
      PostCommand(cmd);
      return WaitCommand(cmd);
    }
  }
}

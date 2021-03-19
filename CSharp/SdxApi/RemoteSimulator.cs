using System;
using Sdx.Cmd;

namespace Sdx
{
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

    private bool m_verbose = false;
    private HilClient m_hil = null;
    private CmdClient m_client = null;
    private long m_checkRunningTime = 0;
    private bool m_beginTrack = false;
    private bool m_beginRoute = false;
    private int m_serverApiVersion = 0;

    public RemoteSimulator(bool isExceptionOnError = true)
    {
      IsExceptionOnError = isExceptionOnError;
      ResetTime();
    }

    private void ResetTime()
    {
      m_checkRunningTime = -999999999;
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

    private void CheckForbidden(CommandBase cmd)
    {
      if (cmd.Name == "Start")
        throw new Exception("You cannot send a Start() command. Use RemoteSimulator.Start() instead.");
      if (cmd.Name == "BeginTrackDefinition")
        throw new Exception("You cannot send a BeginTrackDefinition command. Use RemoteSimulator.BeginTrackDefinition() instead.");
      if (cmd.Name == "EndTrackDefinition")
        throw new Exception("You cannot send a EndTrackDefinition command. Use RemoteSimulator.EndTrackDefinition() instead.");
      if (cmd.Name == "PushTrackEcef")
        throw new Exception("You cannot send a PushTrackEcef command. Use RemoteSimulator.PushTrackEcef() or RemoteSimulator.PushTrackLla() instead.");
      if (cmd.Name == "PushTrackEcefNed")
        throw new Exception("You cannot send a PushTrackEcefNed command. Use RemoteSimulator.PushTrackEcefNed() or RemoteSimulator.PushTrackEcefLlaNed() instead.");
      if (cmd.Name == "BeginRouteDefinition")
        throw new Exception("You cannot send a BeginRouteDefinition command. Use RemoteSimulator.BeginRouteDefinition() instead.");
      if (cmd.Name == "EndRouteDefinition")
        throw new Exception("You cannot send a EndRouteDefinition command. Use RemoteSimulator.EndRouteDefinition() instead.");
      if (cmd.Name == "PushRouteEcef")
        throw new Exception("You cannot send a PushRouteNode command. Use RemoteSimulator.PushRouteLla() or RemoteSimulator.PushRouteEcef() instead.");
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

    public void PushTrackEcef(int elapsedTime, Ecef ecef)
    {
      if (!m_beginTrack)
        throw new Exception("You must call beginTrackDefinition first.");
      PostCommand(new PushTrackEcef(elapsedTime, ecef.X, ecef.Y, ecef.Z));
    }

    public void PushTrackEcefNed(int elapsedTime, Ecef ecef, Attitude attitude)
    {
      if (!m_beginTrack)
        throw new Exception("You must call beginTrackDefinition first.");
      PostCommand(new PushTrackEcefNed(elapsedTime, ecef.X, ecef.Y, ecef.Z,
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

    public void PushRouteEcef(double speed, Ecef ecef)
    {
      if (!m_beginRoute)
        throw new Exception("You must call beginRouteDefinition first.");

      if (speed <= 0)
        throw new Exception("A route node must have a speed limit greater than zero.");

      PostCommand(new PushRouteEcef(speed, ecef.X, ecef.Y, ecef.Z));
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

    private bool HilCheck(long elapsedTime)
    {
      if (m_checkRunningTime < 0)
        m_checkRunningTime = elapsedTime;

      if (elapsedTime - m_checkRunningTime >= 1000)
      {
        m_checkRunningTime = elapsedTime;
        if (!CheckIfStreaming())
        {
          ResetTime();
          return false;
        }

        PrintLine("Position sent at " + elapsedTime + " ms");
      }

      return true;
    }

    public bool PushLla(long elapsedTime, Lla lla, string name = "")
    {
      return PushEcef(elapsedTime, lla.ToEcef(), name);
    }

    public bool PushEcef(long elapsedTime, Ecef ecef, string name = "")
    {
      if (m_hil == null)
        throw new Exception("Cannot send position to simulator because you are not connected.");

      if (!HilCheck(elapsedTime))
        return false;

      m_hil.PushEcef(elapsedTime, ecef, name);
      return true;
    }

    public bool PushLlaNed(long elapsedTime, Lla lla, Attitude attitude, string name = "")
    {
      return PushEcefNed(elapsedTime, lla.ToEcef(), attitude, name);
    }

    public bool PushEcefNed(long elapsedTime, Ecef ecef, Attitude attitude, string name = "")
    {
      if (m_hil == null)
        throw new Exception("Cannot send position to simulator because you are not connected.");

      if (!HilCheck(elapsedTime))
        return false;

      m_hil.PushEcefNed(elapsedTime, ecef, attitude, name);
      return true;
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
      CheckForbidden(cmd);
      Print("Post " + cmd.ToReadableCommand() + " at " + cmd.Timestamp + " secs");
      PostCommand(cmd, timestamp);
      return cmd;
    }

    public CommandBase Post(CommandBase cmd)
    {
      CheckForbidden(cmd);
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
      CheckForbidden(cmd);
      PostCommand(cmd, timestamp);
      Print("Call " + cmd.ToReadableCommand() + " at " + cmd.Timestamp + " secs");
      CommandResult result = WaitCommand(cmd);
      PrintLine(" => " + result.Message);
      return result;
    }

    public CommandResult Call(CommandBase cmd)
    {
      CheckForbidden(cmd);
      PostCommand(cmd);
      Print("Call " + cmd.ToReadableCommand());
      CommandResult result = WaitCommand(cmd);
      PrintLine(" => " + result.Message);
      return result;
    }

    private CommandBase PostCommand(CommandBase cmd, double timestamp)
    {
      cmd.Timestamp = timestamp;
      m_client.SendCommand(cmd);
      return cmd;
    }

    private CommandBase PostCommand(CommandBase cmd)
    {
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

    private CommandResult CallCommand(CommandBase cmd)
    {
      PostCommand(cmd);
      return WaitCommand(cmd);
    }
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Orolia Canada Inc.
// Skydel - Software-Defined GNSS Simulator
// Remote API C# Examples
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// NOTES:
// 1- Before executing the examples, make sure Simulator is running on local computer.
// 2- During the Execution, you can get execution details by enabling the verbose mode: sim.IsVerbose = true;
// 3- All examples are set to run without hardware. 
//    You can easily change the TARGET_TYPE to "X300", for example
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
using System;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Sdx;
using Sdx.Cmd;
using System.Threading;
using System.Collections.Generic;

namespace SdxExamples
{
  class Program
  {
    static void Main(string[] args)
    {
      // If you wish to connect to the simulator running on a remote computer,
      // change "localhost" for the remote computer's IP address, such as "192.168.1.100"
      const string HOST = "localhost";
      const string TARGET_TYPE = "NoneRT"; // Change to "X300" to execute on a X300 device
      const string X300_IP = "";  // Change to "192.168.XXX.XXX" to execute on a X300 device

      try
      {
        RunExampleBasic(HOST, TARGET_TYPE, X300_IP);
        RunExampleVehicleInfo(HOST, TARGET_TYPE, X300_IP);
        RunExampleCreateTrack(HOST, TARGET_TYPE, X300_IP);
        RunExampleCreateTrack6dof(HOST, TARGET_TYPE, X300_IP);
        RunExampleCreateRouteCar(HOST, TARGET_TYPE, X300_IP);
        RunExampleHilRealtime(HOST, TARGET_TYPE, X300_IP);
        RunExampleElapsedTime(HOST, TARGET_TYPE, X300_IP);
        RunExampleInterferences(HOST, TARGET_TYPE, X300_IP);
        RunExampleAutomaticStop(HOST, TARGET_TYPE, X300_IP);
        RunExampleFailureHandling(HOST, TARGET_TYPE, X300_IP);
        RunExampleGetPower(HOST, TARGET_TYPE, X300_IP);
      }
      catch (CommandException e)
      {
        Console.WriteLine("Simulator Command Exception caught:\n" + e.ToString());
      }
      catch (Exception e)
      {
        Console.WriteLine("Runtime Error Exception caught:\n" + e.ToString());
      }

      Console.WriteLine("Press any key to exit...");
      Console.ReadKey();
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Basic Example
    // This example shows:
    // 1- How to connect to the simulator
    // 2- Set Basic Simulation Parameters
    // 3- Start Simulation
    // 4- Send command to the simulator during the simulation
    // 5- Stop the simulation, and disconnect from the simulator
    // 6- How to pause/resume Vehicle motion
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void RunExampleBasic(string host, string target_type, string x300_ip)
    {
      Console.WriteLine("=== Basic Example ===");

      Console.WriteLine("==> Connecting to the simulator");
      RemoteSimulator sim = new RemoteSimulator();
      sim.IsVerbose = false;
      sim.Connect(host);

      Console.WriteLine("==> Create New Configuration, discarding current simulator settings");
      sim.Call(new New(true));

      Console.WriteLine("==> Modulation Settings");
      string targetId = "MyTargetId";
      sim.Call(new SetModulationTarget(target_type, "", x300_ip, true, targetId));
      // Select signals to simulate
      sim.Call(new ChangeModulationTargetSignals(0, 12500000, 12500000, "UpperL", "L1CA", -1, false, targetId));

      Console.WriteLine("==> Vehicle Settings");
      sim.Call(new SetVehicleTrajectoryCircular("Circular", 0.7853995339022749, -1.2740964277717111, 0, 50, 3, true));
      sim.Call(new SetGpsStartTime(new DateTime(2021, 02, 15, 7, 0, 0)));
      sim.Call(new SetVehicleAntennaGain(new List<List<double>>(), AntennaPatternType.AntennaNone, GNSSBand.L1));

      Console.WriteLine("==> Save configuration");
      sim.Call(new Save());

      Console.WriteLine("==> Arming the simulation");
      sim.Arm();

      Console.WriteLine("==> Change satellite 16 power to +5 dB  (relative to nominal power)");
      sim.Call(new SetPowerForSV("GPS", 16, 5, false));

      Console.WriteLine("==> Starting the simulation");
      sim.Start();

      Console.WriteLine("==> Right after start, change satellite 25 power to -15dB (relative to nominal power)");
      sim.Call(new SetPowerForSV("GPS", 25, -15, false));

      // Asynchronous command examples
      Console.WriteLine("==> CMD #1: At simulation time 9.567s, Change satellite 32 power to -25dB (relative to nominal power)");
      CommandBase cmd1 = sim.Post(new SetPowerForSV("GPS", 32, -25, false), 9.567);
      Console.WriteLine("==> CMD #2: At simulation time 12.05s, Change satellite 29 power to +10dB (relative to nominal power)");
      CommandBase cmd2 = sim.Post(new SetPowerForSV("GPS", 29, 10, false), 12.05);

      // Wait for commands to complete
      Console.Write("==> Waiting for CMD #1...");
      sim.Wait(cmd1);
      Console.WriteLine("Done!");
      Console.Write("==> Waiting for CMD #2...");
      sim.Wait(cmd2);
      Console.WriteLine("Done!");

      Console.WriteLine("==> At simulation time 15s, reset all satellites to nominal power");
      sim.Call(new ResetAllSatPower("GPS"), 15);

      Console.WriteLine("==> Pause vehicle motion");
      sim.Call(new Pause());
      sim.Call(new Resume(), 18);
      Console.WriteLine("==> Vehicle motion resumed at 18 sec");

      Console.WriteLine("==> Stop simulation when elapsed time is 20 sec...");
      sim.Stop(20);

      Console.WriteLine("==> Disconnect from Simulator");
      sim.Disconnect();
    }


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Failure Handling Example
    // This example shows:
    // 1- How to verify command result
    // 2- How to get error messages from command failure
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void RunExampleFailureHandling(string host, string target_type, string x300_ip)
    {
      Console.WriteLine();
      Console.WriteLine("=== Failure handling Example ===");

      Console.WriteLine("==> Connecting to the simulator");
      //RemoteSimulator sim = new RemoteSimulator(true); //Stop the script with a exception if a command fail
      RemoteSimulator sim = new RemoteSimulator(false); //Does not stop the script with a exception if a command fail
      sim.IsVerbose = false;
      sim.Connect(host);

      Console.WriteLine("==> Create New Configuration, discarding current simulator settings");
      sim.Call(new New(true));

      Console.WriteLine("==> Modulation Settings");
      string targetId = "MyTargetId";
      sim.Call(new SetModulationTarget(target_type, "", x300_ip, true, targetId));
      // Select signals to simulate
      sim.Call(new ChangeModulationTargetSignals(0, 12500000, 12500000, "UpperL", "L1CA", -1, false, targetId));


      // Command Success Example:
      // Changing configuration before starting the simulation.
      CommandResult result1 = sim.Call(new ChangeModulationTargetSignals(0, 12500000, 50000000, "UpperL", "L1CA,G1", -1, false, targetId));
      Console.WriteLine("SUCCESS MESSAGE EXAMPLE: " + result1.Message); //Will print Success

      // Command Failure Example:
      // The following command is not allowed before you start the simulation.
      CommandResult result2 = sim.Call(new SetPowerForSV("GPS", 12, -10, true));
      Console.WriteLine("FAILURE MESSAGE EXAMPLE: " + result2.Message);

      Console.WriteLine("==> Starting Simulation");
      if (sim.Start())
      {
        // Change satellite 14 power to -15dB (relative to nominal power)
        sim.Call(new SetPowerForSV("GPS", 14, -15, false));

        // Command Failure Example:
        // The following command (setting simulation start time) is not allowed once simulation is started.
        CommandResult result3 = sim.Call(new SetGpsStartTime(new DateTime(2021, 2, 15, 7, 0, 0)));
        Console.WriteLine("FAILURE MESSAGE EXAMPLE: " + result3.RelatedCommand.ToReadableCommand() + ": " + result3.Message);

        // Asynchronous Success command example
        // When simulation elapsed time is 9.567 sec, change satellite 31 power to -25 dB
        CommandBase cmd4 = sim.Post(new SetPowerForSV("GPS", 31, -25, false), 9.567);

        // Asynchronous Failure command example
        // When simulation elapsed time is 12.05 sec, change satellite 200 power to +10 dB
        CommandBase cmd5 = sim.Post(new SetPowerForSV("GPS", 200, 10, false), 12.05);

        // Wait for Asynchronous commands to complete
        CommandResult result4 = sim.Wait(cmd4);
        CommandResult result5 = sim.Wait(cmd5);

        Console.WriteLine("SUCCESS MESSAGE EXAMPLE: " + result4.RelatedCommand.ToReadableCommand() + ": " + result4.Message);
        Console.WriteLine("FAILURE MESSAGE EXAMPLE: " + result5.RelatedCommand.ToReadableCommand() + ": " + result5.Message);

        Console.WriteLine("==> Stop simulation when elapsed time is 20 sec");
        sim.Stop(20);
      }

      SimulatorStateResult stateResult = (SimulatorStateResult)sim.Call(new GetSimulatorState());
      if (stateResult.State == "Error")
        Console.WriteLine("An error occured during simulation. Error message:\n" + stateResult.Error);

      sim.Disconnect();
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Elasped Time Example
    // This example shows:
    // 1- How to get simulation elasped time
    // 2- How to retrieve values from command results
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void RunExampleElapsedTime(string host, string target_type, string x300_ip)
    {
      Console.WriteLine();
      Console.WriteLine("=== Get Elapsed Time Example ===");

      Console.WriteLine("==> Connecting to the simulator");
      RemoteSimulator sim = new RemoteSimulator();
      sim.IsVerbose = false;
      sim.Connect(host);

      Console.WriteLine("==> Create New Configuration, discarding current simulator settings");
      sim.Call(new New(true));

      Console.WriteLine("==> Modulation Settings");
      string targetId = "MyTargetId";
      sim.Call(new SetModulationTarget(target_type, "", x300_ip, true, targetId));
      // Select signals to simulate
      sim.Call(new ChangeModulationTargetSignals(0, 12500000, 12500000, "UpperL", "L1CA", -1, false, targetId));

      sim.Start();

      int elapsedTimeMs = 0;
      while (elapsedTimeMs < 20000)
      {
        SimulationElapsedTimeResult time = (SimulationElapsedTimeResult)sim.Call(new GetSimulationElapsedTime());
        elapsedTimeMs = time.Milliseconds;
        string formattedTime = TimeSpan.FromMilliseconds(elapsedTimeMs).ToString(@"g");
        Console.WriteLine("Simulation Elapsed Time: " + formattedTime);
        Thread.Sleep(250);
      }

      Console.WriteLine("==> Stop simulation after 20 seconds of time polling");
      sim.Stop();
      sim.Disconnect();
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Vehicle Information Example
    // This example shows:
    // 1- Get Information about the simulated Vehicle during the simulation
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void RunExampleVehicleInfo(string host, string target_type, string x300_ip)
    {
      Console.WriteLine("=== Simulation Statistics Example ===");

      Console.WriteLine("==> Connecting to the simulator");
      RemoteSimulator sim = new RemoteSimulator();
      sim.Connect(host);

      Console.WriteLine("==> Create New Configuration, discarding current simulator settings");
      sim.Call(new New(true));

      Console.WriteLine("==> Modulation Settings");
      string targetId = "MyTargetId";
      sim.Call(new SetModulationTarget(target_type, "", x300_ip, true, targetId));
      // Select signals to simulate
      sim.Call(new ChangeModulationTargetSignals(0, 12500000, 12500000, "UpperL", "L1CA", -1, false, targetId));

      Console.WriteLine("==> Vehicle Settings");
      sim.Call(new SetVehicleTrajectoryCircular("Circular", 0.7853995339022749, -1.2740964277717111, 0, 50, 3, true));

      Console.WriteLine("==> Starting the simulation");
      Console.WriteLine("==> Begin receiving vehicle informations");
      //You must call BeginVehicleInfo before getting vehicle informations
      sim.BeginVehicleInfo();
      sim.Start();

      Console.WriteLine("==> Getting vehicle statistics");
      VehicleInfo vehicleInfo = sim.LastVehicleInfo();

      Lla originLla = vehicleInfo.Position.ToLla(); //convert ecef origin to lla
      do
      {
        //sim.LastVehicleInfo() will block till a vehicle info is received,
        //you can use sim.HasVehicleInfo(), if you do not want a blocking behavior :
        //if (!sim.HasVehicleInfo()) continue;

        vehicleInfo = sim.LastVehicleInfo();
        Lla currentLla = vehicleInfo.Position.ToLla(); //convert ecef to lla
        Enu currentEnu = currentLla.ToEnu(originLla); //convert lla to enu
        Console.WriteLine("--------------------------------------------------");
        Console.WriteLine("Time (ms): " + vehicleInfo.ElapsedTime);
        Console.Write("ENU Position (meters): " + currentEnu.North.ToString("F2") + " ");
        Console.WriteLine(currentEnu.East.ToString("F2") + " " + currentEnu.Up.ToString("F2"));
        Console.Write("NED Attitude (deg): " + vehicleInfo.Attitude.YawDeg.ToString("F2") + " ");
        Console.WriteLine(vehicleInfo.Attitude.PitchDeg.ToString("F2") + ", " + vehicleInfo.Attitude.RollDeg.ToString("F2"));
        Console.Write("Odometer (meters): " + vehicleInfo.Odometer.ToString("F2"));
        Console.Write(" | Heading (deg): " + (vehicleInfo.Heading / Math.PI * 180).ToString("F2"));
        Console.WriteLine(" | Speed (m/s): " + vehicleInfo.Speed.ToString("F2"));

        //You can remove or decrease this sleep to get more resolution
        //A vehicle info is sent each 10 ms from simulator
        Thread.Sleep(1000);
      } while (vehicleInfo.ElapsedTime < 90000);

      Console.WriteLine("==> Stop simulation when elapsed time is 90 sec...");
      sim.Stop();
      sim.EndVehicleInfo();

      Console.WriteLine("==> Disconnect from Simulator");
      sim.Disconnect();
    }


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Track creation Example
    // This example shows:
    // 1- Create a vehicle trajectory from different nodes forming a track.
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void RunExampleCreateTrack(string host, string target_type, string x300_ip)
    {
      Console.WriteLine();
      Console.WriteLine("=== Create Track Example ===");

      Console.WriteLine("==> Connecting to the simulator");
      RemoteSimulator sim = new RemoteSimulator();
      sim.Connect(host);

      Console.WriteLine("==> Modulation Settings");
      string targetId = "MyTargetId";
      sim.Call(new SetModulationTarget(target_type, "", x300_ip, true, targetId));
      // Select signals to simulate
      sim.Call(new ChangeModulationTargetSignals(0, 12500000, 12500000, "UpperL", "L1CA", -1, false, targetId));


      sim.Call(new SetVehicleTrajectory("Track"));
      sim.BeginTrackDefinition();

      sim.PushTrackLla(0, new Lla(ToRadian(45.0000), ToRadian(-73.0000), 0));
      sim.PushTrackLla(5000, new Lla(ToRadian(45.0005), ToRadian(-73.0005), 0));
      sim.PushTrackLla(10000, new Lla(ToRadian(45.0010), ToRadian(-73.0000), 0));
      sim.PushTrackLla(15000, new Lla(ToRadian(45.0015), ToRadian(-73.0005), 0));
      sim.PushTrackLla(20000, new Lla(ToRadian(45.0020), ToRadian(-73.0000), 0));

      int numberOfNodes;
      sim.EndTrackDefinition(out numberOfNodes);
      Console.WriteLine("==> Track created, number of nodes in Track = " + numberOfNodes);

      Console.WriteLine("==> Starting Simulation");
      sim.Start();

      Console.WriteLine("==> Stop simulation when elapsed time is 20 sec");
      sim.Stop(20);

      Console.WriteLine("==> Disconnect from Simulator");
      sim.Disconnect();
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // 6 Degrees of Freedom (6DOF) Track creation Example
    // This example shows:
    // 1- Create a vehicle trajectory from different nodes forming a 6DOF track.
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void RunExampleCreateTrack6dof(string host, string target_type, string x300_ip)
    {
      Console.WriteLine();
      Console.WriteLine("=== Create Track 6 Degrees of Liberty Example ===");

      Console.WriteLine("==> Connecting to the simulator");
      RemoteSimulator sim = new RemoteSimulator();
      sim.Connect(host);

      Console.WriteLine("==> Modulation Settings");
      string targetId = "MyTargetId";
      sim.Call(new SetModulationTarget(target_type, "", x300_ip, true, targetId));
      // Select signals to simulate
      sim.Call(new ChangeModulationTargetSignals(0, 12500000, 12500000, "UpperL", "L1CA", -1, false, targetId));

      sim.Call(new SetVehicleTrajectory("Track"));
      sim.BeginTrackDefinition();

      sim.PushTrackLlaNed(0, new Lla(ToRadian(45.0000), ToRadian(-73.0000), 0), new Attitude(ToRadian(-35), ToRadian(5), 0));
      sim.PushTrackLlaNed(4000, new Lla(ToRadian(45.0004), ToRadian(-73.0004), 0), new Attitude(ToRadian(-35), ToRadian(5), 0));
      sim.PushTrackLlaNed(5000, new Lla(ToRadian(45.0005), ToRadian(-73.0005), 0), new Attitude(ToRadian(35), ToRadian(5), 0));
      sim.PushTrackLlaNed(9000, new Lla(ToRadian(45.0009), ToRadian(-73.0001), 0), new Attitude(ToRadian(35), ToRadian(5), 0));
      sim.PushTrackLlaNed(10000, new Lla(ToRadian(45.0010), ToRadian(-73.0000), 0), new Attitude(ToRadian(-35), ToRadian(-5), 0));
      sim.PushTrackLlaNed(14000, new Lla(ToRadian(45.0014), ToRadian(-73.0004), 0), new Attitude(ToRadian(-35), ToRadian(-5), 0));
      sim.PushTrackLlaNed(15000, new Lla(ToRadian(45.0015), ToRadian(-73.0005), 0), new Attitude(ToRadian(35), ToRadian(-5), 0));
      sim.PushTrackLlaNed(19000, new Lla(ToRadian(45.0019), ToRadian(-73.0001), 0), new Attitude(ToRadian(35), ToRadian(-5), 0));
      sim.PushTrackLlaNed(20000, new Lla(ToRadian(45.0020), ToRadian(-73.0000), 0), new Attitude(ToRadian(-35), ToRadian(-5), 0));

      int numberOfNodes;
      sim.EndTrackDefinition(out numberOfNodes);
      Console.WriteLine("==> Track created, number of nodes in Track = " + numberOfNodes);

      Console.WriteLine("==> Starting Simulation");
      sim.Start();

      Console.WriteLine("==> Stop simulation when elapsed time is 20 sec");
      sim.Stop(20);

      Console.WriteLine("==> Disconnect from Simulator");
      sim.Disconnect();
    }

    static void PushRouteNode(RemoteSimulator sim, double speedKmh, double latDeg, double lonDeg)
    {
      // Push Route LLA in radian with speed in m/s
      sim.PushRouteLla(speedKmh / 3.6, new Lla(ToRadian(latDeg), ToRadian(lonDeg), 0));
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Vehicle Route creation Example
    // This example shows:
    // 1- Create a vehicle trajectory from positions and speed limits
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void RunExampleCreateRouteCar(string host, string target_type, string x300_ip)
    {
      Console.WriteLine();
      Console.WriteLine("=== Create Route Example ===");

      Console.WriteLine("==> Connecting to the simulator");
      RemoteSimulator sim = new RemoteSimulator();
      sim.Connect(host);

      Console.WriteLine("==> Create New Configuration, discarding current simulator settings");
      sim.Call(new New(true));

      Console.WriteLine("==> Modulation Settings");
      string targetId = "MyTargetId";
      sim.Call(new SetModulationTarget(target_type, "", x300_ip, true, targetId));
      // Select signals to simulate
      sim.Call(new ChangeModulationTargetSignals(0, 12500000, 12500000, "UpperL", "L1CA", -1, false, targetId));


      sim.Call(new SetVehicleTrajectory("Route"));
      sim.Call(new EnableTrajectorySmoothing(true));
      sim.BeginRouteDefinition();

      PushRouteNode(sim, 50.0, 42.719943, -73.830492);
      PushRouteNode(sim, 50.0, 42.718155, -73.833370);
      PushRouteNode(sim, 60.0, 42.718110, -73.833439);
      PushRouteNode(sim, 60.0, 42.717620, -73.832875);
      PushRouteNode(sim, 60.0, 42.717296, -73.832508);
      PushRouteNode(sim, 60.0, 42.716674, -73.831805);
      PushRouteNode(sim, 60.0, 42.715545, -73.830511);
      PushRouteNode(sim, 60.0, 42.715469, -73.830427);
      PushRouteNode(sim, 60.0, 42.714831, -73.829695);
      PushRouteNode(sim, 60.0, 42.714155, -73.828924);
      PushRouteNode(sim, 60.0, 42.714200, -73.828803);
      PushRouteNode(sim, 80.0, 42.714720, -73.827925);
      PushRouteNode(sim, 80.0, 42.714759, -73.827850);
      PushRouteNode(sim, 80.0, 42.714769, -73.827747);
      PushRouteNode(sim, 80.0, 42.714752, -73.827672);
      PushRouteNode(sim, 80.0, 42.714681, -73.827552);
      PushRouteNode(sim, 80.0, 42.714338, -73.827183);
      PushRouteNode(sim, 80.0, 42.713316, -73.826026);
      PushRouteNode(sim, 60.0, 42.713257, -73.825929);
      PushRouteNode(sim, 60.0, 42.713235, -73.825804);
      PushRouteNode(sim, 60.0, 42.713235, -73.825693);
      PushRouteNode(sim, 60.0, 42.713248, -73.825528);
      PushRouteNode(sim, 60.0, 42.713708, -73.823088);
      PushRouteNode(sim, 40.0, 42.713837, -73.823108);
      PushRouteNode(sim, 40.0, 42.713902, -73.823097);
      PushRouteNode(sim, 40.0, 42.713979, -73.823028);
      PushRouteNode(sim, 40.0, 42.714546, -73.822143);

      int numberOfNodes;
      sim.EndRouteDefinition(out numberOfNodes);
      Console.WriteLine("==> Route created, number of nodes in Route = " + numberOfNodes);

      //You must call BeginVehicleInfo before getting vehicle informations
      sim.BeginVehicleInfo();
      Console.WriteLine("==> Starting Simulation");
      sim.Start();

      Console.WriteLine("==> Getting vehicle statistics");
      VehicleInfo vehicleInfo = sim.LastVehicleInfo();

      Lla originLla = vehicleInfo.Position.ToLla(); //convert ecef origin to lla
      do
      {
        //sim.LastVehicleInfo() will block till a vehicle info is received,
        //you can use sim.HasVehicleInfo(), if you do not want a blocking behavior :
        //if (!sim.HasVehicleInfo()) continue;

        vehicleInfo = sim.LastVehicleInfo();
        Lla currentLla = vehicleInfo.Position.ToLla(); //convert ecef to lla
        Enu currentEnu = currentLla.ToEnu(originLla); //convert lla to enu
        Console.WriteLine("--------------------------------------------------");
        Console.WriteLine("Time (ms): " + vehicleInfo.ElapsedTime);
        Console.Write("ENU Position (meters): " + currentEnu.North.ToString("F2") + " ");
        Console.WriteLine(currentEnu.East.ToString("F2") + " " + currentEnu.Up.ToString("F2"));
        Console.Write("NED Attitude (deg): " + vehicleInfo.Attitude.YawDeg.ToString("F2") + " ");
        Console.WriteLine(vehicleInfo.Attitude.PitchDeg.ToString("F2") + ", " + vehicleInfo.Attitude.RollDeg.ToString("F2"));
        Console.Write("Odometer (meters): " + vehicleInfo.Odometer.ToString("F2"));
        Console.Write(" | Heading (deg): " + (vehicleInfo.Heading / Math.PI * 180).ToString("F2"));
        Console.WriteLine(" | Speed (m/s): " + vehicleInfo.Speed.ToString("F2"));

        //You can remove or decrease this sleep to get more resolution
        //A vehicle info is sent each 10 ms from simulator
        Thread.Sleep(1000);
      } while (vehicleInfo.ElapsedTime < 60 * 1000);

      Console.WriteLine("==> Stopping simulation");
      sim.Stop();

      Console.WriteLine("==> Disconnect from Simulator");
      sim.Disconnect();
    }

    static double ToRadian(double degree)
    {
      return (Math.PI / 180) * degree;
    }

    static long GetCurrentTime()
    {
      return DateTime.Now.Ticks / TimeSpan.TicksPerMillisecond;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Hardware-In-The-Loop (HIL) Example
    // This example shows:
    // 1- How to push simulated positions during the simulation
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void RunExampleHilRealtime(string host, string target_type, string x300_ip)
    {
      const long HIL_DURATION = 60000;
      const double HIL_SPEED = 10;

      Console.WriteLine();
      Console.WriteLine("=== HIL Example ===");

      Console.WriteLine("==> Connecting to the simulator");
      RemoteSimulator sim = new RemoteSimulator();
      sim.IsVerbose = false;
      sim.Connect(host);

      Console.WriteLine("==> Create New Configuration, discarding current simulator settings");
      sim.Call(new New(true));

      Console.WriteLine("==> Modulation Settings");
      string targetId = "MyTargetId";
      sim.Call(new SetModulationTarget(target_type, "", x300_ip, true, targetId));
      // Select signals to simulate
      sim.Call(new ChangeModulationTargetSignals(0, 12500000, 12500000, "UpperL", "L1CA", -1, false, targetId));

      Console.WriteLine("==> Set to HIL Mode");
      sim.Call(new SetVehicleTrajectory("HIL"));

      Console.WriteLine("==> Starting Simulation");
      sim.Start();

      Lla origin = new Lla(ToRadian(45.0), ToRadian(-74.0), 1.0);

      Console.WriteLine("==> Sending positions in Real-Time, for " + (HIL_DURATION / 1000) + " seconds.");
      long startTime = GetCurrentTime();
      while (true)
      {
        // Here we use the PC time as an example. In reality time should come from the position's generator.
        long elapsedTime = GetCurrentTime() - startTime;

        if (elapsedTime > HIL_DURATION)
          break;

        double t = elapsedTime / 1000.0;

        // Vehicule will head North/East
        Enu enu = new Enu(HIL_SPEED * t, HIL_SPEED * t, 0);
        Lla lla = origin.AddEnu(enu);
        sim.PushLla(elapsedTime, lla);

        // You can also push vehicle attitude attached to the node
        //sim.PushLlaNed(elapsedTime, lla, new Attitude(ToRadian(45), ToRadian(2), 0));

        // You can also push Ecef instead of Lla
        //sim.PushEcef(elapsedTime, lla.ToEcef());

        //Send new position to simulator each 10 ms. This should be controlled by the position's generator.
        Thread.Sleep(10);
      }
      Console.WriteLine("==> Stop simulation");
      sim.Stop();
      sim.Disconnect();
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Interferences Example
    // This example shows:
    // 1- How to add in-band interferences to the simulated signal
    // 2- Change the parameters of the interferences during the simulation
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void RunExampleInterferences(string host, string target_type, string x300_ip)
    {
      Console.WriteLine();
      Console.WriteLine("=== Interferences Example ===");

      Console.WriteLine("==> Connecting to the simulator");
      RemoteSimulator sim = new RemoteSimulator();
      sim.IsVerbose = false;
      sim.Connect(host);

      Console.WriteLine("==> Create New Configuration, discarding current simulator settings");
      sim.Call(new New(true));

      Console.WriteLine("==> Modulation Settings");
      string targetId = "MyTargetId";
      sim.Call(new SetModulationTarget(target_type, "", x300_ip, true, targetId));
      // Select signals to simulate
      sim.Call(new ChangeModulationTargetSignals(0, 12500000, 12500000, "UpperL", "L1CA", -1, false, targetId));

      // Interference 1:
      // Basic Example: create a CW interference at 1.5751GHz, that will stay enabled for the whole simulation.
      string interferenceId1 = "CW Interference 1";
      sim.Call(new SetInterferenceCW(0, 0, 1575100000, -20, true, interferenceId1));

      // Interference 2:
      // Create a CW interference at 1.5752GHz
      string interferenceId2 = "CW Interference 2";
      sim.Call(new SetInterferenceCW(0, 0, 1575200000, -20, true, interferenceId2));
      // Update "CW Interference 2":
      // By using the same "InterferenceId", the simulators knows we want to update an interference.
      // We now set it to run between simulation time 2s and 5s (StartTime:2, EndTime:5)
      sim.Call(new SetInterferenceCW(2, 5, 1575200000, -20, true, interferenceId2));

      // Interference 3:
      // Create a CW Interference at 1.5753GHz
      // This time, we don't give an interferenceId.
      // The simulator will create an Id for us. 
      // We will retreive the Id with the result of the call to the simulator
      SetInterferenceCW cmd = new SetInterferenceCW(0, 0, 1575300000, -20, true, "");
      CommandResult result = sim.Call(cmd);
      // Using the result, we can retreive the command that produced this result
      cmd = (SetInterferenceCW)result.RelatedCommand;
      // The retreived command is a SetInterferenceCW command. It was updated by the simulator with a unique InterferenceId.
      // We can update this command to change the interference, and resend it to the simulator.
      // For example, we can disable this interference.
      cmd.Enabled = false;
      sim.Call(cmd);

      // Interference 4:
      // Create a CW Interference at 1.5754GHz
      // We will program updates to change periodically the power of this interference
      SetInterferenceCW cmdInterference4 = new SetInterferenceCW(0, 0, 1575400000, 0, true, "");
      cmdInterference4 = (SetInterferenceCW)sim.Call(cmdInterference4).RelatedCommand;

      Console.WriteLine("==> Starting Simulation");
      sim.Start();

      // Asynchronous command examples
      // Gradually increase cw interference power from 0 to 10 dB for 10 secs and
      // gradually decrease cw interference power from 10 to 0 dB for 20 secs after 10 secs of simulation
      for (int x = 0; x <= 100; ++x)
      {
        double power = x / 10.0;
        double timeStamp = x / 10.0;
        cmdInterference4.Power = power;
        sim.Post(cmdInterference4, timeStamp);
        cmdInterference4.Power = 10.0 - power;
        sim.Post(cmdInterference4, 10.0 + timeStamp);
      }

      Console.WriteLine("==> Stopping Simulation when elapsed time will be 30s");
      sim.Stop(30);
      sim.Disconnect();
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Automatic simulation stop at trajectory end example
    // This example shows:
    // 1- Create a simple vehicle route and simulate it until the vehicle has reached destination
    // 2- Create a simple vehicle track and simulate it until the vehicle has reached destination
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void RunExampleAutomaticStop(string host, string target_type, string x300_ip)
    {
      Console.WriteLine();
      Console.WriteLine("=== Automatic Stop Example ===");

      Console.WriteLine("==> Connecting to the simulator");
      RemoteSimulator sim = new RemoteSimulator();
      sim.IsVerbose = false;
      sim.Connect(host);

      Console.WriteLine("==> Create New Configuration, discarding current simulator settings");
      sim.Call(new New(true));

      Console.WriteLine("==> Modulation Settings");
      string targetId = "MyTargetId";
      sim.Call(new SetModulationTarget(target_type, "", x300_ip, true, targetId));
      // Select signals to simulate
      sim.Call(new ChangeModulationTargetSignals(0, 12500000, 12500000, "UpperL", "L1CA", -1, false, targetId));

      //When enabled, the simulation will stop when the vehicle will reach its trajectory destination
      Console.WriteLine("==> Enable simulation automatic stop at trajectory end");
      sim.Call(new EnableSimulationStopAtTrajectoryEnd(true));

      int numberOfNodes;

      sim.Call(new SetVehicleTrajectory("Route"));
      sim.BeginRouteDefinition();
      PushRouteNode(sim, 50.0, 42.719943, -73.830492);
      PushRouteNode(sim, 60.0, 42.718110, -73.833439);
      PushRouteNode(sim, 60.0, 42.717620, -73.832875);
      sim.EndRouteDefinition(out numberOfNodes);
      Console.WriteLine("==> Route created, number of nodes in Route = " + numberOfNodes);

      Console.WriteLine("==> Starting Simulation");
      sim.Start();

      Console.WriteLine("==> Wait until the automatic stop happens when vehicle reaches route destination");
      sim.WaitState("Ready");

      sim.Call(new SetVehicleTrajectory("Track"));
      sim.BeginTrackDefinition();
      sim.PushTrackLla(0, new Lla(ToRadian(42.719943), ToRadian(-73.830492), 0));
      sim.PushTrackLla(40000, new Lla(ToRadian(42.718110), ToRadian(-73.833439), 0));
      sim.PushTrackLla(45000, new Lla(ToRadian(42.717620), ToRadian(-73.832875), 0));
      sim.EndTrackDefinition(out numberOfNodes);
      Console.WriteLine("==> Track created, number of nodes in Track = " + numberOfNodes);

      Console.WriteLine("==> Starting Simulation");
      sim.Start();

      Console.WriteLine("==> Wait until the automatic stop happens when vehicle reaches track destination");
      sim.WaitState("Ready");

      Console.WriteLine("==> Disconnect from Simulator");
      sim.Disconnect();
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Retrieve satellite power example
    // This example shows:
    // 1- How to get a list of all visible satellites
    // 2- How to retrieve their decomposed power
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void RunExampleGetPower(string host, string target_type, string x300_ip)
    {
      Console.WriteLine("=== Basic Example ===");

      Console.WriteLine("==> Connecting to the simulator");
      RemoteSimulator sim = new RemoteSimulator();
      sim.IsVerbose = false;
      sim.Connect(host);

      Console.WriteLine("==> Create New Configuration, discarding current simulator settings");
      sim.Call(new New(true));

      Console.WriteLine("==> Modulation Settings");
      string targetId = "MyTargetId";
      sim.Call(new SetModulationTarget(target_type, "", x300_ip, true, targetId));
      // Select signals to simulate
      sim.Call(new ChangeModulationTargetSignals(0, 12500000, 12500000, "UpperL", "L1CA", -1, false, targetId));

      Console.WriteLine("==> Arming the simulation");
      sim.Arm();

      GetVisibleSVResult visibles = (GetVisibleSVResult)sim.Call(new GetVisibleSV("GPS"));

      foreach (int svId in visibles.SvId)
      {
        GetPowerForSVResult power = (GetPowerForSVResult)sim.Call(new GetPowerForSV("GPS", svId));

        Console.WriteLine("SV ID {0} received power: {1} dBm", svId, power.Total);
      }

      Console.WriteLine("==> Stop simulation");
      sim.Stop();

      Console.WriteLine("==> Disconnect from Simulator");
      sim.Disconnect();
    }
  }
}

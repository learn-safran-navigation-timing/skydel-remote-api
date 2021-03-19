#include "remote_simulator.h"
#include "all_commands.h"

using namespace Sdx;
using namespace Sdx::Cmd;

int main()
{
  const char* X300IpAddress = "192.168.50.2";

  RemoteSimulator sim;

  sim.connect();

  SimulatorStateResultPtr stateResult;



  sim.call(New::create(true));


  {
    SetModulationTargetPtr setModulationTargetCmd = SetModulationTarget::create("X300", "", (const char*)X300IpAddress, true, "MyOutputId");

    sim.call(setModulationTargetCmd);
  }


  EnableMasterPpsPtr enableMasterPps = EnableMasterPps::create(true);

  sim.call(enableMasterPps);
  
  sim.call(ChangeModulationTargetSignals::create(0, 12500000, 12500000, "UpperL", "L1CA", -1, false, "MyOutputId"));



  sim.call(SetPowerGlobalOffset::create(0.0));



  sim.call(SetVehicleTrajectory::create("HIL"));



  sim.call(SetVehicleAntennaOffset::create(0.0, 0.0, 0.0, 0.0, 0.0, 3.14159));



  sim.call(SetGpsStartTime::create(DateTime(2018, 8, 13, 22, 0, 0)));



  sim.call(SetLeapSecond::create(17));



  stateResult = SimulatorStateResult::dynamicCast(sim.call(GetSimulatorState::create()));



  sim.call(EnableRF::create("GPS", 0, true));



  sim.call(EnableElevationMaskBelow::create(false));



  sim.call(EnableElevationMaskAbove::create(false));



  sim.call(EnableLogRaw::create(true));



  sim.call(EnableLogNmea::create(true));



  sim.call(ArmPPS::create());



  sim.call(WaitAndResetPPS::create());



  sim.call(StartPPS::create(2000));


}
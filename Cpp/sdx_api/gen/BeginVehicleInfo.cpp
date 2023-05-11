
#include "gen/BeginVehicleInfo.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of BeginVehicleInfo
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const BeginVehicleInfo::CmdName = "BeginVehicleInfo";
    const char* const BeginVehicleInfo::Documentation = "Begin receiving simulated vehicle informations. \nDuring simulation, you must call RemoteSimulator.lastVehicleInfo to get current simulation statistics or RemoteSimulator.nextVehicleInfo to get pending simulation statistics";

    REGISTER_COMMAND_FACTORY(BeginVehicleInfo);


    BeginVehicleInfo::BeginVehicleInfo()
      : CommandBase(CmdName)
    {

    }

    BeginVehicleInfoPtr BeginVehicleInfo::create()
    {
      return std::make_shared<BeginVehicleInfo>();
    }

    BeginVehicleInfoPtr BeginVehicleInfo::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<BeginVehicleInfo>(ptr);
    }

    bool BeginVehicleInfo::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string BeginVehicleInfo::documentation() const { return Documentation; }


    int BeginVehicleInfo::executePermission() const
    {
      return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }

  }
}

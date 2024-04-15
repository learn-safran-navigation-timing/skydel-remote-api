
#include "BeginVehicleInfo.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of BeginVehicleInfo
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const BeginVehicleInfo::CmdName = "BeginVehicleInfo";
    const char* const BeginVehicleInfo::Documentation = "Begin receiving simulated vehicle informations. \n"
      "During simulation, you must call RemoteSimulator.lastVehicleInfo to get current simulation statistics or RemoteSimulator.nextVehicleInfo to get pending simulation statistics";
    const char* const BeginVehicleInfo::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(BeginVehicleInfo);
    REGISTER_COMMAND_TO_FACTORY_IMPL(BeginVehicleInfo);


    BeginVehicleInfo::BeginVehicleInfo()
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& BeginVehicleInfo::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int BeginVehicleInfo::executePermission() const
    {
      return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }

  }
}

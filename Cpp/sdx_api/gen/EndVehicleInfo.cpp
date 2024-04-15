
#include "EndVehicleInfo.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of EndVehicleInfo
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const EndVehicleInfo::CmdName = "EndVehicleInfo";
    const char* const EndVehicleInfo::Documentation = "End receiving simulated vehicle informations.";
    const char* const EndVehicleInfo::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(EndVehicleInfo);
    REGISTER_COMMAND_TO_FACTORY_IMPL(EndVehicleInfo);


    EndVehicleInfo::EndVehicleInfo()
      : CommandBase(CmdName, TargetId)
    {

    }

    EndVehicleInfoPtr EndVehicleInfo::create()
    {
      return std::make_shared<EndVehicleInfo>();
    }

    EndVehicleInfoPtr EndVehicleInfo::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<EndVehicleInfo>(ptr);
    }

    bool EndVehicleInfo::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string EndVehicleInfo::documentation() const { return Documentation; }

    const std::vector<std::string>& EndVehicleInfo::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int EndVehicleInfo::executePermission() const
    {
      return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }

  }
}

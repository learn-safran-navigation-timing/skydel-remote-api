
#include "GetVehicleTrajectoryFix.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetVehicleTrajectoryFix
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetVehicleTrajectoryFix::CmdName = "GetVehicleTrajectoryFix";
    const char* const GetVehicleTrajectoryFix::Documentation = "Get vehicle static position and orientation";
    const char* const GetVehicleTrajectoryFix::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetVehicleTrajectoryFix);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetVehicleTrajectoryFix);


    GetVehicleTrajectoryFix::GetVehicleTrajectoryFix()
      : CommandBase(CmdName, TargetId)
    {

    }

    GetVehicleTrajectoryFixPtr GetVehicleTrajectoryFix::create()
    {
      return std::make_shared<GetVehicleTrajectoryFix>();
    }

    GetVehicleTrajectoryFixPtr GetVehicleTrajectoryFix::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetVehicleTrajectoryFix>(ptr);
    }

    bool GetVehicleTrajectoryFix::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetVehicleTrajectoryFix::documentation() const { return Documentation; }

    const std::vector<std::string>& GetVehicleTrajectoryFix::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetVehicleTrajectoryFix::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}

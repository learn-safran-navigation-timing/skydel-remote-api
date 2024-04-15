
#include "GetVehicleTrajectoryFixEcef.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetVehicleTrajectoryFixEcef
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetVehicleTrajectoryFixEcef::CmdName = "GetVehicleTrajectoryFixEcef";
    const char* const GetVehicleTrajectoryFixEcef::Documentation = "Get vehicle static position and orientation";
    const char* const GetVehicleTrajectoryFixEcef::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetVehicleTrajectoryFixEcef);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetVehicleTrajectoryFixEcef);


    GetVehicleTrajectoryFixEcef::GetVehicleTrajectoryFixEcef()
      : CommandBase(CmdName, TargetId)
    {

    }

    GetVehicleTrajectoryFixEcefPtr GetVehicleTrajectoryFixEcef::create()
    {
      return std::make_shared<GetVehicleTrajectoryFixEcef>();
    }

    GetVehicleTrajectoryFixEcefPtr GetVehicleTrajectoryFixEcef::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetVehicleTrajectoryFixEcef>(ptr);
    }

    bool GetVehicleTrajectoryFixEcef::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetVehicleTrajectoryFixEcef::documentation() const { return Documentation; }

    const std::vector<std::string>& GetVehicleTrajectoryFixEcef::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetVehicleTrajectoryFixEcef::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}

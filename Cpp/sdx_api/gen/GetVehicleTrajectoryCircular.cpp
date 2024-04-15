
#include "GetVehicleTrajectoryCircular.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetVehicleTrajectoryCircular
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetVehicleTrajectoryCircular::CmdName = "GetVehicleTrajectoryCircular";
    const char* const GetVehicleTrajectoryCircular::Documentation = "Get vehicle circular trajectory";
    const char* const GetVehicleTrajectoryCircular::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetVehicleTrajectoryCircular);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetVehicleTrajectoryCircular);


    GetVehicleTrajectoryCircular::GetVehicleTrajectoryCircular()
      : CommandBase(CmdName, TargetId)
    {

    }

    GetVehicleTrajectoryCircularPtr GetVehicleTrajectoryCircular::create()
    {
      return std::make_shared<GetVehicleTrajectoryCircular>();
    }

    GetVehicleTrajectoryCircularPtr GetVehicleTrajectoryCircular::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetVehicleTrajectoryCircular>(ptr);
    }

    bool GetVehicleTrajectoryCircular::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetVehicleTrajectoryCircular::documentation() const { return Documentation; }

    const std::vector<std::string>& GetVehicleTrajectoryCircular::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetVehicleTrajectoryCircular::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}

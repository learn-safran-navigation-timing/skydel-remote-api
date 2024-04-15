
#include "GetVehicleTrajectory.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetVehicleTrajectory
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetVehicleTrajectory::CmdName = "GetVehicleTrajectory";
    const char* const GetVehicleTrajectory::Documentation = "Get vehicle trajectory type";
    const char* const GetVehicleTrajectory::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetVehicleTrajectory);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetVehicleTrajectory);


    GetVehicleTrajectory::GetVehicleTrajectory()
      : CommandBase(CmdName, TargetId)
    {

    }

    GetVehicleTrajectoryPtr GetVehicleTrajectory::create()
    {
      return std::make_shared<GetVehicleTrajectory>();
    }

    GetVehicleTrajectoryPtr GetVehicleTrajectory::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetVehicleTrajectory>(ptr);
    }

    bool GetVehicleTrajectory::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetVehicleTrajectory::documentation() const { return Documentation; }

    const std::vector<std::string>& GetVehicleTrajectory::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetVehicleTrajectory::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }

  }
}

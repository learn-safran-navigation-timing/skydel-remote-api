
#include "gen/SetVehicleTrajectory.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetVehicleTrajectory
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetVehicleTrajectory::CmdName = "SetVehicleTrajectory";
    const char* const SetVehicleTrajectory::Documentation = "Set vehicle trajectory type";

    REGISTER_COMMAND_FACTORY(SetVehicleTrajectory);


    SetVehicleTrajectory::SetVehicleTrajectory()
      : CommandBase(CmdName)
    {}

    SetVehicleTrajectory::SetVehicleTrajectory(const std::string& type)
      : CommandBase(CmdName)
    {

      setType(type);
    }

    SetVehicleTrajectoryPtr SetVehicleTrajectory::create(const std::string& type)
    {
      return std::make_shared<SetVehicleTrajectory>(type);
    }

    SetVehicleTrajectoryPtr SetVehicleTrajectory::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetVehicleTrajectory>(ptr);
    }

    bool SetVehicleTrajectory::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Type"])
        ;

    }

    std::string SetVehicleTrajectory::documentation() const { return Documentation; }


    int SetVehicleTrajectory::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetVehicleTrajectory::type() const
    {
      return parse_json<std::string>::parse(m_values["Type"]);
    }

    void SetVehicleTrajectory::setType(const std::string& type)
    {
      m_values.AddMember("Type", parse_json<std::string>::format(type, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

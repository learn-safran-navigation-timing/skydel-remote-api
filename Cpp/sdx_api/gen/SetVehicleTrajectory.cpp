
#include "SetVehicleTrajectory.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetVehicleTrajectory
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetVehicleTrajectory::CmdName = "SetVehicleTrajectory";
    const char* const SetVehicleTrajectory::Documentation = "Set vehicle trajectory type\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ -----------------------------------------------------------------------\n"
      "Type string Trajectory type (\"Fix\", \"Circular\", \"HIL\", \"Track\", \"Route\" or \"Orbit\")";
    const char* const SetVehicleTrajectory::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetVehicleTrajectory);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetVehicleTrajectory);


    SetVehicleTrajectory::SetVehicleTrajectory()
      : CommandBase(CmdName, TargetId)
    {}

    SetVehicleTrajectory::SetVehicleTrajectory(const std::string& type)
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& SetVehicleTrajectory::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Type"}; 
      return names; 
    }


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

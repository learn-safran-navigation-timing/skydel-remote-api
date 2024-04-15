
#include "SetVehicleType.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetVehicleType
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetVehicleType::CmdName = "SetVehicleType";
    const char* const SetVehicleType::Documentation = "Set vehicle type for Route Trajectory\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ ----------------------------------------------------------\n"
      "Type string Vehicle type (\"Ground / Water\" or \"Airborne / Spaceborne\")";
    const char* const SetVehicleType::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetVehicleType);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetVehicleType);


    SetVehicleType::SetVehicleType()
      : CommandBase(CmdName, TargetId)
    {}

    SetVehicleType::SetVehicleType(const std::string& type)
      : CommandBase(CmdName, TargetId)
    {

      setType(type);
    }

    SetVehicleTypePtr SetVehicleType::create(const std::string& type)
    {
      return std::make_shared<SetVehicleType>(type);
    }

    SetVehicleTypePtr SetVehicleType::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetVehicleType>(ptr);
    }

    bool SetVehicleType::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Type"])
        ;

    }

    std::string SetVehicleType::documentation() const { return Documentation; }

    const std::vector<std::string>& SetVehicleType::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Type"}; 
      return names; 
    }


    int SetVehicleType::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetVehicleType::type() const
    {
      return parse_json<std::string>::parse(m_values["Type"]);
    }

    void SetVehicleType::setType(const std::string& type)
    {
      m_values.AddMember("Type", parse_json<std::string>::format(type, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

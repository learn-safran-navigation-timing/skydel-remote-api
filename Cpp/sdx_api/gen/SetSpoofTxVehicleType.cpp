
#include "SetSpoofTxVehicleType.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetSpoofTxVehicleType
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetSpoofTxVehicleType::CmdName = "SetSpoofTxVehicleType";
    const char* const SetSpoofTxVehicleType::Documentation = "Set spoofer transmitter vehicle type for Track Trajectory.\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ -----------------------------------------------------------\n"
      "Type string Vehicle type (\"Ground / Water\" or \"Airborne / Spaceborne\").\n"
      "Id   string Transmitter unique identifier.";
    const char* const SetSpoofTxVehicleType::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetSpoofTxVehicleType);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetSpoofTxVehicleType);


    SetSpoofTxVehicleType::SetSpoofTxVehicleType()
      : CommandBase(CmdName, TargetId)
    {}

    SetSpoofTxVehicleType::SetSpoofTxVehicleType(const std::string& type, const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setType(type);
      setId(id);
    }

    SetSpoofTxVehicleTypePtr SetSpoofTxVehicleType::create(const std::string& type, const std::string& id)
    {
      return std::make_shared<SetSpoofTxVehicleType>(type, id);
    }

    SetSpoofTxVehicleTypePtr SetSpoofTxVehicleType::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetSpoofTxVehicleType>(ptr);
    }

    bool SetSpoofTxVehicleType::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Type"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string SetSpoofTxVehicleType::documentation() const { return Documentation; }

    const std::vector<std::string>& SetSpoofTxVehicleType::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Type", "Id"}; 
      return names; 
    }


    int SetSpoofTxVehicleType::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetSpoofTxVehicleType::type() const
    {
      return parse_json<std::string>::parse(m_values["Type"]);
    }

    void SetSpoofTxVehicleType::setType(const std::string& type)
    {
      m_values.AddMember("Type", parse_json<std::string>::format(type, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetSpoofTxVehicleType::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void SetSpoofTxVehicleType::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

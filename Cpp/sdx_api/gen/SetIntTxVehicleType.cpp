
#include "SetIntTxVehicleType.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetIntTxVehicleType
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetIntTxVehicleType::CmdName = "SetIntTxVehicleType";
    const char* const SetIntTxVehicleType::Documentation = "Set interference vehicle type for Track Trajectory.\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ -----------------------------------------------------------\n"
      "Type string Vehicle type (\"Ground / Water\" or \"Airborne / Spaceborne\").\n"
      "Id   string Transmitter unique identifier.";
    const char* const SetIntTxVehicleType::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetIntTxVehicleType);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetIntTxVehicleType);


    SetIntTxVehicleType::SetIntTxVehicleType()
      : CommandBase(CmdName, TargetId)
    {}

    SetIntTxVehicleType::SetIntTxVehicleType(const std::string& type, const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setType(type);
      setId(id);
    }

    SetIntTxVehicleTypePtr SetIntTxVehicleType::create(const std::string& type, const std::string& id)
    {
      return std::make_shared<SetIntTxVehicleType>(type, id);
    }

    SetIntTxVehicleTypePtr SetIntTxVehicleType::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetIntTxVehicleType>(ptr);
    }

    bool SetIntTxVehicleType::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Type"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string SetIntTxVehicleType::documentation() const { return Documentation; }

    const std::vector<std::string>& SetIntTxVehicleType::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Type", "Id"}; 
      return names; 
    }


    int SetIntTxVehicleType::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetIntTxVehicleType::type() const
    {
      return parse_json<std::string>::parse(m_values["Type"]);
    }

    void SetIntTxVehicleType::setType(const std::string& type)
    {
      m_values.AddMember("Type", parse_json<std::string>::format(type, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetIntTxVehicleType::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void SetIntTxVehicleType::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

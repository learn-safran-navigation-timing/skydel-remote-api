
#include "gen/SetIntTxVehicleType.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetIntTxVehicleType
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetIntTxVehicleType::CmdName = "SetIntTxVehicleType";
    const char* const SetIntTxVehicleType::Documentation = "Set Set interference vehicle type for Track Trajectory";

    REGISTER_COMMAND_FACTORY(SetIntTxVehicleType);


    SetIntTxVehicleType::SetIntTxVehicleType()
      : CommandBase(CmdName)
    {}

    SetIntTxVehicleType::SetIntTxVehicleType(const std::string& type, const std::string& id)
      : CommandBase(CmdName)
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

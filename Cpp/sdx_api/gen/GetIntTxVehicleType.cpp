
#include "GetIntTxVehicleType.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIntTxVehicleType
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIntTxVehicleType::CmdName = "GetIntTxVehicleType";
    const char* const GetIntTxVehicleType::Documentation = "Get interference vehicle type for Track Trajectory.\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ ------------------------------\n"
      "Id   string Transmitter unique identifier.";
    const char* const GetIntTxVehicleType::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetIntTxVehicleType);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetIntTxVehicleType);


    GetIntTxVehicleType::GetIntTxVehicleType()
      : CommandBase(CmdName, TargetId)
    {}

    GetIntTxVehicleType::GetIntTxVehicleType(const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setId(id);
    }

    GetIntTxVehicleTypePtr GetIntTxVehicleType::create(const std::string& id)
    {
      return std::make_shared<GetIntTxVehicleType>(id);
    }

    GetIntTxVehicleTypePtr GetIntTxVehicleType::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetIntTxVehicleType>(ptr);
    }

    bool GetIntTxVehicleType::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetIntTxVehicleType::documentation() const { return Documentation; }

    const std::vector<std::string>& GetIntTxVehicleType::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Id"}; 
      return names; 
    }


    int GetIntTxVehicleType::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetIntTxVehicleType::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetIntTxVehicleType::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

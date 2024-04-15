
#include "GetSpoofTxVehicleType.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSpoofTxVehicleType
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSpoofTxVehicleType::CmdName = "GetSpoofTxVehicleType";
    const char* const GetSpoofTxVehicleType::Documentation = "Get spoofer transmitter vehicle type for Track Trajectory.\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ ------------------------------\n"
      "Id   string Transmitter unique identifier.";
    const char* const GetSpoofTxVehicleType::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetSpoofTxVehicleType);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetSpoofTxVehicleType);


    GetSpoofTxVehicleType::GetSpoofTxVehicleType()
      : CommandBase(CmdName, TargetId)
    {}

    GetSpoofTxVehicleType::GetSpoofTxVehicleType(const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setId(id);
    }

    GetSpoofTxVehicleTypePtr GetSpoofTxVehicleType::create(const std::string& id)
    {
      return std::make_shared<GetSpoofTxVehicleType>(id);
    }

    GetSpoofTxVehicleTypePtr GetSpoofTxVehicleType::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSpoofTxVehicleType>(ptr);
    }

    bool GetSpoofTxVehicleType::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetSpoofTxVehicleType::documentation() const { return Documentation; }

    const std::vector<std::string>& GetSpoofTxVehicleType::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Id"}; 
      return names; 
    }


    int GetSpoofTxVehicleType::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetSpoofTxVehicleType::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetSpoofTxVehicleType::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

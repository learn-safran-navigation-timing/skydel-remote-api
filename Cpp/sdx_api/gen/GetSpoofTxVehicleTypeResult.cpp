
#include "GetSpoofTxVehicleTypeResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSpoofTxVehicleTypeResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSpoofTxVehicleTypeResult::CmdName = "GetSpoofTxVehicleTypeResult";
    const char* const GetSpoofTxVehicleTypeResult::Documentation = "Result of GetSpoofTxVehicleType.\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ -----------------------------------------------------------\n"
      "Type string Vehicle type (\"Ground / Water\" or \"Airborne / Spaceborne\").\n"
      "Id   string Transmitter unique identifier.";
    const char* const GetSpoofTxVehicleTypeResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetSpoofTxVehicleTypeResult);


    GetSpoofTxVehicleTypeResult::GetSpoofTxVehicleTypeResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetSpoofTxVehicleTypeResult::GetSpoofTxVehicleTypeResult(const std::string& type, const std::string& id)
      : CommandResult(CmdName, TargetId)
    {

      setType(type);
      setId(id);
    }

    GetSpoofTxVehicleTypeResult::GetSpoofTxVehicleTypeResult(CommandBasePtr relatedCommand, const std::string& type, const std::string& id)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setType(type);
      setId(id);
    }


    GetSpoofTxVehicleTypeResultPtr GetSpoofTxVehicleTypeResult::create(const std::string& type, const std::string& id)
    {
      return std::make_shared<GetSpoofTxVehicleTypeResult>(type, id);
    }

    GetSpoofTxVehicleTypeResultPtr GetSpoofTxVehicleTypeResult::create(CommandBasePtr relatedCommand, const std::string& type, const std::string& id)
    {
      return std::make_shared<GetSpoofTxVehicleTypeResult>(relatedCommand, type, id);
    }

    GetSpoofTxVehicleTypeResultPtr GetSpoofTxVehicleTypeResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSpoofTxVehicleTypeResult>(ptr);
    }

    bool GetSpoofTxVehicleTypeResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Type"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetSpoofTxVehicleTypeResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetSpoofTxVehicleTypeResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Type", "Id"}; 
      return names; 
    }


    std::string GetSpoofTxVehicleTypeResult::type() const
    {
      return parse_json<std::string>::parse(m_values["Type"]);
    }

    void GetSpoofTxVehicleTypeResult::setType(const std::string& type)
    {
      m_values.AddMember("Type", parse_json<std::string>::format(type, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetSpoofTxVehicleTypeResult::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetSpoofTxVehicleTypeResult::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

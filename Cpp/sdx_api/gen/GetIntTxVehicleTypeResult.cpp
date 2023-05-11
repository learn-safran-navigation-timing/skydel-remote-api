
#include "gen/GetIntTxVehicleTypeResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIntTxVehicleTypeResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIntTxVehicleTypeResult::CmdName = "GetIntTxVehicleTypeResult";
    const char* const GetIntTxVehicleTypeResult::Documentation = "Result of GetIntTxVehicleType.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetIntTxVehicleTypeResult);


    GetIntTxVehicleTypeResult::GetIntTxVehicleTypeResult()
      : CommandResult(CmdName)
    {}

    GetIntTxVehicleTypeResult::GetIntTxVehicleTypeResult(const std::string& type, const std::string& id)
      : CommandResult(CmdName)
    {

      setType(type);
      setId(id);
    }

    GetIntTxVehicleTypeResult::GetIntTxVehicleTypeResult(CommandBasePtr relatedCommand, const std::string& type, const std::string& id)
      : CommandResult(CmdName, relatedCommand)
    {

      setType(type);
      setId(id);
    }


    GetIntTxVehicleTypeResultPtr GetIntTxVehicleTypeResult::create(const std::string& type, const std::string& id)
    {
      return std::make_shared<GetIntTxVehicleTypeResult>(type, id);
    }

    GetIntTxVehicleTypeResultPtr GetIntTxVehicleTypeResult::create(CommandBasePtr relatedCommand, const std::string& type, const std::string& id)
    {
      return std::make_shared<GetIntTxVehicleTypeResult>(relatedCommand, type, id);
    }

    GetIntTxVehicleTypeResultPtr GetIntTxVehicleTypeResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetIntTxVehicleTypeResult>(ptr);
    }

    bool GetIntTxVehicleTypeResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Type"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetIntTxVehicleTypeResult::documentation() const { return Documentation; }


    std::string GetIntTxVehicleTypeResult::type() const
    {
      return parse_json<std::string>::parse(m_values["Type"]);
    }

    void GetIntTxVehicleTypeResult::setType(const std::string& type)
    {
      m_values.AddMember("Type", parse_json<std::string>::format(type, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetIntTxVehicleTypeResult::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetIntTxVehicleTypeResult::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

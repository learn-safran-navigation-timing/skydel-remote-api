
#include "gen/GetVehicleTypeResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetVehicleTypeResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetVehicleTypeResult::CmdName = "GetVehicleTypeResult";
    const char* const GetVehicleTypeResult::Documentation = "Result of GetVehicleType.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetVehicleTypeResult);


    GetVehicleTypeResult::GetVehicleTypeResult()
      : CommandResult(CmdName)
    {}

    GetVehicleTypeResult::GetVehicleTypeResult(const std::string& type)
      : CommandResult(CmdName)
    {

      setType(type);
    }

    GetVehicleTypeResult::GetVehicleTypeResult(CommandBasePtr relatedCommand, const std::string& type)
      : CommandResult(CmdName, relatedCommand)
    {

      setType(type);
    }


    GetVehicleTypeResultPtr GetVehicleTypeResult::create(const std::string& type)
    {
      return std::make_shared<GetVehicleTypeResult>(type);
    }

    GetVehicleTypeResultPtr GetVehicleTypeResult::create(CommandBasePtr relatedCommand, const std::string& type)
    {
      return std::make_shared<GetVehicleTypeResult>(relatedCommand, type);
    }

    GetVehicleTypeResultPtr GetVehicleTypeResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetVehicleTypeResult>(ptr);
    }

    bool GetVehicleTypeResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Type"])
        ;

    }

    std::string GetVehicleTypeResult::documentation() const { return Documentation; }


    std::string GetVehicleTypeResult::type() const
    {
      return parse_json<std::string>::parse(m_values["Type"]);
    }

    void GetVehicleTypeResult::setType(const std::string& type)
    {
      m_values.AddMember("Type", parse_json<std::string>::format(type, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

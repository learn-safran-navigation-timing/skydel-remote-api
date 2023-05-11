
#include "gen/GetDefaultVehicleAntennaModelResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetDefaultVehicleAntennaModelResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetDefaultVehicleAntennaModelResult::CmdName = "GetDefaultVehicleAntennaModelResult";
    const char* const GetDefaultVehicleAntennaModelResult::Documentation = "Result of GetDefaultVehicleAntennaModel.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetDefaultVehicleAntennaModelResult);


    GetDefaultVehicleAntennaModelResult::GetDefaultVehicleAntennaModelResult()
      : CommandResult(CmdName)
    {}

    GetDefaultVehicleAntennaModelResult::GetDefaultVehicleAntennaModelResult(const std::string& name)
      : CommandResult(CmdName)
    {

      setName(name);
    }

    GetDefaultVehicleAntennaModelResult::GetDefaultVehicleAntennaModelResult(CommandBasePtr relatedCommand, const std::string& name)
      : CommandResult(CmdName, relatedCommand)
    {

      setName(name);
    }


    GetDefaultVehicleAntennaModelResultPtr GetDefaultVehicleAntennaModelResult::create(const std::string& name)
    {
      return std::make_shared<GetDefaultVehicleAntennaModelResult>(name);
    }

    GetDefaultVehicleAntennaModelResultPtr GetDefaultVehicleAntennaModelResult::create(CommandBasePtr relatedCommand, const std::string& name)
    {
      return std::make_shared<GetDefaultVehicleAntennaModelResult>(relatedCommand, name);
    }

    GetDefaultVehicleAntennaModelResultPtr GetDefaultVehicleAntennaModelResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetDefaultVehicleAntennaModelResult>(ptr);
    }

    bool GetDefaultVehicleAntennaModelResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Name"])
        ;

    }

    std::string GetDefaultVehicleAntennaModelResult::documentation() const { return Documentation; }


    std::string GetDefaultVehicleAntennaModelResult::name() const
    {
      return parse_json<std::string>::parse(m_values["Name"]);
    }

    void GetDefaultVehicleAntennaModelResult::setName(const std::string& name)
    {
      m_values.AddMember("Name", parse_json<std::string>::format(name, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}


#include "GetCurrentConfigPathResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetCurrentConfigPathResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetCurrentConfigPathResult::CmdName = "GetCurrentConfigPathResult";
    const char* const GetCurrentConfigPathResult::Documentation = "Result of GetCurrentConfigPath.\n"
      "\n"
      "Name       Type   Description\n"
      "---------- ------ ----------------------------------------------\n"
      "ConfigPath string The config file path currently used by Skydel.";
    const char* const GetCurrentConfigPathResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetCurrentConfigPathResult);


    GetCurrentConfigPathResult::GetCurrentConfigPathResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetCurrentConfigPathResult::GetCurrentConfigPathResult(const std::string& configPath)
      : CommandResult(CmdName, TargetId)
    {

      setConfigPath(configPath);
    }

    GetCurrentConfigPathResult::GetCurrentConfigPathResult(CommandBasePtr relatedCommand, const std::string& configPath)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setConfigPath(configPath);
    }


    GetCurrentConfigPathResultPtr GetCurrentConfigPathResult::create(const std::string& configPath)
    {
      return std::make_shared<GetCurrentConfigPathResult>(configPath);
    }

    GetCurrentConfigPathResultPtr GetCurrentConfigPathResult::create(CommandBasePtr relatedCommand, const std::string& configPath)
    {
      return std::make_shared<GetCurrentConfigPathResult>(relatedCommand, configPath);
    }

    GetCurrentConfigPathResultPtr GetCurrentConfigPathResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetCurrentConfigPathResult>(ptr);
    }

    bool GetCurrentConfigPathResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ConfigPath"])
        ;

    }

    std::string GetCurrentConfigPathResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetCurrentConfigPathResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"ConfigPath"}; 
      return names; 
    }


    std::string GetCurrentConfigPathResult::configPath() const
    {
      return parse_json<std::string>::parse(m_values["ConfigPath"]);
    }

    void GetCurrentConfigPathResult::setConfigPath(const std::string& configPath)
    {
      m_values.AddMember("ConfigPath", parse_json<std::string>::format(configPath, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

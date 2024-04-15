
#include "GetPluginsResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetPluginsResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetPluginsResult::CmdName = "GetPluginsResult";
    const char* const GetPluginsResult::Documentation = "Result of GetPlugins.\n"
      "\n"
      "Name    Type         Description\n"
      "------- ------------ ---------------------------------------------------------------------\n"
      "Plugins array string List of all Plug-ins present on the system (regardless of the state).";
    const char* const GetPluginsResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetPluginsResult);


    GetPluginsResult::GetPluginsResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetPluginsResult::GetPluginsResult(const std::vector<std::string>& plugins)
      : CommandResult(CmdName, TargetId)
    {

      setPlugins(plugins);
    }

    GetPluginsResult::GetPluginsResult(CommandBasePtr relatedCommand, const std::vector<std::string>& plugins)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setPlugins(plugins);
    }


    GetPluginsResultPtr GetPluginsResult::create(const std::vector<std::string>& plugins)
    {
      return std::make_shared<GetPluginsResult>(plugins);
    }

    GetPluginsResultPtr GetPluginsResult::create(CommandBasePtr relatedCommand, const std::vector<std::string>& plugins)
    {
      return std::make_shared<GetPluginsResult>(relatedCommand, plugins);
    }

    GetPluginsResultPtr GetPluginsResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetPluginsResult>(ptr);
    }

    bool GetPluginsResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<std::string>>::is_valid(m_values["Plugins"])
        ;

    }

    std::string GetPluginsResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetPluginsResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Plugins"}; 
      return names; 
    }


    std::vector<std::string> GetPluginsResult::plugins() const
    {
      return parse_json<std::vector<std::string>>::parse(m_values["Plugins"]);
    }

    void GetPluginsResult::setPlugins(const std::vector<std::string>& plugins)
    {
      m_values.AddMember("Plugins", parse_json<std::vector<std::string>>::format(plugins, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

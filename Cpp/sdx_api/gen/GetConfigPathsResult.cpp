
#include "GetConfigPathsResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetConfigPathsResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetConfigPathsResult::CmdName = "GetConfigPathsResult";
    const char* const GetConfigPathsResult::Documentation = "Result of GetConfigPaths.\n"
      "\n"
      "Name  Type         Description\n"
      "----- ------------ --------------------------------\n"
      "Paths array string Paths of the configuration files";
    const char* const GetConfigPathsResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetConfigPathsResult);


    GetConfigPathsResult::GetConfigPathsResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetConfigPathsResult::GetConfigPathsResult(const std::vector<std::string>& paths)
      : CommandResult(CmdName, TargetId)
    {

      setPaths(paths);
    }

    GetConfigPathsResult::GetConfigPathsResult(CommandBasePtr relatedCommand, const std::vector<std::string>& paths)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setPaths(paths);
    }


    GetConfigPathsResultPtr GetConfigPathsResult::create(const std::vector<std::string>& paths)
    {
      return std::make_shared<GetConfigPathsResult>(paths);
    }

    GetConfigPathsResultPtr GetConfigPathsResult::create(CommandBasePtr relatedCommand, const std::vector<std::string>& paths)
    {
      return std::make_shared<GetConfigPathsResult>(relatedCommand, paths);
    }

    GetConfigPathsResultPtr GetConfigPathsResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetConfigPathsResult>(ptr);
    }

    bool GetConfigPathsResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<std::string>>::is_valid(m_values["Paths"])
        ;

    }

    std::string GetConfigPathsResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetConfigPathsResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Paths"}; 
      return names; 
    }


    std::vector<std::string> GetConfigPathsResult::paths() const
    {
      return parse_json<std::vector<std::string>>::parse(m_values["Paths"]);
    }

    void GetConfigPathsResult::setPaths(const std::vector<std::string>& paths)
    {
      m_values.AddMember("Paths", parse_json<std::vector<std::string>>::format(paths, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

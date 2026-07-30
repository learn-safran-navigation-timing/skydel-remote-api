
#include "GetGeoidFilePathResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGeoidFilePathResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGeoidFilePathResult::CmdName = "GetGeoidFilePathResult";
    const char* const GetGeoidFilePathResult::Documentation = "Result of GetGeoidFilePath.\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ ------------------------------\n"
      "Path string Path to the Geoid file to use.";
    const char* const GetGeoidFilePathResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetGeoidFilePathResult);


    GetGeoidFilePathResult::GetGeoidFilePathResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetGeoidFilePathResult::GetGeoidFilePathResult(const std::string& path)
      : CommandResult(CmdName, TargetId)
    {

      setPath(path);
    }

    GetGeoidFilePathResult::GetGeoidFilePathResult(CommandBasePtr relatedCommand, const std::string& path)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setPath(path);
    }


    GetGeoidFilePathResultPtr GetGeoidFilePathResult::create(const std::string& path)
    {
      return std::make_shared<GetGeoidFilePathResult>(path);
    }

    GetGeoidFilePathResultPtr GetGeoidFilePathResult::create(CommandBasePtr relatedCommand, const std::string& path)
    {
      return std::make_shared<GetGeoidFilePathResult>(relatedCommand, path);
    }

    GetGeoidFilePathResultPtr GetGeoidFilePathResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGeoidFilePathResult>(ptr);
    }

    bool GetGeoidFilePathResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Path"])
        ;

    }

    std::string GetGeoidFilePathResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetGeoidFilePathResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Path"}; 
      return names; 
    }


    std::string GetGeoidFilePathResult::path() const
    {
      return parse_json<std::string>::parse(m_values["Path"]);
    }

    void GetGeoidFilePathResult::setPath(const std::string& path)
    {
      setValue("Path", parse_json<std::string>::format(path, m_values.GetAllocator()));
    }


  }
}

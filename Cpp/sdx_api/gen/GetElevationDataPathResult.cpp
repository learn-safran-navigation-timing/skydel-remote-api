
#include "GetElevationDataPathResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetElevationDataPathResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetElevationDataPathResult::CmdName = "GetElevationDataPathResult";
    const char* const GetElevationDataPathResult::Documentation = "Result of GetElevationDataPath.\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ ---------------------------\n"
      "Path string Path to the elevation data.";
    const char* const GetElevationDataPathResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetElevationDataPathResult);


    GetElevationDataPathResult::GetElevationDataPathResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetElevationDataPathResult::GetElevationDataPathResult(const std::string& path)
      : CommandResult(CmdName, TargetId)
    {

      setPath(path);
    }

    GetElevationDataPathResult::GetElevationDataPathResult(CommandBasePtr relatedCommand, const std::string& path)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setPath(path);
    }


    GetElevationDataPathResultPtr GetElevationDataPathResult::create(const std::string& path)
    {
      return std::make_shared<GetElevationDataPathResult>(path);
    }

    GetElevationDataPathResultPtr GetElevationDataPathResult::create(CommandBasePtr relatedCommand, const std::string& path)
    {
      return std::make_shared<GetElevationDataPathResult>(relatedCommand, path);
    }

    GetElevationDataPathResultPtr GetElevationDataPathResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetElevationDataPathResult>(ptr);
    }

    bool GetElevationDataPathResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Path"])
        ;

    }

    std::string GetElevationDataPathResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetElevationDataPathResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Path"}; 
      return names; 
    }


    std::string GetElevationDataPathResult::path() const
    {
      return parse_json<std::string>::parse(m_values["Path"]);
    }

    void GetElevationDataPathResult::setPath(const std::string& path)
    {
      setValue("Path", parse_json<std::string>::format(path, m_values.GetAllocator()));
    }


  }
}

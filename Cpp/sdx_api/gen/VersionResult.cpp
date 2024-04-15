
#include "VersionResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of VersionResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const VersionResult::CmdName = "VersionResult";
    const char* const VersionResult::Documentation = "Result of GetVersion.\n"
      "\n"
      "Name    Type   Description\n"
      "------- ------ --------------\n"
      "Version string Skydel version";
    const char* const VersionResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(VersionResult);


    VersionResult::VersionResult()
      : CommandResult(CmdName, TargetId)
    {}

    VersionResult::VersionResult(const std::string& version)
      : CommandResult(CmdName, TargetId)
    {

      setVersion(version);
    }

    VersionResult::VersionResult(CommandBasePtr relatedCommand, const std::string& version)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setVersion(version);
    }


    VersionResultPtr VersionResult::create(const std::string& version)
    {
      return std::make_shared<VersionResult>(version);
    }

    VersionResultPtr VersionResult::create(CommandBasePtr relatedCommand, const std::string& version)
    {
      return std::make_shared<VersionResult>(relatedCommand, version);
    }

    VersionResultPtr VersionResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<VersionResult>(ptr);
    }

    bool VersionResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Version"])
        ;

    }

    std::string VersionResult::documentation() const { return Documentation; }

    const std::vector<std::string>& VersionResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Version"}; 
      return names; 
    }


    std::string VersionResult::version() const
    {
      return parse_json<std::string>::parse(m_values["Version"]);
    }

    void VersionResult::setVersion(const std::string& version)
    {
      m_values.AddMember("Version", parse_json<std::string>::format(version, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

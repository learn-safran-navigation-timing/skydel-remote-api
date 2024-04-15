
#include "SetExternalChannelsPath.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetExternalChannelsPath
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetExternalChannelsPath::CmdName = "SetExternalChannelsPath";
    const char* const SetExternalChannelsPath::Documentation = "Set external channels path.\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ -----------------------------\n"
      "Path string Path to the sdxpand directory";
    const char* const SetExternalChannelsPath::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetExternalChannelsPath);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetExternalChannelsPath);


    SetExternalChannelsPath::SetExternalChannelsPath()
      : CommandBase(CmdName, TargetId)
    {}

    SetExternalChannelsPath::SetExternalChannelsPath(const std::string& path)
      : CommandBase(CmdName, TargetId)
    {

      setPath(path);
    }

    SetExternalChannelsPathPtr SetExternalChannelsPath::create(const std::string& path)
    {
      return std::make_shared<SetExternalChannelsPath>(path);
    }

    SetExternalChannelsPathPtr SetExternalChannelsPath::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetExternalChannelsPath>(ptr);
    }

    bool SetExternalChannelsPath::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Path"])
        ;

    }

    std::string SetExternalChannelsPath::documentation() const { return Documentation; }

    const std::vector<std::string>& SetExternalChannelsPath::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Path"}; 
      return names; 
    }


    int SetExternalChannelsPath::executePermission() const
    {
      return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE;
    }


    std::string SetExternalChannelsPath::path() const
    {
      return parse_json<std::string>::parse(m_values["Path"]);
    }

    void SetExternalChannelsPath::setPath(const std::string& path)
    {
      m_values.AddMember("Path", parse_json<std::string>::format(path, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

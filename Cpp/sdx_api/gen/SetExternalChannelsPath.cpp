
#include "gen/SetExternalChannelsPath.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetExternalChannelsPath
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetExternalChannelsPath::CmdName = "SetExternalChannelsPath";
    const char* const SetExternalChannelsPath::Documentation = "Set external channels path.";

    REGISTER_COMMAND_FACTORY(SetExternalChannelsPath);


    SetExternalChannelsPath::SetExternalChannelsPath()
      : CommandBase(CmdName)
    {}

    SetExternalChannelsPath::SetExternalChannelsPath(const std::string& path)
      : CommandBase(CmdName)
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

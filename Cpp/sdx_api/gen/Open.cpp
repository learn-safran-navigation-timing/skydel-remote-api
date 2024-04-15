
#include "Open.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of Open
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const Open::CmdName = "Open";
    const char* const Open::Documentation = "Open configuration.\n"
      "\n"
      "Name                 Type   Description\n"
      "-------------------- ------ ----------------------------------------------------------------------------------------------------\n"
      "Path                 string Filename path, Automatically add file suffix if missing. If folder not defined, user default folder.\n"
      "DiscardCurrentConfig bool   Discard current config even if it is not saved";
    const char* const Open::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(Open);
    REGISTER_COMMAND_TO_FACTORY_IMPL(Open);


    Open::Open()
      : CommandBase(CmdName, TargetId)
    {}

    Open::Open(const std::string& path, bool discardCurrentConfig)
      : CommandBase(CmdName, TargetId)
    {

      setPath(path);
      setDiscardCurrentConfig(discardCurrentConfig);
    }

    OpenPtr Open::create(const std::string& path, bool discardCurrentConfig)
    {
      return std::make_shared<Open>(path, discardCurrentConfig);
    }

    OpenPtr Open::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<Open>(ptr);
    }

    bool Open::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Path"])
          && parse_json<bool>::is_valid(m_values["DiscardCurrentConfig"])
        ;

    }

    std::string Open::documentation() const { return Documentation; }

    const std::vector<std::string>& Open::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Path", "DiscardCurrentConfig"}; 
      return names; 
    }


    int Open::executePermission() const
    {
      return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE;
    }


    std::string Open::path() const
    {
      return parse_json<std::string>::parse(m_values["Path"]);
    }

    void Open::setPath(const std::string& path)
    {
      m_values.AddMember("Path", parse_json<std::string>::format(path, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool Open::discardCurrentConfig() const
    {
      return parse_json<bool>::parse(m_values["DiscardCurrentConfig"]);
    }

    void Open::setDiscardCurrentConfig(bool discardCurrentConfig)
    {
      m_values.AddMember("DiscardCurrentConfig", parse_json<bool>::format(discardCurrentConfig, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

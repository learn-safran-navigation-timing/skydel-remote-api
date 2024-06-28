
#include "New.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of New
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const New::CmdName = "New";
    const char* const New::Documentation = "Create a new configuration.\n"
      "\n"
      "Name                 Type          Description\n"
      "-------------------- ------------- ----------------------------------------------\n"
      "DiscardCurrentConfig bool          Discard current config even if it is not saved\n"
      "LoadDefaultConfig    optional bool Apply the default configuration";
    const char* const New::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(New);
    REGISTER_COMMAND_TO_FACTORY_IMPL(New);


    New::New()
      : CommandBase(CmdName, TargetId)
    {}

    New::New(bool discardCurrentConfig, const std::optional<bool>& loadDefaultConfig)
      : CommandBase(CmdName, TargetId)
    {

      setDiscardCurrentConfig(discardCurrentConfig);
      setLoadDefaultConfig(loadDefaultConfig);
    }

    NewPtr New::create(bool discardCurrentConfig, const std::optional<bool>& loadDefaultConfig)
    {
      return std::make_shared<New>(discardCurrentConfig, loadDefaultConfig);
    }

    NewPtr New::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<New>(ptr);
    }

    bool New::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["DiscardCurrentConfig"])
          && parse_json<std::optional<bool>>::is_valid(m_values["LoadDefaultConfig"])
        ;

    }

    std::string New::documentation() const { return Documentation; }

    const std::vector<std::string>& New::fieldNames() const 
    { 
      static const std::vector<std::string> names {"DiscardCurrentConfig", "LoadDefaultConfig"}; 
      return names; 
    }


    int New::executePermission() const
    {
      return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE;
    }


    bool New::discardCurrentConfig() const
    {
      return parse_json<bool>::parse(m_values["DiscardCurrentConfig"]);
    }

    void New::setDiscardCurrentConfig(bool discardCurrentConfig)
    {
      m_values.AddMember("DiscardCurrentConfig", parse_json<bool>::format(discardCurrentConfig, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<bool> New::loadDefaultConfig() const
    {
      return parse_json<std::optional<bool>>::parse(m_values["LoadDefaultConfig"]);
    }

    void New::setLoadDefaultConfig(const std::optional<bool>& loadDefaultConfig)
    {
      m_values.AddMember("LoadDefaultConfig", parse_json<std::optional<bool>>::format(loadDefaultConfig, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

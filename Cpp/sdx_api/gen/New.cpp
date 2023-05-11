
#include "gen/New.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of New
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const New::CmdName = "New";
    const char* const New::Documentation = "Create a new configuration.";

    REGISTER_COMMAND_FACTORY(New);


    New::New()
      : CommandBase(CmdName)
    {}

    New::New(bool discardCurrentConfig, const Sdx::optional<bool>& loadDefaultConfig)
      : CommandBase(CmdName)
    {

      setDiscardCurrentConfig(discardCurrentConfig);
      setLoadDefaultConfig(loadDefaultConfig);
    }

    NewPtr New::create(bool discardCurrentConfig, const Sdx::optional<bool>& loadDefaultConfig)
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
          && parse_json<Sdx::optional<bool>>::is_valid(m_values["LoadDefaultConfig"])
        ;

    }

    std::string New::documentation() const { return Documentation; }


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



    Sdx::optional<bool> New::loadDefaultConfig() const
    {
      return parse_json<Sdx::optional<bool>>::parse(m_values["LoadDefaultConfig"]);
    }

    void New::setLoadDefaultConfig(const Sdx::optional<bool>& loadDefaultConfig)
    {
      m_values.AddMember("LoadDefaultConfig", parse_json<Sdx::optional<bool>>::format(loadDefaultConfig, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}


#include "EnableIonoOffset.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of EnableIonoOffset
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const EnableIonoOffset::CmdName = "EnableIonoOffset";
    const char* const EnableIonoOffset::Documentation = "Set whether the ionospheric offsets grid should be applied to the ionosphere\n"
      "\n"
      "Name      Type Description\n"
      "--------- ---- ---------------------------------------------\n"
      "IsEnabled bool True if offsets are applied on the ionosphere";
    const char* const EnableIonoOffset::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(EnableIonoOffset);
    REGISTER_COMMAND_TO_FACTORY_IMPL(EnableIonoOffset);


    EnableIonoOffset::EnableIonoOffset()
      : CommandBase(CmdName, TargetId)
    {}

    EnableIonoOffset::EnableIonoOffset(bool isEnabled)
      : CommandBase(CmdName, TargetId)
    {

      setIsEnabled(isEnabled);
    }

    EnableIonoOffsetPtr EnableIonoOffset::create(bool isEnabled)
    {
      return std::make_shared<EnableIonoOffset>(isEnabled);
    }

    EnableIonoOffsetPtr EnableIonoOffset::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<EnableIonoOffset>(ptr);
    }

    bool EnableIonoOffset::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["IsEnabled"])
        ;

    }

    std::string EnableIonoOffset::documentation() const { return Documentation; }

    const std::vector<std::string>& EnableIonoOffset::fieldNames() const 
    { 
      static const std::vector<std::string> names {"IsEnabled"}; 
      return names; 
    }


    int EnableIonoOffset::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    bool EnableIonoOffset::isEnabled() const
    {
      return parse_json<bool>::parse(m_values["IsEnabled"]);
    }

    void EnableIonoOffset::setIsEnabled(bool isEnabled)
    {
      m_values.AddMember("IsEnabled", parse_json<bool>::format(isEnabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

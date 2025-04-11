
#include "EnableEarthMask.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of EnableEarthMask
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const EnableEarthMask::CmdName = "EnableEarthMask";
    const char* const EnableEarthMask::Documentation = "Enable (or disable) the Earth mask.\n"
      "\n"
      "Name    Type Description\n"
      "------- ---- ----------------------------------------------------------------------------------------------\n"
      "Enabled bool If disabled, all satellites will be visible, thereby eliminating the Earth's occlusion effect.";
    const char* const EnableEarthMask::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(EnableEarthMask);
    REGISTER_COMMAND_TO_FACTORY_IMPL(EnableEarthMask);


    EnableEarthMask::EnableEarthMask()
      : CommandBase(CmdName, TargetId)
    {}

    EnableEarthMask::EnableEarthMask(bool enabled)
      : CommandBase(CmdName, TargetId)
    {

      setEnabled(enabled);
    }

    EnableEarthMaskPtr EnableEarthMask::create(bool enabled)
    {
      return std::make_shared<EnableEarthMask>(enabled);
    }

    EnableEarthMaskPtr EnableEarthMask::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<EnableEarthMask>(ptr);
    }

    bool EnableEarthMask::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string EnableEarthMask::documentation() const { return Documentation; }

    const std::vector<std::string>& EnableEarthMask::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Enabled"}; 
      return names; 
    }


    int EnableEarthMask::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    bool EnableEarthMask::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void EnableEarthMask::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

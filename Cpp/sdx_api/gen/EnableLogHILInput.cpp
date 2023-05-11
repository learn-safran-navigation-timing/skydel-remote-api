
#include "gen/EnableLogHILInput.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of EnableLogHILInput
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const EnableLogHILInput::CmdName = "EnableLogHILInput";
    const char* const EnableLogHILInput::Documentation = "Enable (or disable) log of all the data received on the HIL API in a CSV format";

    REGISTER_COMMAND_FACTORY(EnableLogHILInput);


    EnableLogHILInput::EnableLogHILInput()
      : CommandBase(CmdName)
    {}

    EnableLogHILInput::EnableLogHILInput(bool enabled)
      : CommandBase(CmdName)
    {

      setEnabled(enabled);
    }

    EnableLogHILInputPtr EnableLogHILInput::create(bool enabled)
    {
      return std::make_shared<EnableLogHILInput>(enabled);
    }

    EnableLogHILInputPtr EnableLogHILInput::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<EnableLogHILInput>(ptr);
    }

    bool EnableLogHILInput::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string EnableLogHILInput::documentation() const { return Documentation; }


    int EnableLogHILInput::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    bool EnableLogHILInput::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void EnableLogHILInput::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}


#include "StopWhenCommandFail.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of StopWhenCommandFail
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const StopWhenCommandFail::CmdName = "StopWhenCommandFail";
    const char* const StopWhenCommandFail::Documentation = "If enabled, simulation stops when a command result fail.\n"
      "\n"
      "Name    Type Description\n"
      "------- ---- ----------------------------------\n"
      "Enabled bool Enable stop when command fail flag";
    const char* const StopWhenCommandFail::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(StopWhenCommandFail);
    REGISTER_COMMAND_TO_FACTORY_IMPL(StopWhenCommandFail);


    StopWhenCommandFail::StopWhenCommandFail()
      : CommandBase(CmdName, TargetId)
    {}

    StopWhenCommandFail::StopWhenCommandFail(bool enabled)
      : CommandBase(CmdName, TargetId)
    {

      setEnabled(enabled);
    }

    StopWhenCommandFailPtr StopWhenCommandFail::create(bool enabled)
    {
      return std::make_shared<StopWhenCommandFail>(enabled);
    }

    StopWhenCommandFailPtr StopWhenCommandFail::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<StopWhenCommandFail>(ptr);
    }

    bool StopWhenCommandFail::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string StopWhenCommandFail::documentation() const { return Documentation; }

    const std::vector<std::string>& StopWhenCommandFail::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Enabled"}; 
      return names; 
    }


    int StopWhenCommandFail::executePermission() const
    {
      return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }


    bool StopWhenCommandFail::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void StopWhenCommandFail::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

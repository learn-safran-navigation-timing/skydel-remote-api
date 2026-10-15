
#include "IsAuthenticationNavMessageSkipped.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsAuthenticationNavMessageSkipped
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsAuthenticationNavMessageSkipped::CmdName = "IsAuthenticationNavMessageSkipped";
    const char* const IsAuthenticationNavMessageSkipped::Documentation = "Get Skips all authentication messages in the message sequence of the given signal.\n"
      "\n"
      "Name   Type   Description\n"
      "------ ------ --------------------------------------------------------\n"
      "Signal string Signal key, accepted values : \"PULSARX1\" and \"PULSARX5\".";
    const char* const IsAuthenticationNavMessageSkipped::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(IsAuthenticationNavMessageSkipped);
    REGISTER_COMMAND_TO_FACTORY_IMPL(IsAuthenticationNavMessageSkipped);


    IsAuthenticationNavMessageSkipped::IsAuthenticationNavMessageSkipped()
      : CommandBase(CmdName, TargetId)
    {}

    IsAuthenticationNavMessageSkipped::IsAuthenticationNavMessageSkipped(const std::string& signal)
      : CommandBase(CmdName, TargetId)
    {

      setSignal(signal);
    }

    IsAuthenticationNavMessageSkippedPtr IsAuthenticationNavMessageSkipped::create(const std::string& signal)
    {
      return std::make_shared<IsAuthenticationNavMessageSkipped>(signal);
    }

    IsAuthenticationNavMessageSkippedPtr IsAuthenticationNavMessageSkipped::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsAuthenticationNavMessageSkipped>(ptr);
    }

    bool IsAuthenticationNavMessageSkipped::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Signal"])
        ;

    }

    std::string IsAuthenticationNavMessageSkipped::documentation() const { return Documentation; }

    const std::vector<std::string>& IsAuthenticationNavMessageSkipped::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Signal"}; 
      return names; 
    }


    int IsAuthenticationNavMessageSkipped::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string IsAuthenticationNavMessageSkipped::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void IsAuthenticationNavMessageSkipped::setSignal(const std::string& signal)
    {
      setValue("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()));
    }


  }
}

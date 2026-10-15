
#include "IsEncryptionNavMessageSkipped.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsEncryptionNavMessageSkipped
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsEncryptionNavMessageSkipped::CmdName = "IsEncryptionNavMessageSkipped";
    const char* const IsEncryptionNavMessageSkipped::Documentation = "Get Skips all encryption messages in the message sequence of the given signal.\n"
      "\n"
      "Name   Type   Description\n"
      "------ ------ --------------------------------------------------------\n"
      "Signal string Signal key, accepted values : \"PULSARX1\" and \"PULSARX5\".";
    const char* const IsEncryptionNavMessageSkipped::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(IsEncryptionNavMessageSkipped);
    REGISTER_COMMAND_TO_FACTORY_IMPL(IsEncryptionNavMessageSkipped);


    IsEncryptionNavMessageSkipped::IsEncryptionNavMessageSkipped()
      : CommandBase(CmdName, TargetId)
    {}

    IsEncryptionNavMessageSkipped::IsEncryptionNavMessageSkipped(const std::string& signal)
      : CommandBase(CmdName, TargetId)
    {

      setSignal(signal);
    }

    IsEncryptionNavMessageSkippedPtr IsEncryptionNavMessageSkipped::create(const std::string& signal)
    {
      return std::make_shared<IsEncryptionNavMessageSkipped>(signal);
    }

    IsEncryptionNavMessageSkippedPtr IsEncryptionNavMessageSkipped::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsEncryptionNavMessageSkipped>(ptr);
    }

    bool IsEncryptionNavMessageSkipped::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Signal"])
        ;

    }

    std::string IsEncryptionNavMessageSkipped::documentation() const { return Documentation; }

    const std::vector<std::string>& IsEncryptionNavMessageSkipped::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Signal"}; 
      return names; 
    }


    int IsEncryptionNavMessageSkipped::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string IsEncryptionNavMessageSkipped::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void IsEncryptionNavMessageSkipped::setSignal(const std::string& signal)
    {
      setValue("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()));
    }


  }
}

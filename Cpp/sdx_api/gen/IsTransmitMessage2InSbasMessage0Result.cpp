
#include "gen/IsTransmitMessage2InSbasMessage0Result.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsTransmitMessage2InSbasMessage0Result
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsTransmitMessage2InSbasMessage0Result::CmdName = "IsTransmitMessage2InSbasMessage0Result";
    const char* const IsTransmitMessage2InSbasMessage0Result::Documentation = "Result of IsTransmitMessage2InSbasMessage0.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(IsTransmitMessage2InSbasMessage0Result);


    IsTransmitMessage2InSbasMessage0Result::IsTransmitMessage2InSbasMessage0Result()
      : CommandResult(CmdName)
    {}

    IsTransmitMessage2InSbasMessage0Result::IsTransmitMessage2InSbasMessage0Result(bool transmitMessage2)
      : CommandResult(CmdName)
    {

      setTransmitMessage2(transmitMessage2);
    }

    IsTransmitMessage2InSbasMessage0Result::IsTransmitMessage2InSbasMessage0Result(CommandBasePtr relatedCommand, bool transmitMessage2)
      : CommandResult(CmdName, relatedCommand)
    {

      setTransmitMessage2(transmitMessage2);
    }


    IsTransmitMessage2InSbasMessage0ResultPtr IsTransmitMessage2InSbasMessage0Result::create(bool transmitMessage2)
    {
      return std::make_shared<IsTransmitMessage2InSbasMessage0Result>(transmitMessage2);
    }

    IsTransmitMessage2InSbasMessage0ResultPtr IsTransmitMessage2InSbasMessage0Result::create(CommandBasePtr relatedCommand, bool transmitMessage2)
    {
      return std::make_shared<IsTransmitMessage2InSbasMessage0Result>(relatedCommand, transmitMessage2);
    }

    IsTransmitMessage2InSbasMessage0ResultPtr IsTransmitMessage2InSbasMessage0Result::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsTransmitMessage2InSbasMessage0Result>(ptr);
    }

    bool IsTransmitMessage2InSbasMessage0Result::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["TransmitMessage2"])
        ;

    }

    std::string IsTransmitMessage2InSbasMessage0Result::documentation() const { return Documentation; }


    bool IsTransmitMessage2InSbasMessage0Result::transmitMessage2() const
    {
      return parse_json<bool>::parse(m_values["TransmitMessage2"]);
    }

    void IsTransmitMessage2InSbasMessage0Result::setTransmitMessage2(bool transmitMessage2)
    {
      m_values.AddMember("TransmitMessage2", parse_json<bool>::format(transmitMessage2, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

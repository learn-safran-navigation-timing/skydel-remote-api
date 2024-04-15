
#include "GetComputerSystemTimeSinceEpochAtPps0Result.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetComputerSystemTimeSinceEpochAtPps0Result
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetComputerSystemTimeSinceEpochAtPps0Result::CmdName = "GetComputerSystemTimeSinceEpochAtPps0Result";
    const char* const GetComputerSystemTimeSinceEpochAtPps0Result::Documentation = "Result of GetComputerSystemTimeSinceEpochAtPps0.\n"
      "\n"
      "Name         Type   Description\n"
      "------------ ------ ---------------------------------------------------------\n"
      "Milliseconds double Computer system time since epoch at PPS0 in milliseconds.";
    const char* const GetComputerSystemTimeSinceEpochAtPps0Result::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetComputerSystemTimeSinceEpochAtPps0Result);


    GetComputerSystemTimeSinceEpochAtPps0Result::GetComputerSystemTimeSinceEpochAtPps0Result()
      : CommandResult(CmdName, TargetId)
    {}

    GetComputerSystemTimeSinceEpochAtPps0Result::GetComputerSystemTimeSinceEpochAtPps0Result(double milliseconds)
      : CommandResult(CmdName, TargetId)
    {

      setMilliseconds(milliseconds);
    }

    GetComputerSystemTimeSinceEpochAtPps0Result::GetComputerSystemTimeSinceEpochAtPps0Result(CommandBasePtr relatedCommand, double milliseconds)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setMilliseconds(milliseconds);
    }


    GetComputerSystemTimeSinceEpochAtPps0ResultPtr GetComputerSystemTimeSinceEpochAtPps0Result::create(double milliseconds)
    {
      return std::make_shared<GetComputerSystemTimeSinceEpochAtPps0Result>(milliseconds);
    }

    GetComputerSystemTimeSinceEpochAtPps0ResultPtr GetComputerSystemTimeSinceEpochAtPps0Result::create(CommandBasePtr relatedCommand, double milliseconds)
    {
      return std::make_shared<GetComputerSystemTimeSinceEpochAtPps0Result>(relatedCommand, milliseconds);
    }

    GetComputerSystemTimeSinceEpochAtPps0ResultPtr GetComputerSystemTimeSinceEpochAtPps0Result::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetComputerSystemTimeSinceEpochAtPps0Result>(ptr);
    }

    bool GetComputerSystemTimeSinceEpochAtPps0Result::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<double>::is_valid(m_values["Milliseconds"])
        ;

    }

    std::string GetComputerSystemTimeSinceEpochAtPps0Result::documentation() const { return Documentation; }

    const std::vector<std::string>& GetComputerSystemTimeSinceEpochAtPps0Result::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Milliseconds"}; 
      return names; 
    }


    double GetComputerSystemTimeSinceEpochAtPps0Result::milliseconds() const
    {
      return parse_json<double>::parse(m_values["Milliseconds"]);
    }

    void GetComputerSystemTimeSinceEpochAtPps0Result::setMilliseconds(double milliseconds)
    {
      m_values.AddMember("Milliseconds", parse_json<double>::format(milliseconds, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

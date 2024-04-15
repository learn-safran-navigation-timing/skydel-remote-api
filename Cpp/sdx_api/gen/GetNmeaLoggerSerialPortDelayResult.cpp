
#include "GetNmeaLoggerSerialPortDelayResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetNmeaLoggerSerialPortDelayResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetNmeaLoggerSerialPortDelayResult::CmdName = "GetNmeaLoggerSerialPortDelayResult";
    const char* const GetNmeaLoggerSerialPortDelayResult::Documentation = "Result of GetNmeaLoggerSerialPortDelay.\n"
      "\n"
      "Name  Type Description\n"
      "----- ---- ---------------------------------\n"
      "Delay int  Delay from 0 to 100 milliseconds.";
    const char* const GetNmeaLoggerSerialPortDelayResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetNmeaLoggerSerialPortDelayResult);


    GetNmeaLoggerSerialPortDelayResult::GetNmeaLoggerSerialPortDelayResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetNmeaLoggerSerialPortDelayResult::GetNmeaLoggerSerialPortDelayResult(int delay)
      : CommandResult(CmdName, TargetId)
    {

      setDelay(delay);
    }

    GetNmeaLoggerSerialPortDelayResult::GetNmeaLoggerSerialPortDelayResult(CommandBasePtr relatedCommand, int delay)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setDelay(delay);
    }


    GetNmeaLoggerSerialPortDelayResultPtr GetNmeaLoggerSerialPortDelayResult::create(int delay)
    {
      return std::make_shared<GetNmeaLoggerSerialPortDelayResult>(delay);
    }

    GetNmeaLoggerSerialPortDelayResultPtr GetNmeaLoggerSerialPortDelayResult::create(CommandBasePtr relatedCommand, int delay)
    {
      return std::make_shared<GetNmeaLoggerSerialPortDelayResult>(relatedCommand, delay);
    }

    GetNmeaLoggerSerialPortDelayResultPtr GetNmeaLoggerSerialPortDelayResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetNmeaLoggerSerialPortDelayResult>(ptr);
    }

    bool GetNmeaLoggerSerialPortDelayResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Delay"])
        ;

    }

    std::string GetNmeaLoggerSerialPortDelayResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetNmeaLoggerSerialPortDelayResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Delay"}; 
      return names; 
    }


    int GetNmeaLoggerSerialPortDelayResult::delay() const
    {
      return parse_json<int>::parse(m_values["Delay"]);
    }

    void GetNmeaLoggerSerialPortDelayResult::setDelay(int delay)
    {
      m_values.AddMember("Delay", parse_json<int>::format(delay, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

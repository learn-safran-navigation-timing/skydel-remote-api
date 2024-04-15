
#include "LogNmeaRateResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of LogNmeaRateResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const LogNmeaRateResult::CmdName = "LogNmeaRateResult";
    const char* const LogNmeaRateResult::Documentation = "Result of GetLogNmeaRate.\n"
      "\n"
      "Name Type Description\n"
      "---- ---- ------------------------------\n"
      "Rate int  Accepted rates are 1 and 10 Hz";
    const char* const LogNmeaRateResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(LogNmeaRateResult);


    LogNmeaRateResult::LogNmeaRateResult()
      : CommandResult(CmdName, TargetId)
    {}

    LogNmeaRateResult::LogNmeaRateResult(int rate)
      : CommandResult(CmdName, TargetId)
    {

      setRate(rate);
    }

    LogNmeaRateResult::LogNmeaRateResult(CommandBasePtr relatedCommand, int rate)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setRate(rate);
    }


    LogNmeaRateResultPtr LogNmeaRateResult::create(int rate)
    {
      return std::make_shared<LogNmeaRateResult>(rate);
    }

    LogNmeaRateResultPtr LogNmeaRateResult::create(CommandBasePtr relatedCommand, int rate)
    {
      return std::make_shared<LogNmeaRateResult>(relatedCommand, rate);
    }

    LogNmeaRateResultPtr LogNmeaRateResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<LogNmeaRateResult>(ptr);
    }

    bool LogNmeaRateResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Rate"])
        ;

    }

    std::string LogNmeaRateResult::documentation() const { return Documentation; }

    const std::vector<std::string>& LogNmeaRateResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Rate"}; 
      return names; 
    }


    int LogNmeaRateResult::rate() const
    {
      return parse_json<int>::parse(m_values["Rate"]);
    }

    void LogNmeaRateResult::setRate(int rate)
    {
      m_values.AddMember("Rate", parse_json<int>::format(rate, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

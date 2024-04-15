
#include "LogRawRateResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of LogRawRateResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const LogRawRateResult::CmdName = "LogRawRateResult";
    const char* const LogRawRateResult::Documentation = "Result of GetLogRawRate.\n"
      "\n"
      "Name Type Description\n"
      "---- ---- --------------------------------------\n"
      "Rate int  Accepted rates are 10, 100 and 1000 Hz";
    const char* const LogRawRateResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(LogRawRateResult);


    LogRawRateResult::LogRawRateResult()
      : CommandResult(CmdName, TargetId)
    {}

    LogRawRateResult::LogRawRateResult(int rate)
      : CommandResult(CmdName, TargetId)
    {

      setRate(rate);
    }

    LogRawRateResult::LogRawRateResult(CommandBasePtr relatedCommand, int rate)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setRate(rate);
    }


    LogRawRateResultPtr LogRawRateResult::create(int rate)
    {
      return std::make_shared<LogRawRateResult>(rate);
    }

    LogRawRateResultPtr LogRawRateResult::create(CommandBasePtr relatedCommand, int rate)
    {
      return std::make_shared<LogRawRateResult>(relatedCommand, rate);
    }

    LogRawRateResultPtr LogRawRateResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<LogRawRateResult>(ptr);
    }

    bool LogRawRateResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Rate"])
        ;

    }

    std::string LogRawRateResult::documentation() const { return Documentation; }

    const std::vector<std::string>& LogRawRateResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Rate"}; 
      return names; 
    }


    int LogRawRateResult::rate() const
    {
      return parse_json<int>::parse(m_values["Rate"]);
    }

    void LogRawRateResult::setRate(int rate)
    {
      m_values.AddMember("Rate", parse_json<int>::format(rate, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

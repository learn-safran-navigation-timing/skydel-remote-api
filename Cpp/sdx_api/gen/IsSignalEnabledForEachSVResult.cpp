
#include "gen/IsSignalEnabledForEachSVResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsSignalEnabledForEachSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsSignalEnabledForEachSVResult::CmdName = "IsSignalEnabledForEachSVResult";
    const char* const IsSignalEnabledForEachSVResult::Documentation = "Result of IsSignalEnabledForEachSV.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(IsSignalEnabledForEachSVResult);


    IsSignalEnabledForEachSVResult::IsSignalEnabledForEachSVResult()
      : CommandResult(CmdName)
    {}

    IsSignalEnabledForEachSVResult::IsSignalEnabledForEachSVResult(const std::string& signal, const std::vector<bool>& enabled)
      : CommandResult(CmdName)
    {

      setSignal(signal);
      setEnabled(enabled);
    }

    IsSignalEnabledForEachSVResult::IsSignalEnabledForEachSVResult(CommandBasePtr relatedCommand, const std::string& signal, const std::vector<bool>& enabled)
      : CommandResult(CmdName, relatedCommand)
    {

      setSignal(signal);
      setEnabled(enabled);
    }


    IsSignalEnabledForEachSVResultPtr IsSignalEnabledForEachSVResult::create(const std::string& signal, const std::vector<bool>& enabled)
    {
      return std::make_shared<IsSignalEnabledForEachSVResult>(signal, enabled);
    }

    IsSignalEnabledForEachSVResultPtr IsSignalEnabledForEachSVResult::create(CommandBasePtr relatedCommand, const std::string& signal, const std::vector<bool>& enabled)
    {
      return std::make_shared<IsSignalEnabledForEachSVResult>(relatedCommand, signal, enabled);
    }

    IsSignalEnabledForEachSVResultPtr IsSignalEnabledForEachSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsSignalEnabledForEachSVResult>(ptr);
    }

    bool IsSignalEnabledForEachSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Signal"])
          && parse_json<std::vector<bool>>::is_valid(m_values["Enabled"])
        ;

    }

    std::string IsSignalEnabledForEachSVResult::documentation() const { return Documentation; }


    std::string IsSignalEnabledForEachSVResult::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void IsSignalEnabledForEachSVResult::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<bool> IsSignalEnabledForEachSVResult::enabled() const
    {
      return parse_json<std::vector<bool>>::parse(m_values["Enabled"]);
    }

    void IsSignalEnabledForEachSVResult::setEnabled(const std::vector<bool>& enabled)
    {
      m_values.AddMember("Enabled", parse_json<std::vector<bool>>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

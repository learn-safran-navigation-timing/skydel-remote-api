
#include "gen/IsSignalEnabledForSVResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsSignalEnabledForSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsSignalEnabledForSVResult::CmdName = "IsSignalEnabledForSVResult";
    const char* const IsSignalEnabledForSVResult::Documentation = "Result of IsSignalEnabledForSV.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(IsSignalEnabledForSVResult);


    IsSignalEnabledForSVResult::IsSignalEnabledForSVResult()
      : CommandResult(CmdName)
    {}

    IsSignalEnabledForSVResult::IsSignalEnabledForSVResult(const std::string& signal, int svId, bool enabled)
      : CommandResult(CmdName)
    {

      setSignal(signal);
      setSvId(svId);
      setEnabled(enabled);
    }

    IsSignalEnabledForSVResult::IsSignalEnabledForSVResult(CommandBasePtr relatedCommand, const std::string& signal, int svId, bool enabled)
      : CommandResult(CmdName, relatedCommand)
    {

      setSignal(signal);
      setSvId(svId);
      setEnabled(enabled);
    }


    IsSignalEnabledForSVResultPtr IsSignalEnabledForSVResult::create(const std::string& signal, int svId, bool enabled)
    {
      return std::make_shared<IsSignalEnabledForSVResult>(signal, svId, enabled);
    }

    IsSignalEnabledForSVResultPtr IsSignalEnabledForSVResult::create(CommandBasePtr relatedCommand, const std::string& signal, int svId, bool enabled)
    {
      return std::make_shared<IsSignalEnabledForSVResult>(relatedCommand, signal, svId, enabled);
    }

    IsSignalEnabledForSVResultPtr IsSignalEnabledForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsSignalEnabledForSVResult>(ptr);
    }

    bool IsSignalEnabledForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Signal"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string IsSignalEnabledForSVResult::documentation() const { return Documentation; }


    std::string IsSignalEnabledForSVResult::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void IsSignalEnabledForSVResult::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int IsSignalEnabledForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void IsSignalEnabledForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool IsSignalEnabledForSVResult::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void IsSignalEnabledForSVResult::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

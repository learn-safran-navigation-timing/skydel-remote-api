
#include "IsSignalEnabledForEachSVResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsSignalEnabledForEachSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsSignalEnabledForEachSVResult::CmdName = "IsSignalEnabledForEachSVResult";
    const char* const IsSignalEnabledForEachSVResult::Documentation = "Result of IsSignalEnabledForEachSV.\n"
      "\n"
      "Name    Type       Description\n"
      "------- ---------- ----------------------------------------------------------------------------------------------------------------------\n"
      "Signal  string     Accepted signal keys: \"L1CA\", \"L1C\", \"L1P\", \"L1ME\", \"L1MR\", \"L2C\", \"L2P\", \"L2ME\", \"L2MR\", \"L5\",\n"
      "                                         \"G1\", \"G2\", \"E1\", \"E1PRS\", \"E5a\", \"E5b\", \"E6BC\", \"E6PRS\",\n"
      "                                         \"B1\", \"B2\", \"B1C\", \"B2a\", \"B3I\", \"SBASL1\", \"SBASL5\", \"QZSSL1CA\", \"QZSSL1CB\", \"QZSSL1C\",\n"
      "                                          \"QZSSL2C\", \"QZSSL5\", \"QZSSL1S\", \"QZSSL5S\", \"QZSSL6\", \"NAVICL1\", \"NAVICL5\", \"NAVICS\", \"PULSARXL\"\n"
      "Enabled array bool Signal is enabled when value is True. Zero based index (index 0 => first SV ID, index 1 => second SV ID, etc).";
    const char* const IsSignalEnabledForEachSVResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(IsSignalEnabledForEachSVResult);


    IsSignalEnabledForEachSVResult::IsSignalEnabledForEachSVResult()
      : CommandResult(CmdName, TargetId)
    {}

    IsSignalEnabledForEachSVResult::IsSignalEnabledForEachSVResult(const std::string& signal, const std::vector<bool>& enabled)
      : CommandResult(CmdName, TargetId)
    {

      setSignal(signal);
      setEnabled(enabled);
    }

    IsSignalEnabledForEachSVResult::IsSignalEnabledForEachSVResult(CommandBasePtr relatedCommand, const std::string& signal, const std::vector<bool>& enabled)
      : CommandResult(CmdName, TargetId, relatedCommand)
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

    const std::vector<std::string>& IsSignalEnabledForEachSVResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Signal", "Enabled"}; 
      return names; 
    }


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


#include "IsSignalEnabledForSVResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsSignalEnabledForSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsSignalEnabledForSVResult::CmdName = "IsSignalEnabledForSVResult";
    const char* const IsSignalEnabledForSVResult::Documentation = "Result of IsSignalEnabledForSV.\n"
      "\n"
      "Name    Type   Description\n"
      "------- ------ -------------------------------------------------------------------------------------------------------------\n"
      "Signal  string Accepted signal keys: \"L1CA\", \"L1C\", \"L1P\", \"L1ME\", \"L1MR\", \"L2C\", \"L2P\", \"L2ME\", \"L2MR\", \"L5\",\n"
      "                                     \"G1\", \"G2\", \"E1\", \"E1PRS\", \"E5a\", \"E5b\", \"E6BC\", \"E6PRS\",\n"
      "                                     \"B1\", \"B2\", \"B1C\", \"B2a\", \"B3I\", \"SBASL1\", \"SBASL5\", \"QZSSL1CA\"\n"
      "                                     \"QZSSL1CB\", \"QZSSL1C\", \"QZSSL2C\", \"QZSSL5\", \"QZSSL1S\", \"QZSSL5S\", \"NAVICL5\", \"PULSARXL\"\n"
      "SvId    int    The satellite's SV ID (use 0 for all constellation's satellites)\n"
      "Enabled bool   Signal is enabled when value is True";
    const char* const IsSignalEnabledForSVResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(IsSignalEnabledForSVResult);


    IsSignalEnabledForSVResult::IsSignalEnabledForSVResult()
      : CommandResult(CmdName, TargetId)
    {}

    IsSignalEnabledForSVResult::IsSignalEnabledForSVResult(const std::string& signal, int svId, bool enabled)
      : CommandResult(CmdName, TargetId)
    {

      setSignal(signal);
      setSvId(svId);
      setEnabled(enabled);
    }

    IsSignalEnabledForSVResult::IsSignalEnabledForSVResult(CommandBasePtr relatedCommand, const std::string& signal, int svId, bool enabled)
      : CommandResult(CmdName, TargetId, relatedCommand)
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

    const std::vector<std::string>& IsSignalEnabledForSVResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Signal", "SvId", "Enabled"}; 
      return names; 
    }


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


#include "IsPYCodeEnabledForSVResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsPYCodeEnabledForSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsPYCodeEnabledForSVResult::CmdName = "IsPYCodeEnabledForSVResult";
    const char* const IsPYCodeEnabledForSVResult::Documentation = "Result of IsPYCodeEnabledForSV.\n"
      "\n"
      "Name    Type   Description\n"
      "------- ------ -----------------------------------------------\n"
      "Signal  string Accepted signal keys: \"L1P\", \"L2P\"\n"
      "SvId    int    The satellite's SV ID 1..32 (use 0 for all SVs)\n"
      "Enabled bool   Enable P(Y)-Code if True";
    const char* const IsPYCodeEnabledForSVResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(IsPYCodeEnabledForSVResult);


    IsPYCodeEnabledForSVResult::IsPYCodeEnabledForSVResult()
      : CommandResult(CmdName, TargetId)
    {}

    IsPYCodeEnabledForSVResult::IsPYCodeEnabledForSVResult(const std::string& signal, int svId, bool enabled)
      : CommandResult(CmdName, TargetId)
    {

      setSignal(signal);
      setSvId(svId);
      setEnabled(enabled);
    }

    IsPYCodeEnabledForSVResult::IsPYCodeEnabledForSVResult(CommandBasePtr relatedCommand, const std::string& signal, int svId, bool enabled)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setSignal(signal);
      setSvId(svId);
      setEnabled(enabled);
    }


    IsPYCodeEnabledForSVResultPtr IsPYCodeEnabledForSVResult::create(const std::string& signal, int svId, bool enabled)
    {
      return std::make_shared<IsPYCodeEnabledForSVResult>(signal, svId, enabled);
    }

    IsPYCodeEnabledForSVResultPtr IsPYCodeEnabledForSVResult::create(CommandBasePtr relatedCommand, const std::string& signal, int svId, bool enabled)
    {
      return std::make_shared<IsPYCodeEnabledForSVResult>(relatedCommand, signal, svId, enabled);
    }

    IsPYCodeEnabledForSVResultPtr IsPYCodeEnabledForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsPYCodeEnabledForSVResult>(ptr);
    }

    bool IsPYCodeEnabledForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Signal"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string IsPYCodeEnabledForSVResult::documentation() const { return Documentation; }

    const std::vector<std::string>& IsPYCodeEnabledForSVResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Signal", "SvId", "Enabled"}; 
      return names; 
    }


    std::string IsPYCodeEnabledForSVResult::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void IsPYCodeEnabledForSVResult::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int IsPYCodeEnabledForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void IsPYCodeEnabledForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool IsPYCodeEnabledForSVResult::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void IsPYCodeEnabledForSVResult::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

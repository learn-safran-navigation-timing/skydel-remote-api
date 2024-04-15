
#include "IsSVEnabledResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsSVEnabledResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsSVEnabledResult::CmdName = "IsSVEnabledResult";
    const char* const IsSVEnabledResult::Documentation = "Result of IsSVEnabled.\n"
      "\n"
      "Name    Type   Description\n"
      "------- ------ ----------------------------------------------------------------------------------------------------------------\n"
      "System  string The satellite's constellation. Can be \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
      "SvId    int    The satellite's SV ID (use 0 for all SVs).\n"
      "Enabled bool   The satellite will be present/absent from the constellation";
    const char* const IsSVEnabledResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(IsSVEnabledResult);


    IsSVEnabledResult::IsSVEnabledResult()
      : CommandResult(CmdName, TargetId)
    {}

    IsSVEnabledResult::IsSVEnabledResult(const std::string& system, int svId, bool enabled)
      : CommandResult(CmdName, TargetId)
    {

      setSystem(system);
      setSvId(svId);
      setEnabled(enabled);
    }

    IsSVEnabledResult::IsSVEnabledResult(CommandBasePtr relatedCommand, const std::string& system, int svId, bool enabled)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setSystem(system);
      setSvId(svId);
      setEnabled(enabled);
    }


    IsSVEnabledResultPtr IsSVEnabledResult::create(const std::string& system, int svId, bool enabled)
    {
      return std::make_shared<IsSVEnabledResult>(system, svId, enabled);
    }

    IsSVEnabledResultPtr IsSVEnabledResult::create(CommandBasePtr relatedCommand, const std::string& system, int svId, bool enabled)
    {
      return std::make_shared<IsSVEnabledResult>(relatedCommand, system, svId, enabled);
    }

    IsSVEnabledResultPtr IsSVEnabledResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsSVEnabledResult>(ptr);
    }

    bool IsSVEnabledResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string IsSVEnabledResult::documentation() const { return Documentation; }

    const std::vector<std::string>& IsSVEnabledResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "SvId", "Enabled"}; 
      return names; 
    }


    std::string IsSVEnabledResult::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void IsSVEnabledResult::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int IsSVEnabledResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void IsSVEnabledResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool IsSVEnabledResult::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void IsSVEnabledResult::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

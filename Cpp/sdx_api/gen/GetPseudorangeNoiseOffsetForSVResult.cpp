
#include "GetPseudorangeNoiseOffsetForSVResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetPseudorangeNoiseOffsetForSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetPseudorangeNoiseOffsetForSVResult::CmdName = "GetPseudorangeNoiseOffsetForSVResult";
    const char* const GetPseudorangeNoiseOffsetForSVResult::Documentation = "Result of GetPseudorangeNoiseOffsetForSV.\n"
      "\n"
      "Name    Type   Description\n"
      "------- ------ --------------------------------------------------------------------------\n"
      "System  string \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
      "SvId    int    Satellite SV ID.\n"
      "Enabled bool   If true, the offset is enabled (applied)\n"
      "Offset  double The constant offset in metters";
    const char* const GetPseudorangeNoiseOffsetForSVResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetPseudorangeNoiseOffsetForSVResult);


    GetPseudorangeNoiseOffsetForSVResult::GetPseudorangeNoiseOffsetForSVResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetPseudorangeNoiseOffsetForSVResult::GetPseudorangeNoiseOffsetForSVResult(const std::string& system, int svId, bool enabled, double offset)
      : CommandResult(CmdName, TargetId)
    {

      setSystem(system);
      setSvId(svId);
      setEnabled(enabled);
      setOffset(offset);
    }

    GetPseudorangeNoiseOffsetForSVResult::GetPseudorangeNoiseOffsetForSVResult(CommandBasePtr relatedCommand, const std::string& system, int svId, bool enabled, double offset)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setSystem(system);
      setSvId(svId);
      setEnabled(enabled);
      setOffset(offset);
    }


    GetPseudorangeNoiseOffsetForSVResultPtr GetPseudorangeNoiseOffsetForSVResult::create(const std::string& system, int svId, bool enabled, double offset)
    {
      return std::make_shared<GetPseudorangeNoiseOffsetForSVResult>(system, svId, enabled, offset);
    }

    GetPseudorangeNoiseOffsetForSVResultPtr GetPseudorangeNoiseOffsetForSVResult::create(CommandBasePtr relatedCommand, const std::string& system, int svId, bool enabled, double offset)
    {
      return std::make_shared<GetPseudorangeNoiseOffsetForSVResult>(relatedCommand, system, svId, enabled, offset);
    }

    GetPseudorangeNoiseOffsetForSVResultPtr GetPseudorangeNoiseOffsetForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetPseudorangeNoiseOffsetForSVResult>(ptr);
    }

    bool GetPseudorangeNoiseOffsetForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Enabled"])
          && parse_json<double>::is_valid(m_values["Offset"])
        ;

    }

    std::string GetPseudorangeNoiseOffsetForSVResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetPseudorangeNoiseOffsetForSVResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "SvId", "Enabled", "Offset"}; 
      return names; 
    }


    std::string GetPseudorangeNoiseOffsetForSVResult::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetPseudorangeNoiseOffsetForSVResult::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetPseudorangeNoiseOffsetForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetPseudorangeNoiseOffsetForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetPseudorangeNoiseOffsetForSVResult::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void GetPseudorangeNoiseOffsetForSVResult::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetPseudorangeNoiseOffsetForSVResult::offset() const
    {
      return parse_json<double>::parse(m_values["Offset"]);
    }

    void GetPseudorangeNoiseOffsetForSVResult::setOffset(double offset)
    {
      m_values.AddMember("Offset", parse_json<double>::format(offset, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}


#include "GetManualPowerOffsetForSVResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetManualPowerOffsetForSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetManualPowerOffsetForSVResult::CmdName = "GetManualPowerOffsetForSVResult";
    const char* const GetManualPowerOffsetForSVResult::Documentation = "Result of GetManualPowerOffsetForSV.\n"
      "\n"
      "Name                  Type               Description\n"
      "--------------------- ------------------ -----------------------------------------------------------------------------\n"
      "System                string             \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\".\n"
      "SvId                  int                The satellite's SV ID.\n"
      "SignalPowerOffsetDict dict string:double A dictionary of signal poweroffset pairs.\n"
      "                                         Accepted keys are: \"All\", \"L1CA\", \"L1C\", \"L1P\", \"L1ME\", \"L1MR\", \"L2C\", \"L2P\",\n"
      "                                                            \"L2ME\", \"L2MR\", \"L5\", \"G1\", \"G2\", \"E1\", \"E1PRS\", \"E5a\",\n"
      "                                                            \"E5b\", \"E6BC\", \"E6PRS\", \"B1\", \"B2\", \"B1C\", \"B2a\", \"B3I\",\n"
      "                                                            \"SBASL1\", \"SBASL5\", \"QZSSL1CA\", \"QZSSL1CB\", \"QZSSL1C\",\n"
      "                                                            \"QZSSL2C\", \"QZSSL5\", \"QZSSL1S\", \"QZSSL5S\", \"QZSSL6\",\n"
      "                                                            \"NAVICL1\", \"NAVICL5\", \"NAVICS\", \"PULSARXL\", \"PULSARX1\" and\n"
      "                                                            \"PULSARX5\"";
    const char* const GetManualPowerOffsetForSVResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetManualPowerOffsetForSVResult);


    GetManualPowerOffsetForSVResult::GetManualPowerOffsetForSVResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetManualPowerOffsetForSVResult::GetManualPowerOffsetForSVResult(const std::string& system, int svId, const std::map<std::string, double>& signalPowerOffsetDict)
      : CommandResult(CmdName, TargetId)
    {

      setSystem(system);
      setSvId(svId);
      setSignalPowerOffsetDict(signalPowerOffsetDict);
    }

    GetManualPowerOffsetForSVResult::GetManualPowerOffsetForSVResult(CommandBasePtr relatedCommand, const std::string& system, int svId, const std::map<std::string, double>& signalPowerOffsetDict)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setSystem(system);
      setSvId(svId);
      setSignalPowerOffsetDict(signalPowerOffsetDict);
    }


    GetManualPowerOffsetForSVResultPtr GetManualPowerOffsetForSVResult::create(const std::string& system, int svId, const std::map<std::string, double>& signalPowerOffsetDict)
    {
      return std::make_shared<GetManualPowerOffsetForSVResult>(system, svId, signalPowerOffsetDict);
    }

    GetManualPowerOffsetForSVResultPtr GetManualPowerOffsetForSVResult::create(CommandBasePtr relatedCommand, const std::string& system, int svId, const std::map<std::string, double>& signalPowerOffsetDict)
    {
      return std::make_shared<GetManualPowerOffsetForSVResult>(relatedCommand, system, svId, signalPowerOffsetDict);
    }

    GetManualPowerOffsetForSVResultPtr GetManualPowerOffsetForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetManualPowerOffsetForSVResult>(ptr);
    }

    bool GetManualPowerOffsetForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::map<std::string, double>>::is_valid(m_values["SignalPowerOffsetDict"])
        ;

    }

    std::string GetManualPowerOffsetForSVResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetManualPowerOffsetForSVResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "SvId", "SignalPowerOffsetDict"}; 
      return names; 
    }


    std::string GetManualPowerOffsetForSVResult::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetManualPowerOffsetForSVResult::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetManualPowerOffsetForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetManualPowerOffsetForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::map<std::string, double> GetManualPowerOffsetForSVResult::signalPowerOffsetDict() const
    {
      return parse_json<std::map<std::string, double>>::parse(m_values["SignalPowerOffsetDict"]);
    }

    void GetManualPowerOffsetForSVResult::setSignalPowerOffsetDict(const std::map<std::string, double>& signalPowerOffsetDict)
    {
      m_values.AddMember("SignalPowerOffsetDict", parse_json<std::map<std::string, double>>::format(signalPowerOffsetDict, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

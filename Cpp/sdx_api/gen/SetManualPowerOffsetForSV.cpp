
#include "SetManualPowerOffsetForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetManualPowerOffsetForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetManualPowerOffsetForSV::CmdName = "SetManualPowerOffsetForSV";
    const char* const SetManualPowerOffsetForSV::Documentation = "Set the power offsets applied to the signals of a satellite. Use SV ID 0 to set the power offset of all the satellites. Use key \"All\" to set the power offset to all signals.\n"
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
      "                                                            \"QZSSL2C\", \"QZSSL5\", \"QZSSL1S\", \"QZSSL5S\", \"NAVICL5\" and\n"
      "                                                            \"PULSARXL\"\n"
      "IsRelativePowerOffset bool               If true, the power offset(s) are added to the current value(s).";
    const char* const SetManualPowerOffsetForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetManualPowerOffsetForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetManualPowerOffsetForSV);


    SetManualPowerOffsetForSV::SetManualPowerOffsetForSV()
      : CommandBase(CmdName, TargetId)
    {}

    SetManualPowerOffsetForSV::SetManualPowerOffsetForSV(const std::string& system, int svId, const std::map<std::string, double>& signalPowerOffsetDict, bool isRelativePowerOffset)
      : CommandBase(CmdName, TargetId)
    {

      setSystem(system);
      setSvId(svId);
      setSignalPowerOffsetDict(signalPowerOffsetDict);
      setIsRelativePowerOffset(isRelativePowerOffset);
    }

    SetManualPowerOffsetForSVPtr SetManualPowerOffsetForSV::create(const std::string& system, int svId, const std::map<std::string, double>& signalPowerOffsetDict, bool isRelativePowerOffset)
    {
      return std::make_shared<SetManualPowerOffsetForSV>(system, svId, signalPowerOffsetDict, isRelativePowerOffset);
    }

    SetManualPowerOffsetForSVPtr SetManualPowerOffsetForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetManualPowerOffsetForSV>(ptr);
    }

    bool SetManualPowerOffsetForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::map<std::string, double>>::is_valid(m_values["SignalPowerOffsetDict"])
          && parse_json<bool>::is_valid(m_values["IsRelativePowerOffset"])
        ;

    }

    std::string SetManualPowerOffsetForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& SetManualPowerOffsetForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "SvId", "SignalPowerOffsetDict", "IsRelativePowerOffset"}; 
      return names; 
    }


    int SetManualPowerOffsetForSV::executePermission() const
    {
      return EXECUTE_IF_SIMULATING;
    }


    std::string SetManualPowerOffsetForSV::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void SetManualPowerOffsetForSV::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetManualPowerOffsetForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetManualPowerOffsetForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::map<std::string, double> SetManualPowerOffsetForSV::signalPowerOffsetDict() const
    {
      return parse_json<std::map<std::string, double>>::parse(m_values["SignalPowerOffsetDict"]);
    }

    void SetManualPowerOffsetForSV::setSignalPowerOffsetDict(const std::map<std::string, double>& signalPowerOffsetDict)
    {
      m_values.AddMember("SignalPowerOffsetDict", parse_json<std::map<std::string, double>>::format(signalPowerOffsetDict, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetManualPowerOffsetForSV::isRelativePowerOffset() const
    {
      return parse_json<bool>::parse(m_values["IsRelativePowerOffset"]);
    }

    void SetManualPowerOffsetForSV::setIsRelativePowerOffset(bool isRelativePowerOffset)
    {
      m_values.AddMember("IsRelativePowerOffset", parse_json<bool>::format(isRelativePowerOffset, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

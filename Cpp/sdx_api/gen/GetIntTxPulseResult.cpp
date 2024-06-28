
#include "GetIntTxPulseResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIntTxPulseResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIntTxPulseResult::CmdName = "GetIntTxPulseResult";
    const char* const GetIntTxPulseResult::Documentation = "Result of GetIntTxPulse.\n"
      "\n"
      "Name          Type         Description\n"
      "------------- ------------ --------------------------------------------------------------\n"
      "Enabled       bool         Enable (true) or disable (false) the signal\n"
      "CentralFreq   double       Central frequency (Hz)\n"
      "Power         double       Power (dB), relative to transmitter reference power\n"
      "DutyCycle     double       Duty Cycle between 0.01 and 100, as a percentage of Pulse Rate\n"
      "PulseRate     int          Pulse rate (Hz), between 1 and 100000\n"
      "TransmitterId string       Transmitter unique identifier.\n"
      "SignalId      string       Pulse unique identifier.\n"
      "Group         optional int Group, if not using default group.";
    const char* const GetIntTxPulseResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetIntTxPulseResult);


    GetIntTxPulseResult::GetIntTxPulseResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetIntTxPulseResult::GetIntTxPulseResult(bool enabled, double centralFreq, double power, double dutyCycle, int pulseRate, const std::string& transmitterId, const std::string& signalId, const std::optional<int>& group)
      : CommandResult(CmdName, TargetId)
    {

      setEnabled(enabled);
      setCentralFreq(centralFreq);
      setPower(power);
      setDutyCycle(dutyCycle);
      setPulseRate(pulseRate);
      setTransmitterId(transmitterId);
      setSignalId(signalId);
      setGroup(group);
    }

    GetIntTxPulseResult::GetIntTxPulseResult(CommandBasePtr relatedCommand, bool enabled, double centralFreq, double power, double dutyCycle, int pulseRate, const std::string& transmitterId, const std::string& signalId, const std::optional<int>& group)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setEnabled(enabled);
      setCentralFreq(centralFreq);
      setPower(power);
      setDutyCycle(dutyCycle);
      setPulseRate(pulseRate);
      setTransmitterId(transmitterId);
      setSignalId(signalId);
      setGroup(group);
    }


    GetIntTxPulseResultPtr GetIntTxPulseResult::create(bool enabled, double centralFreq, double power, double dutyCycle, int pulseRate, const std::string& transmitterId, const std::string& signalId, const std::optional<int>& group)
    {
      return std::make_shared<GetIntTxPulseResult>(enabled, centralFreq, power, dutyCycle, pulseRate, transmitterId, signalId, group);
    }

    GetIntTxPulseResultPtr GetIntTxPulseResult::create(CommandBasePtr relatedCommand, bool enabled, double centralFreq, double power, double dutyCycle, int pulseRate, const std::string& transmitterId, const std::string& signalId, const std::optional<int>& group)
    {
      return std::make_shared<GetIntTxPulseResult>(relatedCommand, enabled, centralFreq, power, dutyCycle, pulseRate, transmitterId, signalId, group);
    }

    GetIntTxPulseResultPtr GetIntTxPulseResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetIntTxPulseResult>(ptr);
    }

    bool GetIntTxPulseResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enabled"])
          && parse_json<double>::is_valid(m_values["CentralFreq"])
          && parse_json<double>::is_valid(m_values["Power"])
          && parse_json<double>::is_valid(m_values["DutyCycle"])
          && parse_json<int>::is_valid(m_values["PulseRate"])
          && parse_json<std::string>::is_valid(m_values["TransmitterId"])
          && parse_json<std::string>::is_valid(m_values["SignalId"])
          && parse_json<std::optional<int>>::is_valid(m_values["Group"])
        ;

    }

    std::string GetIntTxPulseResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetIntTxPulseResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Enabled", "CentralFreq", "Power", "DutyCycle", "PulseRate", "TransmitterId", "SignalId", "Group"}; 
      return names; 
    }


    bool GetIntTxPulseResult::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void GetIntTxPulseResult::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetIntTxPulseResult::centralFreq() const
    {
      return parse_json<double>::parse(m_values["CentralFreq"]);
    }

    void GetIntTxPulseResult::setCentralFreq(double centralFreq)
    {
      m_values.AddMember("CentralFreq", parse_json<double>::format(centralFreq, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetIntTxPulseResult::power() const
    {
      return parse_json<double>::parse(m_values["Power"]);
    }

    void GetIntTxPulseResult::setPower(double power)
    {
      m_values.AddMember("Power", parse_json<double>::format(power, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetIntTxPulseResult::dutyCycle() const
    {
      return parse_json<double>::parse(m_values["DutyCycle"]);
    }

    void GetIntTxPulseResult::setDutyCycle(double dutyCycle)
    {
      m_values.AddMember("DutyCycle", parse_json<double>::format(dutyCycle, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetIntTxPulseResult::pulseRate() const
    {
      return parse_json<int>::parse(m_values["PulseRate"]);
    }

    void GetIntTxPulseResult::setPulseRate(int pulseRate)
    {
      m_values.AddMember("PulseRate", parse_json<int>::format(pulseRate, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetIntTxPulseResult::transmitterId() const
    {
      return parse_json<std::string>::parse(m_values["TransmitterId"]);
    }

    void GetIntTxPulseResult::setTransmitterId(const std::string& transmitterId)
    {
      m_values.AddMember("TransmitterId", parse_json<std::string>::format(transmitterId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetIntTxPulseResult::signalId() const
    {
      return parse_json<std::string>::parse(m_values["SignalId"]);
    }

    void GetIntTxPulseResult::setSignalId(const std::string& signalId)
    {
      m_values.AddMember("SignalId", parse_json<std::string>::format(signalId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<int> GetIntTxPulseResult::group() const
    {
      return parse_json<std::optional<int>>::parse(m_values["Group"]);
    }

    void GetIntTxPulseResult::setGroup(const std::optional<int>& group)
    {
      m_values.AddMember("Group", parse_json<std::optional<int>>::format(group, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

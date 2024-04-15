
#include "SetIntTxPulse.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetIntTxPulse
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetIntTxPulse::CmdName = "SetIntTxPulse";
    const char* const SetIntTxPulse::Documentation = "Set pulse signal interference.\n"
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
    const char* const SetIntTxPulse::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetIntTxPulse);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetIntTxPulse);


    SetIntTxPulse::SetIntTxPulse()
      : CommandBase(CmdName, TargetId)
    {}

    SetIntTxPulse::SetIntTxPulse(bool enabled, double centralFreq, double power, double dutyCycle, int pulseRate, const std::string& transmitterId, const std::string& signalId, const Sdx::optional<int>& group)
      : CommandBase(CmdName, TargetId)
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

    SetIntTxPulsePtr SetIntTxPulse::create(bool enabled, double centralFreq, double power, double dutyCycle, int pulseRate, const std::string& transmitterId, const std::string& signalId, const Sdx::optional<int>& group)
    {
      return std::make_shared<SetIntTxPulse>(enabled, centralFreq, power, dutyCycle, pulseRate, transmitterId, signalId, group);
    }

    SetIntTxPulsePtr SetIntTxPulse::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetIntTxPulse>(ptr);
    }

    bool SetIntTxPulse::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enabled"])
          && parse_json<double>::is_valid(m_values["CentralFreq"])
          && parse_json<double>::is_valid(m_values["Power"])
          && parse_json<double>::is_valid(m_values["DutyCycle"])
          && parse_json<int>::is_valid(m_values["PulseRate"])
          && parse_json<std::string>::is_valid(m_values["TransmitterId"])
          && parse_json<std::string>::is_valid(m_values["SignalId"])
          && parse_json<Sdx::optional<int>>::is_valid(m_values["Group"])
        ;

    }

    std::string SetIntTxPulse::documentation() const { return Documentation; }

    const std::vector<std::string>& SetIntTxPulse::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Enabled", "CentralFreq", "Power", "DutyCycle", "PulseRate", "TransmitterId", "SignalId", "Group"}; 
      return names; 
    }


    int SetIntTxPulse::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    bool SetIntTxPulse::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void SetIntTxPulse::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetIntTxPulse::centralFreq() const
    {
      return parse_json<double>::parse(m_values["CentralFreq"]);
    }

    void SetIntTxPulse::setCentralFreq(double centralFreq)
    {
      m_values.AddMember("CentralFreq", parse_json<double>::format(centralFreq, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetIntTxPulse::power() const
    {
      return parse_json<double>::parse(m_values["Power"]);
    }

    void SetIntTxPulse::setPower(double power)
    {
      m_values.AddMember("Power", parse_json<double>::format(power, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetIntTxPulse::dutyCycle() const
    {
      return parse_json<double>::parse(m_values["DutyCycle"]);
    }

    void SetIntTxPulse::setDutyCycle(double dutyCycle)
    {
      m_values.AddMember("DutyCycle", parse_json<double>::format(dutyCycle, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetIntTxPulse::pulseRate() const
    {
      return parse_json<int>::parse(m_values["PulseRate"]);
    }

    void SetIntTxPulse::setPulseRate(int pulseRate)
    {
      m_values.AddMember("PulseRate", parse_json<int>::format(pulseRate, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetIntTxPulse::transmitterId() const
    {
      return parse_json<std::string>::parse(m_values["TransmitterId"]);
    }

    void SetIntTxPulse::setTransmitterId(const std::string& transmitterId)
    {
      m_values.AddMember("TransmitterId", parse_json<std::string>::format(transmitterId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetIntTxPulse::signalId() const
    {
      return parse_json<std::string>::parse(m_values["SignalId"]);
    }

    void SetIntTxPulse::setSignalId(const std::string& signalId)
    {
      m_values.AddMember("SignalId", parse_json<std::string>::format(signalId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<int> SetIntTxPulse::group() const
    {
      return parse_json<Sdx::optional<int>>::parse(m_values["Group"]);
    }

    void SetIntTxPulse::setGroup(const Sdx::optional<int>& group)
    {
      m_values.AddMember("Group", parse_json<Sdx::optional<int>>::format(group, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

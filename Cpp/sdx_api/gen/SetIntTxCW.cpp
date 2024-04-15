
#include "SetIntTxCW.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetIntTxCW
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetIntTxCW::CmdName = "SetIntTxCW";
    const char* const SetIntTxCW::Documentation = "Set continuous wave (CW) signal to interference transmitter. A transmitter can combine\n"
      "multiple signals of different types to create complex waveform. The CW id (SignalId) can be an empty\n"
      "string. In such case, Skydel will assign a unique ID. If the signal id is already in use for the\n"
      "specified transmitted, the existing signal is updated, ortherwise a new signal is added.\n"
      "\n"
      "Name               Type            Description\n"
      "------------------ --------------- ---------------------------------------------------\n"
      "Enabled            bool            Enable (true) or disable (false) the signal\n"
      "CentralFreq        double          Central frequency (Hz)\n"
      "Power              double          Power (dB), relative to transmitter reference power\n"
      "TransmitterId      string          Transmitter unique identifier.\n"
      "SignalId           string          CW unique identifier.\n"
      "InitialPhaseOffset optional double Initial phase offset, in radians. Defaults to 0.\n"
      "Group              optional int    Group, if not using default group.";
    const char* const SetIntTxCW::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetIntTxCW);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetIntTxCW);


    SetIntTxCW::SetIntTxCW()
      : CommandBase(CmdName, TargetId)
    {}

    SetIntTxCW::SetIntTxCW(bool enabled, double centralFreq, double power, const std::string& transmitterId, const std::string& signalId, const Sdx::optional<double>& initialPhaseOffset, const Sdx::optional<int>& group)
      : CommandBase(CmdName, TargetId)
    {

      setEnabled(enabled);
      setCentralFreq(centralFreq);
      setPower(power);
      setTransmitterId(transmitterId);
      setSignalId(signalId);
      setInitialPhaseOffset(initialPhaseOffset);
      setGroup(group);
    }

    SetIntTxCWPtr SetIntTxCW::create(bool enabled, double centralFreq, double power, const std::string& transmitterId, const std::string& signalId, const Sdx::optional<double>& initialPhaseOffset, const Sdx::optional<int>& group)
    {
      return std::make_shared<SetIntTxCW>(enabled, centralFreq, power, transmitterId, signalId, initialPhaseOffset, group);
    }

    SetIntTxCWPtr SetIntTxCW::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetIntTxCW>(ptr);
    }

    bool SetIntTxCW::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enabled"])
          && parse_json<double>::is_valid(m_values["CentralFreq"])
          && parse_json<double>::is_valid(m_values["Power"])
          && parse_json<std::string>::is_valid(m_values["TransmitterId"])
          && parse_json<std::string>::is_valid(m_values["SignalId"])
          && parse_json<Sdx::optional<double>>::is_valid(m_values["InitialPhaseOffset"])
          && parse_json<Sdx::optional<int>>::is_valid(m_values["Group"])
        ;

    }

    std::string SetIntTxCW::documentation() const { return Documentation; }

    const std::vector<std::string>& SetIntTxCW::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Enabled", "CentralFreq", "Power", "TransmitterId", "SignalId", "InitialPhaseOffset", "Group"}; 
      return names; 
    }


    int SetIntTxCW::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    bool SetIntTxCW::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void SetIntTxCW::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetIntTxCW::centralFreq() const
    {
      return parse_json<double>::parse(m_values["CentralFreq"]);
    }

    void SetIntTxCW::setCentralFreq(double centralFreq)
    {
      m_values.AddMember("CentralFreq", parse_json<double>::format(centralFreq, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetIntTxCW::power() const
    {
      return parse_json<double>::parse(m_values["Power"]);
    }

    void SetIntTxCW::setPower(double power)
    {
      m_values.AddMember("Power", parse_json<double>::format(power, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetIntTxCW::transmitterId() const
    {
      return parse_json<std::string>::parse(m_values["TransmitterId"]);
    }

    void SetIntTxCW::setTransmitterId(const std::string& transmitterId)
    {
      m_values.AddMember("TransmitterId", parse_json<std::string>::format(transmitterId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetIntTxCW::signalId() const
    {
      return parse_json<std::string>::parse(m_values["SignalId"]);
    }

    void SetIntTxCW::setSignalId(const std::string& signalId)
    {
      m_values.AddMember("SignalId", parse_json<std::string>::format(signalId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<double> SetIntTxCW::initialPhaseOffset() const
    {
      return parse_json<Sdx::optional<double>>::parse(m_values["InitialPhaseOffset"]);
    }

    void SetIntTxCW::setInitialPhaseOffset(const Sdx::optional<double>& initialPhaseOffset)
    {
      m_values.AddMember("InitialPhaseOffset", parse_json<Sdx::optional<double>>::format(initialPhaseOffset, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<int> SetIntTxCW::group() const
    {
      return parse_json<Sdx::optional<int>>::parse(m_values["Group"]);
    }

    void SetIntTxCW::setGroup(const Sdx::optional<int>& group)
    {
      m_values.AddMember("Group", parse_json<Sdx::optional<int>>::format(group, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}


#include "gen/SetIntTxChirp.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetIntTxChirp
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetIntTxChirp::CmdName = "SetIntTxChirp";
    const char* const SetIntTxChirp::Documentation = "Set Chirp signal to interference transmitter. A transmitter can combine\nmultiple signals of different types to create complex waveform. The signal id (SignalId) can be an empty\nstring. In such case, Skydel will assign a unique ID. If the signal id is already in use for the\nspecified transmitted, the existing signal is updated, ortherwise a new signal is added.";

    REGISTER_COMMAND_FACTORY(SetIntTxChirp);


    SetIntTxChirp::SetIntTxChirp()
      : CommandBase(CmdName)
    {}

    SetIntTxChirp::SetIntTxChirp(bool enabled, double centralFreq, double power, double bandwidth, double sweepTime, const std::string& transmitterId, const std::string& signalId, const Sdx::optional<int>& group)
      : CommandBase(CmdName)
    {

      setEnabled(enabled);
      setCentralFreq(centralFreq);
      setPower(power);
      setBandwidth(bandwidth);
      setSweepTime(sweepTime);
      setTransmitterId(transmitterId);
      setSignalId(signalId);
      setGroup(group);
    }

    SetIntTxChirpPtr SetIntTxChirp::create(bool enabled, double centralFreq, double power, double bandwidth, double sweepTime, const std::string& transmitterId, const std::string& signalId, const Sdx::optional<int>& group)
    {
      return std::make_shared<SetIntTxChirp>(enabled, centralFreq, power, bandwidth, sweepTime, transmitterId, signalId, group);
    }

    SetIntTxChirpPtr SetIntTxChirp::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetIntTxChirp>(ptr);
    }

    bool SetIntTxChirp::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enabled"])
          && parse_json<double>::is_valid(m_values["CentralFreq"])
          && parse_json<double>::is_valid(m_values["Power"])
          && parse_json<double>::is_valid(m_values["Bandwidth"])
          && parse_json<double>::is_valid(m_values["SweepTime"])
          && parse_json<std::string>::is_valid(m_values["TransmitterId"])
          && parse_json<std::string>::is_valid(m_values["SignalId"])
          && parse_json<Sdx::optional<int>>::is_valid(m_values["Group"])
        ;

    }

    std::string SetIntTxChirp::documentation() const { return Documentation; }


    int SetIntTxChirp::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    bool SetIntTxChirp::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void SetIntTxChirp::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetIntTxChirp::centralFreq() const
    {
      return parse_json<double>::parse(m_values["CentralFreq"]);
    }

    void SetIntTxChirp::setCentralFreq(double centralFreq)
    {
      m_values.AddMember("CentralFreq", parse_json<double>::format(centralFreq, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetIntTxChirp::power() const
    {
      return parse_json<double>::parse(m_values["Power"]);
    }

    void SetIntTxChirp::setPower(double power)
    {
      m_values.AddMember("Power", parse_json<double>::format(power, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetIntTxChirp::bandwidth() const
    {
      return parse_json<double>::parse(m_values["Bandwidth"]);
    }

    void SetIntTxChirp::setBandwidth(double bandwidth)
    {
      m_values.AddMember("Bandwidth", parse_json<double>::format(bandwidth, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetIntTxChirp::sweepTime() const
    {
      return parse_json<double>::parse(m_values["SweepTime"]);
    }

    void SetIntTxChirp::setSweepTime(double sweepTime)
    {
      m_values.AddMember("SweepTime", parse_json<double>::format(sweepTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetIntTxChirp::transmitterId() const
    {
      return parse_json<std::string>::parse(m_values["TransmitterId"]);
    }

    void SetIntTxChirp::setTransmitterId(const std::string& transmitterId)
    {
      m_values.AddMember("TransmitterId", parse_json<std::string>::format(transmitterId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetIntTxChirp::signalId() const
    {
      return parse_json<std::string>::parse(m_values["SignalId"]);
    }

    void SetIntTxChirp::setSignalId(const std::string& signalId)
    {
      m_values.AddMember("SignalId", parse_json<std::string>::format(signalId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<int> SetIntTxChirp::group() const
    {
      return parse_json<Sdx::optional<int>>::parse(m_values["Group"]);
    }

    void SetIntTxChirp::setGroup(const Sdx::optional<int>& group)
    {
      m_values.AddMember("Group", parse_json<Sdx::optional<int>>::format(group, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}


#include "gen/SetIntTxBPSK.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetIntTxBPSK
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetIntTxBPSK::CmdName = "SetIntTxBPSK";
    const char* const SetIntTxBPSK::Documentation = "Set BPSK signal interference.";

    REGISTER_COMMAND_FACTORY(SetIntTxBPSK);


    SetIntTxBPSK::SetIntTxBPSK()
      : CommandBase(CmdName)
    {}

    SetIntTxBPSK::SetIntTxBPSK(bool enabled, double centralFreq, double power, int codeRate, int codeLengthMs, const std::string& transmitterId, const std::string& signalId, const Sdx::optional<int>& group, const Sdx::optional<int>& prn)
      : CommandBase(CmdName)
    {

      setEnabled(enabled);
      setCentralFreq(centralFreq);
      setPower(power);
      setCodeRate(codeRate);
      setCodeLengthMs(codeLengthMs);
      setTransmitterId(transmitterId);
      setSignalId(signalId);
      setGroup(group);
      setPrn(prn);
    }

    SetIntTxBPSKPtr SetIntTxBPSK::create(bool enabled, double centralFreq, double power, int codeRate, int codeLengthMs, const std::string& transmitterId, const std::string& signalId, const Sdx::optional<int>& group, const Sdx::optional<int>& prn)
    {
      return std::make_shared<SetIntTxBPSK>(enabled, centralFreq, power, codeRate, codeLengthMs, transmitterId, signalId, group, prn);
    }

    SetIntTxBPSKPtr SetIntTxBPSK::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetIntTxBPSK>(ptr);
    }

    bool SetIntTxBPSK::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enabled"])
          && parse_json<double>::is_valid(m_values["CentralFreq"])
          && parse_json<double>::is_valid(m_values["Power"])
          && parse_json<int>::is_valid(m_values["CodeRate"])
          && parse_json<int>::is_valid(m_values["CodeLengthMs"])
          && parse_json<std::string>::is_valid(m_values["TransmitterId"])
          && parse_json<std::string>::is_valid(m_values["SignalId"])
          && parse_json<Sdx::optional<int>>::is_valid(m_values["Group"])
          && parse_json<Sdx::optional<int>>::is_valid(m_values["Prn"])
        ;

    }

    std::string SetIntTxBPSK::documentation() const { return Documentation; }


    int SetIntTxBPSK::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    bool SetIntTxBPSK::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void SetIntTxBPSK::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetIntTxBPSK::centralFreq() const
    {
      return parse_json<double>::parse(m_values["CentralFreq"]);
    }

    void SetIntTxBPSK::setCentralFreq(double centralFreq)
    {
      m_values.AddMember("CentralFreq", parse_json<double>::format(centralFreq, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetIntTxBPSK::power() const
    {
      return parse_json<double>::parse(m_values["Power"]);
    }

    void SetIntTxBPSK::setPower(double power)
    {
      m_values.AddMember("Power", parse_json<double>::format(power, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetIntTxBPSK::codeRate() const
    {
      return parse_json<int>::parse(m_values["CodeRate"]);
    }

    void SetIntTxBPSK::setCodeRate(int codeRate)
    {
      m_values.AddMember("CodeRate", parse_json<int>::format(codeRate, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetIntTxBPSK::codeLengthMs() const
    {
      return parse_json<int>::parse(m_values["CodeLengthMs"]);
    }

    void SetIntTxBPSK::setCodeLengthMs(int codeLengthMs)
    {
      m_values.AddMember("CodeLengthMs", parse_json<int>::format(codeLengthMs, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetIntTxBPSK::transmitterId() const
    {
      return parse_json<std::string>::parse(m_values["TransmitterId"]);
    }

    void SetIntTxBPSK::setTransmitterId(const std::string& transmitterId)
    {
      m_values.AddMember("TransmitterId", parse_json<std::string>::format(transmitterId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetIntTxBPSK::signalId() const
    {
      return parse_json<std::string>::parse(m_values["SignalId"]);
    }

    void SetIntTxBPSK::setSignalId(const std::string& signalId)
    {
      m_values.AddMember("SignalId", parse_json<std::string>::format(signalId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<int> SetIntTxBPSK::group() const
    {
      return parse_json<Sdx::optional<int>>::parse(m_values["Group"]);
    }

    void SetIntTxBPSK::setGroup(const Sdx::optional<int>& group)
    {
      m_values.AddMember("Group", parse_json<Sdx::optional<int>>::format(group, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<int> SetIntTxBPSK::prn() const
    {
      return parse_json<Sdx::optional<int>>::parse(m_values["Prn"]);
    }

    void SetIntTxBPSK::setPrn(const Sdx::optional<int>& prn)
    {
      m_values.AddMember("Prn", parse_json<Sdx::optional<int>>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

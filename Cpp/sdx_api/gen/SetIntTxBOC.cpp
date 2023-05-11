
#include "gen/SetIntTxBOC.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetIntTxBOC
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetIntTxBOC::CmdName = "SetIntTxBOC";
    const char* const SetIntTxBOC::Documentation = "Set BOC signal interference.";

    REGISTER_COMMAND_FACTORY(SetIntTxBOC);


    SetIntTxBOC::SetIntTxBOC()
      : CommandBase(CmdName)
    {}

    SetIntTxBOC::SetIntTxBOC(bool enabled, double centralFreq, double power, int codeRate, int codeLengthMs, int subCarrierRate, bool cosinePhaseBoc, const std::string& transmitterId, const std::string& signalId, const Sdx::optional<int>& group)
      : CommandBase(CmdName)
    {

      setEnabled(enabled);
      setCentralFreq(centralFreq);
      setPower(power);
      setCodeRate(codeRate);
      setCodeLengthMs(codeLengthMs);
      setSubCarrierRate(subCarrierRate);
      setCosinePhaseBoc(cosinePhaseBoc);
      setTransmitterId(transmitterId);
      setSignalId(signalId);
      setGroup(group);
    }

    SetIntTxBOCPtr SetIntTxBOC::create(bool enabled, double centralFreq, double power, int codeRate, int codeLengthMs, int subCarrierRate, bool cosinePhaseBoc, const std::string& transmitterId, const std::string& signalId, const Sdx::optional<int>& group)
    {
      return std::make_shared<SetIntTxBOC>(enabled, centralFreq, power, codeRate, codeLengthMs, subCarrierRate, cosinePhaseBoc, transmitterId, signalId, group);
    }

    SetIntTxBOCPtr SetIntTxBOC::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetIntTxBOC>(ptr);
    }

    bool SetIntTxBOC::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enabled"])
          && parse_json<double>::is_valid(m_values["CentralFreq"])
          && parse_json<double>::is_valid(m_values["Power"])
          && parse_json<int>::is_valid(m_values["CodeRate"])
          && parse_json<int>::is_valid(m_values["CodeLengthMs"])
          && parse_json<int>::is_valid(m_values["SubCarrierRate"])
          && parse_json<bool>::is_valid(m_values["CosinePhaseBoc"])
          && parse_json<std::string>::is_valid(m_values["TransmitterId"])
          && parse_json<std::string>::is_valid(m_values["SignalId"])
          && parse_json<Sdx::optional<int>>::is_valid(m_values["Group"])
        ;

    }

    std::string SetIntTxBOC::documentation() const { return Documentation; }


    int SetIntTxBOC::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    bool SetIntTxBOC::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void SetIntTxBOC::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetIntTxBOC::centralFreq() const
    {
      return parse_json<double>::parse(m_values["CentralFreq"]);
    }

    void SetIntTxBOC::setCentralFreq(double centralFreq)
    {
      m_values.AddMember("CentralFreq", parse_json<double>::format(centralFreq, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetIntTxBOC::power() const
    {
      return parse_json<double>::parse(m_values["Power"]);
    }

    void SetIntTxBOC::setPower(double power)
    {
      m_values.AddMember("Power", parse_json<double>::format(power, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetIntTxBOC::codeRate() const
    {
      return parse_json<int>::parse(m_values["CodeRate"]);
    }

    void SetIntTxBOC::setCodeRate(int codeRate)
    {
      m_values.AddMember("CodeRate", parse_json<int>::format(codeRate, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetIntTxBOC::codeLengthMs() const
    {
      return parse_json<int>::parse(m_values["CodeLengthMs"]);
    }

    void SetIntTxBOC::setCodeLengthMs(int codeLengthMs)
    {
      m_values.AddMember("CodeLengthMs", parse_json<int>::format(codeLengthMs, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetIntTxBOC::subCarrierRate() const
    {
      return parse_json<int>::parse(m_values["SubCarrierRate"]);
    }

    void SetIntTxBOC::setSubCarrierRate(int subCarrierRate)
    {
      m_values.AddMember("SubCarrierRate", parse_json<int>::format(subCarrierRate, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetIntTxBOC::cosinePhaseBoc() const
    {
      return parse_json<bool>::parse(m_values["CosinePhaseBoc"]);
    }

    void SetIntTxBOC::setCosinePhaseBoc(bool cosinePhaseBoc)
    {
      m_values.AddMember("CosinePhaseBoc", parse_json<bool>::format(cosinePhaseBoc, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetIntTxBOC::transmitterId() const
    {
      return parse_json<std::string>::parse(m_values["TransmitterId"]);
    }

    void SetIntTxBOC::setTransmitterId(const std::string& transmitterId)
    {
      m_values.AddMember("TransmitterId", parse_json<std::string>::format(transmitterId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetIntTxBOC::signalId() const
    {
      return parse_json<std::string>::parse(m_values["SignalId"]);
    }

    void SetIntTxBOC::setSignalId(const std::string& signalId)
    {
      m_values.AddMember("SignalId", parse_json<std::string>::format(signalId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<int> SetIntTxBOC::group() const
    {
      return parse_json<Sdx::optional<int>>::parse(m_values["Group"]);
    }

    void SetIntTxBOC::setGroup(const Sdx::optional<int>& group)
    {
      m_values.AddMember("Group", parse_json<Sdx::optional<int>>::format(group, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

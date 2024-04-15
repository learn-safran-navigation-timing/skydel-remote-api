
#include "GetIntTxBOCResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIntTxBOCResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIntTxBOCResult::CmdName = "GetIntTxBOCResult";
    const char* const GetIntTxBOCResult::Documentation = "Result of GetIntTxBOC.\n"
      "\n"
      "Name           Type         Description\n"
      "-------------- ------------ -------------------------------------------------------------------------\n"
      "Enabled        bool         Enable (true) or disable (false) the signal\n"
      "CentralFreq    double       Central frequency (Hz)\n"
      "Power          double       Power (dB), relative to transmitter reference power\n"
      "CodeRate       int          Code rate (Hz). Must be between 1000 and 60000000 and a multiple of 1KHz.\n"
      "CodeLengthMs   int          Code length (ms). Must be between 1 and 100.\n"
      "SubCarrierRate int          Code rate (Hz). Must be between 1000 and 60000000 and a multiple of 1KHz.\n"
      "CosinePhaseBoc bool         Use Cosine-Phase BOC instead of default Sine-Phase BOC.\n"
      "TransmitterId  string       Transmitter unique identifier.\n"
      "SignalId       string       BOC unique identifier.\n"
      "Group          optional int Group, if not using default group.";
    const char* const GetIntTxBOCResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetIntTxBOCResult);


    GetIntTxBOCResult::GetIntTxBOCResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetIntTxBOCResult::GetIntTxBOCResult(bool enabled, double centralFreq, double power, int codeRate, int codeLengthMs, int subCarrierRate, bool cosinePhaseBoc, const std::string& transmitterId, const std::string& signalId, const Sdx::optional<int>& group)
      : CommandResult(CmdName, TargetId)
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

    GetIntTxBOCResult::GetIntTxBOCResult(CommandBasePtr relatedCommand, bool enabled, double centralFreq, double power, int codeRate, int codeLengthMs, int subCarrierRate, bool cosinePhaseBoc, const std::string& transmitterId, const std::string& signalId, const Sdx::optional<int>& group)
      : CommandResult(CmdName, TargetId, relatedCommand)
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


    GetIntTxBOCResultPtr GetIntTxBOCResult::create(bool enabled, double centralFreq, double power, int codeRate, int codeLengthMs, int subCarrierRate, bool cosinePhaseBoc, const std::string& transmitterId, const std::string& signalId, const Sdx::optional<int>& group)
    {
      return std::make_shared<GetIntTxBOCResult>(enabled, centralFreq, power, codeRate, codeLengthMs, subCarrierRate, cosinePhaseBoc, transmitterId, signalId, group);
    }

    GetIntTxBOCResultPtr GetIntTxBOCResult::create(CommandBasePtr relatedCommand, bool enabled, double centralFreq, double power, int codeRate, int codeLengthMs, int subCarrierRate, bool cosinePhaseBoc, const std::string& transmitterId, const std::string& signalId, const Sdx::optional<int>& group)
    {
      return std::make_shared<GetIntTxBOCResult>(relatedCommand, enabled, centralFreq, power, codeRate, codeLengthMs, subCarrierRate, cosinePhaseBoc, transmitterId, signalId, group);
    }

    GetIntTxBOCResultPtr GetIntTxBOCResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetIntTxBOCResult>(ptr);
    }

    bool GetIntTxBOCResult::isValid() const
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

    std::string GetIntTxBOCResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetIntTxBOCResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Enabled", "CentralFreq", "Power", "CodeRate", "CodeLengthMs", "SubCarrierRate", "CosinePhaseBoc", "TransmitterId", "SignalId", "Group"}; 
      return names; 
    }


    bool GetIntTxBOCResult::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void GetIntTxBOCResult::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetIntTxBOCResult::centralFreq() const
    {
      return parse_json<double>::parse(m_values["CentralFreq"]);
    }

    void GetIntTxBOCResult::setCentralFreq(double centralFreq)
    {
      m_values.AddMember("CentralFreq", parse_json<double>::format(centralFreq, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetIntTxBOCResult::power() const
    {
      return parse_json<double>::parse(m_values["Power"]);
    }

    void GetIntTxBOCResult::setPower(double power)
    {
      m_values.AddMember("Power", parse_json<double>::format(power, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetIntTxBOCResult::codeRate() const
    {
      return parse_json<int>::parse(m_values["CodeRate"]);
    }

    void GetIntTxBOCResult::setCodeRate(int codeRate)
    {
      m_values.AddMember("CodeRate", parse_json<int>::format(codeRate, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetIntTxBOCResult::codeLengthMs() const
    {
      return parse_json<int>::parse(m_values["CodeLengthMs"]);
    }

    void GetIntTxBOCResult::setCodeLengthMs(int codeLengthMs)
    {
      m_values.AddMember("CodeLengthMs", parse_json<int>::format(codeLengthMs, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetIntTxBOCResult::subCarrierRate() const
    {
      return parse_json<int>::parse(m_values["SubCarrierRate"]);
    }

    void GetIntTxBOCResult::setSubCarrierRate(int subCarrierRate)
    {
      m_values.AddMember("SubCarrierRate", parse_json<int>::format(subCarrierRate, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetIntTxBOCResult::cosinePhaseBoc() const
    {
      return parse_json<bool>::parse(m_values["CosinePhaseBoc"]);
    }

    void GetIntTxBOCResult::setCosinePhaseBoc(bool cosinePhaseBoc)
    {
      m_values.AddMember("CosinePhaseBoc", parse_json<bool>::format(cosinePhaseBoc, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetIntTxBOCResult::transmitterId() const
    {
      return parse_json<std::string>::parse(m_values["TransmitterId"]);
    }

    void GetIntTxBOCResult::setTransmitterId(const std::string& transmitterId)
    {
      m_values.AddMember("TransmitterId", parse_json<std::string>::format(transmitterId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetIntTxBOCResult::signalId() const
    {
      return parse_json<std::string>::parse(m_values["SignalId"]);
    }

    void GetIntTxBOCResult::setSignalId(const std::string& signalId)
    {
      m_values.AddMember("SignalId", parse_json<std::string>::format(signalId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<int> GetIntTxBOCResult::group() const
    {
      return parse_json<Sdx::optional<int>>::parse(m_values["Group"]);
    }

    void GetIntTxBOCResult::setGroup(const Sdx::optional<int>& group)
    {
      m_values.AddMember("Group", parse_json<Sdx::optional<int>>::format(group, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}


#include "gen/GetIntTxBPSKResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIntTxBPSKResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIntTxBPSKResult::CmdName = "GetIntTxBPSKResult";
    const char* const GetIntTxBPSKResult::Documentation = "Result of GetIntTxBPSK.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetIntTxBPSKResult);


    GetIntTxBPSKResult::GetIntTxBPSKResult()
      : CommandResult(CmdName)
    {}

    GetIntTxBPSKResult::GetIntTxBPSKResult(bool enabled, double centralFreq, double power, int codeRate, int codeLengthMs, const std::string& transmitterId, const std::string& signalId, const Sdx::optional<int>& group, const Sdx::optional<int>& prn)
      : CommandResult(CmdName)
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

    GetIntTxBPSKResult::GetIntTxBPSKResult(CommandBasePtr relatedCommand, bool enabled, double centralFreq, double power, int codeRate, int codeLengthMs, const std::string& transmitterId, const std::string& signalId, const Sdx::optional<int>& group, const Sdx::optional<int>& prn)
      : CommandResult(CmdName, relatedCommand)
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


    GetIntTxBPSKResultPtr GetIntTxBPSKResult::create(bool enabled, double centralFreq, double power, int codeRate, int codeLengthMs, const std::string& transmitterId, const std::string& signalId, const Sdx::optional<int>& group, const Sdx::optional<int>& prn)
    {
      return std::make_shared<GetIntTxBPSKResult>(enabled, centralFreq, power, codeRate, codeLengthMs, transmitterId, signalId, group, prn);
    }

    GetIntTxBPSKResultPtr GetIntTxBPSKResult::create(CommandBasePtr relatedCommand, bool enabled, double centralFreq, double power, int codeRate, int codeLengthMs, const std::string& transmitterId, const std::string& signalId, const Sdx::optional<int>& group, const Sdx::optional<int>& prn)
    {
      return std::make_shared<GetIntTxBPSKResult>(relatedCommand, enabled, centralFreq, power, codeRate, codeLengthMs, transmitterId, signalId, group, prn);
    }

    GetIntTxBPSKResultPtr GetIntTxBPSKResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetIntTxBPSKResult>(ptr);
    }

    bool GetIntTxBPSKResult::isValid() const
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

    std::string GetIntTxBPSKResult::documentation() const { return Documentation; }


    bool GetIntTxBPSKResult::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void GetIntTxBPSKResult::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetIntTxBPSKResult::centralFreq() const
    {
      return parse_json<double>::parse(m_values["CentralFreq"]);
    }

    void GetIntTxBPSKResult::setCentralFreq(double centralFreq)
    {
      m_values.AddMember("CentralFreq", parse_json<double>::format(centralFreq, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetIntTxBPSKResult::power() const
    {
      return parse_json<double>::parse(m_values["Power"]);
    }

    void GetIntTxBPSKResult::setPower(double power)
    {
      m_values.AddMember("Power", parse_json<double>::format(power, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetIntTxBPSKResult::codeRate() const
    {
      return parse_json<int>::parse(m_values["CodeRate"]);
    }

    void GetIntTxBPSKResult::setCodeRate(int codeRate)
    {
      m_values.AddMember("CodeRate", parse_json<int>::format(codeRate, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetIntTxBPSKResult::codeLengthMs() const
    {
      return parse_json<int>::parse(m_values["CodeLengthMs"]);
    }

    void GetIntTxBPSKResult::setCodeLengthMs(int codeLengthMs)
    {
      m_values.AddMember("CodeLengthMs", parse_json<int>::format(codeLengthMs, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetIntTxBPSKResult::transmitterId() const
    {
      return parse_json<std::string>::parse(m_values["TransmitterId"]);
    }

    void GetIntTxBPSKResult::setTransmitterId(const std::string& transmitterId)
    {
      m_values.AddMember("TransmitterId", parse_json<std::string>::format(transmitterId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetIntTxBPSKResult::signalId() const
    {
      return parse_json<std::string>::parse(m_values["SignalId"]);
    }

    void GetIntTxBPSKResult::setSignalId(const std::string& signalId)
    {
      m_values.AddMember("SignalId", parse_json<std::string>::format(signalId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<int> GetIntTxBPSKResult::group() const
    {
      return parse_json<Sdx::optional<int>>::parse(m_values["Group"]);
    }

    void GetIntTxBPSKResult::setGroup(const Sdx::optional<int>& group)
    {
      m_values.AddMember("Group", parse_json<Sdx::optional<int>>::format(group, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<int> GetIntTxBPSKResult::prn() const
    {
      return parse_json<Sdx::optional<int>>::parse(m_values["Prn"]);
    }

    void GetIntTxBPSKResult::setPrn(const Sdx::optional<int>& prn)
    {
      m_values.AddMember("Prn", parse_json<Sdx::optional<int>>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

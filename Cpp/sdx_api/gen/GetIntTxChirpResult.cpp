
#include "gen/GetIntTxChirpResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIntTxChirpResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIntTxChirpResult::CmdName = "GetIntTxChirpResult";
    const char* const GetIntTxChirpResult::Documentation = "Result of GetIntTxChirp.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetIntTxChirpResult);


    GetIntTxChirpResult::GetIntTxChirpResult()
      : CommandResult(CmdName)
    {}

    GetIntTxChirpResult::GetIntTxChirpResult(bool enabled, double centralFreq, double power, double bandwidth, double sweepTime, const std::string& transmitterId, const std::string& signalId, const Sdx::optional<int>& group)
      : CommandResult(CmdName)
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

    GetIntTxChirpResult::GetIntTxChirpResult(CommandBasePtr relatedCommand, bool enabled, double centralFreq, double power, double bandwidth, double sweepTime, const std::string& transmitterId, const std::string& signalId, const Sdx::optional<int>& group)
      : CommandResult(CmdName, relatedCommand)
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


    GetIntTxChirpResultPtr GetIntTxChirpResult::create(bool enabled, double centralFreq, double power, double bandwidth, double sweepTime, const std::string& transmitterId, const std::string& signalId, const Sdx::optional<int>& group)
    {
      return std::make_shared<GetIntTxChirpResult>(enabled, centralFreq, power, bandwidth, sweepTime, transmitterId, signalId, group);
    }

    GetIntTxChirpResultPtr GetIntTxChirpResult::create(CommandBasePtr relatedCommand, bool enabled, double centralFreq, double power, double bandwidth, double sweepTime, const std::string& transmitterId, const std::string& signalId, const Sdx::optional<int>& group)
    {
      return std::make_shared<GetIntTxChirpResult>(relatedCommand, enabled, centralFreq, power, bandwidth, sweepTime, transmitterId, signalId, group);
    }

    GetIntTxChirpResultPtr GetIntTxChirpResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetIntTxChirpResult>(ptr);
    }

    bool GetIntTxChirpResult::isValid() const
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

    std::string GetIntTxChirpResult::documentation() const { return Documentation; }


    bool GetIntTxChirpResult::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void GetIntTxChirpResult::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetIntTxChirpResult::centralFreq() const
    {
      return parse_json<double>::parse(m_values["CentralFreq"]);
    }

    void GetIntTxChirpResult::setCentralFreq(double centralFreq)
    {
      m_values.AddMember("CentralFreq", parse_json<double>::format(centralFreq, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetIntTxChirpResult::power() const
    {
      return parse_json<double>::parse(m_values["Power"]);
    }

    void GetIntTxChirpResult::setPower(double power)
    {
      m_values.AddMember("Power", parse_json<double>::format(power, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetIntTxChirpResult::bandwidth() const
    {
      return parse_json<double>::parse(m_values["Bandwidth"]);
    }

    void GetIntTxChirpResult::setBandwidth(double bandwidth)
    {
      m_values.AddMember("Bandwidth", parse_json<double>::format(bandwidth, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetIntTxChirpResult::sweepTime() const
    {
      return parse_json<double>::parse(m_values["SweepTime"]);
    }

    void GetIntTxChirpResult::setSweepTime(double sweepTime)
    {
      m_values.AddMember("SweepTime", parse_json<double>::format(sweepTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetIntTxChirpResult::transmitterId() const
    {
      return parse_json<std::string>::parse(m_values["TransmitterId"]);
    }

    void GetIntTxChirpResult::setTransmitterId(const std::string& transmitterId)
    {
      m_values.AddMember("TransmitterId", parse_json<std::string>::format(transmitterId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetIntTxChirpResult::signalId() const
    {
      return parse_json<std::string>::parse(m_values["SignalId"]);
    }

    void GetIntTxChirpResult::setSignalId(const std::string& signalId)
    {
      m_values.AddMember("SignalId", parse_json<std::string>::format(signalId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<int> GetIntTxChirpResult::group() const
    {
      return parse_json<Sdx::optional<int>>::parse(m_values["Group"]);
    }

    void GetIntTxChirpResult::setGroup(const Sdx::optional<int>& group)
    {
      m_values.AddMember("Group", parse_json<Sdx::optional<int>>::format(group, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

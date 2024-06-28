
#include "GetIntTxChirpResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIntTxChirpResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIntTxChirpResult::CmdName = "GetIntTxChirpResult";
    const char* const GetIntTxChirpResult::Documentation = "Result of GetIntTxChirp.\n"
      "\n"
      "Name          Type         Description\n"
      "------------- ------------ ---------------------------------------------------\n"
      "Enabled       bool         Enable (true) or disable (false) the signal\n"
      "CentralFreq   double       Central frequency (Hz)\n"
      "Power         double       Power (dB), relative to transmitter reference power\n"
      "Bandwidth     double       Bandwidth (Hz)\n"
      "SweepTime     double       sweep Time (us)\n"
      "TransmitterId string       Transmitter unique identifier.\n"
      "SignalId      string       Chirp unique identifier.\n"
      "Group         optional int Group, if not using default group.";
    const char* const GetIntTxChirpResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetIntTxChirpResult);


    GetIntTxChirpResult::GetIntTxChirpResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetIntTxChirpResult::GetIntTxChirpResult(bool enabled, double centralFreq, double power, double bandwidth, double sweepTime, const std::string& transmitterId, const std::string& signalId, const std::optional<int>& group)
      : CommandResult(CmdName, TargetId)
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

    GetIntTxChirpResult::GetIntTxChirpResult(CommandBasePtr relatedCommand, bool enabled, double centralFreq, double power, double bandwidth, double sweepTime, const std::string& transmitterId, const std::string& signalId, const std::optional<int>& group)
      : CommandResult(CmdName, TargetId, relatedCommand)
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


    GetIntTxChirpResultPtr GetIntTxChirpResult::create(bool enabled, double centralFreq, double power, double bandwidth, double sweepTime, const std::string& transmitterId, const std::string& signalId, const std::optional<int>& group)
    {
      return std::make_shared<GetIntTxChirpResult>(enabled, centralFreq, power, bandwidth, sweepTime, transmitterId, signalId, group);
    }

    GetIntTxChirpResultPtr GetIntTxChirpResult::create(CommandBasePtr relatedCommand, bool enabled, double centralFreq, double power, double bandwidth, double sweepTime, const std::string& transmitterId, const std::string& signalId, const std::optional<int>& group)
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
          && parse_json<std::optional<int>>::is_valid(m_values["Group"])
        ;

    }

    std::string GetIntTxChirpResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetIntTxChirpResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Enabled", "CentralFreq", "Power", "Bandwidth", "SweepTime", "TransmitterId", "SignalId", "Group"}; 
      return names; 
    }


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



    std::optional<int> GetIntTxChirpResult::group() const
    {
      return parse_json<std::optional<int>>::parse(m_values["Group"]);
    }

    void GetIntTxChirpResult::setGroup(const std::optional<int>& group)
    {
      m_values.AddMember("Group", parse_json<std::optional<int>>::format(group, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}


#include "GetIntTxAWGNResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIntTxAWGNResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIntTxAWGNResult::CmdName = "GetIntTxAWGNResult";
    const char* const GetIntTxAWGNResult::Documentation = "Result of GetIntTxAWGN.\n"
      "\n"
      "Name          Type         Description\n"
      "------------- ------------ ------------------------------------------------------------------------------------------\n"
      "Enabled       bool         Enable (true) or disable (false) the signal\n"
      "CentralFreq   double       Central frequency (Hz)\n"
      "Power         double       Power (dB), relative to transmitter reference power\n"
      "Bandwidth     double       Bandwidth (Hz)\n"
      "TransmitterId string       Transmitter unique identifier.\n"
      "SignalId      string       AWGN unique identifier.\n"
      "Seed          optional int Seed for the random number generator. Signals with the same seed will have the same shape.\n"
      "Group         optional int Group, if not using default group.";
    const char* const GetIntTxAWGNResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetIntTxAWGNResult);


    GetIntTxAWGNResult::GetIntTxAWGNResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetIntTxAWGNResult::GetIntTxAWGNResult(bool enabled, double centralFreq, double power, double bandwidth, const std::string& transmitterId, const std::string& signalId, const std::optional<int>& seed, const std::optional<int>& group)
      : CommandResult(CmdName, TargetId)
    {

      setEnabled(enabled);
      setCentralFreq(centralFreq);
      setPower(power);
      setBandwidth(bandwidth);
      setTransmitterId(transmitterId);
      setSignalId(signalId);
      setSeed(seed);
      setGroup(group);
    }

    GetIntTxAWGNResult::GetIntTxAWGNResult(CommandBasePtr relatedCommand, bool enabled, double centralFreq, double power, double bandwidth, const std::string& transmitterId, const std::string& signalId, const std::optional<int>& seed, const std::optional<int>& group)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setEnabled(enabled);
      setCentralFreq(centralFreq);
      setPower(power);
      setBandwidth(bandwidth);
      setTransmitterId(transmitterId);
      setSignalId(signalId);
      setSeed(seed);
      setGroup(group);
    }


    GetIntTxAWGNResultPtr GetIntTxAWGNResult::create(bool enabled, double centralFreq, double power, double bandwidth, const std::string& transmitterId, const std::string& signalId, const std::optional<int>& seed, const std::optional<int>& group)
    {
      return std::make_shared<GetIntTxAWGNResult>(enabled, centralFreq, power, bandwidth, transmitterId, signalId, seed, group);
    }

    GetIntTxAWGNResultPtr GetIntTxAWGNResult::create(CommandBasePtr relatedCommand, bool enabled, double centralFreq, double power, double bandwidth, const std::string& transmitterId, const std::string& signalId, const std::optional<int>& seed, const std::optional<int>& group)
    {
      return std::make_shared<GetIntTxAWGNResult>(relatedCommand, enabled, centralFreq, power, bandwidth, transmitterId, signalId, seed, group);
    }

    GetIntTxAWGNResultPtr GetIntTxAWGNResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetIntTxAWGNResult>(ptr);
    }

    bool GetIntTxAWGNResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enabled"])
          && parse_json<double>::is_valid(m_values["CentralFreq"])
          && parse_json<double>::is_valid(m_values["Power"])
          && parse_json<double>::is_valid(m_values["Bandwidth"])
          && parse_json<std::string>::is_valid(m_values["TransmitterId"])
          && parse_json<std::string>::is_valid(m_values["SignalId"])
          && parse_json<std::optional<int>>::is_valid(m_values["Seed"])
          && parse_json<std::optional<int>>::is_valid(m_values["Group"])
        ;

    }

    std::string GetIntTxAWGNResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetIntTxAWGNResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Enabled", "CentralFreq", "Power", "Bandwidth", "TransmitterId", "SignalId", "Seed", "Group"}; 
      return names; 
    }


    bool GetIntTxAWGNResult::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void GetIntTxAWGNResult::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetIntTxAWGNResult::centralFreq() const
    {
      return parse_json<double>::parse(m_values["CentralFreq"]);
    }

    void GetIntTxAWGNResult::setCentralFreq(double centralFreq)
    {
      m_values.AddMember("CentralFreq", parse_json<double>::format(centralFreq, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetIntTxAWGNResult::power() const
    {
      return parse_json<double>::parse(m_values["Power"]);
    }

    void GetIntTxAWGNResult::setPower(double power)
    {
      m_values.AddMember("Power", parse_json<double>::format(power, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetIntTxAWGNResult::bandwidth() const
    {
      return parse_json<double>::parse(m_values["Bandwidth"]);
    }

    void GetIntTxAWGNResult::setBandwidth(double bandwidth)
    {
      m_values.AddMember("Bandwidth", parse_json<double>::format(bandwidth, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetIntTxAWGNResult::transmitterId() const
    {
      return parse_json<std::string>::parse(m_values["TransmitterId"]);
    }

    void GetIntTxAWGNResult::setTransmitterId(const std::string& transmitterId)
    {
      m_values.AddMember("TransmitterId", parse_json<std::string>::format(transmitterId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetIntTxAWGNResult::signalId() const
    {
      return parse_json<std::string>::parse(m_values["SignalId"]);
    }

    void GetIntTxAWGNResult::setSignalId(const std::string& signalId)
    {
      m_values.AddMember("SignalId", parse_json<std::string>::format(signalId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<int> GetIntTxAWGNResult::seed() const
    {
      return parse_json<std::optional<int>>::parse(m_values["Seed"]);
    }

    void GetIntTxAWGNResult::setSeed(const std::optional<int>& seed)
    {
      m_values.AddMember("Seed", parse_json<std::optional<int>>::format(seed, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<int> GetIntTxAWGNResult::group() const
    {
      return parse_json<std::optional<int>>::parse(m_values["Group"]);
    }

    void GetIntTxAWGNResult::setGroup(const std::optional<int>& group)
    {
      m_values.AddMember("Group", parse_json<std::optional<int>>::format(group, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

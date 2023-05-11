
#include "gen/GetIntTxAWGNResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIntTxAWGNResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIntTxAWGNResult::CmdName = "GetIntTxAWGNResult";
    const char* const GetIntTxAWGNResult::Documentation = "Result of GetIntTxAWGN.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetIntTxAWGNResult);


    GetIntTxAWGNResult::GetIntTxAWGNResult()
      : CommandResult(CmdName)
    {}

    GetIntTxAWGNResult::GetIntTxAWGNResult(bool enabled, double centralFreq, double power, double bandwidth, const std::string& transmitterId, const std::string& signalId, const Sdx::optional<int>& seed, const Sdx::optional<int>& group)
      : CommandResult(CmdName)
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

    GetIntTxAWGNResult::GetIntTxAWGNResult(CommandBasePtr relatedCommand, bool enabled, double centralFreq, double power, double bandwidth, const std::string& transmitterId, const std::string& signalId, const Sdx::optional<int>& seed, const Sdx::optional<int>& group)
      : CommandResult(CmdName, relatedCommand)
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


    GetIntTxAWGNResultPtr GetIntTxAWGNResult::create(bool enabled, double centralFreq, double power, double bandwidth, const std::string& transmitterId, const std::string& signalId, const Sdx::optional<int>& seed, const Sdx::optional<int>& group)
    {
      return std::make_shared<GetIntTxAWGNResult>(enabled, centralFreq, power, bandwidth, transmitterId, signalId, seed, group);
    }

    GetIntTxAWGNResultPtr GetIntTxAWGNResult::create(CommandBasePtr relatedCommand, bool enabled, double centralFreq, double power, double bandwidth, const std::string& transmitterId, const std::string& signalId, const Sdx::optional<int>& seed, const Sdx::optional<int>& group)
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
          && parse_json<Sdx::optional<int>>::is_valid(m_values["Seed"])
          && parse_json<Sdx::optional<int>>::is_valid(m_values["Group"])
        ;

    }

    std::string GetIntTxAWGNResult::documentation() const { return Documentation; }


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



    Sdx::optional<int> GetIntTxAWGNResult::seed() const
    {
      return parse_json<Sdx::optional<int>>::parse(m_values["Seed"]);
    }

    void GetIntTxAWGNResult::setSeed(const Sdx::optional<int>& seed)
    {
      m_values.AddMember("Seed", parse_json<Sdx::optional<int>>::format(seed, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<int> GetIntTxAWGNResult::group() const
    {
      return parse_json<Sdx::optional<int>>::parse(m_values["Group"]);
    }

    void GetIntTxAWGNResult::setGroup(const Sdx::optional<int>& group)
    {
      m_values.AddMember("Group", parse_json<Sdx::optional<int>>::format(group, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

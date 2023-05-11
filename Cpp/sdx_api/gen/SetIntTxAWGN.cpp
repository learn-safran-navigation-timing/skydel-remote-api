
#include "gen/SetIntTxAWGN.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetIntTxAWGN
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetIntTxAWGN::CmdName = "SetIntTxAWGN";
    const char* const SetIntTxAWGN::Documentation = "Set AWGN signal interference.";

    REGISTER_COMMAND_FACTORY(SetIntTxAWGN);


    SetIntTxAWGN::SetIntTxAWGN()
      : CommandBase(CmdName)
    {}

    SetIntTxAWGN::SetIntTxAWGN(bool enabled, double centralFreq, double power, double bandwidth, const std::string& transmitterId, const std::string& signalId, const Sdx::optional<int>& seed, const Sdx::optional<int>& group)
      : CommandBase(CmdName)
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

    SetIntTxAWGNPtr SetIntTxAWGN::create(bool enabled, double centralFreq, double power, double bandwidth, const std::string& transmitterId, const std::string& signalId, const Sdx::optional<int>& seed, const Sdx::optional<int>& group)
    {
      return std::make_shared<SetIntTxAWGN>(enabled, centralFreq, power, bandwidth, transmitterId, signalId, seed, group);
    }

    SetIntTxAWGNPtr SetIntTxAWGN::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetIntTxAWGN>(ptr);
    }

    bool SetIntTxAWGN::isValid() const
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

    std::string SetIntTxAWGN::documentation() const { return Documentation; }


    int SetIntTxAWGN::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    bool SetIntTxAWGN::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void SetIntTxAWGN::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetIntTxAWGN::centralFreq() const
    {
      return parse_json<double>::parse(m_values["CentralFreq"]);
    }

    void SetIntTxAWGN::setCentralFreq(double centralFreq)
    {
      m_values.AddMember("CentralFreq", parse_json<double>::format(centralFreq, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetIntTxAWGN::power() const
    {
      return parse_json<double>::parse(m_values["Power"]);
    }

    void SetIntTxAWGN::setPower(double power)
    {
      m_values.AddMember("Power", parse_json<double>::format(power, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetIntTxAWGN::bandwidth() const
    {
      return parse_json<double>::parse(m_values["Bandwidth"]);
    }

    void SetIntTxAWGN::setBandwidth(double bandwidth)
    {
      m_values.AddMember("Bandwidth", parse_json<double>::format(bandwidth, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetIntTxAWGN::transmitterId() const
    {
      return parse_json<std::string>::parse(m_values["TransmitterId"]);
    }

    void SetIntTxAWGN::setTransmitterId(const std::string& transmitterId)
    {
      m_values.AddMember("TransmitterId", parse_json<std::string>::format(transmitterId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetIntTxAWGN::signalId() const
    {
      return parse_json<std::string>::parse(m_values["SignalId"]);
    }

    void SetIntTxAWGN::setSignalId(const std::string& signalId)
    {
      m_values.AddMember("SignalId", parse_json<std::string>::format(signalId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<int> SetIntTxAWGN::seed() const
    {
      return parse_json<Sdx::optional<int>>::parse(m_values["Seed"]);
    }

    void SetIntTxAWGN::setSeed(const Sdx::optional<int>& seed)
    {
      m_values.AddMember("Seed", parse_json<Sdx::optional<int>>::format(seed, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<int> SetIntTxAWGN::group() const
    {
      return parse_json<Sdx::optional<int>>::parse(m_values["Group"]);
    }

    void SetIntTxAWGN::setGroup(const Sdx::optional<int>& group)
    {
      m_values.AddMember("Group", parse_json<Sdx::optional<int>>::format(group, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

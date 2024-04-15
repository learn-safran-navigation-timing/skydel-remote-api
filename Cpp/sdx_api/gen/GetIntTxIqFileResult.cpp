
#include "GetIntTxIqFileResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIntTxIqFileResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIntTxIqFileResult::CmdName = "GetIntTxIqFileResult";
    const char* const GetIntTxIqFileResult::Documentation = "Result of GetIntTxIqFile.\n"
      "\n"
      "Name          Type         Description\n"
      "------------- ------------ ---------------------------------------------------\n"
      "Enabled       bool         Enable (true) or disable (false) the signal\n"
      "CentralFreq   double       Central frequency (Hz)\n"
      "Power         double       Power (dB), relative to transmitter reference power\n"
      "Path          string       Path to the file to play\n"
      "TransmitterId string       Transmitter unique identifier.\n"
      "SignalId      string       AWGN unique identifier.\n"
      "Group         optional int Group, if not using default group.";
    const char* const GetIntTxIqFileResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetIntTxIqFileResult);


    GetIntTxIqFileResult::GetIntTxIqFileResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetIntTxIqFileResult::GetIntTxIqFileResult(bool enabled, double centralFreq, double power, const std::string& path, const std::string& transmitterId, const std::string& signalId, const Sdx::optional<int>& group)
      : CommandResult(CmdName, TargetId)
    {

      setEnabled(enabled);
      setCentralFreq(centralFreq);
      setPower(power);
      setPath(path);
      setTransmitterId(transmitterId);
      setSignalId(signalId);
      setGroup(group);
    }

    GetIntTxIqFileResult::GetIntTxIqFileResult(CommandBasePtr relatedCommand, bool enabled, double centralFreq, double power, const std::string& path, const std::string& transmitterId, const std::string& signalId, const Sdx::optional<int>& group)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setEnabled(enabled);
      setCentralFreq(centralFreq);
      setPower(power);
      setPath(path);
      setTransmitterId(transmitterId);
      setSignalId(signalId);
      setGroup(group);
    }


    GetIntTxIqFileResultPtr GetIntTxIqFileResult::create(bool enabled, double centralFreq, double power, const std::string& path, const std::string& transmitterId, const std::string& signalId, const Sdx::optional<int>& group)
    {
      return std::make_shared<GetIntTxIqFileResult>(enabled, centralFreq, power, path, transmitterId, signalId, group);
    }

    GetIntTxIqFileResultPtr GetIntTxIqFileResult::create(CommandBasePtr relatedCommand, bool enabled, double centralFreq, double power, const std::string& path, const std::string& transmitterId, const std::string& signalId, const Sdx::optional<int>& group)
    {
      return std::make_shared<GetIntTxIqFileResult>(relatedCommand, enabled, centralFreq, power, path, transmitterId, signalId, group);
    }

    GetIntTxIqFileResultPtr GetIntTxIqFileResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetIntTxIqFileResult>(ptr);
    }

    bool GetIntTxIqFileResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enabled"])
          && parse_json<double>::is_valid(m_values["CentralFreq"])
          && parse_json<double>::is_valid(m_values["Power"])
          && parse_json<std::string>::is_valid(m_values["Path"])
          && parse_json<std::string>::is_valid(m_values["TransmitterId"])
          && parse_json<std::string>::is_valid(m_values["SignalId"])
          && parse_json<Sdx::optional<int>>::is_valid(m_values["Group"])
        ;

    }

    std::string GetIntTxIqFileResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetIntTxIqFileResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Enabled", "CentralFreq", "Power", "Path", "TransmitterId", "SignalId", "Group"}; 
      return names; 
    }


    bool GetIntTxIqFileResult::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void GetIntTxIqFileResult::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetIntTxIqFileResult::centralFreq() const
    {
      return parse_json<double>::parse(m_values["CentralFreq"]);
    }

    void GetIntTxIqFileResult::setCentralFreq(double centralFreq)
    {
      m_values.AddMember("CentralFreq", parse_json<double>::format(centralFreq, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetIntTxIqFileResult::power() const
    {
      return parse_json<double>::parse(m_values["Power"]);
    }

    void GetIntTxIqFileResult::setPower(double power)
    {
      m_values.AddMember("Power", parse_json<double>::format(power, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetIntTxIqFileResult::path() const
    {
      return parse_json<std::string>::parse(m_values["Path"]);
    }

    void GetIntTxIqFileResult::setPath(const std::string& path)
    {
      m_values.AddMember("Path", parse_json<std::string>::format(path, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetIntTxIqFileResult::transmitterId() const
    {
      return parse_json<std::string>::parse(m_values["TransmitterId"]);
    }

    void GetIntTxIqFileResult::setTransmitterId(const std::string& transmitterId)
    {
      m_values.AddMember("TransmitterId", parse_json<std::string>::format(transmitterId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetIntTxIqFileResult::signalId() const
    {
      return parse_json<std::string>::parse(m_values["SignalId"]);
    }

    void GetIntTxIqFileResult::setSignalId(const std::string& signalId)
    {
      m_values.AddMember("SignalId", parse_json<std::string>::format(signalId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<int> GetIntTxIqFileResult::group() const
    {
      return parse_json<Sdx::optional<int>>::parse(m_values["Group"]);
    }

    void GetIntTxIqFileResult::setGroup(const Sdx::optional<int>& group)
    {
      m_values.AddMember("Group", parse_json<Sdx::optional<int>>::format(group, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}


#include "SetIntTxIqFile.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetIntTxIqFile
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetIntTxIqFile::CmdName = "SetIntTxIqFile";
    const char* const SetIntTxIqFile::Documentation = "Set IQ file signal interference.\n"
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
    const char* const SetIntTxIqFile::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetIntTxIqFile);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetIntTxIqFile);


    SetIntTxIqFile::SetIntTxIqFile()
      : CommandBase(CmdName, TargetId)
    {}

    SetIntTxIqFile::SetIntTxIqFile(bool enabled, double centralFreq, double power, const std::string& path, const std::string& transmitterId, const std::string& signalId, const std::optional<int>& group)
      : CommandBase(CmdName, TargetId)
    {

      setEnabled(enabled);
      setCentralFreq(centralFreq);
      setPower(power);
      setPath(path);
      setTransmitterId(transmitterId);
      setSignalId(signalId);
      setGroup(group);
    }

    SetIntTxIqFilePtr SetIntTxIqFile::create(bool enabled, double centralFreq, double power, const std::string& path, const std::string& transmitterId, const std::string& signalId, const std::optional<int>& group)
    {
      return std::make_shared<SetIntTxIqFile>(enabled, centralFreq, power, path, transmitterId, signalId, group);
    }

    SetIntTxIqFilePtr SetIntTxIqFile::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetIntTxIqFile>(ptr);
    }

    bool SetIntTxIqFile::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enabled"])
          && parse_json<double>::is_valid(m_values["CentralFreq"])
          && parse_json<double>::is_valid(m_values["Power"])
          && parse_json<std::string>::is_valid(m_values["Path"])
          && parse_json<std::string>::is_valid(m_values["TransmitterId"])
          && parse_json<std::string>::is_valid(m_values["SignalId"])
          && parse_json<std::optional<int>>::is_valid(m_values["Group"])
        ;

    }

    std::string SetIntTxIqFile::documentation() const { return Documentation; }

    const std::vector<std::string>& SetIntTxIqFile::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Enabled", "CentralFreq", "Power", "Path", "TransmitterId", "SignalId", "Group"}; 
      return names; 
    }


    int SetIntTxIqFile::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    bool SetIntTxIqFile::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void SetIntTxIqFile::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetIntTxIqFile::centralFreq() const
    {
      return parse_json<double>::parse(m_values["CentralFreq"]);
    }

    void SetIntTxIqFile::setCentralFreq(double centralFreq)
    {
      m_values.AddMember("CentralFreq", parse_json<double>::format(centralFreq, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetIntTxIqFile::power() const
    {
      return parse_json<double>::parse(m_values["Power"]);
    }

    void SetIntTxIqFile::setPower(double power)
    {
      m_values.AddMember("Power", parse_json<double>::format(power, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetIntTxIqFile::path() const
    {
      return parse_json<std::string>::parse(m_values["Path"]);
    }

    void SetIntTxIqFile::setPath(const std::string& path)
    {
      m_values.AddMember("Path", parse_json<std::string>::format(path, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetIntTxIqFile::transmitterId() const
    {
      return parse_json<std::string>::parse(m_values["TransmitterId"]);
    }

    void SetIntTxIqFile::setTransmitterId(const std::string& transmitterId)
    {
      m_values.AddMember("TransmitterId", parse_json<std::string>::format(transmitterId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetIntTxIqFile::signalId() const
    {
      return parse_json<std::string>::parse(m_values["SignalId"]);
    }

    void SetIntTxIqFile::setSignalId(const std::string& signalId)
    {
      m_values.AddMember("SignalId", parse_json<std::string>::format(signalId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<int> SetIntTxIqFile::group() const
    {
      return parse_json<std::optional<int>>::parse(m_values["Group"]);
    }

    void SetIntTxIqFile::setGroup(const std::optional<int>& group)
    {
      m_values.AddMember("Group", parse_json<std::optional<int>>::format(group, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

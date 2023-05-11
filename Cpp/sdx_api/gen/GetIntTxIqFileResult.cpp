
#include "gen/GetIntTxIqFileResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIntTxIqFileResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIntTxIqFileResult::CmdName = "GetIntTxIqFileResult";
    const char* const GetIntTxIqFileResult::Documentation = "Result of GetIntTxIqFile.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetIntTxIqFileResult);


    GetIntTxIqFileResult::GetIntTxIqFileResult()
      : CommandResult(CmdName)
    {}

    GetIntTxIqFileResult::GetIntTxIqFileResult(bool enabled, double centralFreq, double power, const std::string& path, const std::string& transmitterId, const std::string& signalId, const Sdx::optional<int>& group)
      : CommandResult(CmdName)
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
      : CommandResult(CmdName, relatedCommand)
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

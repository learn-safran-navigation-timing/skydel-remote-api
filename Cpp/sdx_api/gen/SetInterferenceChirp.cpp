
#include "gen/SetInterferenceChirp.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetInterferenceChirp
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetInterferenceChirp::CmdName = "SetInterferenceChirp";
    const char* const SetInterferenceChirp::Documentation = "Add or update chirp signal interference.";

    REGISTER_COMMAND_FACTORY(SetInterferenceChirp);


    SetInterferenceChirp::SetInterferenceChirp()
      : CommandBase(CmdName)
    {}

    SetInterferenceChirp::SetInterferenceChirp(int startTime, int stopTime, double centralFreq, double power, double bandwidth, double sweepTime, bool enabled, const std::string& id)
      : CommandBase(CmdName)
    {

      setStartTime(startTime);
      setStopTime(stopTime);
      setCentralFreq(centralFreq);
      setPower(power);
      setBandwidth(bandwidth);
      setSweepTime(sweepTime);
      setEnabled(enabled);
      setId(id);
    }

    SetInterferenceChirpPtr SetInterferenceChirp::create(int startTime, int stopTime, double centralFreq, double power, double bandwidth, double sweepTime, bool enabled, const std::string& id)
    {
      return std::make_shared<SetInterferenceChirp>(startTime, stopTime, centralFreq, power, bandwidth, sweepTime, enabled, id);
    }

    SetInterferenceChirpPtr SetInterferenceChirp::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetInterferenceChirp>(ptr);
    }

    bool SetInterferenceChirp::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["StartTime"])
          && parse_json<int>::is_valid(m_values["StopTime"])
          && parse_json<double>::is_valid(m_values["CentralFreq"])
          && parse_json<double>::is_valid(m_values["Power"])
          && parse_json<double>::is_valid(m_values["Bandwidth"])
          && parse_json<double>::is_valid(m_values["SweepTime"])
          && parse_json<bool>::is_valid(m_values["Enabled"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string SetInterferenceChirp::documentation() const { return Documentation; }


    int SetInterferenceChirp::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetInterferenceChirp::startTime() const
    {
      return parse_json<int>::parse(m_values["StartTime"]);
    }

    void SetInterferenceChirp::setStartTime(int startTime)
    {
      m_values.AddMember("StartTime", parse_json<int>::format(startTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetInterferenceChirp::stopTime() const
    {
      return parse_json<int>::parse(m_values["StopTime"]);
    }

    void SetInterferenceChirp::setStopTime(int stopTime)
    {
      m_values.AddMember("StopTime", parse_json<int>::format(stopTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetInterferenceChirp::centralFreq() const
    {
      return parse_json<double>::parse(m_values["CentralFreq"]);
    }

    void SetInterferenceChirp::setCentralFreq(double centralFreq)
    {
      m_values.AddMember("CentralFreq", parse_json<double>::format(centralFreq, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetInterferenceChirp::power() const
    {
      return parse_json<double>::parse(m_values["Power"]);
    }

    void SetInterferenceChirp::setPower(double power)
    {
      m_values.AddMember("Power", parse_json<double>::format(power, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetInterferenceChirp::bandwidth() const
    {
      return parse_json<double>::parse(m_values["Bandwidth"]);
    }

    void SetInterferenceChirp::setBandwidth(double bandwidth)
    {
      m_values.AddMember("Bandwidth", parse_json<double>::format(bandwidth, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetInterferenceChirp::sweepTime() const
    {
      return parse_json<double>::parse(m_values["SweepTime"]);
    }

    void SetInterferenceChirp::setSweepTime(double sweepTime)
    {
      m_values.AddMember("SweepTime", parse_json<double>::format(sweepTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetInterferenceChirp::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void SetInterferenceChirp::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetInterferenceChirp::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void SetInterferenceChirp::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}


#include "SetInterferenceChirp.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetInterferenceChirp
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetInterferenceChirp::CmdName = "SetInterferenceChirp";
    const char* const SetInterferenceChirp::Documentation = "Add or update chirp signal interference signal.\n"
      "\n"
      "Name        Type   Description\n"
      "----------- ------ -------------------------------------------------------------------------------------------------------------------------\n"
      "StartTime   int    Elapsed time at which the signal is enabled (s). Minimum = 0 s, Maximum = 86399 s (23 hours, 59 minutes and 59 seconds).\n"
      "StopTime    int    Elapsed time at which the signal is disabled (s). Minimum = 0 s, Maximum = 86399 s (23 hours, 59 minutes and 59 seconds).\n"
      "CentralFreq double Central frequency (Hz). Minimum = 100000000 Hz (100 MHz), Maximum = 6000000000 Hz (6 GHz).\n"
      "Power       double Power (dB) relative to nominal power. Minimum = -40 dB, Maximum = 43 dB.\n"
      "Bandwidth   double Bandwidth (Hz). Minimum = 1000 Hz (1 kHz), Maximum = 40000000 Hz (40 MHz).\n"
      "SweepTime   double Sweep time (s). Minimum = 0.000005 s (5 us), Maximum = 0.000500 s (500 us).\n"
      "Enabled     bool   Enables or disables the interference signal.\n"
      "Id          string Interference signal unique identifier.";
    const char* const SetInterferenceChirp::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetInterferenceChirp);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetInterferenceChirp);


    SetInterferenceChirp::SetInterferenceChirp()
      : CommandBase(CmdName, TargetId)
    {}

    SetInterferenceChirp::SetInterferenceChirp(int startTime, int stopTime, double centralFreq, double power, double bandwidth, double sweepTime, bool enabled, const std::string& id)
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& SetInterferenceChirp::fieldNames() const 
    { 
      static const std::vector<std::string> names {"StartTime", "StopTime", "CentralFreq", "Power", "Bandwidth", "SweepTime", "Enabled", "Id"}; 
      return names; 
    }


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

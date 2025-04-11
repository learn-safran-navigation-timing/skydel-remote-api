
#include "SetInterferenceAWGN.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetInterferenceAWGN
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetInterferenceAWGN::CmdName = "SetInterferenceAWGN";
    const char* const SetInterferenceAWGN::Documentation = "Add or update an AWGN interference signal.\n"
      "\n"
      "Name        Type         Description\n"
      "----------- ------------ --------------------------------------------------------------------------------------------------------------------------------------------\n"
      "StartTime   int          Elapsed time at which the signal is enabled (s). Minimum = 0 s, Maximum = 86399 s (23 hours, 59 minutes and 59 seconds).\n"
      "StopTime    int          Elapsed time at which the signal is disabled (s). Minimum = 0 s, Maximum = 86399 s (23 hours, 59 minutes and 59 seconds).\n"
      "CentralFreq double       Central frequency (Hz). Minimum = 100000000 Hz (100 MHz), Maximum = 6000000000 Hz (6 GHz).\n"
      "Power       double       Power (dB) relative to nominal power. Minimum = -40 dB, Maximum = 43 dB.\n"
      "Bandwidth   double       Bandwidth (Hz). Minimum = 1000 Hz (1 kHz), Maximum = 40000000 Hz (40 MHz).\n"
      "Enabled     bool         Enables or disables the interference signal.\n"
      "Id          string       Interference signal unique identifier.\n"
      "Seed        optional int Seed used to initialize the random number generator. Signals with the same seed will have the same shape. Minimum = 0, Maximum = 4294967295.";
    const char* const SetInterferenceAWGN::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetInterferenceAWGN);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetInterferenceAWGN);


    SetInterferenceAWGN::SetInterferenceAWGN()
      : CommandBase(CmdName, TargetId)
    {}

    SetInterferenceAWGN::SetInterferenceAWGN(int startTime, int stopTime, double centralFreq, double power, double bandwidth, bool enabled, const std::string& id, const std::optional<int>& seed)
      : CommandBase(CmdName, TargetId)
    {

      setStartTime(startTime);
      setStopTime(stopTime);
      setCentralFreq(centralFreq);
      setPower(power);
      setBandwidth(bandwidth);
      setEnabled(enabled);
      setId(id);
      setSeed(seed);
    }

    SetInterferenceAWGNPtr SetInterferenceAWGN::create(int startTime, int stopTime, double centralFreq, double power, double bandwidth, bool enabled, const std::string& id, const std::optional<int>& seed)
    {
      return std::make_shared<SetInterferenceAWGN>(startTime, stopTime, centralFreq, power, bandwidth, enabled, id, seed);
    }

    SetInterferenceAWGNPtr SetInterferenceAWGN::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetInterferenceAWGN>(ptr);
    }

    bool SetInterferenceAWGN::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["StartTime"])
          && parse_json<int>::is_valid(m_values["StopTime"])
          && parse_json<double>::is_valid(m_values["CentralFreq"])
          && parse_json<double>::is_valid(m_values["Power"])
          && parse_json<double>::is_valid(m_values["Bandwidth"])
          && parse_json<bool>::is_valid(m_values["Enabled"])
          && parse_json<std::string>::is_valid(m_values["Id"])
          && parse_json<std::optional<int>>::is_valid(m_values["Seed"])
        ;

    }

    std::string SetInterferenceAWGN::documentation() const { return Documentation; }

    const std::vector<std::string>& SetInterferenceAWGN::fieldNames() const 
    { 
      static const std::vector<std::string> names {"StartTime", "StopTime", "CentralFreq", "Power", "Bandwidth", "Enabled", "Id", "Seed"}; 
      return names; 
    }


    int SetInterferenceAWGN::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetInterferenceAWGN::startTime() const
    {
      return parse_json<int>::parse(m_values["StartTime"]);
    }

    void SetInterferenceAWGN::setStartTime(int startTime)
    {
      m_values.AddMember("StartTime", parse_json<int>::format(startTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetInterferenceAWGN::stopTime() const
    {
      return parse_json<int>::parse(m_values["StopTime"]);
    }

    void SetInterferenceAWGN::setStopTime(int stopTime)
    {
      m_values.AddMember("StopTime", parse_json<int>::format(stopTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetInterferenceAWGN::centralFreq() const
    {
      return parse_json<double>::parse(m_values["CentralFreq"]);
    }

    void SetInterferenceAWGN::setCentralFreq(double centralFreq)
    {
      m_values.AddMember("CentralFreq", parse_json<double>::format(centralFreq, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetInterferenceAWGN::power() const
    {
      return parse_json<double>::parse(m_values["Power"]);
    }

    void SetInterferenceAWGN::setPower(double power)
    {
      m_values.AddMember("Power", parse_json<double>::format(power, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetInterferenceAWGN::bandwidth() const
    {
      return parse_json<double>::parse(m_values["Bandwidth"]);
    }

    void SetInterferenceAWGN::setBandwidth(double bandwidth)
    {
      m_values.AddMember("Bandwidth", parse_json<double>::format(bandwidth, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetInterferenceAWGN::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void SetInterferenceAWGN::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetInterferenceAWGN::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void SetInterferenceAWGN::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<int> SetInterferenceAWGN::seed() const
    {
      return parse_json<std::optional<int>>::parse(m_values["Seed"]);
    }

    void SetInterferenceAWGN::setSeed(const std::optional<int>& seed)
    {
      m_values.AddMember("Seed", parse_json<std::optional<int>>::format(seed, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

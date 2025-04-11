
#include "SetInterferenceCW.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetInterferenceCW
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetInterferenceCW::CmdName = "SetInterferenceCW";
    const char* const SetInterferenceCW::Documentation = "Add or update continuous wave interference signal.\n"
      "\n"
      "Name        Type   Description\n"
      "----------- ------ -------------------------------------------------------------------------------------------------------------------------\n"
      "StartTime   int    Elapsed time at which the signal is enabled (s). Minimum = 0 s, Maximum = 86399 s (23 hours, 59 minutes and 59 seconds).\n"
      "StopTime    int    Elapsed time at which the signal is disabled (s). Minimum = 0 s, Maximum = 86399 s (23 hours, 59 minutes and 59 seconds).\n"
      "CentralFreq double Central frequency (Hz). Minimum = 100000000 Hz (100 MHz), Maximum = 6000000000 Hz (6 GHz).\n"
      "Power       double Power (dB) relative to nominal power. Minimum = -40 dB, Maximum = 43 dB.\n"
      "Enabled     bool   Enables or disables the interference signal.\n"
      "Id          string Interference signal unique identifier.";
    const char* const SetInterferenceCW::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetInterferenceCW);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetInterferenceCW);


    SetInterferenceCW::SetInterferenceCW()
      : CommandBase(CmdName, TargetId)
    {}

    SetInterferenceCW::SetInterferenceCW(int startTime, int stopTime, double centralFreq, double power, bool enabled, const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setStartTime(startTime);
      setStopTime(stopTime);
      setCentralFreq(centralFreq);
      setPower(power);
      setEnabled(enabled);
      setId(id);
    }

    SetInterferenceCWPtr SetInterferenceCW::create(int startTime, int stopTime, double centralFreq, double power, bool enabled, const std::string& id)
    {
      return std::make_shared<SetInterferenceCW>(startTime, stopTime, centralFreq, power, enabled, id);
    }

    SetInterferenceCWPtr SetInterferenceCW::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetInterferenceCW>(ptr);
    }

    bool SetInterferenceCW::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["StartTime"])
          && parse_json<int>::is_valid(m_values["StopTime"])
          && parse_json<double>::is_valid(m_values["CentralFreq"])
          && parse_json<double>::is_valid(m_values["Power"])
          && parse_json<bool>::is_valid(m_values["Enabled"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string SetInterferenceCW::documentation() const { return Documentation; }

    const std::vector<std::string>& SetInterferenceCW::fieldNames() const 
    { 
      static const std::vector<std::string> names {"StartTime", "StopTime", "CentralFreq", "Power", "Enabled", "Id"}; 
      return names; 
    }


    int SetInterferenceCW::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetInterferenceCW::startTime() const
    {
      return parse_json<int>::parse(m_values["StartTime"]);
    }

    void SetInterferenceCW::setStartTime(int startTime)
    {
      m_values.AddMember("StartTime", parse_json<int>::format(startTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetInterferenceCW::stopTime() const
    {
      return parse_json<int>::parse(m_values["StopTime"]);
    }

    void SetInterferenceCW::setStopTime(int stopTime)
    {
      m_values.AddMember("StopTime", parse_json<int>::format(stopTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetInterferenceCW::centralFreq() const
    {
      return parse_json<double>::parse(m_values["CentralFreq"]);
    }

    void SetInterferenceCW::setCentralFreq(double centralFreq)
    {
      m_values.AddMember("CentralFreq", parse_json<double>::format(centralFreq, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetInterferenceCW::power() const
    {
      return parse_json<double>::parse(m_values["Power"]);
    }

    void SetInterferenceCW::setPower(double power)
    {
      m_values.AddMember("Power", parse_json<double>::format(power, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetInterferenceCW::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void SetInterferenceCW::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetInterferenceCW::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void SetInterferenceCW::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

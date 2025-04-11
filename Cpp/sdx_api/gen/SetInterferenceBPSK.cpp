
#include "SetInterferenceBPSK.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetInterferenceBPSK
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetInterferenceBPSK::CmdName = "SetInterferenceBPSK";
    const char* const SetInterferenceBPSK::Documentation = "Add or update a BPSK interference signal.\n"
      "\n"
      "Name         Type         Description\n"
      "------------ ------------ -------------------------------------------------------------------------------------------------------------------------------------\n"
      "StartTime    int          Elapsed time at which the signal is enabled (s). Minimum = 0 s, Maximum = 86399 s (23 hours, 59 minutes and 59 seconds).\n"
      "StopTime     int          Elapsed time at which the signal is disabled (s). Minimum = 0 s, Maximum = 86399 s (23 hours, 59 minutes and 59 seconds).\n"
      "CentralFreq  double       Central frequency (Hz). Minimum = 100000000 Hz (100 MHz), Maximum = 6000000000 Hz (6 GHz).\n"
      "Power        double       Power (dB) relative to nominal power. Minimum = -40 dB, Maximum = 43 dB.\n"
      "CodeRate     int          Code rate (Chips/s). Must be a multiple of 1 kChips/s. Minimum = 1000 Chips/s (1 kChips/s), Maximum = 60000000 Chips/s (60 MChips/s).\n"
      "CodeLengthMs int          Code length (ms). Minimum = 1 ms, Maximum = 100 ms.\n"
      "Enabled      bool         Enables or disables the interference signal.\n"
      "Id           string       Interference signal unique identifier.\n"
      "Prn          optional int PRN code index to use in the BPSK modulation. If zero, a random code will be used. Minimum = 0, Maximum = 32.";
    const char* const SetInterferenceBPSK::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetInterferenceBPSK);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetInterferenceBPSK);


    SetInterferenceBPSK::SetInterferenceBPSK()
      : CommandBase(CmdName, TargetId)
    {}

    SetInterferenceBPSK::SetInterferenceBPSK(int startTime, int stopTime, double centralFreq, double power, int codeRate, int codeLengthMs, bool enabled, const std::string& id, const std::optional<int>& prn)
      : CommandBase(CmdName, TargetId)
    {

      setStartTime(startTime);
      setStopTime(stopTime);
      setCentralFreq(centralFreq);
      setPower(power);
      setCodeRate(codeRate);
      setCodeLengthMs(codeLengthMs);
      setEnabled(enabled);
      setId(id);
      setPrn(prn);
    }

    SetInterferenceBPSKPtr SetInterferenceBPSK::create(int startTime, int stopTime, double centralFreq, double power, int codeRate, int codeLengthMs, bool enabled, const std::string& id, const std::optional<int>& prn)
    {
      return std::make_shared<SetInterferenceBPSK>(startTime, stopTime, centralFreq, power, codeRate, codeLengthMs, enabled, id, prn);
    }

    SetInterferenceBPSKPtr SetInterferenceBPSK::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetInterferenceBPSK>(ptr);
    }

    bool SetInterferenceBPSK::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["StartTime"])
          && parse_json<int>::is_valid(m_values["StopTime"])
          && parse_json<double>::is_valid(m_values["CentralFreq"])
          && parse_json<double>::is_valid(m_values["Power"])
          && parse_json<int>::is_valid(m_values["CodeRate"])
          && parse_json<int>::is_valid(m_values["CodeLengthMs"])
          && parse_json<bool>::is_valid(m_values["Enabled"])
          && parse_json<std::string>::is_valid(m_values["Id"])
          && parse_json<std::optional<int>>::is_valid(m_values["Prn"])
        ;

    }

    std::string SetInterferenceBPSK::documentation() const { return Documentation; }

    const std::vector<std::string>& SetInterferenceBPSK::fieldNames() const 
    { 
      static const std::vector<std::string> names {"StartTime", "StopTime", "CentralFreq", "Power", "CodeRate", "CodeLengthMs", "Enabled", "Id", "Prn"}; 
      return names; 
    }


    int SetInterferenceBPSK::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetInterferenceBPSK::startTime() const
    {
      return parse_json<int>::parse(m_values["StartTime"]);
    }

    void SetInterferenceBPSK::setStartTime(int startTime)
    {
      m_values.AddMember("StartTime", parse_json<int>::format(startTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetInterferenceBPSK::stopTime() const
    {
      return parse_json<int>::parse(m_values["StopTime"]);
    }

    void SetInterferenceBPSK::setStopTime(int stopTime)
    {
      m_values.AddMember("StopTime", parse_json<int>::format(stopTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetInterferenceBPSK::centralFreq() const
    {
      return parse_json<double>::parse(m_values["CentralFreq"]);
    }

    void SetInterferenceBPSK::setCentralFreq(double centralFreq)
    {
      m_values.AddMember("CentralFreq", parse_json<double>::format(centralFreq, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetInterferenceBPSK::power() const
    {
      return parse_json<double>::parse(m_values["Power"]);
    }

    void SetInterferenceBPSK::setPower(double power)
    {
      m_values.AddMember("Power", parse_json<double>::format(power, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetInterferenceBPSK::codeRate() const
    {
      return parse_json<int>::parse(m_values["CodeRate"]);
    }

    void SetInterferenceBPSK::setCodeRate(int codeRate)
    {
      m_values.AddMember("CodeRate", parse_json<int>::format(codeRate, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetInterferenceBPSK::codeLengthMs() const
    {
      return parse_json<int>::parse(m_values["CodeLengthMs"]);
    }

    void SetInterferenceBPSK::setCodeLengthMs(int codeLengthMs)
    {
      m_values.AddMember("CodeLengthMs", parse_json<int>::format(codeLengthMs, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetInterferenceBPSK::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void SetInterferenceBPSK::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetInterferenceBPSK::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void SetInterferenceBPSK::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<int> SetInterferenceBPSK::prn() const
    {
      return parse_json<std::optional<int>>::parse(m_values["Prn"]);
    }

    void SetInterferenceBPSK::setPrn(const std::optional<int>& prn)
    {
      m_values.AddMember("Prn", parse_json<std::optional<int>>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

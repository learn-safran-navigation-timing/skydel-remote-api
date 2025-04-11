
#include "SetInterferenceBOC.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetInterferenceBOC
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetInterferenceBOC::CmdName = "SetInterferenceBOC";
    const char* const SetInterferenceBOC::Documentation = "Add or update a BOC interference signal.\n"
      "\n"
      "Name           Type   Description\n"
      "-------------- ------ -------------------------------------------------------------------------------------------------------------------------------------\n"
      "StartTime      int    Elapsed time at which the signal is enabled (s). Minimum = 0 s, Maximum = 86399 s (23 hours, 59 minutes and 59 seconds).\n"
      "StopTime       int    Elapsed time at which the signal is disabled (s). Minimum = 0 s, Maximum = 86399 s (23 hours, 59 minutes and 59 seconds).\n"
      "CentralFreq    double Central frequency (Hz). Minimum = 100000000 Hz (100 MHz), Maximum = 6000000000 Hz (6 GHz).\n"
      "Power          double Power (dB) relative to nominal power. Minimum = -40 dB, Maximum = 43 dB.\n"
      "CodeRate       int    Code rate (Chips/s). Must be a multiple of 1 kChips/s. Minimum = 1000 Chips/s (1 kChips/s), Maximum = 60000000 Chips/s (60 MChips/s).\n"
      "CodeLengthMs   int    Code length (ms). Minimum = 1 ms, Maximum = 100 ms.\n"
      "SubCarrierRate int    Sub-carrier rate (Hz). Must be a multiple of 1 kHz. Minimum = 1000 Hz (1 kHz), Maximum = 60000000 (60 MHz).\n"
      "CosinePhaseBoc bool   Use Cosine-Phase BOC instead of default Sine-Phase BOC.\n"
      "Enabled        bool   Enables or disables the interference signal.\n"
      "Id             string Interference signal unique identifier.";
    const char* const SetInterferenceBOC::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetInterferenceBOC);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetInterferenceBOC);


    SetInterferenceBOC::SetInterferenceBOC()
      : CommandBase(CmdName, TargetId)
    {}

    SetInterferenceBOC::SetInterferenceBOC(int startTime, int stopTime, double centralFreq, double power, int codeRate, int codeLengthMs, int subCarrierRate, bool cosinePhaseBoc, bool enabled, const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setStartTime(startTime);
      setStopTime(stopTime);
      setCentralFreq(centralFreq);
      setPower(power);
      setCodeRate(codeRate);
      setCodeLengthMs(codeLengthMs);
      setSubCarrierRate(subCarrierRate);
      setCosinePhaseBoc(cosinePhaseBoc);
      setEnabled(enabled);
      setId(id);
    }

    SetInterferenceBOCPtr SetInterferenceBOC::create(int startTime, int stopTime, double centralFreq, double power, int codeRate, int codeLengthMs, int subCarrierRate, bool cosinePhaseBoc, bool enabled, const std::string& id)
    {
      return std::make_shared<SetInterferenceBOC>(startTime, stopTime, centralFreq, power, codeRate, codeLengthMs, subCarrierRate, cosinePhaseBoc, enabled, id);
    }

    SetInterferenceBOCPtr SetInterferenceBOC::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetInterferenceBOC>(ptr);
    }

    bool SetInterferenceBOC::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["StartTime"])
          && parse_json<int>::is_valid(m_values["StopTime"])
          && parse_json<double>::is_valid(m_values["CentralFreq"])
          && parse_json<double>::is_valid(m_values["Power"])
          && parse_json<int>::is_valid(m_values["CodeRate"])
          && parse_json<int>::is_valid(m_values["CodeLengthMs"])
          && parse_json<int>::is_valid(m_values["SubCarrierRate"])
          && parse_json<bool>::is_valid(m_values["CosinePhaseBoc"])
          && parse_json<bool>::is_valid(m_values["Enabled"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string SetInterferenceBOC::documentation() const { return Documentation; }

    const std::vector<std::string>& SetInterferenceBOC::fieldNames() const 
    { 
      static const std::vector<std::string> names {"StartTime", "StopTime", "CentralFreq", "Power", "CodeRate", "CodeLengthMs", "SubCarrierRate", "CosinePhaseBoc", "Enabled", "Id"}; 
      return names; 
    }


    int SetInterferenceBOC::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetInterferenceBOC::startTime() const
    {
      return parse_json<int>::parse(m_values["StartTime"]);
    }

    void SetInterferenceBOC::setStartTime(int startTime)
    {
      m_values.AddMember("StartTime", parse_json<int>::format(startTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetInterferenceBOC::stopTime() const
    {
      return parse_json<int>::parse(m_values["StopTime"]);
    }

    void SetInterferenceBOC::setStopTime(int stopTime)
    {
      m_values.AddMember("StopTime", parse_json<int>::format(stopTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetInterferenceBOC::centralFreq() const
    {
      return parse_json<double>::parse(m_values["CentralFreq"]);
    }

    void SetInterferenceBOC::setCentralFreq(double centralFreq)
    {
      m_values.AddMember("CentralFreq", parse_json<double>::format(centralFreq, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetInterferenceBOC::power() const
    {
      return parse_json<double>::parse(m_values["Power"]);
    }

    void SetInterferenceBOC::setPower(double power)
    {
      m_values.AddMember("Power", parse_json<double>::format(power, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetInterferenceBOC::codeRate() const
    {
      return parse_json<int>::parse(m_values["CodeRate"]);
    }

    void SetInterferenceBOC::setCodeRate(int codeRate)
    {
      m_values.AddMember("CodeRate", parse_json<int>::format(codeRate, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetInterferenceBOC::codeLengthMs() const
    {
      return parse_json<int>::parse(m_values["CodeLengthMs"]);
    }

    void SetInterferenceBOC::setCodeLengthMs(int codeLengthMs)
    {
      m_values.AddMember("CodeLengthMs", parse_json<int>::format(codeLengthMs, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetInterferenceBOC::subCarrierRate() const
    {
      return parse_json<int>::parse(m_values["SubCarrierRate"]);
    }

    void SetInterferenceBOC::setSubCarrierRate(int subCarrierRate)
    {
      m_values.AddMember("SubCarrierRate", parse_json<int>::format(subCarrierRate, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetInterferenceBOC::cosinePhaseBoc() const
    {
      return parse_json<bool>::parse(m_values["CosinePhaseBoc"]);
    }

    void SetInterferenceBOC::setCosinePhaseBoc(bool cosinePhaseBoc)
    {
      m_values.AddMember("CosinePhaseBoc", parse_json<bool>::format(cosinePhaseBoc, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetInterferenceBOC::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void SetInterferenceBOC::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetInterferenceBOC::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void SetInterferenceBOC::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

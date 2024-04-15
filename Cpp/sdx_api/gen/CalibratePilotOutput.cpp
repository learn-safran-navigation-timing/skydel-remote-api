
#include "CalibratePilotOutput.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of CalibratePilotOutput
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const CalibratePilotOutput::CmdName = "CalibratePilotOutput";
    const char* const CalibratePilotOutput::Documentation = "Calibrate a pilot output\n"
      "\n"
      "Name         Type   Description\n"
      "------------ ------ ---------------------------------------------------\n"
      "OutputIdx    int    RF Output index (zero-based)\n"
      "Power        double Power (dB), relative to transmitter reference power\n"
      "Time         double Code time offset in second\n"
      "CarrierPhase double Carrier phase offset in radians";
    const char* const CalibratePilotOutput::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(CalibratePilotOutput);
    REGISTER_COMMAND_TO_FACTORY_IMPL(CalibratePilotOutput);


    CalibratePilotOutput::CalibratePilotOutput()
      : CommandBase(CmdName, TargetId)
    {}

    CalibratePilotOutput::CalibratePilotOutput(int outputIdx, double power, double time, double carrierPhase)
      : CommandBase(CmdName, TargetId)
    {

      setOutputIdx(outputIdx);
      setPower(power);
      setTime(time);
      setCarrierPhase(carrierPhase);
    }

    CalibratePilotOutputPtr CalibratePilotOutput::create(int outputIdx, double power, double time, double carrierPhase)
    {
      return std::make_shared<CalibratePilotOutput>(outputIdx, power, time, carrierPhase);
    }

    CalibratePilotOutputPtr CalibratePilotOutput::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<CalibratePilotOutput>(ptr);
    }

    bool CalibratePilotOutput::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["OutputIdx"])
          && parse_json<double>::is_valid(m_values["Power"])
          && parse_json<double>::is_valid(m_values["Time"])
          && parse_json<double>::is_valid(m_values["CarrierPhase"])
        ;

    }

    std::string CalibratePilotOutput::documentation() const { return Documentation; }

    const std::vector<std::string>& CalibratePilotOutput::fieldNames() const 
    { 
      static const std::vector<std::string> names {"OutputIdx", "Power", "Time", "CarrierPhase"}; 
      return names; 
    }


    int CalibratePilotOutput::executePermission() const
    {
      return EXECUTE_IF_SIMULATING;
    }


    int CalibratePilotOutput::outputIdx() const
    {
      return parse_json<int>::parse(m_values["OutputIdx"]);
    }

    void CalibratePilotOutput::setOutputIdx(int outputIdx)
    {
      m_values.AddMember("OutputIdx", parse_json<int>::format(outputIdx, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double CalibratePilotOutput::power() const
    {
      return parse_json<double>::parse(m_values["Power"]);
    }

    void CalibratePilotOutput::setPower(double power)
    {
      m_values.AddMember("Power", parse_json<double>::format(power, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double CalibratePilotOutput::time() const
    {
      return parse_json<double>::parse(m_values["Time"]);
    }

    void CalibratePilotOutput::setTime(double time)
    {
      m_values.AddMember("Time", parse_json<double>::format(time, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double CalibratePilotOutput::carrierPhase() const
    {
      return parse_json<double>::parse(m_values["CarrierPhase"]);
    }

    void CalibratePilotOutput::setCarrierPhase(double carrierPhase)
    {
      m_values.AddMember("CarrierPhase", parse_json<double>::format(carrierPhase, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

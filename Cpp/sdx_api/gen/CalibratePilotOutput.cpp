
#include "gen/CalibratePilotOutput.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of CalibratePilotOutput
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const CalibratePilotOutput::CmdName = "CalibratePilotOutput";
    const char* const CalibratePilotOutput::Documentation = "Calibrate a pilot output";

    REGISTER_COMMAND_FACTORY(CalibratePilotOutput);


    CalibratePilotOutput::CalibratePilotOutput()
      : CommandBase(CmdName)
    {}

    CalibratePilotOutput::CalibratePilotOutput(int outputIdx, double power, double time, double carrierPhase)
      : CommandBase(CmdName)
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

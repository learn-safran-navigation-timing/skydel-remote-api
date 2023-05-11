
#include "gen/SetRfGain.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetRfGain
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetRfGain::CmdName = "SetRfGain";
    const char* const SetRfGain::Documentation = "USE AT YOUR OWN RISKS. Set the RF Gain of the SDR";

    REGISTER_COMMAND_FACTORY(SetRfGain);


    SetRfGain::SetRfGain()
      : CommandBase(CmdName)
    {}

    SetRfGain::SetRfGain(int output, double gain)
      : CommandBase(CmdName)
    {

      setOutput(output);
      setGain(gain);
    }

    SetRfGainPtr SetRfGain::create(int output, double gain)
    {
      return std::make_shared<SetRfGain>(output, gain);
    }

    SetRfGainPtr SetRfGain::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetRfGain>(ptr);
    }

    bool SetRfGain::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Output"])
          && parse_json<double>::is_valid(m_values["Gain"])
        ;

    }

    std::string SetRfGain::documentation() const { return Documentation; }


    int SetRfGain::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetRfGain::output() const
    {
      return parse_json<int>::parse(m_values["Output"]);
    }

    void SetRfGain::setOutput(int output)
    {
      m_values.AddMember("Output", parse_json<int>::format(output, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetRfGain::gain() const
    {
      return parse_json<double>::parse(m_values["Gain"]);
    }

    void SetRfGain::setGain(double gain)
    {
      m_values.AddMember("Gain", parse_json<double>::format(gain, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

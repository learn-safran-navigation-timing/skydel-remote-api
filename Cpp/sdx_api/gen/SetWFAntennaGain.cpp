
#include "gen/SetWFAntennaGain.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetWFAntennaGain
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetWFAntennaGain::CmdName = "SetWFAntennaGain";
    const char* const SetWFAntennaGain::Documentation = "Set The CRPA LNA gain";

    REGISTER_COMMAND_FACTORY(SetWFAntennaGain);


    SetWFAntennaGain::SetWFAntennaGain()
      : CommandBase(CmdName)
    {}

    SetWFAntennaGain::SetWFAntennaGain(int gain)
      : CommandBase(CmdName)
    {

      setGain(gain);
    }

    SetWFAntennaGainPtr SetWFAntennaGain::create(int gain)
    {
      return std::make_shared<SetWFAntennaGain>(gain);
    }

    SetWFAntennaGainPtr SetWFAntennaGain::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetWFAntennaGain>(ptr);
    }

    bool SetWFAntennaGain::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Gain"])
        ;

    }

    std::string SetWFAntennaGain::documentation() const { return Documentation; }


    int SetWFAntennaGain::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int SetWFAntennaGain::gain() const
    {
      return parse_json<int>::parse(m_values["Gain"]);
    }

    void SetWFAntennaGain::setGain(int gain)
    {
      m_values.AddMember("Gain", parse_json<int>::format(gain, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

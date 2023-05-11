
#include "gen/SetLogNmeaRate.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetLogNmeaRate
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetLogNmeaRate::CmdName = "SetLogNmeaRate";
    const char* const SetLogNmeaRate::Documentation = "Set Rate logging of NMEA data";

    REGISTER_COMMAND_FACTORY(SetLogNmeaRate);


    SetLogNmeaRate::SetLogNmeaRate()
      : CommandBase(CmdName)
    {}

    SetLogNmeaRate::SetLogNmeaRate(int rate)
      : CommandBase(CmdName)
    {

      setRate(rate);
    }

    SetLogNmeaRatePtr SetLogNmeaRate::create(int rate)
    {
      return std::make_shared<SetLogNmeaRate>(rate);
    }

    SetLogNmeaRatePtr SetLogNmeaRate::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetLogNmeaRate>(ptr);
    }

    bool SetLogNmeaRate::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Rate"])
        ;

    }

    std::string SetLogNmeaRate::documentation() const { return Documentation; }


    int SetLogNmeaRate::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int SetLogNmeaRate::rate() const
    {
      return parse_json<int>::parse(m_values["Rate"]);
    }

    void SetLogNmeaRate::setRate(int rate)
    {
      m_values.AddMember("Rate", parse_json<int>::format(rate, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

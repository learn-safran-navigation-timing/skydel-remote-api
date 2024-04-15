
#include "SetLogNmeaRate.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetLogNmeaRate
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetLogNmeaRate::CmdName = "SetLogNmeaRate";
    const char* const SetLogNmeaRate::Documentation = "Set Rate logging of NMEA data\n"
      "\n"
      "Name Type Description\n"
      "---- ---- ------------------------------\n"
      "Rate int  Accepted rates are 1 and 10 Hz";
    const char* const SetLogNmeaRate::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetLogNmeaRate);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetLogNmeaRate);


    SetLogNmeaRate::SetLogNmeaRate()
      : CommandBase(CmdName, TargetId)
    {}

    SetLogNmeaRate::SetLogNmeaRate(int rate)
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& SetLogNmeaRate::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Rate"}; 
      return names; 
    }


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

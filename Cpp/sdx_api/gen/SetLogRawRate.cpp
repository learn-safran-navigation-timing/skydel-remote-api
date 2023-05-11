
#include "gen/SetLogRawRate.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetLogRawRate
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetLogRawRate::CmdName = "SetLogRawRate";
    const char* const SetLogRawRate::Documentation = "Set Rate logging of raw data";

    REGISTER_COMMAND_FACTORY(SetLogRawRate);


    SetLogRawRate::SetLogRawRate()
      : CommandBase(CmdName)
    {}

    SetLogRawRate::SetLogRawRate(int rate)
      : CommandBase(CmdName)
    {

      setRate(rate);
    }

    SetLogRawRatePtr SetLogRawRate::create(int rate)
    {
      return std::make_shared<SetLogRawRate>(rate);
    }

    SetLogRawRatePtr SetLogRawRate::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetLogRawRate>(ptr);
    }

    bool SetLogRawRate::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Rate"])
        ;

    }

    std::string SetLogRawRate::documentation() const { return Documentation; }


    int SetLogRawRate::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int SetLogRawRate::rate() const
    {
      return parse_json<int>::parse(m_values["Rate"]);
    }

    void SetLogRawRate::setRate(int rate)
    {
      m_values.AddMember("Rate", parse_json<int>::format(rate, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

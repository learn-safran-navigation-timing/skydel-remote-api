
#include "SetLogRawRate.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetLogRawRate
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetLogRawRate::CmdName = "SetLogRawRate";
    const char* const SetLogRawRate::Documentation = "Set Rate logging of raw data\n"
      "\n"
      "Name Type Description\n"
      "---- ---- --------------------------------------\n"
      "Rate int  Accepted rates are 10, 100 and 1000 Hz";
    const char* const SetLogRawRate::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetLogRawRate);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetLogRawRate);


    SetLogRawRate::SetLogRawRate()
      : CommandBase(CmdName, TargetId)
    {}

    SetLogRawRate::SetLogRawRate(int rate)
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& SetLogRawRate::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Rate"}; 
      return names; 
    }


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

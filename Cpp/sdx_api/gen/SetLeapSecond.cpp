
#include "SetLeapSecond.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetLeapSecond
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetLeapSecond::CmdName = "SetLeapSecond";
    const char* const SetLeapSecond::Documentation = "Set the UTC leap seconds added since GPS epoch.\n"
      "\n"
      "Name       Type Description\n"
      "---------- ---- ----------------------------------------------------------------\n"
      "LeapSecond int  The number of leap seconds to convert GPS date and time into UTC";
    const char* const SetLeapSecond::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetLeapSecond);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetLeapSecond);


    SetLeapSecond::SetLeapSecond()
      : CommandBase(CmdName, TargetId)
    {}

    SetLeapSecond::SetLeapSecond(int leapSecond)
      : CommandBase(CmdName, TargetId)
    {

      setLeapSecond(leapSecond);
    }

    SetLeapSecondPtr SetLeapSecond::create(int leapSecond)
    {
      return std::make_shared<SetLeapSecond>(leapSecond);
    }

    SetLeapSecondPtr SetLeapSecond::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetLeapSecond>(ptr);
    }

    bool SetLeapSecond::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["LeapSecond"])
        ;

    }

    std::string SetLeapSecond::documentation() const { return Documentation; }

    const std::vector<std::string>& SetLeapSecond::fieldNames() const 
    { 
      static const std::vector<std::string> names {"LeapSecond"}; 
      return names; 
    }


    int SetLeapSecond::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int SetLeapSecond::leapSecond() const
    {
      return parse_json<int>::parse(m_values["LeapSecond"]);
    }

    void SetLeapSecond::setLeapSecond(int leapSecond)
    {
      m_values.AddMember("LeapSecond", parse_json<int>::format(leapSecond, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

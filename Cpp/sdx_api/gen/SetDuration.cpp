
#include "SetDuration.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetDuration
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetDuration::CmdName = "SetDuration";
    const char* const SetDuration::Documentation = "Set the simulation duration. The simulation will stop automatically when this duration is reached\n"
      "\n"
      "Name   Type Description\n"
      "------ ---- -----------------------\n"
      "Second int  The duration in seconds";
    const char* const SetDuration::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetDuration);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetDuration);


    SetDuration::SetDuration()
      : CommandBase(CmdName, TargetId)
    {}

    SetDuration::SetDuration(int second)
      : CommandBase(CmdName, TargetId)
    {

      setSecond(second);
    }

    SetDurationPtr SetDuration::create(int second)
    {
      return std::make_shared<SetDuration>(second);
    }

    SetDurationPtr SetDuration::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetDuration>(ptr);
    }

    bool SetDuration::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Second"])
        ;

    }

    std::string SetDuration::documentation() const { return Documentation; }

    const std::vector<std::string>& SetDuration::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Second"}; 
      return names; 
    }


    int SetDuration::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int SetDuration::second() const
    {
      return parse_json<int>::parse(m_values["Second"]);
    }

    void SetDuration::setSecond(int second)
    {
      m_values.AddMember("Second", parse_json<int>::format(second, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

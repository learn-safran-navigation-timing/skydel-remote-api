
#include "gen/SetGpsStartTime.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGpsStartTime
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGpsStartTime::CmdName = "SetGpsStartTime";
    const char* const SetGpsStartTime::Documentation = "Set the simulation start date and time";

    REGISTER_COMMAND_FACTORY(SetGpsStartTime);


    SetGpsStartTime::SetGpsStartTime()
      : CommandBase(CmdName)
    {}

    SetGpsStartTime::SetGpsStartTime(const Sdx::DateTime& start)
      : CommandBase(CmdName)
    {

      setStart(start);
    }

    SetGpsStartTimePtr SetGpsStartTime::create(const Sdx::DateTime& start)
    {
      return std::make_shared<SetGpsStartTime>(start);
    }

    SetGpsStartTimePtr SetGpsStartTime::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetGpsStartTime>(ptr);
    }

    bool SetGpsStartTime::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<Sdx::DateTime>::is_valid(m_values["Start"])
        ;

    }

    std::string SetGpsStartTime::documentation() const { return Documentation; }


    int SetGpsStartTime::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    Sdx::DateTime SetGpsStartTime::start() const
    {
      return parse_json<Sdx::DateTime>::parse(m_values["Start"]);
    }

    void SetGpsStartTime::setStart(const Sdx::DateTime& start)
    {
      m_values.AddMember("Start", parse_json<Sdx::DateTime>::format(start, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

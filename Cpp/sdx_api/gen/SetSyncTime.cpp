
#include "gen/SetSyncTime.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetSyncTime
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetSyncTime::CmdName = "SetSyncTime";
    const char* const SetSyncTime::Documentation = "Set time delay to start streaming, in order to allign PPS out Signal with RF.\n2000 ms is a calibrated value.";

    REGISTER_COMMAND_FACTORY(SetSyncTime);


    SetSyncTime::SetSyncTime()
      : CommandBase(CmdName)
    {}

    SetSyncTime::SetSyncTime(double time)
      : CommandBase(CmdName)
    {

      setTime(time);
    }

    SetSyncTimePtr SetSyncTime::create(double time)
    {
      return std::make_shared<SetSyncTime>(time);
    }

    SetSyncTimePtr SetSyncTime::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetSyncTime>(ptr);
    }

    bool SetSyncTime::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<double>::is_valid(m_values["Time"])
        ;

    }

    std::string SetSyncTime::documentation() const { return Documentation; }


    int SetSyncTime::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    double SetSyncTime::time() const
    {
      return parse_json<double>::parse(m_values["Time"]);
    }

    void SetSyncTime::setTime(double time)
    {
      m_values.AddMember("Time", parse_json<double>::format(time, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

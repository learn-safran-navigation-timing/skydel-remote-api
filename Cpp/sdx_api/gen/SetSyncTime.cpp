
#include "SetSyncTime.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetSyncTime
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetSyncTime::CmdName = "SetSyncTime";
    const char* const SetSyncTime::Documentation = "Set time delay to start streaming, in order to allign PPS out Signal with RF.\n"
      "2000 ms is a calibrated value.\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ ----------------------------------------\n"
      "Time double Time delay in msec (minimum is 500 msec)";
    const char* const SetSyncTime::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetSyncTime);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetSyncTime);


    SetSyncTime::SetSyncTime()
      : CommandBase(CmdName, TargetId)
    {}

    SetSyncTime::SetSyncTime(double time)
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& SetSyncTime::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Time"}; 
      return names; 
    }


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

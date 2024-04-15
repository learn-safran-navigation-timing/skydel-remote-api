
#include "SetSyncTimeMaster.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetSyncTimeMaster
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetSyncTimeMaster::CmdName = "SetSyncTimeMaster";
    const char* const SetSyncTimeMaster::Documentation = "Please note the command SetSyncTimeMaster is deprecated since 23.11. You may use SetSyncTimeMainInstance.\n"
      "\n"
      "Set time delay to start streaming after PPS synchronization. A value of 1500\n"
      "means the simulation will start streaming 1.5 sec after the PPS used for\n"
      "synchornization.\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ ----------------------------------------\n"
      "Time double Time delay in msec (minimum is 500 msec)";
    const char* const SetSyncTimeMaster::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetSyncTimeMaster);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetSyncTimeMaster);


    SetSyncTimeMaster::SetSyncTimeMaster()
      : CommandBase(CmdName, TargetId)
    {}

    SetSyncTimeMaster::SetSyncTimeMaster(double time)
      : CommandBase(CmdName, TargetId)
    {

      setTime(time);
    }

    SetSyncTimeMasterPtr SetSyncTimeMaster::create(double time)
    {
      return std::make_shared<SetSyncTimeMaster>(time);
    }

    SetSyncTimeMasterPtr SetSyncTimeMaster::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetSyncTimeMaster>(ptr);
    }

    bool SetSyncTimeMaster::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<double>::is_valid(m_values["Time"])
        ;

    }

    std::string SetSyncTimeMaster::documentation() const { return Documentation; }

    const std::vector<std::string>& SetSyncTimeMaster::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Time"}; 
      return names; 
    }


    int SetSyncTimeMaster::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    double SetSyncTimeMaster::time() const
    {
      return parse_json<double>::parse(m_values["Time"]);
    }

    void SetSyncTimeMaster::setTime(double time)
    {
      m_values.AddMember("Time", parse_json<double>::format(time, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}


#include "SetSyncTimeMainInstance.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetSyncTimeMainInstance
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetSyncTimeMainInstance::CmdName = "SetSyncTimeMainInstance";
    const char* const SetSyncTimeMainInstance::Documentation = "Set time delay to start streaming after PPS synchronization. A value of 1500\n"
      "means the simulation will start streaming 1.5 sec after the PPS used for\n"
      "synchornization.\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ ----------------------------------------\n"
      "Time double Time delay in msec (minimum is 500 msec)";
    const char* const SetSyncTimeMainInstance::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetSyncTimeMainInstance);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetSyncTimeMainInstance);


    SetSyncTimeMainInstance::SetSyncTimeMainInstance()
      : CommandBase(CmdName, TargetId)
    {}

    SetSyncTimeMainInstance::SetSyncTimeMainInstance(double time)
      : CommandBase(CmdName, TargetId)
    {

      setTime(time);
    }

    SetSyncTimeMainInstancePtr SetSyncTimeMainInstance::create(double time)
    {
      return std::make_shared<SetSyncTimeMainInstance>(time);
    }

    SetSyncTimeMainInstancePtr SetSyncTimeMainInstance::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetSyncTimeMainInstance>(ptr);
    }

    bool SetSyncTimeMainInstance::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<double>::is_valid(m_values["Time"])
        ;

    }

    std::string SetSyncTimeMainInstance::documentation() const { return Documentation; }

    const std::vector<std::string>& SetSyncTimeMainInstance::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Time"}; 
      return names; 
    }


    int SetSyncTimeMainInstance::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    double SetSyncTimeMainInstance::time() const
    {
      return parse_json<double>::parse(m_values["Time"]);
    }

    void SetSyncTimeMainInstance::setTime(double time)
    {
      m_values.AddMember("Time", parse_json<double>::format(time, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

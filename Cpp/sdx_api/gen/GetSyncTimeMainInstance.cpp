
#include "GetSyncTimeMainInstance.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSyncTimeMainInstance
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSyncTimeMainInstance::CmdName = "GetSyncTimeMainInstance";
    const char* const GetSyncTimeMainInstance::Documentation = "Get time delay to start streaming after PPS synchronization. A value of 1500\n"
      "means the simulation will start streaming 1.5 sec after the PPS used for\n"
      "synchornization.";
    const char* const GetSyncTimeMainInstance::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetSyncTimeMainInstance);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetSyncTimeMainInstance);


    GetSyncTimeMainInstance::GetSyncTimeMainInstance()
      : CommandBase(CmdName, TargetId)
    {

    }

    GetSyncTimeMainInstancePtr GetSyncTimeMainInstance::create()
    {
      return std::make_shared<GetSyncTimeMainInstance>();
    }

    GetSyncTimeMainInstancePtr GetSyncTimeMainInstance::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSyncTimeMainInstance>(ptr);
    }

    bool GetSyncTimeMainInstance::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetSyncTimeMainInstance::documentation() const { return Documentation; }

    const std::vector<std::string>& GetSyncTimeMainInstance::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetSyncTimeMainInstance::executePermission() const
    {
      return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }

  }
}

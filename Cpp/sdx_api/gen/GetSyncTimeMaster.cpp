
#include "GetSyncTimeMaster.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSyncTimeMaster
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSyncTimeMaster::CmdName = "GetSyncTimeMaster";
    const char* const GetSyncTimeMaster::Documentation = "Please note the command GetSyncTimeMaster is deprecated since 23.11. You may use GetSyncTimeMainInstance.\n"
      "\n"
      "Get time delay to start streaming after PPS synchronization. A value of 1500\n"
      "means the simulation will start streaming 1.5 sec after the PPS used for\n"
      "synchornization.";
    const char* const GetSyncTimeMaster::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetSyncTimeMaster);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetSyncTimeMaster);


    GetSyncTimeMaster::GetSyncTimeMaster()
      : CommandBase(CmdName, TargetId)
    {

    }

    GetSyncTimeMasterPtr GetSyncTimeMaster::create()
    {
      return std::make_shared<GetSyncTimeMaster>();
    }

    GetSyncTimeMasterPtr GetSyncTimeMaster::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSyncTimeMaster>(ptr);
    }

    bool GetSyncTimeMaster::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetSyncTimeMaster::documentation() const { return Documentation; }

    const std::vector<std::string>& GetSyncTimeMaster::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetSyncTimeMaster::executePermission() const
    {
      return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }

  }
}

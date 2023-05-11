
#include "gen/GetSyncTimeMaster.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSyncTimeMaster
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSyncTimeMaster::CmdName = "GetSyncTimeMaster";
    const char* const GetSyncTimeMaster::Documentation = "Get time delay to start streaming after PPS synchronization. A value of 1500\nmeans the simulation will start streaming 1.5 sec after the PPS used for\nsynchornization.";

    REGISTER_COMMAND_FACTORY(GetSyncTimeMaster);


    GetSyncTimeMaster::GetSyncTimeMaster()
      : CommandBase(CmdName)
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


    int GetSyncTimeMaster::executePermission() const
    {
      return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }

  }
}

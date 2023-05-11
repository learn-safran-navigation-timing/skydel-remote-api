
#include "gen/GetSyncTime.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSyncTime
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSyncTime::CmdName = "GetSyncTime";
    const char* const GetSyncTime::Documentation = "Get time delay to start streaming, in order to allign PPS out Signal with RF.\n2000 ms is a calibrated value.";

    REGISTER_COMMAND_FACTORY(GetSyncTime);


    GetSyncTime::GetSyncTime()
      : CommandBase(CmdName)
    {

    }

    GetSyncTimePtr GetSyncTime::create()
    {
      return std::make_shared<GetSyncTime>();
    }

    GetSyncTimePtr GetSyncTime::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSyncTime>(ptr);
    }

    bool GetSyncTime::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetSyncTime::documentation() const { return Documentation; }


    int GetSyncTime::executePermission() const
    {
      return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }

  }
}

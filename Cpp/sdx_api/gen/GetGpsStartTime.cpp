
#include "gen/GetGpsStartTime.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsStartTime
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsStartTime::CmdName = "GetGpsStartTime";
    const char* const GetGpsStartTime::Documentation = "Get the simulation GPS start date and time and leap second to convert into UTC time";

    REGISTER_COMMAND_FACTORY(GetGpsStartTime);


    GetGpsStartTime::GetGpsStartTime()
      : CommandBase(CmdName)
    {

    }

    GetGpsStartTimePtr GetGpsStartTime::create()
    {
      return std::make_shared<GetGpsStartTime>();
    }

    GetGpsStartTimePtr GetGpsStartTime::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsStartTime>(ptr);
    }

    bool GetGpsStartTime::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetGpsStartTime::documentation() const { return Documentation; }


    int GetGpsStartTime::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }

  }
}

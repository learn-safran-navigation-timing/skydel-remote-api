
#include "gen/GetAlmanacUploadTimeInterval.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetAlmanacUploadTimeInterval
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetAlmanacUploadTimeInterval::CmdName = "GetAlmanacUploadTimeInterval";
    const char* const GetAlmanacUploadTimeInterval::Documentation = "Get almanac upload interval in seconds. After the initial upload set with command \nSetAlmanacInitialUploadTimeOffset, the almanac will automatically update at each interval.";

    REGISTER_COMMAND_FACTORY(GetAlmanacUploadTimeInterval);


    GetAlmanacUploadTimeInterval::GetAlmanacUploadTimeInterval()
      : CommandBase(CmdName)
    {

    }

    GetAlmanacUploadTimeIntervalPtr GetAlmanacUploadTimeInterval::create()
    {
      return std::make_shared<GetAlmanacUploadTimeInterval>();
    }

    GetAlmanacUploadTimeIntervalPtr GetAlmanacUploadTimeInterval::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetAlmanacUploadTimeInterval>(ptr);
    }

    bool GetAlmanacUploadTimeInterval::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetAlmanacUploadTimeInterval::documentation() const { return Documentation; }


    int GetAlmanacUploadTimeInterval::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}

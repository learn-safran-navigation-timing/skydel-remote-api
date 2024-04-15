
#include "GetAlmanacUploadTimeInterval.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetAlmanacUploadTimeInterval
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetAlmanacUploadTimeInterval::CmdName = "GetAlmanacUploadTimeInterval";
    const char* const GetAlmanacUploadTimeInterval::Documentation = "Get almanac upload interval in seconds. After the initial upload set with command \n"
      "SetAlmanacInitialUploadTimeOffset, the almanac will automatically update at each interval.";
    const char* const GetAlmanacUploadTimeInterval::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetAlmanacUploadTimeInterval);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetAlmanacUploadTimeInterval);


    GetAlmanacUploadTimeInterval::GetAlmanacUploadTimeInterval()
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& GetAlmanacUploadTimeInterval::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetAlmanacUploadTimeInterval::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}

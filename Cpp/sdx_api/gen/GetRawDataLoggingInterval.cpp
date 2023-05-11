
#include "gen/GetRawDataLoggingInterval.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetRawDataLoggingInterval
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetRawDataLoggingInterval::CmdName = "GetRawDataLoggingInterval";
    const char* const GetRawDataLoggingInterval::Documentation = "Get the time interval of the Raw Data logging.";

    REGISTER_COMMAND_FACTORY(GetRawDataLoggingInterval);


    GetRawDataLoggingInterval::GetRawDataLoggingInterval()
      : CommandBase(CmdName)
    {

    }

    GetRawDataLoggingIntervalPtr GetRawDataLoggingInterval::create()
    {
      return std::make_shared<GetRawDataLoggingInterval>();
    }

    GetRawDataLoggingIntervalPtr GetRawDataLoggingInterval::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetRawDataLoggingInterval>(ptr);
    }

    bool GetRawDataLoggingInterval::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetRawDataLoggingInterval::documentation() const { return Documentation; }


    int GetRawDataLoggingInterval::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}

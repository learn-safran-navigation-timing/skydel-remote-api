
#include "gen/GetLogRawRate.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetLogRawRate
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetLogRawRate::CmdName = "GetLogRawRate";
    const char* const GetLogRawRate::Documentation = "Get Rate logging of raw data";

    REGISTER_COMMAND_FACTORY(GetLogRawRate);


    GetLogRawRate::GetLogRawRate()
      : CommandBase(CmdName)
    {

    }

    GetLogRawRatePtr GetLogRawRate::create()
    {
      return std::make_shared<GetLogRawRate>();
    }

    GetLogRawRatePtr GetLogRawRate::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetLogRawRate>(ptr);
    }

    bool GetLogRawRate::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetLogRawRate::documentation() const { return Documentation; }


    int GetLogRawRate::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}


#include "gen/GetLogNmeaRate.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetLogNmeaRate
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetLogNmeaRate::CmdName = "GetLogNmeaRate";
    const char* const GetLogNmeaRate::Documentation = "Get Rate logging of NMEA data";

    REGISTER_COMMAND_FACTORY(GetLogNmeaRate);


    GetLogNmeaRate::GetLogNmeaRate()
      : CommandBase(CmdName)
    {

    }

    GetLogNmeaRatePtr GetLogNmeaRate::create()
    {
      return std::make_shared<GetLogNmeaRate>();
    }

    GetLogNmeaRatePtr GetLogNmeaRate::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetLogNmeaRate>(ptr);
    }

    bool GetLogNmeaRate::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetLogNmeaRate::documentation() const { return Documentation; }


    int GetLogNmeaRate::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}

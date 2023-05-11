
#include "gen/GetLastLeapSecondDate.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetLastLeapSecondDate
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetLastLeapSecondDate::CmdName = "GetLastLeapSecondDate";
    const char* const GetLastLeapSecondDate::Documentation = "Returns the last known leap second date";

    REGISTER_COMMAND_FACTORY(GetLastLeapSecondDate);


    GetLastLeapSecondDate::GetLastLeapSecondDate()
      : CommandBase(CmdName)
    {

    }

    GetLastLeapSecondDatePtr GetLastLeapSecondDate::create()
    {
      return std::make_shared<GetLastLeapSecondDate>();
    }

    GetLastLeapSecondDatePtr GetLastLeapSecondDate::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetLastLeapSecondDate>(ptr);
    }

    bool GetLastLeapSecondDate::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetLastLeapSecondDate::documentation() const { return Documentation; }


    int GetLastLeapSecondDate::executePermission() const
    {
      return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }

  }
}

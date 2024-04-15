
#include "GetLastLeapSecondDate.h"

#include "command_factory.h"
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
    const char* const GetLastLeapSecondDate::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetLastLeapSecondDate);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetLastLeapSecondDate);


    GetLastLeapSecondDate::GetLastLeapSecondDate()
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& GetLastLeapSecondDate::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetLastLeapSecondDate::executePermission() const
    {
      return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }

  }
}

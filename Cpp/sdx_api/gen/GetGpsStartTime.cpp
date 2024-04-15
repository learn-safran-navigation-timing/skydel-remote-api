
#include "GetGpsStartTime.h"

#include "command_factory.h"
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
    const char* const GetGpsStartTime::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetGpsStartTime);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetGpsStartTime);


    GetGpsStartTime::GetGpsStartTime()
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& GetGpsStartTime::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetGpsStartTime::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }

  }
}

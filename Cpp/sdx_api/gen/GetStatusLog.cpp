
#include "GetStatusLog.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetStatusLog
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetStatusLog::CmdName = "GetStatusLog";
    const char* const GetStatusLog::Documentation = "Returns the status log in a GetStatusLogResult and clears it";
    const char* const GetStatusLog::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetStatusLog);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetStatusLog);


    GetStatusLog::GetStatusLog()
      : CommandBase(CmdName, TargetId)
    {

    }

    GetStatusLogPtr GetStatusLog::create()
    {
      return std::make_shared<GetStatusLog>();
    }

    GetStatusLogPtr GetStatusLog::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetStatusLog>(ptr);
    }

    bool GetStatusLog::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetStatusLog::documentation() const { return Documentation; }

    const std::vector<std::string>& GetStatusLog::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetStatusLog::executePermission() const
    {
      return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }

  }
}

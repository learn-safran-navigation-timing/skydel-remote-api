
#include "gen/ClearStatusLog.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of ClearStatusLog
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ClearStatusLog::CmdName = "ClearStatusLog";
    const char* const ClearStatusLog::Documentation = "Clears the status log";

    REGISTER_COMMAND_FACTORY(ClearStatusLog);


    ClearStatusLog::ClearStatusLog()
      : CommandBase(CmdName)
    {

    }

    ClearStatusLogPtr ClearStatusLog::create()
    {
      return std::make_shared<ClearStatusLog>();
    }

    ClearStatusLogPtr ClearStatusLog::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ClearStatusLog>(ptr);
    }

    bool ClearStatusLog::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string ClearStatusLog::documentation() const { return Documentation; }


    int ClearStatusLog::executePermission() const
    {
      return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }

  }
}

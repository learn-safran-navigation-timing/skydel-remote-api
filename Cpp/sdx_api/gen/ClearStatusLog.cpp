
#include "ClearStatusLog.h"

#include "command_factory.h"
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
    const char* const ClearStatusLog::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(ClearStatusLog);
    REGISTER_COMMAND_TO_FACTORY_IMPL(ClearStatusLog);


    ClearStatusLog::ClearStatusLog()
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& ClearStatusLog::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int ClearStatusLog::executePermission() const
    {
      return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }

  }
}

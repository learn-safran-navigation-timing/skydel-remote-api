
#include "WaitAndResetPPS.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of WaitAndResetPPS
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const WaitAndResetPPS::CmdName = "WaitAndResetPPS";
    const char* const WaitAndResetPPS::Documentation = "Ask Skydel to reset its PPS counter.";
    const char* const WaitAndResetPPS::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(WaitAndResetPPS);
    REGISTER_COMMAND_TO_FACTORY_IMPL(WaitAndResetPPS);


    WaitAndResetPPS::WaitAndResetPPS()
      : CommandBase(CmdName, TargetId)
    {

    }

    WaitAndResetPPSPtr WaitAndResetPPS::create()
    {
      return std::make_shared<WaitAndResetPPS>();
    }

    WaitAndResetPPSPtr WaitAndResetPPS::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<WaitAndResetPPS>(ptr);
    }

    bool WaitAndResetPPS::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string WaitAndResetPPS::documentation() const { return Documentation; }

    const std::vector<std::string>& WaitAndResetPPS::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int WaitAndResetPPS::executePermission() const
    {
      return EXECUTE_IF_SIMULATING;
    }

  }
}

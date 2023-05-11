
#include "gen/WaitAndResetPPS.h"

#include "command_factory.h"
#include "command_result_factory.h"
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

    REGISTER_COMMAND_FACTORY(WaitAndResetPPS);


    WaitAndResetPPS::WaitAndResetPPS()
      : CommandBase(CmdName)
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


    int WaitAndResetPPS::executePermission() const
    {
      return EXECUTE_IF_SIMULATING;
    }

  }
}

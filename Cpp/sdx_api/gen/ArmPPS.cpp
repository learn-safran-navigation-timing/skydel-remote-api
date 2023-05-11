
#include "gen/ArmPPS.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of ArmPPS
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ArmPPS::CmdName = "ArmPPS";
    const char* const ArmPPS::Documentation = "Arm the system for further PPS synchronization instructions.";

    REGISTER_COMMAND_FACTORY(ArmPPS);


    ArmPPS::ArmPPS()
      : CommandBase(CmdName)
    {

    }

    ArmPPSPtr ArmPPS::create()
    {
      return std::make_shared<ArmPPS>();
    }

    ArmPPSPtr ArmPPS::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ArmPPS>(ptr);
    }

    bool ArmPPS::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string ArmPPS::documentation() const { return Documentation; }


    int ArmPPS::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}

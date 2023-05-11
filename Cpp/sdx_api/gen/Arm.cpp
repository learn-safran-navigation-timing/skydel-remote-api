
#include "gen/Arm.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of Arm
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const Arm::CmdName = "Arm";
    const char* const Arm::Documentation = "Arm the simulation. Simulation may or may not arm depending on the current state of the simulator.";

    REGISTER_COMMAND_FACTORY(Arm);


    Arm::Arm()
      : CommandBase(CmdName)
    {

    }

    ArmPtr Arm::create()
    {
      return std::make_shared<Arm>();
    }

    ArmPtr Arm::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<Arm>(ptr);
    }

    bool Arm::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string Arm::documentation() const { return Documentation; }


    int Arm::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}

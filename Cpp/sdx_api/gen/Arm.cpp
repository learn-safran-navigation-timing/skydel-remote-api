
#include "Arm.h"

#include "command_factory.h"
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
    const char* const Arm::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(Arm);
    REGISTER_COMMAND_TO_FACTORY_IMPL(Arm);


    Arm::Arm()
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& Arm::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int Arm::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}

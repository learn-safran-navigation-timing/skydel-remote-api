
#include "ArmPPS.h"

#include "command_factory.h"
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
    const char* const ArmPPS::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(ArmPPS);
    REGISTER_COMMAND_TO_FACTORY_IMPL(ArmPPS);


    ArmPPS::ArmPPS()
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& ArmPPS::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int ArmPPS::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}

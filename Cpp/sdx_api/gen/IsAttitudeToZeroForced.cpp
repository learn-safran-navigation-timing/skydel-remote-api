
#include "IsAttitudeToZeroForced.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsAttitudeToZeroForced
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsAttitudeToZeroForced::CmdName = "IsAttitudeToZeroForced";
    const char* const IsAttitudeToZeroForced::Documentation = "Get force vehicle yaw, pitch and roll to zero enabled or disabled";
    const char* const IsAttitudeToZeroForced::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(IsAttitudeToZeroForced);
    REGISTER_COMMAND_TO_FACTORY_IMPL(IsAttitudeToZeroForced);


    IsAttitudeToZeroForced::IsAttitudeToZeroForced()
      : CommandBase(CmdName, TargetId)
    {

    }

    IsAttitudeToZeroForcedPtr IsAttitudeToZeroForced::create()
    {
      return std::make_shared<IsAttitudeToZeroForced>();
    }

    IsAttitudeToZeroForcedPtr IsAttitudeToZeroForced::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsAttitudeToZeroForced>(ptr);
    }

    bool IsAttitudeToZeroForced::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string IsAttitudeToZeroForced::documentation() const { return Documentation; }

    const std::vector<std::string>& IsAttitudeToZeroForced::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int IsAttitudeToZeroForced::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}

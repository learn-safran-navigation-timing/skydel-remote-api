
#include "gen/IsAttitudeToZeroForced.h"

#include "command_factory.h"
#include "command_result_factory.h"
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

    REGISTER_COMMAND_FACTORY(IsAttitudeToZeroForced);


    IsAttitudeToZeroForced::IsAttitudeToZeroForced()
      : CommandBase(CmdName)
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


    int IsAttitudeToZeroForced::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}

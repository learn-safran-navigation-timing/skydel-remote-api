
#include "gen/IsUsingVelocityInSbasMessage25.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsUsingVelocityInSbasMessage25
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsUsingVelocityInSbasMessage25::CmdName = "IsUsingVelocityInSbasMessage25";
    const char* const IsUsingVelocityInSbasMessage25::Documentation = "Get whether SBAS message 25 should send velocity corrections";

    REGISTER_COMMAND_FACTORY(IsUsingVelocityInSbasMessage25);


    IsUsingVelocityInSbasMessage25::IsUsingVelocityInSbasMessage25()
      : CommandBase(CmdName)
    {

    }

    IsUsingVelocityInSbasMessage25Ptr IsUsingVelocityInSbasMessage25::create()
    {
      return std::make_shared<IsUsingVelocityInSbasMessage25>();
    }

    IsUsingVelocityInSbasMessage25Ptr IsUsingVelocityInSbasMessage25::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsUsingVelocityInSbasMessage25>(ptr);
    }

    bool IsUsingVelocityInSbasMessage25::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string IsUsingVelocityInSbasMessage25::documentation() const { return Documentation; }


    int IsUsingVelocityInSbasMessage25::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}

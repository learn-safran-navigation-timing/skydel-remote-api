
#include "IsUsingVelocityInSbasMessage25.h"

#include "command_factory.h"
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
    const char* const IsUsingVelocityInSbasMessage25::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(IsUsingVelocityInSbasMessage25);
    REGISTER_COMMAND_TO_FACTORY_IMPL(IsUsingVelocityInSbasMessage25);


    IsUsingVelocityInSbasMessage25::IsUsingVelocityInSbasMessage25()
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& IsUsingVelocityInSbasMessage25::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int IsUsingVelocityInSbasMessage25::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}


#include "gen/IsUsingVelocityInSbasMessage25Result.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsUsingVelocityInSbasMessage25Result
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsUsingVelocityInSbasMessage25Result::CmdName = "IsUsingVelocityInSbasMessage25Result";
    const char* const IsUsingVelocityInSbasMessage25Result::Documentation = "Result of IsUsingVelocityInSbasMessage25.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(IsUsingVelocityInSbasMessage25Result);


    IsUsingVelocityInSbasMessage25Result::IsUsingVelocityInSbasMessage25Result()
      : CommandResult(CmdName)
    {}

    IsUsingVelocityInSbasMessage25Result::IsUsingVelocityInSbasMessage25Result(bool useVelocity)
      : CommandResult(CmdName)
    {

      setUseVelocity(useVelocity);
    }

    IsUsingVelocityInSbasMessage25Result::IsUsingVelocityInSbasMessage25Result(CommandBasePtr relatedCommand, bool useVelocity)
      : CommandResult(CmdName, relatedCommand)
    {

      setUseVelocity(useVelocity);
    }


    IsUsingVelocityInSbasMessage25ResultPtr IsUsingVelocityInSbasMessage25Result::create(bool useVelocity)
    {
      return std::make_shared<IsUsingVelocityInSbasMessage25Result>(useVelocity);
    }

    IsUsingVelocityInSbasMessage25ResultPtr IsUsingVelocityInSbasMessage25Result::create(CommandBasePtr relatedCommand, bool useVelocity)
    {
      return std::make_shared<IsUsingVelocityInSbasMessage25Result>(relatedCommand, useVelocity);
    }

    IsUsingVelocityInSbasMessage25ResultPtr IsUsingVelocityInSbasMessage25Result::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsUsingVelocityInSbasMessage25Result>(ptr);
    }

    bool IsUsingVelocityInSbasMessage25Result::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["UseVelocity"])
        ;

    }

    std::string IsUsingVelocityInSbasMessage25Result::documentation() const { return Documentation; }


    bool IsUsingVelocityInSbasMessage25Result::useVelocity() const
    {
      return parse_json<bool>::parse(m_values["UseVelocity"]);
    }

    void IsUsingVelocityInSbasMessage25Result::setUseVelocity(bool useVelocity)
    {
      m_values.AddMember("UseVelocity", parse_json<bool>::format(useVelocity, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

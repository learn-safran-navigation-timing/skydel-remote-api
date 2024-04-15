
#include "IsTrajectoryCompletedResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsTrajectoryCompletedResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsTrajectoryCompletedResult::CmdName = "IsTrajectoryCompletedResult";
    const char* const IsTrajectoryCompletedResult::Documentation = "Result of IsTrajectoryCompleted.\n"
      "\n"
      "Name        Type Description\n"
      "----------- ---- ------------------------------------------\n"
      "IsCompleted bool Whether the trajectory is completed or not";
    const char* const IsTrajectoryCompletedResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(IsTrajectoryCompletedResult);


    IsTrajectoryCompletedResult::IsTrajectoryCompletedResult()
      : CommandResult(CmdName, TargetId)
    {}

    IsTrajectoryCompletedResult::IsTrajectoryCompletedResult(bool isCompleted)
      : CommandResult(CmdName, TargetId)
    {

      setIsCompleted(isCompleted);
    }

    IsTrajectoryCompletedResult::IsTrajectoryCompletedResult(CommandBasePtr relatedCommand, bool isCompleted)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setIsCompleted(isCompleted);
    }


    IsTrajectoryCompletedResultPtr IsTrajectoryCompletedResult::create(bool isCompleted)
    {
      return std::make_shared<IsTrajectoryCompletedResult>(isCompleted);
    }

    IsTrajectoryCompletedResultPtr IsTrajectoryCompletedResult::create(CommandBasePtr relatedCommand, bool isCompleted)
    {
      return std::make_shared<IsTrajectoryCompletedResult>(relatedCommand, isCompleted);
    }

    IsTrajectoryCompletedResultPtr IsTrajectoryCompletedResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsTrajectoryCompletedResult>(ptr);
    }

    bool IsTrajectoryCompletedResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["IsCompleted"])
        ;

    }

    std::string IsTrajectoryCompletedResult::documentation() const { return Documentation; }

    const std::vector<std::string>& IsTrajectoryCompletedResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"IsCompleted"}; 
      return names; 
    }


    bool IsTrajectoryCompletedResult::isCompleted() const
    {
      return parse_json<bool>::parse(m_values["IsCompleted"]);
    }

    void IsTrajectoryCompletedResult::setIsCompleted(bool isCompleted)
    {
      m_values.AddMember("IsCompleted", parse_json<bool>::format(isCompleted, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

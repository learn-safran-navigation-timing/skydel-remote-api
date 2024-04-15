
#include "SuccessResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SuccessResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SuccessResult::CmdName = "SuccessResult";
    const char* const SuccessResult::Documentation = "When command succeed.";
    const char* const SuccessResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(SuccessResult);


    SuccessResult::SuccessResult()
      : CommandResult(CmdName, TargetId)
    {}

    SuccessResult::SuccessResult(CommandBasePtr relatedCommand)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

    }

    SuccessResultPtr SuccessResult::create(CommandBasePtr relatedCommand)
    {
      return std::make_shared<SuccessResult>(relatedCommand);
    }

    SuccessResultPtr SuccessResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SuccessResult>(ptr);
    }

    bool SuccessResult::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string SuccessResult::documentation() const { return Documentation; }

    const std::vector<std::string>& SuccessResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }

  }
}

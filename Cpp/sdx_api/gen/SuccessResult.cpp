
#include "gen/SuccessResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
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

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(SuccessResult);


    SuccessResult::SuccessResult()
      : CommandResult(CmdName)
    {}

    SuccessResult::SuccessResult(CommandBasePtr relatedCommand)
      : CommandResult(CmdName, relatedCommand)
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

  }
}

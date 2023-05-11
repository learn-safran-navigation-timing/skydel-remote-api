
#include "gen/ResetHilWarning.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of ResetHilWarning
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ResetHilWarning::CmdName = "ResetHilWarning";
    const char* const ResetHilWarning::Documentation = "Please note the command ResetHilWarning is deprecated since 22.5. You may use GetHilExtrapolationState.\n\nReset Hardware in the loop trajectory server warning message.";

    const char* const ResetHilWarning::Deprecated = "Please note the command ResetHilWarning is deprecated since 22.5. You may use GetHilExtrapolationState.";

    REGISTER_COMMAND_FACTORY(ResetHilWarning);


    ResetHilWarning::ResetHilWarning()
      : CommandBase(CmdName)
    {

    }

    ResetHilWarningPtr ResetHilWarning::create()
    {
      return std::make_shared<ResetHilWarning>();
    }

    ResetHilWarningPtr ResetHilWarning::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ResetHilWarning>(ptr);
    }

    bool ResetHilWarning::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string ResetHilWarning::documentation() const { return Documentation; }

    Sdx::optional<std::string> ResetHilWarning::deprecated() const { return Sdx::optional<std::string>{Deprecated}; }


    int ResetHilWarning::executePermission() const
    {
      return EXECUTE_IF_SIMULATING;
    }

  }
}

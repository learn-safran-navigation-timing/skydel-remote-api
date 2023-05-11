
#include "gen/GetLastHilWarning.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetLastHilWarning
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetLastHilWarning::CmdName = "GetLastHilWarning";
    const char* const GetLastHilWarning::Documentation = "Please note the command GetLastHilWarning is deprecated since 22.5. You may use GetHilExtrapolationState.\n\nGet last Hardware in the loop trajectory server warning message. Returns HilWarningResult.";

    const char* const GetLastHilWarning::Deprecated = "Please note the command GetLastHilWarning is deprecated since 22.5. You may use GetHilExtrapolationState.";

    REGISTER_COMMAND_FACTORY(GetLastHilWarning);


    GetLastHilWarning::GetLastHilWarning()
      : CommandBase(CmdName)
    {

    }

    GetLastHilWarningPtr GetLastHilWarning::create()
    {
      return std::make_shared<GetLastHilWarning>();
    }

    GetLastHilWarningPtr GetLastHilWarning::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetLastHilWarning>(ptr);
    }

    bool GetLastHilWarning::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetLastHilWarning::documentation() const { return Documentation; }

    Sdx::optional<std::string> GetLastHilWarning::deprecated() const { return Sdx::optional<std::string>{Deprecated}; }


    int GetLastHilWarning::executePermission() const
    {
      return EXECUTE_IF_SIMULATING;
    }

  }
}

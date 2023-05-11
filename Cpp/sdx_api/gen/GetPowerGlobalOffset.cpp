
#include "gen/GetPowerGlobalOffset.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetPowerGlobalOffset
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetPowerGlobalOffset::CmdName = "GetPowerGlobalOffset";
    const char* const GetPowerGlobalOffset::Documentation = "Please note the command GetPowerGlobalOffset is deprecated since 21.7. You may use GetGlobalPowerOffset.\n\nGet global power offset default value for all signals and all systems";

    REGISTER_COMMAND_FACTORY(GetPowerGlobalOffset);


    GetPowerGlobalOffset::GetPowerGlobalOffset()
      : CommandBase(CmdName)
    {

    }

    GetPowerGlobalOffsetPtr GetPowerGlobalOffset::create()
    {
      return std::make_shared<GetPowerGlobalOffset>();
    }

    GetPowerGlobalOffsetPtr GetPowerGlobalOffset::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetPowerGlobalOffset>(ptr);
    }

    bool GetPowerGlobalOffset::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetPowerGlobalOffset::documentation() const { return Documentation; }


    int GetPowerGlobalOffset::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}

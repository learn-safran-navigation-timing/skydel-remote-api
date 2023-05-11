
#include "gen/GetSVDataUpdateMode.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSVDataUpdateMode
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSVDataUpdateMode::CmdName = "GetSVDataUpdateMode";
    const char* const GetSVDataUpdateMode::Documentation = "Get the SV Data Update Mode.";

    REGISTER_COMMAND_FACTORY(GetSVDataUpdateMode);


    GetSVDataUpdateMode::GetSVDataUpdateMode()
      : CommandBase(CmdName)
    {

    }

    GetSVDataUpdateModePtr GetSVDataUpdateMode::create()
    {
      return std::make_shared<GetSVDataUpdateMode>();
    }

    GetSVDataUpdateModePtr GetSVDataUpdateMode::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSVDataUpdateMode>(ptr);
    }

    bool GetSVDataUpdateMode::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetSVDataUpdateMode::documentation() const { return Documentation; }


    int GetSVDataUpdateMode::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}


#include "GetPowerGlobalOffset.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetPowerGlobalOffset
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetPowerGlobalOffset::CmdName = "GetPowerGlobalOffset";
    const char* const GetPowerGlobalOffset::Documentation = "Please note the command GetPowerGlobalOffset is deprecated since 21.7. You may use GetGlobalPowerOffset.\n"
      "\n"
      "Get global power offset default value for all signals and all systems";
    const char* const GetPowerGlobalOffset::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetPowerGlobalOffset);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetPowerGlobalOffset);


    GetPowerGlobalOffset::GetPowerGlobalOffset()
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& GetPowerGlobalOffset::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetPowerGlobalOffset::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}

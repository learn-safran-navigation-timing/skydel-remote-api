
#include "gen/GetGlobalPowerOffset.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGlobalPowerOffset
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGlobalPowerOffset::CmdName = "GetGlobalPowerOffset";
    const char* const GetGlobalPowerOffset::Documentation = "Get global power offset default value for all signals and all systems";

    REGISTER_COMMAND_FACTORY(GetGlobalPowerOffset);


    GetGlobalPowerOffset::GetGlobalPowerOffset()
      : CommandBase(CmdName)
    {

    }

    GetGlobalPowerOffsetPtr GetGlobalPowerOffset::create()
    {
      return std::make_shared<GetGlobalPowerOffset>();
    }

    GetGlobalPowerOffsetPtr GetGlobalPowerOffset::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGlobalPowerOffset>(ptr);
    }

    bool GetGlobalPowerOffset::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetGlobalPowerOffset::documentation() const { return Documentation; }


    int GetGlobalPowerOffset::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}

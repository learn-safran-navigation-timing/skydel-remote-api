
#include "GetGlobalPowerOffset.h"

#include "command_factory.h"
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
    const char* const GetGlobalPowerOffset::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetGlobalPowerOffset);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetGlobalPowerOffset);


    GetGlobalPowerOffset::GetGlobalPowerOffset()
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& GetGlobalPowerOffset::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetGlobalPowerOffset::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}

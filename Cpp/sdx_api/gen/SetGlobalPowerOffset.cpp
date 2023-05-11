
#include "gen/SetGlobalPowerOffset.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGlobalPowerOffset
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGlobalPowerOffset::CmdName = "SetGlobalPowerOffset";
    const char* const SetGlobalPowerOffset::Documentation = "Set global power offset default value for all signals and all systems";

    REGISTER_COMMAND_FACTORY(SetGlobalPowerOffset);


    SetGlobalPowerOffset::SetGlobalPowerOffset()
      : CommandBase(CmdName)
    {}

    SetGlobalPowerOffset::SetGlobalPowerOffset(double offset)
      : CommandBase(CmdName)
    {

      setOffset(offset);
    }

    SetGlobalPowerOffsetPtr SetGlobalPowerOffset::create(double offset)
    {
      return std::make_shared<SetGlobalPowerOffset>(offset);
    }

    SetGlobalPowerOffsetPtr SetGlobalPowerOffset::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetGlobalPowerOffset>(ptr);
    }

    bool SetGlobalPowerOffset::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<double>::is_valid(m_values["Offset"])
        ;

    }

    std::string SetGlobalPowerOffset::documentation() const { return Documentation; }


    int SetGlobalPowerOffset::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    double SetGlobalPowerOffset::offset() const
    {
      return parse_json<double>::parse(m_values["Offset"]);
    }

    void SetGlobalPowerOffset::setOffset(double offset)
    {
      m_values.AddMember("Offset", parse_json<double>::format(offset, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}


#include "SetPowerGlobalOffset.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetPowerGlobalOffset
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetPowerGlobalOffset::CmdName = "SetPowerGlobalOffset";
    const char* const SetPowerGlobalOffset::Documentation = "Please note the command SetPowerGlobalOffset is deprecated since 21.7. You may use SetGlobalPowerOffset.\n"
      "\n"
      "Set global power offset default value for all signals and all systems\n"
      "\n"
      "Name   Type   Description\n"
      "------ ------ ---------------------------------------------------\n"
      "Offset double Offset in dB (negative value will attenuate signal)";
    const char* const SetPowerGlobalOffset::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetPowerGlobalOffset);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetPowerGlobalOffset);


    SetPowerGlobalOffset::SetPowerGlobalOffset()
      : CommandBase(CmdName, TargetId)
    {}

    SetPowerGlobalOffset::SetPowerGlobalOffset(double offset)
      : CommandBase(CmdName, TargetId)
    {

      setOffset(offset);
    }

    SetPowerGlobalOffsetPtr SetPowerGlobalOffset::create(double offset)
    {
      return std::make_shared<SetPowerGlobalOffset>(offset);
    }

    SetPowerGlobalOffsetPtr SetPowerGlobalOffset::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetPowerGlobalOffset>(ptr);
    }

    bool SetPowerGlobalOffset::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<double>::is_valid(m_values["Offset"])
        ;

    }

    std::string SetPowerGlobalOffset::documentation() const { return Documentation; }

    const std::vector<std::string>& SetPowerGlobalOffset::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Offset"}; 
      return names; 
    }


    int SetPowerGlobalOffset::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    double SetPowerGlobalOffset::offset() const
    {
      return parse_json<double>::parse(m_values["Offset"]);
    }

    void SetPowerGlobalOffset::setOffset(double offset)
    {
      m_values.AddMember("Offset", parse_json<double>::format(offset, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

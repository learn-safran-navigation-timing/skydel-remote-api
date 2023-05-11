
#include "gen/SetPowerOffset.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetPowerOffset
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetPowerOffset::CmdName = "SetPowerOffset";
    const char* const SetPowerOffset::Documentation = "Please note the command SetPowerOffset is deprecated since 21.7. You may use SetSignalPowerOffset.\n\nSet power offset default value for the signal given in argument";

    REGISTER_COMMAND_FACTORY(SetPowerOffset);


    SetPowerOffset::SetPowerOffset()
      : CommandBase(CmdName)
    {}

    SetPowerOffset::SetPowerOffset(const std::string& signal, double offset)
      : CommandBase(CmdName)
    {

      setSignal(signal);
      setOffset(offset);
    }

    SetPowerOffsetPtr SetPowerOffset::create(const std::string& signal, double offset)
    {
      return std::make_shared<SetPowerOffset>(signal, offset);
    }

    SetPowerOffsetPtr SetPowerOffset::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetPowerOffset>(ptr);
    }

    bool SetPowerOffset::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Signal"])
          && parse_json<double>::is_valid(m_values["Offset"])
        ;

    }

    std::string SetPowerOffset::documentation() const { return Documentation; }


    int SetPowerOffset::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    std::string SetPowerOffset::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void SetPowerOffset::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetPowerOffset::offset() const
    {
      return parse_json<double>::parse(m_values["Offset"]);
    }

    void SetPowerOffset::setOffset(double offset)
    {
      m_values.AddMember("Offset", parse_json<double>::format(offset, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

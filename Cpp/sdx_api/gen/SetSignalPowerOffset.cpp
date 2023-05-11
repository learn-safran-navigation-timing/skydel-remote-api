
#include "gen/SetSignalPowerOffset.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetSignalPowerOffset
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetSignalPowerOffset::CmdName = "SetSignalPowerOffset";
    const char* const SetSignalPowerOffset::Documentation = "Set power offset default value for the signal given in argument";

    REGISTER_COMMAND_FACTORY(SetSignalPowerOffset);


    SetSignalPowerOffset::SetSignalPowerOffset()
      : CommandBase(CmdName)
    {}

    SetSignalPowerOffset::SetSignalPowerOffset(const std::string& signal, double offset)
      : CommandBase(CmdName)
    {

      setSignal(signal);
      setOffset(offset);
    }

    SetSignalPowerOffsetPtr SetSignalPowerOffset::create(const std::string& signal, double offset)
    {
      return std::make_shared<SetSignalPowerOffset>(signal, offset);
    }

    SetSignalPowerOffsetPtr SetSignalPowerOffset::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetSignalPowerOffset>(ptr);
    }

    bool SetSignalPowerOffset::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Signal"])
          && parse_json<double>::is_valid(m_values["Offset"])
        ;

    }

    std::string SetSignalPowerOffset::documentation() const { return Documentation; }


    int SetSignalPowerOffset::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    std::string SetSignalPowerOffset::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void SetSignalPowerOffset::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetSignalPowerOffset::offset() const
    {
      return parse_json<double>::parse(m_values["Offset"]);
    }

    void SetSignalPowerOffset::setOffset(double offset)
    {
      m_values.AddMember("Offset", parse_json<double>::format(offset, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}


#include "gen/GetSignalPowerOffset.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSignalPowerOffset
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSignalPowerOffset::CmdName = "GetSignalPowerOffset";
    const char* const GetSignalPowerOffset::Documentation = "Get power offset default value for the signal given in argument";

    REGISTER_COMMAND_FACTORY(GetSignalPowerOffset);


    GetSignalPowerOffset::GetSignalPowerOffset()
      : CommandBase(CmdName)
    {}

    GetSignalPowerOffset::GetSignalPowerOffset(const std::string& signal)
      : CommandBase(CmdName)
    {

      setSignal(signal);
    }

    GetSignalPowerOffsetPtr GetSignalPowerOffset::create(const std::string& signal)
    {
      return std::make_shared<GetSignalPowerOffset>(signal);
    }

    GetSignalPowerOffsetPtr GetSignalPowerOffset::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSignalPowerOffset>(ptr);
    }

    bool GetSignalPowerOffset::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Signal"])
        ;

    }

    std::string GetSignalPowerOffset::documentation() const { return Documentation; }


    int GetSignalPowerOffset::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetSignalPowerOffset::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void GetSignalPowerOffset::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

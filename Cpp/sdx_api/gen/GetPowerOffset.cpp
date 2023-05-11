
#include "gen/GetPowerOffset.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetPowerOffset
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetPowerOffset::CmdName = "GetPowerOffset";
    const char* const GetPowerOffset::Documentation = "Please note the command GetPowerOffset is deprecated since 21.7. You may use GetSignalPowerOffset.\n\nGet power offset default value for the signal given in argument";

    REGISTER_COMMAND_FACTORY(GetPowerOffset);


    GetPowerOffset::GetPowerOffset()
      : CommandBase(CmdName)
    {}

    GetPowerOffset::GetPowerOffset(const std::string& signal)
      : CommandBase(CmdName)
    {

      setSignal(signal);
    }

    GetPowerOffsetPtr GetPowerOffset::create(const std::string& signal)
    {
      return std::make_shared<GetPowerOffset>(signal);
    }

    GetPowerOffsetPtr GetPowerOffset::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetPowerOffset>(ptr);
    }

    bool GetPowerOffset::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Signal"])
        ;

    }

    std::string GetPowerOffset::documentation() const { return Documentation; }


    int GetPowerOffset::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetPowerOffset::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void GetPowerOffset::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

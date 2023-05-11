
#include "gen/SetStartTimeMode.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetStartTimeMode
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetStartTimeMode::CmdName = "SetStartTimeMode";
    const char* const SetStartTimeMode::Documentation = "Set the simulation start time mode.";

    REGISTER_COMMAND_FACTORY(SetStartTimeMode);


    SetStartTimeMode::SetStartTimeMode()
      : CommandBase(CmdName)
    {}

    SetStartTimeMode::SetStartTimeMode(const std::string& mode)
      : CommandBase(CmdName)
    {

      setMode(mode);
    }

    SetStartTimeModePtr SetStartTimeMode::create(const std::string& mode)
    {
      return std::make_shared<SetStartTimeMode>(mode);
    }

    SetStartTimeModePtr SetStartTimeMode::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetStartTimeMode>(ptr);
    }

    bool SetStartTimeMode::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Mode"])
        ;

    }

    std::string SetStartTimeMode::documentation() const { return Documentation; }


    int SetStartTimeMode::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetStartTimeMode::mode() const
    {
      return parse_json<std::string>::parse(m_values["Mode"]);
    }

    void SetStartTimeMode::setMode(const std::string& mode)
    {
      m_values.AddMember("Mode", parse_json<std::string>::format(mode, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

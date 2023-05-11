
#include "gen/SetSVDataUpdateMode.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetSVDataUpdateMode
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetSVDataUpdateMode::CmdName = "SetSVDataUpdateMode";
    const char* const SetSVDataUpdateMode::Documentation = "Set the SV Data Update Mode.";

    REGISTER_COMMAND_FACTORY(SetSVDataUpdateMode);


    SetSVDataUpdateMode::SetSVDataUpdateMode()
      : CommandBase(CmdName)
    {}

    SetSVDataUpdateMode::SetSVDataUpdateMode(const Sdx::SVDataUpdateMode& mode)
      : CommandBase(CmdName)
    {

      setMode(mode);
    }

    SetSVDataUpdateModePtr SetSVDataUpdateMode::create(const Sdx::SVDataUpdateMode& mode)
    {
      return std::make_shared<SetSVDataUpdateMode>(mode);
    }

    SetSVDataUpdateModePtr SetSVDataUpdateMode::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetSVDataUpdateMode>(ptr);
    }

    bool SetSVDataUpdateMode::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<Sdx::SVDataUpdateMode>::is_valid(m_values["Mode"])
        ;

    }

    std::string SetSVDataUpdateMode::documentation() const { return Documentation; }


    int SetSVDataUpdateMode::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    Sdx::SVDataUpdateMode SetSVDataUpdateMode::mode() const
    {
      return parse_json<Sdx::SVDataUpdateMode>::parse(m_values["Mode"]);
    }

    void SetSVDataUpdateMode::setMode(const Sdx::SVDataUpdateMode& mode)
    {
      m_values.AddMember("Mode", parse_json<Sdx::SVDataUpdateMode>::format(mode, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

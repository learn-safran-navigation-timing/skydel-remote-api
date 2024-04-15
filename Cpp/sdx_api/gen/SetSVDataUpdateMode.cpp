
#include "SetSVDataUpdateMode.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetSVDataUpdateMode
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetSVDataUpdateMode::CmdName = "SetSVDataUpdateMode";
    const char* const SetSVDataUpdateMode::Documentation = "Set the SV Data Update Mode.\n"
      "\n"
      "Name Type             Description\n"
      "---- ---------------- ------------------------------------------------------------------\n"
      "Mode SVDataUpdateMode SV Data Update Mode:\n"
      "                      Extrapolation: Skydel extrapolates from the first block (default).\n"
      "                      Dynamic: Blocks must be pushed during the simulation.";
    const char* const SetSVDataUpdateMode::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetSVDataUpdateMode);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetSVDataUpdateMode);


    SetSVDataUpdateMode::SetSVDataUpdateMode()
      : CommandBase(CmdName, TargetId)
    {}

    SetSVDataUpdateMode::SetSVDataUpdateMode(const Sdx::SVDataUpdateMode& mode)
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& SetSVDataUpdateMode::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Mode"}; 
      return names; 
    }


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


#include "gen/SetSpectrumVisible.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetSpectrumVisible
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetSpectrumVisible::CmdName = "SetSpectrumVisible";
    const char* const SetSpectrumVisible::Documentation = "Set if spectrums are show/hide.";

    REGISTER_COMMAND_FACTORY(SetSpectrumVisible);


    SetSpectrumVisible::SetSpectrumVisible()
      : CommandBase(CmdName)
    {}

    SetSpectrumVisible::SetSpectrumVisible(bool visible)
      : CommandBase(CmdName)
    {

      setVisible(visible);
    }

    SetSpectrumVisiblePtr SetSpectrumVisible::create(bool visible)
    {
      return std::make_shared<SetSpectrumVisible>(visible);
    }

    SetSpectrumVisiblePtr SetSpectrumVisible::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetSpectrumVisible>(ptr);
    }

    bool SetSpectrumVisible::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Visible"])
        ;

    }

    std::string SetSpectrumVisible::documentation() const { return Documentation; }


    int SetSpectrumVisible::executePermission() const
    {
      return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE;
    }


    bool SetSpectrumVisible::visible() const
    {
      return parse_json<bool>::parse(m_values["Visible"]);
    }

    void SetSpectrumVisible::setVisible(bool visible)
    {
      m_values.AddMember("Visible", parse_json<bool>::format(visible, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

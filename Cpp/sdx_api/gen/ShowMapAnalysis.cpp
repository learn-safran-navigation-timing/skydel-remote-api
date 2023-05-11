
#include "gen/ShowMapAnalysis.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of ShowMapAnalysis
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ShowMapAnalysis::CmdName = "ShowMapAnalysis";
    const char* const ShowMapAnalysis::Documentation = "Set if map is show/hide in Analysis tab.";

    REGISTER_COMMAND_FACTORY(ShowMapAnalysis);


    ShowMapAnalysis::ShowMapAnalysis()
      : CommandBase(CmdName)
    {}

    ShowMapAnalysis::ShowMapAnalysis(bool show)
      : CommandBase(CmdName)
    {

      setShow(show);
    }

    ShowMapAnalysisPtr ShowMapAnalysis::create(bool show)
    {
      return std::make_shared<ShowMapAnalysis>(show);
    }

    ShowMapAnalysisPtr ShowMapAnalysis::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ShowMapAnalysis>(ptr);
    }

    bool ShowMapAnalysis::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Show"])
        ;

    }

    std::string ShowMapAnalysis::documentation() const { return Documentation; }


    int ShowMapAnalysis::executePermission() const
    {
      return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE;
    }


    bool ShowMapAnalysis::show() const
    {
      return parse_json<bool>::parse(m_values["Show"]);
    }

    void ShowMapAnalysis::setShow(bool show)
    {
      m_values.AddMember("Show", parse_json<bool>::format(show, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

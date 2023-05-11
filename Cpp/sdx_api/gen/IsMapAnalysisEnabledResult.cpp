
#include "gen/IsMapAnalysisEnabledResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsMapAnalysisEnabledResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsMapAnalysisEnabledResult::CmdName = "IsMapAnalysisEnabledResult";
    const char* const IsMapAnalysisEnabledResult::Documentation = "Result of IsMapAnalysisEnabled.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(IsMapAnalysisEnabledResult);


    IsMapAnalysisEnabledResult::IsMapAnalysisEnabledResult()
      : CommandResult(CmdName)
    {}

    IsMapAnalysisEnabledResult::IsMapAnalysisEnabledResult(bool show)
      : CommandResult(CmdName)
    {

      setShow(show);
    }

    IsMapAnalysisEnabledResult::IsMapAnalysisEnabledResult(CommandBasePtr relatedCommand, bool show)
      : CommandResult(CmdName, relatedCommand)
    {

      setShow(show);
    }


    IsMapAnalysisEnabledResultPtr IsMapAnalysisEnabledResult::create(bool show)
    {
      return std::make_shared<IsMapAnalysisEnabledResult>(show);
    }

    IsMapAnalysisEnabledResultPtr IsMapAnalysisEnabledResult::create(CommandBasePtr relatedCommand, bool show)
    {
      return std::make_shared<IsMapAnalysisEnabledResult>(relatedCommand, show);
    }

    IsMapAnalysisEnabledResultPtr IsMapAnalysisEnabledResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsMapAnalysisEnabledResult>(ptr);
    }

    bool IsMapAnalysisEnabledResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Show"])
        ;

    }

    std::string IsMapAnalysisEnabledResult::documentation() const { return Documentation; }


    bool IsMapAnalysisEnabledResult::show() const
    {
      return parse_json<bool>::parse(m_values["Show"]);
    }

    void IsMapAnalysisEnabledResult::setShow(bool show)
    {
      m_values.AddMember("Show", parse_json<bool>::format(show, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

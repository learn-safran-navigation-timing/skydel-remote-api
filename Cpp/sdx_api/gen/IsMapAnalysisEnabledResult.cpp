
#include "IsMapAnalysisEnabledResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsMapAnalysisEnabledResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsMapAnalysisEnabledResult::CmdName = "IsMapAnalysisEnabledResult";
    const char* const IsMapAnalysisEnabledResult::Documentation = "Result of IsMapAnalysisEnabled.\n"
      "\n"
      "Name Type Description\n"
      "---- ---- -------------\n"
      "Show bool Show map flag";
    const char* const IsMapAnalysisEnabledResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(IsMapAnalysisEnabledResult);


    IsMapAnalysisEnabledResult::IsMapAnalysisEnabledResult()
      : CommandResult(CmdName, TargetId)
    {}

    IsMapAnalysisEnabledResult::IsMapAnalysisEnabledResult(bool show)
      : CommandResult(CmdName, TargetId)
    {

      setShow(show);
    }

    IsMapAnalysisEnabledResult::IsMapAnalysisEnabledResult(CommandBasePtr relatedCommand, bool show)
      : CommandResult(CmdName, TargetId, relatedCommand)
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

    const std::vector<std::string>& IsMapAnalysisEnabledResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Show"}; 
      return names; 
    }


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

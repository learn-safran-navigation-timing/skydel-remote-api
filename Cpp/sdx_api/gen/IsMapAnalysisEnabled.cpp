
#include "IsMapAnalysisEnabled.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsMapAnalysisEnabled
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsMapAnalysisEnabled::CmdName = "IsMapAnalysisEnabled";
    const char* const IsMapAnalysisEnabled::Documentation = "Get if map is show/hide in Analysis tab.";
    const char* const IsMapAnalysisEnabled::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(IsMapAnalysisEnabled);
    REGISTER_COMMAND_TO_FACTORY_IMPL(IsMapAnalysisEnabled);


    IsMapAnalysisEnabled::IsMapAnalysisEnabled()
      : CommandBase(CmdName, TargetId)
    {

    }

    IsMapAnalysisEnabledPtr IsMapAnalysisEnabled::create()
    {
      return std::make_shared<IsMapAnalysisEnabled>();
    }

    IsMapAnalysisEnabledPtr IsMapAnalysisEnabled::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsMapAnalysisEnabled>(ptr);
    }

    bool IsMapAnalysisEnabled::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string IsMapAnalysisEnabled::documentation() const { return Documentation; }

    const std::vector<std::string>& IsMapAnalysisEnabled::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int IsMapAnalysisEnabled::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}

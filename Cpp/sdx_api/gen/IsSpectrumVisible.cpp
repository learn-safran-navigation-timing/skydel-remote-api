
#include "IsSpectrumVisible.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsSpectrumVisible
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsSpectrumVisible::CmdName = "IsSpectrumVisible";
    const char* const IsSpectrumVisible::Documentation = "Get if spectrums are show/hide.";
    const char* const IsSpectrumVisible::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(IsSpectrumVisible);
    REGISTER_COMMAND_TO_FACTORY_IMPL(IsSpectrumVisible);


    IsSpectrumVisible::IsSpectrumVisible()
      : CommandBase(CmdName, TargetId)
    {

    }

    IsSpectrumVisiblePtr IsSpectrumVisible::create()
    {
      return std::make_shared<IsSpectrumVisible>();
    }

    IsSpectrumVisiblePtr IsSpectrumVisible::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsSpectrumVisible>(ptr);
    }

    bool IsSpectrumVisible::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string IsSpectrumVisible::documentation() const { return Documentation; }

    const std::vector<std::string>& IsSpectrumVisible::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int IsSpectrumVisible::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}

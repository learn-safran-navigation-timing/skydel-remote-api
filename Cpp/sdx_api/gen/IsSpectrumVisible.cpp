
#include "gen/IsSpectrumVisible.h"

#include "command_factory.h"
#include "command_result_factory.h"
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

    REGISTER_COMMAND_FACTORY(IsSpectrumVisible);


    IsSpectrumVisible::IsSpectrumVisible()
      : CommandBase(CmdName)
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


    int IsSpectrumVisible::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}

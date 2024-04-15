
#include "IsOsnmaEnabledForEachSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsOsnmaEnabledForEachSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsOsnmaEnabledForEachSV::CmdName = "IsOsnmaEnabledForEachSV";
    const char* const IsOsnmaEnabledForEachSV::Documentation = "Tells if OSNMA is enabled or disabled for each satellite.";
    const char* const IsOsnmaEnabledForEachSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(IsOsnmaEnabledForEachSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(IsOsnmaEnabledForEachSV);


    IsOsnmaEnabledForEachSV::IsOsnmaEnabledForEachSV()
      : CommandBase(CmdName, TargetId)
    {

    }

    IsOsnmaEnabledForEachSVPtr IsOsnmaEnabledForEachSV::create()
    {
      return std::make_shared<IsOsnmaEnabledForEachSV>();
    }

    IsOsnmaEnabledForEachSVPtr IsOsnmaEnabledForEachSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsOsnmaEnabledForEachSV>(ptr);
    }

    bool IsOsnmaEnabledForEachSV::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string IsOsnmaEnabledForEachSV::documentation() const { return Documentation; }

    const std::vector<std::string>& IsOsnmaEnabledForEachSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int IsOsnmaEnabledForEachSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}

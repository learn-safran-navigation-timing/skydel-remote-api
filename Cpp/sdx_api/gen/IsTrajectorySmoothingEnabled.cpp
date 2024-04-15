
#include "IsTrajectorySmoothingEnabled.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsTrajectorySmoothingEnabled
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsTrajectorySmoothingEnabled::CmdName = "IsTrajectorySmoothingEnabled";
    const char* const IsTrajectorySmoothingEnabled::Documentation = "Get trajectory smoothing for Track or Route enabled or disabled";
    const char* const IsTrajectorySmoothingEnabled::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(IsTrajectorySmoothingEnabled);
    REGISTER_COMMAND_TO_FACTORY_IMPL(IsTrajectorySmoothingEnabled);


    IsTrajectorySmoothingEnabled::IsTrajectorySmoothingEnabled()
      : CommandBase(CmdName, TargetId)
    {

    }

    IsTrajectorySmoothingEnabledPtr IsTrajectorySmoothingEnabled::create()
    {
      return std::make_shared<IsTrajectorySmoothingEnabled>();
    }

    IsTrajectorySmoothingEnabledPtr IsTrajectorySmoothingEnabled::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsTrajectorySmoothingEnabled>(ptr);
    }

    bool IsTrajectorySmoothingEnabled::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string IsTrajectorySmoothingEnabled::documentation() const { return Documentation; }

    const std::vector<std::string>& IsTrajectorySmoothingEnabled::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int IsTrajectorySmoothingEnabled::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}

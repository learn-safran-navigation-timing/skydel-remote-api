
#include "RemoveAllInterferences.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of RemoveAllInterferences
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const RemoveAllInterferences::CmdName = "RemoveAllInterferences";
    const char* const RemoveAllInterferences::Documentation = "Removes all interference signals.";
    const char* const RemoveAllInterferences::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(RemoveAllInterferences);
    REGISTER_COMMAND_TO_FACTORY_IMPL(RemoveAllInterferences);


    RemoveAllInterferences::RemoveAllInterferences()
      : CommandBase(CmdName, TargetId)
    {

    }

    RemoveAllInterferencesPtr RemoveAllInterferences::create()
    {
      return std::make_shared<RemoveAllInterferences>();
    }

    RemoveAllInterferencesPtr RemoveAllInterferences::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<RemoveAllInterferences>(ptr);
    }

    bool RemoveAllInterferences::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string RemoveAllInterferences::documentation() const { return Documentation; }

    const std::vector<std::string>& RemoveAllInterferences::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int RemoveAllInterferences::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}


#include "gen/RemoveAllInterferences.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of RemoveAllInterferences
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const RemoveAllInterferences::CmdName = "RemoveAllInterferences";
    const char* const RemoveAllInterferences::Documentation = "Clear all interferences";

    REGISTER_COMMAND_FACTORY(RemoveAllInterferences);


    RemoveAllInterferences::RemoveAllInterferences()
      : CommandBase(CmdName)
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


    int RemoveAllInterferences::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}

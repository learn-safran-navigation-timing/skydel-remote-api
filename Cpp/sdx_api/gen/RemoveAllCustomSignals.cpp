
#include "gen/RemoveAllCustomSignals.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of RemoveAllCustomSignals
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const RemoveAllCustomSignals::CmdName = "RemoveAllCustomSignals";
    const char* const RemoveAllCustomSignals::Documentation = "Removes all the custom signals";

    REGISTER_COMMAND_FACTORY(RemoveAllCustomSignals);


    RemoveAllCustomSignals::RemoveAllCustomSignals()
      : CommandBase(CmdName)
    {

    }

    RemoveAllCustomSignalsPtr RemoveAllCustomSignals::create()
    {
      return std::make_shared<RemoveAllCustomSignals>();
    }

    RemoveAllCustomSignalsPtr RemoveAllCustomSignals::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<RemoveAllCustomSignals>(ptr);
    }

    bool RemoveAllCustomSignals::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string RemoveAllCustomSignals::documentation() const { return Documentation; }


    int RemoveAllCustomSignals::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}

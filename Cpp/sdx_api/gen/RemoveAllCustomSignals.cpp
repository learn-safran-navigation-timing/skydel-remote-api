
#include "RemoveAllCustomSignals.h"

#include "command_factory.h"
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
    const char* const RemoveAllCustomSignals::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(RemoveAllCustomSignals);
    REGISTER_COMMAND_TO_FACTORY_IMPL(RemoveAllCustomSignals);


    RemoveAllCustomSignals::RemoveAllCustomSignals()
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& RemoveAllCustomSignals::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int RemoveAllCustomSignals::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}

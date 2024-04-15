
#include "RemoveAllPilots.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of RemoveAllPilots
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const RemoveAllPilots::CmdName = "RemoveAllPilots";
    const char* const RemoveAllPilots::Documentation = "Remove all pilots on all outputs";
    const char* const RemoveAllPilots::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(RemoveAllPilots);
    REGISTER_COMMAND_TO_FACTORY_IMPL(RemoveAllPilots);


    RemoveAllPilots::RemoveAllPilots()
      : CommandBase(CmdName, TargetId)
    {

    }

    RemoveAllPilotsPtr RemoveAllPilots::create()
    {
      return std::make_shared<RemoveAllPilots>();
    }

    RemoveAllPilotsPtr RemoveAllPilots::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<RemoveAllPilots>(ptr);
    }

    bool RemoveAllPilots::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string RemoveAllPilots::documentation() const { return Documentation; }

    const std::vector<std::string>& RemoveAllPilots::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int RemoveAllPilots::executePermission() const
    {
      return EXECUTE_IF_SIMULATING;
    }

  }
}

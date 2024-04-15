
#include "GetStartTimeOffset.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetStartTimeOffset
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetStartTimeOffset::CmdName = "GetStartTimeOffset";
    const char* const GetStartTimeOffset::Documentation = "Get offset between the simulated GPS time and time given by GPS Timing receiver when using GPS Timing receiver to set the start time of the simulation.\n"
      "This value has no effect when GPS start time is \"custom\" or \"computer\".";
    const char* const GetStartTimeOffset::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetStartTimeOffset);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetStartTimeOffset);


    GetStartTimeOffset::GetStartTimeOffset()
      : CommandBase(CmdName, TargetId)
    {

    }

    GetStartTimeOffsetPtr GetStartTimeOffset::create()
    {
      return std::make_shared<GetStartTimeOffset>();
    }

    GetStartTimeOffsetPtr GetStartTimeOffset::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetStartTimeOffset>(ptr);
    }

    bool GetStartTimeOffset::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetStartTimeOffset::documentation() const { return Documentation; }

    const std::vector<std::string>& GetStartTimeOffset::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetStartTimeOffset::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}

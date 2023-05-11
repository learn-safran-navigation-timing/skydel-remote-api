
#include "gen/GetStartTimeOffset.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetStartTimeOffset
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetStartTimeOffset::CmdName = "GetStartTimeOffset";
    const char* const GetStartTimeOffset::Documentation = "Get offset between the simulated GPS time and time given by GPS Timing receiver when using GPS Timing receiver to set the start time of the simulation.\nThis value has no effect when GPS start time is \"custom\" or \"computer\".";

    REGISTER_COMMAND_FACTORY(GetStartTimeOffset);


    GetStartTimeOffset::GetStartTimeOffset()
      : CommandBase(CmdName)
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


    int GetStartTimeOffset::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}

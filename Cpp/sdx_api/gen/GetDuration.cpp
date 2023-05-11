
#include "gen/GetDuration.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetDuration
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetDuration::CmdName = "GetDuration";
    const char* const GetDuration::Documentation = "Get the simulation duration.";

    REGISTER_COMMAND_FACTORY(GetDuration);


    GetDuration::GetDuration()
      : CommandBase(CmdName)
    {

    }

    GetDurationPtr GetDuration::create()
    {
      return std::make_shared<GetDuration>();
    }

    GetDurationPtr GetDuration::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetDuration>(ptr);
    }

    bool GetDuration::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetDuration::documentation() const { return Documentation; }


    int GetDuration::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}

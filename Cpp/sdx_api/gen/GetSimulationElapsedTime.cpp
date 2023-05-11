
#include "gen/GetSimulationElapsedTime.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSimulationElapsedTime
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSimulationElapsedTime::CmdName = "GetSimulationElapsedTime";
    const char* const GetSimulationElapsedTime::Documentation = "Get simulation elapsed time in milliseconds.";

    REGISTER_COMMAND_FACTORY(GetSimulationElapsedTime);


    GetSimulationElapsedTime::GetSimulationElapsedTime()
      : CommandBase(CmdName)
    {

    }

    GetSimulationElapsedTimePtr GetSimulationElapsedTime::create()
    {
      return std::make_shared<GetSimulationElapsedTime>();
    }

    GetSimulationElapsedTimePtr GetSimulationElapsedTime::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSimulationElapsedTime>(ptr);
    }

    bool GetSimulationElapsedTime::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetSimulationElapsedTime::documentation() const { return Documentation; }


    int GetSimulationElapsedTime::executePermission() const
    {
      return EXECUTE_IF_SIMULATING;
    }

  }
}

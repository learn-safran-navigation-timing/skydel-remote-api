
#include "GetSimulationElapsedTime.h"

#include "command_factory.h"
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
    const char* const GetSimulationElapsedTime::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetSimulationElapsedTime);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetSimulationElapsedTime);


    GetSimulationElapsedTime::GetSimulationElapsedTime()
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& GetSimulationElapsedTime::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetSimulationElapsedTime::executePermission() const
    {
      return EXECUTE_IF_SIMULATING;
    }

  }
}

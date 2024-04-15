
#include "GetStartTimeMode.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetStartTimeMode
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetStartTimeMode::CmdName = "GetStartTimeMode";
    const char* const GetStartTimeMode::Documentation = "Get the simulation start time mode.";
    const char* const GetStartTimeMode::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetStartTimeMode);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetStartTimeMode);


    GetStartTimeMode::GetStartTimeMode()
      : CommandBase(CmdName, TargetId)
    {

    }

    GetStartTimeModePtr GetStartTimeMode::create()
    {
      return std::make_shared<GetStartTimeMode>();
    }

    GetStartTimeModePtr GetStartTimeMode::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetStartTimeMode>(ptr);
    }

    bool GetStartTimeMode::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetStartTimeMode::documentation() const { return Documentation; }

    const std::vector<std::string>& GetStartTimeMode::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetStartTimeMode::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}

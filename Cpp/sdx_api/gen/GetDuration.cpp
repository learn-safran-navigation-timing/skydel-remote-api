
#include "GetDuration.h"

#include "command_factory.h"
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
    const char* const GetDuration::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetDuration);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetDuration);


    GetDuration::GetDuration()
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& GetDuration::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetDuration::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}

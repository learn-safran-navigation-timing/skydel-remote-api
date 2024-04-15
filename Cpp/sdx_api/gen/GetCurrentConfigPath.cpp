
#include "GetCurrentConfigPath.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetCurrentConfigPath
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetCurrentConfigPath::CmdName = "GetCurrentConfigPath";
    const char* const GetCurrentConfigPath::Documentation = "Get the config file path currently used by Skydel.";
    const char* const GetCurrentConfigPath::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetCurrentConfigPath);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetCurrentConfigPath);


    GetCurrentConfigPath::GetCurrentConfigPath()
      : CommandBase(CmdName, TargetId)
    {

    }

    GetCurrentConfigPathPtr GetCurrentConfigPath::create()
    {
      return std::make_shared<GetCurrentConfigPath>();
    }

    GetCurrentConfigPathPtr GetCurrentConfigPath::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetCurrentConfigPath>(ptr);
    }

    bool GetCurrentConfigPath::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetCurrentConfigPath::documentation() const { return Documentation; }

    const std::vector<std::string>& GetCurrentConfigPath::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetCurrentConfigPath::executePermission() const
    {
      return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }

  }
}


#include "GetConfigPaths.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetConfigPaths
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetConfigPaths::CmdName = "GetConfigPaths";
    const char* const GetConfigPaths::Documentation = "Get a list of paths for all the files in the Configurations folder.";
    const char* const GetConfigPaths::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetConfigPaths);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetConfigPaths);


    GetConfigPaths::GetConfigPaths()
      : CommandBase(CmdName, TargetId)
    {

    }

    GetConfigPathsPtr GetConfigPaths::create()
    {
      return std::make_shared<GetConfigPaths>();
    }

    GetConfigPathsPtr GetConfigPaths::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetConfigPaths>(ptr);
    }

    bool GetConfigPaths::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetConfigPaths::documentation() const { return Documentation; }

    const std::vector<std::string>& GetConfigPaths::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetConfigPaths::executePermission() const
    {
      return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }

  }
}

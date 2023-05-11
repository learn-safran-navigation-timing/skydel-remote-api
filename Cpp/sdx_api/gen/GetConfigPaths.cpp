
#include "gen/GetConfigPaths.h"

#include "command_factory.h"
#include "command_result_factory.h"
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

    REGISTER_COMMAND_FACTORY(GetConfigPaths);


    GetConfigPaths::GetConfigPaths()
      : CommandBase(CmdName)
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


    int GetConfigPaths::executePermission() const
    {
      return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }

  }
}

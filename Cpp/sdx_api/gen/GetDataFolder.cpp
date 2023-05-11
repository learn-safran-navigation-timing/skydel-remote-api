
#include "gen/GetDataFolder.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetDataFolder
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetDataFolder::CmdName = "GetDataFolder";
    const char* const GetDataFolder::Documentation = "Get Skydel's Data Folder. The user can changed it in the GUI's Preferences.";

    REGISTER_COMMAND_FACTORY(GetDataFolder);


    GetDataFolder::GetDataFolder()
      : CommandBase(CmdName)
    {

    }

    GetDataFolderPtr GetDataFolder::create()
    {
      return std::make_shared<GetDataFolder>();
    }

    GetDataFolderPtr GetDataFolder::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetDataFolder>(ptr);
    }

    bool GetDataFolder::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetDataFolder::documentation() const { return Documentation; }


    int GetDataFolder::executePermission() const
    {
      return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }

  }
}

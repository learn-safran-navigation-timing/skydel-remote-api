
#include "GetDataFolder.h"

#include "command_factory.h"
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
    const char* const GetDataFolder::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetDataFolder);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetDataFolder);


    GetDataFolder::GetDataFolder()
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& GetDataFolder::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetDataFolder::executePermission() const
    {
      return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }

  }
}

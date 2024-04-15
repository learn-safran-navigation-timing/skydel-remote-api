
#include "GetSVDataUpdateMode.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSVDataUpdateMode
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSVDataUpdateMode::CmdName = "GetSVDataUpdateMode";
    const char* const GetSVDataUpdateMode::Documentation = "Get the SV Data Update Mode.";
    const char* const GetSVDataUpdateMode::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetSVDataUpdateMode);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetSVDataUpdateMode);


    GetSVDataUpdateMode::GetSVDataUpdateMode()
      : CommandBase(CmdName, TargetId)
    {

    }

    GetSVDataUpdateModePtr GetSVDataUpdateMode::create()
    {
      return std::make_shared<GetSVDataUpdateMode>();
    }

    GetSVDataUpdateModePtr GetSVDataUpdateMode::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSVDataUpdateMode>(ptr);
    }

    bool GetSVDataUpdateMode::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetSVDataUpdateMode::documentation() const { return Documentation; }

    const std::vector<std::string>& GetSVDataUpdateMode::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetSVDataUpdateMode::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}

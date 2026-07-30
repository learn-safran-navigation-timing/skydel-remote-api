
#include "GetGeoidFilePath.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGeoidFilePath
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGeoidFilePath::CmdName = "GetGeoidFilePath";
    const char* const GetGeoidFilePath::Documentation = "Get the Geoid file path.";
    const char* const GetGeoidFilePath::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetGeoidFilePath);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetGeoidFilePath);


    GetGeoidFilePath::GetGeoidFilePath()
      : CommandBase(CmdName, TargetId)
    {

    }

    GetGeoidFilePathPtr GetGeoidFilePath::create()
    {
      return std::make_shared<GetGeoidFilePath>();
    }

    GetGeoidFilePathPtr GetGeoidFilePath::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGeoidFilePath>(ptr);
    }

    bool GetGeoidFilePath::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetGeoidFilePath::documentation() const { return Documentation; }

    const std::vector<std::string>& GetGeoidFilePath::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetGeoidFilePath::executePermission() const
    {
      return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE;
    }

  }
}

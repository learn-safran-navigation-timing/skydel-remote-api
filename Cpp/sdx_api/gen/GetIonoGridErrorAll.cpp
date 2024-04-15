
#include "GetIonoGridErrorAll.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIonoGridErrorAll
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIonoGridErrorAll::CmdName = "GetIonoGridErrorAll";
    const char* const GetIonoGridErrorAll::Documentation = "Get Error offsets in the ionospheric grid.  The array is zero based, the index 0 in a band array is for the IGP with an index 1, etc.";
    const char* const GetIonoGridErrorAll::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetIonoGridErrorAll);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetIonoGridErrorAll);


    GetIonoGridErrorAll::GetIonoGridErrorAll()
      : CommandBase(CmdName, TargetId)
    {

    }

    GetIonoGridErrorAllPtr GetIonoGridErrorAll::create()
    {
      return std::make_shared<GetIonoGridErrorAll>();
    }

    GetIonoGridErrorAllPtr GetIonoGridErrorAll::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetIonoGridErrorAll>(ptr);
    }

    bool GetIonoGridErrorAll::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetIonoGridErrorAll::documentation() const { return Documentation; }

    const std::vector<std::string>& GetIonoGridErrorAll::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetIonoGridErrorAll::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}


#include "gen/GetIonoGridErrorAll.h"

#include "command_factory.h"
#include "command_result_factory.h"
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

    REGISTER_COMMAND_FACTORY(GetIonoGridErrorAll);


    GetIonoGridErrorAll::GetIonoGridErrorAll()
      : CommandBase(CmdName)
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


    int GetIonoGridErrorAll::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}


#include "gen/GetCnav2PagesEnabled.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetCnav2PagesEnabled
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetCnav2PagesEnabled::CmdName = "GetCnav2PagesEnabled";
    const char* const GetCnav2PagesEnabled::Documentation = "Get the enabled L1C CNAV2 pages";

    REGISTER_COMMAND_FACTORY(GetCnav2PagesEnabled);


    GetCnav2PagesEnabled::GetCnav2PagesEnabled()
      : CommandBase(CmdName)
    {

    }

    GetCnav2PagesEnabledPtr GetCnav2PagesEnabled::create()
    {
      return std::make_shared<GetCnav2PagesEnabled>();
    }

    GetCnav2PagesEnabledPtr GetCnav2PagesEnabled::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetCnav2PagesEnabled>(ptr);
    }

    bool GetCnav2PagesEnabled::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetCnav2PagesEnabled::documentation() const { return Documentation; }


    int GetCnav2PagesEnabled::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}

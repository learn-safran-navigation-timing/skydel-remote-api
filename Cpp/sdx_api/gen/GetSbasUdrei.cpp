
#include "gen/GetSbasUdrei.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSbasUdrei
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSbasUdrei::CmdName = "GetSbasUdrei";
    const char* const GetSbasUdrei::Documentation = "Please note the command GetSbasUdrei is deprecated since 22.2. You may use GetUdreiForSV.\n\nGet the global UDREI value transmitted by SBAS";

    const char* const GetSbasUdrei::Deprecated = "Please note the command GetSbasUdrei is deprecated since 22.2. You may use GetUdreiForSV.";

    REGISTER_COMMAND_FACTORY(GetSbasUdrei);


    GetSbasUdrei::GetSbasUdrei()
      : CommandBase(CmdName)
    {

    }

    GetSbasUdreiPtr GetSbasUdrei::create()
    {
      return std::make_shared<GetSbasUdrei>();
    }

    GetSbasUdreiPtr GetSbasUdrei::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSbasUdrei>(ptr);
    }

    bool GetSbasUdrei::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetSbasUdrei::documentation() const { return Documentation; }

    Sdx::optional<std::string> GetSbasUdrei::deprecated() const { return Sdx::optional<std::string>{Deprecated}; }


    int GetSbasUdrei::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}

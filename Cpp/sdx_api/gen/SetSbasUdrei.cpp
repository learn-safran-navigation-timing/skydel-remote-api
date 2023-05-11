
#include "gen/SetSbasUdrei.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetSbasUdrei
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetSbasUdrei::CmdName = "SetSbasUdrei";
    const char* const SetSbasUdrei::Documentation = "Please note the command SetSbasUdrei is deprecated since 22.2. You may use SetUdreiForSV.\n\nSet the global UDREI value transmitted by SBAS";

    const char* const SetSbasUdrei::Deprecated = "Please note the command SetSbasUdrei is deprecated since 22.2. You may use SetUdreiForSV.";

    REGISTER_COMMAND_FACTORY(SetSbasUdrei);


    SetSbasUdrei::SetSbasUdrei()
      : CommandBase(CmdName)
    {}

    SetSbasUdrei::SetSbasUdrei(int udrei)
      : CommandBase(CmdName)
    {

      setUdrei(udrei);
    }

    SetSbasUdreiPtr SetSbasUdrei::create(int udrei)
    {
      return std::make_shared<SetSbasUdrei>(udrei);
    }

    SetSbasUdreiPtr SetSbasUdrei::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetSbasUdrei>(ptr);
    }

    bool SetSbasUdrei::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Udrei"])
        ;

    }

    std::string SetSbasUdrei::documentation() const { return Documentation; }

    Sdx::optional<std::string> SetSbasUdrei::deprecated() const { return Sdx::optional<std::string>{Deprecated}; }


    int SetSbasUdrei::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int SetSbasUdrei::udrei() const
    {
      return parse_json<int>::parse(m_values["Udrei"]);
    }

    void SetSbasUdrei::setUdrei(int udrei)
    {
      m_values.AddMember("Udrei", parse_json<int>::format(udrei, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

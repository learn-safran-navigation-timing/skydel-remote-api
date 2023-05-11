
#include "gen/SetIntTxHil.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetIntTxHil
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetIntTxHil::CmdName = "SetIntTxHil";
    const char* const SetIntTxHil::Documentation = "Set interference transmitter HIL trajectory";

    REGISTER_COMMAND_FACTORY(SetIntTxHil);


    SetIntTxHil::SetIntTxHil()
      : CommandBase(CmdName)
    {}

    SetIntTxHil::SetIntTxHil(const std::string& id)
      : CommandBase(CmdName)
    {

      setId(id);
    }

    SetIntTxHilPtr SetIntTxHil::create(const std::string& id)
    {
      return std::make_shared<SetIntTxHil>(id);
    }

    SetIntTxHilPtr SetIntTxHil::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetIntTxHil>(ptr);
    }

    bool SetIntTxHil::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string SetIntTxHil::documentation() const { return Documentation; }


    int SetIntTxHil::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    std::string SetIntTxHil::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void SetIntTxHil::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

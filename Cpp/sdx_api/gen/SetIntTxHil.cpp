
#include "SetIntTxHil.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetIntTxHil
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetIntTxHil::CmdName = "SetIntTxHil";
    const char* const SetIntTxHil::Documentation = "Set interference transmitter HIL trajectory\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ ------------------------------\n"
      "Id   string Transmitter unique identifier.";
    const char* const SetIntTxHil::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetIntTxHil);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetIntTxHil);


    SetIntTxHil::SetIntTxHil()
      : CommandBase(CmdName, TargetId)
    {}

    SetIntTxHil::SetIntTxHil(const std::string& id)
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& SetIntTxHil::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Id"}; 
      return names; 
    }


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


#include "SetSpoofTxHil.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetSpoofTxHil
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetSpoofTxHil::CmdName = "SetSpoofTxHil";
    const char* const SetSpoofTxHil::Documentation = "Set spoofer transmitter HIL trajectory\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ ------------------------------\n"
      "Id   string Transmitter unique identifier.";
    const char* const SetSpoofTxHil::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetSpoofTxHil);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetSpoofTxHil);


    SetSpoofTxHil::SetSpoofTxHil()
      : CommandBase(CmdName, TargetId)
    {}

    SetSpoofTxHil::SetSpoofTxHil(const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setId(id);
    }

    SetSpoofTxHilPtr SetSpoofTxHil::create(const std::string& id)
    {
      return std::make_shared<SetSpoofTxHil>(id);
    }

    SetSpoofTxHilPtr SetSpoofTxHil::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetSpoofTxHil>(ptr);
    }

    bool SetSpoofTxHil::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string SetSpoofTxHil::documentation() const { return Documentation; }

    const std::vector<std::string>& SetSpoofTxHil::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Id"}; 
      return names; 
    }


    int SetSpoofTxHil::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetSpoofTxHil::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void SetSpoofTxHil::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

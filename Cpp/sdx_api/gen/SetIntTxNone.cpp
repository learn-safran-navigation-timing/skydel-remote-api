
#include "SetIntTxNone.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetIntTxNone
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetIntTxNone::CmdName = "SetIntTxNone";
    const char* const SetIntTxNone::Documentation = "Set an undefined trajectory to a transmitter, thus preventing it to be modulated (default value).\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ ------------------------------\n"
      "Id   string Transmitter unique identifier.";
    const char* const SetIntTxNone::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetIntTxNone);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetIntTxNone);


    SetIntTxNone::SetIntTxNone()
      : CommandBase(CmdName, TargetId)
    {}

    SetIntTxNone::SetIntTxNone(const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setId(id);
    }

    SetIntTxNonePtr SetIntTxNone::create(const std::string& id)
    {
      return std::make_shared<SetIntTxNone>(id);
    }

    SetIntTxNonePtr SetIntTxNone::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetIntTxNone>(ptr);
    }

    bool SetIntTxNone::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string SetIntTxNone::documentation() const { return Documentation; }

    const std::vector<std::string>& SetIntTxNone::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Id"}; 
      return names; 
    }


    int SetIntTxNone::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    std::string SetIntTxNone::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void SetIntTxNone::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}


#include "RemoveIntTx.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of RemoveIntTx
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const RemoveIntTx::CmdName = "RemoveIntTx";
    const char* const RemoveIntTx::Documentation = "Removes the interference transmitter. See EnableIntTx if all you want is to\n"
      "disable the interference temporarily.\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ ------------------------------\n"
      "Id   string Transmitter unique identifier.";
    const char* const RemoveIntTx::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(RemoveIntTx);
    REGISTER_COMMAND_TO_FACTORY_IMPL(RemoveIntTx);


    RemoveIntTx::RemoveIntTx()
      : CommandBase(CmdName, TargetId)
    {}

    RemoveIntTx::RemoveIntTx(const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setId(id);
    }

    RemoveIntTxPtr RemoveIntTx::create(const std::string& id)
    {
      return std::make_shared<RemoveIntTx>(id);
    }

    RemoveIntTxPtr RemoveIntTx::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<RemoveIntTx>(ptr);
    }

    bool RemoveIntTx::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string RemoveIntTx::documentation() const { return Documentation; }

    const std::vector<std::string>& RemoveIntTx::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Id"}; 
      return names; 
    }


    int RemoveIntTx::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    std::string RemoveIntTx::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void RemoveIntTx::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

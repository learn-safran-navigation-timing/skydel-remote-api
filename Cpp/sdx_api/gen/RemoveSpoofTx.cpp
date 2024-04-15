
#include "RemoveSpoofTx.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of RemoveSpoofTx
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const RemoveSpoofTx::CmdName = "RemoveSpoofTx";
    const char* const RemoveSpoofTx::Documentation = "Removes the spoofer transmitter. See EnableSpoofTx if all you want is to\n"
      "disable the interference temporarily.\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ ------------------------------\n"
      "Id   string Transmitter unique identifier.";
    const char* const RemoveSpoofTx::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(RemoveSpoofTx);
    REGISTER_COMMAND_TO_FACTORY_IMPL(RemoveSpoofTx);


    RemoveSpoofTx::RemoveSpoofTx()
      : CommandBase(CmdName, TargetId)
    {}

    RemoveSpoofTx::RemoveSpoofTx(const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setId(id);
    }

    RemoveSpoofTxPtr RemoveSpoofTx::create(const std::string& id)
    {
      return std::make_shared<RemoveSpoofTx>(id);
    }

    RemoveSpoofTxPtr RemoveSpoofTx::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<RemoveSpoofTx>(ptr);
    }

    bool RemoveSpoofTx::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string RemoveSpoofTx::documentation() const { return Documentation; }

    const std::vector<std::string>& RemoveSpoofTx::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Id"}; 
      return names; 
    }


    int RemoveSpoofTx::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string RemoveSpoofTx::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void RemoveSpoofTx::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

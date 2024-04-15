
#include "GetIntTx.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIntTx
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIntTx::CmdName = "GetIntTx";
    const char* const GetIntTx::Documentation = "Get an interference transmitter.\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ ------------------------------\n"
      "Id   string Transmitter unique identifier.";
    const char* const GetIntTx::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetIntTx);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetIntTx);


    GetIntTx::GetIntTx()
      : CommandBase(CmdName, TargetId)
    {}

    GetIntTx::GetIntTx(const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setId(id);
    }

    GetIntTxPtr GetIntTx::create(const std::string& id)
    {
      return std::make_shared<GetIntTx>(id);
    }

    GetIntTxPtr GetIntTx::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetIntTx>(ptr);
    }

    bool GetIntTx::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetIntTx::documentation() const { return Documentation; }

    const std::vector<std::string>& GetIntTx::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Id"}; 
      return names; 
    }


    int GetIntTx::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetIntTx::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetIntTx::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

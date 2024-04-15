
#include "GetAllSignalsFromIntTx.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetAllSignalsFromIntTx
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetAllSignalsFromIntTx::CmdName = "GetAllSignalsFromIntTx";
    const char* const GetAllSignalsFromIntTx::Documentation = "Get all signal ID for this interference transmitters.\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ ------------------------------\n"
      "Id   string Transmitter unique identifier.";
    const char* const GetAllSignalsFromIntTx::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetAllSignalsFromIntTx);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetAllSignalsFromIntTx);


    GetAllSignalsFromIntTx::GetAllSignalsFromIntTx()
      : CommandBase(CmdName, TargetId)
    {}

    GetAllSignalsFromIntTx::GetAllSignalsFromIntTx(const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setId(id);
    }

    GetAllSignalsFromIntTxPtr GetAllSignalsFromIntTx::create(const std::string& id)
    {
      return std::make_shared<GetAllSignalsFromIntTx>(id);
    }

    GetAllSignalsFromIntTxPtr GetAllSignalsFromIntTx::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetAllSignalsFromIntTx>(ptr);
    }

    bool GetAllSignalsFromIntTx::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetAllSignalsFromIntTx::documentation() const { return Documentation; }

    const std::vector<std::string>& GetAllSignalsFromIntTx::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Id"}; 
      return names; 
    }


    int GetAllSignalsFromIntTx::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetAllSignalsFromIntTx::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetAllSignalsFromIntTx::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

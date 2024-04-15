
#include "GetSpoofTx.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSpoofTx
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSpoofTx::CmdName = "GetSpoofTx";
    const char* const GetSpoofTx::Documentation = "Get a spoofer transmitter. For set : the transmitter Id parameter is not set (empty string),\n"
      "Skydel will assign a unique Id to the transmitter. If the Id is set and already used by Skydel, the\n"
      "command will fail.\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ ------------------------------\n"
      "Id   string Transmitter unique identifier.";
    const char* const GetSpoofTx::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetSpoofTx);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetSpoofTx);


    GetSpoofTx::GetSpoofTx()
      : CommandBase(CmdName, TargetId)
    {}

    GetSpoofTx::GetSpoofTx(const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setId(id);
    }

    GetSpoofTxPtr GetSpoofTx::create(const std::string& id)
    {
      return std::make_shared<GetSpoofTx>(id);
    }

    GetSpoofTxPtr GetSpoofTx::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSpoofTx>(ptr);
    }

    bool GetSpoofTx::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetSpoofTx::documentation() const { return Documentation; }

    const std::vector<std::string>& GetSpoofTx::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Id"}; 
      return names; 
    }


    int GetSpoofTx::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetSpoofTx::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetSpoofTx::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

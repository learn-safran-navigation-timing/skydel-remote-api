
#include "GetIntTxFixEcef.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIntTxFixEcef
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIntTxFixEcef::CmdName = "GetIntTxFixEcef";
    const char* const GetIntTxFixEcef::Documentation = "Get interference transmitter static position and orientation\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ ------------------------------\n"
      "Id   string Transmitter unique identifier.";
    const char* const GetIntTxFixEcef::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetIntTxFixEcef);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetIntTxFixEcef);


    GetIntTxFixEcef::GetIntTxFixEcef()
      : CommandBase(CmdName, TargetId)
    {}

    GetIntTxFixEcef::GetIntTxFixEcef(const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setId(id);
    }

    GetIntTxFixEcefPtr GetIntTxFixEcef::create(const std::string& id)
    {
      return std::make_shared<GetIntTxFixEcef>(id);
    }

    GetIntTxFixEcefPtr GetIntTxFixEcef::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetIntTxFixEcef>(ptr);
    }

    bool GetIntTxFixEcef::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetIntTxFixEcef::documentation() const { return Documentation; }

    const std::vector<std::string>& GetIntTxFixEcef::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Id"}; 
      return names; 
    }


    int GetIntTxFixEcef::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetIntTxFixEcef::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetIntTxFixEcef::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

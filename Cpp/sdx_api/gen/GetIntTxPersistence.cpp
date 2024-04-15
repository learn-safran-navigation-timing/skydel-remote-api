
#include "GetIntTxPersistence.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIntTxPersistence
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIntTxPersistence::CmdName = "GetIntTxPersistence";
    const char* const GetIntTxPersistence::Documentation = "Get whether the transmitter should keep the modifications done during the simulation.\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ ------------------------------\n"
      "Id   string Transmitter unique identifier.";
    const char* const GetIntTxPersistence::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetIntTxPersistence);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetIntTxPersistence);


    GetIntTxPersistence::GetIntTxPersistence()
      : CommandBase(CmdName, TargetId)
    {}

    GetIntTxPersistence::GetIntTxPersistence(const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setId(id);
    }

    GetIntTxPersistencePtr GetIntTxPersistence::create(const std::string& id)
    {
      return std::make_shared<GetIntTxPersistence>(id);
    }

    GetIntTxPersistencePtr GetIntTxPersistence::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetIntTxPersistence>(ptr);
    }

    bool GetIntTxPersistence::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetIntTxPersistence::documentation() const { return Documentation; }

    const std::vector<std::string>& GetIntTxPersistence::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Id"}; 
      return names; 
    }


    int GetIntTxPersistence::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetIntTxPersistence::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetIntTxPersistence::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

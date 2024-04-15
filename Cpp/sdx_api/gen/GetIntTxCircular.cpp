
#include "GetIntTxCircular.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIntTxCircular
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIntTxCircular::CmdName = "GetIntTxCircular";
    const char* const GetIntTxCircular::Documentation = "Get interference transmitter circular trajectory\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ ------------------------------\n"
      "Id   string Transmitter unique identifier.";
    const char* const GetIntTxCircular::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetIntTxCircular);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetIntTxCircular);


    GetIntTxCircular::GetIntTxCircular()
      : CommandBase(CmdName, TargetId)
    {}

    GetIntTxCircular::GetIntTxCircular(const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setId(id);
    }

    GetIntTxCircularPtr GetIntTxCircular::create(const std::string& id)
    {
      return std::make_shared<GetIntTxCircular>(id);
    }

    GetIntTxCircularPtr GetIntTxCircular::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetIntTxCircular>(ptr);
    }

    bool GetIntTxCircular::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetIntTxCircular::documentation() const { return Documentation; }

    const std::vector<std::string>& GetIntTxCircular::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Id"}; 
      return names; 
    }


    int GetIntTxCircular::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetIntTxCircular::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetIntTxCircular::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

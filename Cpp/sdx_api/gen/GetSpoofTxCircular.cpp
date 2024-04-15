
#include "GetSpoofTxCircular.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSpoofTxCircular
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSpoofTxCircular::CmdName = "GetSpoofTxCircular";
    const char* const GetSpoofTxCircular::Documentation = "Get spoofer transmitter circular trajectory\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ ------------------------------\n"
      "Id   string Transmitter unique identifier.";
    const char* const GetSpoofTxCircular::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetSpoofTxCircular);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetSpoofTxCircular);


    GetSpoofTxCircular::GetSpoofTxCircular()
      : CommandBase(CmdName, TargetId)
    {}

    GetSpoofTxCircular::GetSpoofTxCircular(const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setId(id);
    }

    GetSpoofTxCircularPtr GetSpoofTxCircular::create(const std::string& id)
    {
      return std::make_shared<GetSpoofTxCircular>(id);
    }

    GetSpoofTxCircularPtr GetSpoofTxCircular::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSpoofTxCircular>(ptr);
    }

    bool GetSpoofTxCircular::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetSpoofTxCircular::documentation() const { return Documentation; }

    const std::vector<std::string>& GetSpoofTxCircular::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Id"}; 
      return names; 
    }


    int GetSpoofTxCircular::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetSpoofTxCircular::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetSpoofTxCircular::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

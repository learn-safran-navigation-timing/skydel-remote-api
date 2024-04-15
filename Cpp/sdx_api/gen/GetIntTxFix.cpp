
#include "GetIntTxFix.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIntTxFix
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIntTxFix::CmdName = "GetIntTxFix";
    const char* const GetIntTxFix::Documentation = "Get interference transmitter static position and orientation\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ ------------------------------\n"
      "Id   string Transmitter unique identifier.";
    const char* const GetIntTxFix::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetIntTxFix);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetIntTxFix);


    GetIntTxFix::GetIntTxFix()
      : CommandBase(CmdName, TargetId)
    {}

    GetIntTxFix::GetIntTxFix(const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setId(id);
    }

    GetIntTxFixPtr GetIntTxFix::create(const std::string& id)
    {
      return std::make_shared<GetIntTxFix>(id);
    }

    GetIntTxFixPtr GetIntTxFix::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetIntTxFix>(ptr);
    }

    bool GetIntTxFix::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetIntTxFix::documentation() const { return Documentation; }

    const std::vector<std::string>& GetIntTxFix::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Id"}; 
      return names; 
    }


    int GetIntTxFix::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetIntTxFix::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetIntTxFix::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

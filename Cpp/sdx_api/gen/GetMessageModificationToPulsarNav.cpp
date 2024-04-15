
#include "GetMessageModificationToPulsarNav.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetMessageModificationToPulsarNav
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetMessageModificationToPulsarNav::CmdName = "GetMessageModificationToPulsarNav";
    const char* const GetMessageModificationToPulsarNav::Documentation = "Get infos about the PULSAR NAV message modification with this ID.\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ ------------------------------\n"
      "Id   string Unique identifier of the event";
    const char* const GetMessageModificationToPulsarNav::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetMessageModificationToPulsarNav);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetMessageModificationToPulsarNav);


    GetMessageModificationToPulsarNav::GetMessageModificationToPulsarNav()
      : CommandBase(CmdName, TargetId)
    {}

    GetMessageModificationToPulsarNav::GetMessageModificationToPulsarNav(const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setId(id);
    }

    GetMessageModificationToPulsarNavPtr GetMessageModificationToPulsarNav::create(const std::string& id)
    {
      return std::make_shared<GetMessageModificationToPulsarNav>(id);
    }

    GetMessageModificationToPulsarNavPtr GetMessageModificationToPulsarNav::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetMessageModificationToPulsarNav>(ptr);
    }

    bool GetMessageModificationToPulsarNav::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetMessageModificationToPulsarNav::documentation() const { return Documentation; }

    const std::vector<std::string>& GetMessageModificationToPulsarNav::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Id"}; 
      return names; 
    }


    int GetMessageModificationToPulsarNav::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetMessageModificationToPulsarNav::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetMessageModificationToPulsarNav::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

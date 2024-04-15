
#include "GetMessageModificationToNavICNav.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetMessageModificationToNavICNav
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetMessageModificationToNavICNav::CmdName = "GetMessageModificationToNavICNav";
    const char* const GetMessageModificationToNavICNav::Documentation = "Get infos about the NavIC NAV message modification with this ID.\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ ------------------------------\n"
      "Id   string Unique identifier of the event";
    const char* const GetMessageModificationToNavICNav::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetMessageModificationToNavICNav);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetMessageModificationToNavICNav);


    GetMessageModificationToNavICNav::GetMessageModificationToNavICNav()
      : CommandBase(CmdName, TargetId)
    {}

    GetMessageModificationToNavICNav::GetMessageModificationToNavICNav(const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setId(id);
    }

    GetMessageModificationToNavICNavPtr GetMessageModificationToNavICNav::create(const std::string& id)
    {
      return std::make_shared<GetMessageModificationToNavICNav>(id);
    }

    GetMessageModificationToNavICNavPtr GetMessageModificationToNavICNav::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetMessageModificationToNavICNav>(ptr);
    }

    bool GetMessageModificationToNavICNav::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetMessageModificationToNavICNav::documentation() const { return Documentation; }

    const std::vector<std::string>& GetMessageModificationToNavICNav::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Id"}; 
      return names; 
    }


    int GetMessageModificationToNavICNav::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetMessageModificationToNavICNav::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetMessageModificationToNavICNav::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

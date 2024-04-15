
#include "GetMessageModificationToSbasNav.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetMessageModificationToSbasNav
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetMessageModificationToSbasNav::CmdName = "GetMessageModificationToSbasNav";
    const char* const GetMessageModificationToSbasNav::Documentation = "Get infos about the SBAS NAV message modification with this ID.\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ ------------------------------\n"
      "Id   string Unique identifier of the event";
    const char* const GetMessageModificationToSbasNav::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetMessageModificationToSbasNav);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetMessageModificationToSbasNav);


    GetMessageModificationToSbasNav::GetMessageModificationToSbasNav()
      : CommandBase(CmdName, TargetId)
    {}

    GetMessageModificationToSbasNav::GetMessageModificationToSbasNav(const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setId(id);
    }

    GetMessageModificationToSbasNavPtr GetMessageModificationToSbasNav::create(const std::string& id)
    {
      return std::make_shared<GetMessageModificationToSbasNav>(id);
    }

    GetMessageModificationToSbasNavPtr GetMessageModificationToSbasNav::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetMessageModificationToSbasNav>(ptr);
    }

    bool GetMessageModificationToSbasNav::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetMessageModificationToSbasNav::documentation() const { return Documentation; }

    const std::vector<std::string>& GetMessageModificationToSbasNav::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Id"}; 
      return names; 
    }


    int GetMessageModificationToSbasNav::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetMessageModificationToSbasNav::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetMessageModificationToSbasNav::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

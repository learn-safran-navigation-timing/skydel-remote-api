
#include "GetMessageModificationToQzssCNav.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetMessageModificationToQzssCNav
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetMessageModificationToQzssCNav::CmdName = "GetMessageModificationToQzssCNav";
    const char* const GetMessageModificationToQzssCNav::Documentation = "Get infos about the QZSS CNAV message modification with this ID.\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ ------------------------------\n"
      "Id   string Unique identifier of the event";
    const char* const GetMessageModificationToQzssCNav::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetMessageModificationToQzssCNav);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetMessageModificationToQzssCNav);


    GetMessageModificationToQzssCNav::GetMessageModificationToQzssCNav()
      : CommandBase(CmdName, TargetId)
    {}

    GetMessageModificationToQzssCNav::GetMessageModificationToQzssCNav(const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setId(id);
    }

    GetMessageModificationToQzssCNavPtr GetMessageModificationToQzssCNav::create(const std::string& id)
    {
      return std::make_shared<GetMessageModificationToQzssCNav>(id);
    }

    GetMessageModificationToQzssCNavPtr GetMessageModificationToQzssCNav::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetMessageModificationToQzssCNav>(ptr);
    }

    bool GetMessageModificationToQzssCNav::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetMessageModificationToQzssCNav::documentation() const { return Documentation; }

    const std::vector<std::string>& GetMessageModificationToQzssCNav::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Id"}; 
      return names; 
    }


    int GetMessageModificationToQzssCNav::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetMessageModificationToQzssCNav::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetMessageModificationToQzssCNav::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

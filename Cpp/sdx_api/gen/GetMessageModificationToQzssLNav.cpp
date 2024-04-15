
#include "GetMessageModificationToQzssLNav.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetMessageModificationToQzssLNav
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetMessageModificationToQzssLNav::CmdName = "GetMessageModificationToQzssLNav";
    const char* const GetMessageModificationToQzssLNav::Documentation = "Get infos about the QZSS LNAV message modification with this ID.\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ ------------------------------\n"
      "Id   string Unique identifier of the event";
    const char* const GetMessageModificationToQzssLNav::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetMessageModificationToQzssLNav);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetMessageModificationToQzssLNav);


    GetMessageModificationToQzssLNav::GetMessageModificationToQzssLNav()
      : CommandBase(CmdName, TargetId)
    {}

    GetMessageModificationToQzssLNav::GetMessageModificationToQzssLNav(const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setId(id);
    }

    GetMessageModificationToQzssLNavPtr GetMessageModificationToQzssLNav::create(const std::string& id)
    {
      return std::make_shared<GetMessageModificationToQzssLNav>(id);
    }

    GetMessageModificationToQzssLNavPtr GetMessageModificationToQzssLNav::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetMessageModificationToQzssLNav>(ptr);
    }

    bool GetMessageModificationToQzssLNav::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetMessageModificationToQzssLNav::documentation() const { return Documentation; }

    const std::vector<std::string>& GetMessageModificationToQzssLNav::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Id"}; 
      return names; 
    }


    int GetMessageModificationToQzssLNav::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetMessageModificationToQzssLNav::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetMessageModificationToQzssLNav::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}


#include "gen/GetMessageModificationToQzssLNav.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetMessageModificationToQzssLNav
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetMessageModificationToQzssLNav::CmdName = "GetMessageModificationToQzssLNav";
    const char* const GetMessageModificationToQzssLNav::Documentation = "Get infos about the QZSS LNAV message modification with this ID.";

    REGISTER_COMMAND_FACTORY(GetMessageModificationToQzssLNav);


    GetMessageModificationToQzssLNav::GetMessageModificationToQzssLNav()
      : CommandBase(CmdName)
    {}

    GetMessageModificationToQzssLNav::GetMessageModificationToQzssLNav(const std::string& id)
      : CommandBase(CmdName)
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

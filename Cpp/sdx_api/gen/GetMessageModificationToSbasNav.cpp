
#include "gen/GetMessageModificationToSbasNav.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetMessageModificationToSbasNav
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetMessageModificationToSbasNav::CmdName = "GetMessageModificationToSbasNav";
    const char* const GetMessageModificationToSbasNav::Documentation = "Get infos about the SBAS NAV message modification with this ID.";

    REGISTER_COMMAND_FACTORY(GetMessageModificationToSbasNav);


    GetMessageModificationToSbasNav::GetMessageModificationToSbasNav()
      : CommandBase(CmdName)
    {}

    GetMessageModificationToSbasNav::GetMessageModificationToSbasNav(const std::string& id)
      : CommandBase(CmdName)
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

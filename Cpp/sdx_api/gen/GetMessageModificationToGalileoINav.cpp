
#include "gen/GetMessageModificationToGalileoINav.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetMessageModificationToGalileoINav
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetMessageModificationToGalileoINav::CmdName = "GetMessageModificationToGalileoINav";
    const char* const GetMessageModificationToGalileoINav::Documentation = "Get infos about the Galileo I/NAV message modification with this ID.";

    REGISTER_COMMAND_FACTORY(GetMessageModificationToGalileoINav);


    GetMessageModificationToGalileoINav::GetMessageModificationToGalileoINav()
      : CommandBase(CmdName)
    {}

    GetMessageModificationToGalileoINav::GetMessageModificationToGalileoINav(const std::string& id)
      : CommandBase(CmdName)
    {

      setId(id);
    }

    GetMessageModificationToGalileoINavPtr GetMessageModificationToGalileoINav::create(const std::string& id)
    {
      return std::make_shared<GetMessageModificationToGalileoINav>(id);
    }

    GetMessageModificationToGalileoINavPtr GetMessageModificationToGalileoINav::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetMessageModificationToGalileoINav>(ptr);
    }

    bool GetMessageModificationToGalileoINav::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetMessageModificationToGalileoINav::documentation() const { return Documentation; }


    int GetMessageModificationToGalileoINav::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetMessageModificationToGalileoINav::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetMessageModificationToGalileoINav::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

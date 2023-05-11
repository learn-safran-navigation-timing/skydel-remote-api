
#include "gen/GetMessageModificationToGalileoFNav.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetMessageModificationToGalileoFNav
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetMessageModificationToGalileoFNav::CmdName = "GetMessageModificationToGalileoFNav";
    const char* const GetMessageModificationToGalileoFNav::Documentation = "Get infos about the Galileo F/NAV message modification with this ID.";

    REGISTER_COMMAND_FACTORY(GetMessageModificationToGalileoFNav);


    GetMessageModificationToGalileoFNav::GetMessageModificationToGalileoFNav()
      : CommandBase(CmdName)
    {}

    GetMessageModificationToGalileoFNav::GetMessageModificationToGalileoFNav(const std::string& id)
      : CommandBase(CmdName)
    {

      setId(id);
    }

    GetMessageModificationToGalileoFNavPtr GetMessageModificationToGalileoFNav::create(const std::string& id)
    {
      return std::make_shared<GetMessageModificationToGalileoFNav>(id);
    }

    GetMessageModificationToGalileoFNavPtr GetMessageModificationToGalileoFNav::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetMessageModificationToGalileoFNav>(ptr);
    }

    bool GetMessageModificationToGalileoFNav::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetMessageModificationToGalileoFNav::documentation() const { return Documentation; }


    int GetMessageModificationToGalileoFNav::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetMessageModificationToGalileoFNav::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetMessageModificationToGalileoFNav::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

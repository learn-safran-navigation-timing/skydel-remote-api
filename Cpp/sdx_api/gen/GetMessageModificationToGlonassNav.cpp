
#include "gen/GetMessageModificationToGlonassNav.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetMessageModificationToGlonassNav
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetMessageModificationToGlonassNav::CmdName = "GetMessageModificationToGlonassNav";
    const char* const GetMessageModificationToGlonassNav::Documentation = "Get infos about the GLONASS NAV message modification with this ID.";

    REGISTER_COMMAND_FACTORY(GetMessageModificationToGlonassNav);


    GetMessageModificationToGlonassNav::GetMessageModificationToGlonassNav()
      : CommandBase(CmdName)
    {}

    GetMessageModificationToGlonassNav::GetMessageModificationToGlonassNav(const std::string& id)
      : CommandBase(CmdName)
    {

      setId(id);
    }

    GetMessageModificationToGlonassNavPtr GetMessageModificationToGlonassNav::create(const std::string& id)
    {
      return std::make_shared<GetMessageModificationToGlonassNav>(id);
    }

    GetMessageModificationToGlonassNavPtr GetMessageModificationToGlonassNav::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetMessageModificationToGlonassNav>(ptr);
    }

    bool GetMessageModificationToGlonassNav::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetMessageModificationToGlonassNav::documentation() const { return Documentation; }


    int GetMessageModificationToGlonassNav::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetMessageModificationToGlonassNav::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetMessageModificationToGlonassNav::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

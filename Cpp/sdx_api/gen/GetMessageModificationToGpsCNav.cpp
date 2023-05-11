
#include "gen/GetMessageModificationToGpsCNav.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetMessageModificationToGpsCNav
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetMessageModificationToGpsCNav::CmdName = "GetMessageModificationToGpsCNav";
    const char* const GetMessageModificationToGpsCNav::Documentation = "Get infos about the GPS CNAV message modification with this ID.";

    REGISTER_COMMAND_FACTORY(GetMessageModificationToGpsCNav);


    GetMessageModificationToGpsCNav::GetMessageModificationToGpsCNav()
      : CommandBase(CmdName)
    {}

    GetMessageModificationToGpsCNav::GetMessageModificationToGpsCNav(const std::string& id)
      : CommandBase(CmdName)
    {

      setId(id);
    }

    GetMessageModificationToGpsCNavPtr GetMessageModificationToGpsCNav::create(const std::string& id)
    {
      return std::make_shared<GetMessageModificationToGpsCNav>(id);
    }

    GetMessageModificationToGpsCNavPtr GetMessageModificationToGpsCNav::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetMessageModificationToGpsCNav>(ptr);
    }

    bool GetMessageModificationToGpsCNav::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetMessageModificationToGpsCNav::documentation() const { return Documentation; }


    int GetMessageModificationToGpsCNav::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetMessageModificationToGpsCNav::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetMessageModificationToGpsCNav::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

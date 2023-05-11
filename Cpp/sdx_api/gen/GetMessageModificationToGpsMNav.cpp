
#include "gen/GetMessageModificationToGpsMNav.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetMessageModificationToGpsMNav
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetMessageModificationToGpsMNav::CmdName = "GetMessageModificationToGpsMNav";
    const char* const GetMessageModificationToGpsMNav::Documentation = "Get infos about the GPS MNAV message modification with this ID.";

    REGISTER_COMMAND_FACTORY(GetMessageModificationToGpsMNav);


    GetMessageModificationToGpsMNav::GetMessageModificationToGpsMNav()
      : CommandBase(CmdName)
    {}

    GetMessageModificationToGpsMNav::GetMessageModificationToGpsMNav(const std::string& id)
      : CommandBase(CmdName)
    {

      setId(id);
    }

    GetMessageModificationToGpsMNavPtr GetMessageModificationToGpsMNav::create(const std::string& id)
    {
      return std::make_shared<GetMessageModificationToGpsMNav>(id);
    }

    GetMessageModificationToGpsMNavPtr GetMessageModificationToGpsMNav::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetMessageModificationToGpsMNav>(ptr);
    }

    bool GetMessageModificationToGpsMNav::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetMessageModificationToGpsMNav::documentation() const { return Documentation; }


    int GetMessageModificationToGpsMNav::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetMessageModificationToGpsMNav::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetMessageModificationToGpsMNav::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

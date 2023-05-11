
#include "gen/GetMessageModificationToBeiDouD1Nav.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetMessageModificationToBeiDouD1Nav
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetMessageModificationToBeiDouD1Nav::CmdName = "GetMessageModificationToBeiDouD1Nav";
    const char* const GetMessageModificationToBeiDouD1Nav::Documentation = "Get infos about the BeiDou D1 NAV message modification with this ID.";

    REGISTER_COMMAND_FACTORY(GetMessageModificationToBeiDouD1Nav);


    GetMessageModificationToBeiDouD1Nav::GetMessageModificationToBeiDouD1Nav()
      : CommandBase(CmdName)
    {}

    GetMessageModificationToBeiDouD1Nav::GetMessageModificationToBeiDouD1Nav(const std::string& id)
      : CommandBase(CmdName)
    {

      setId(id);
    }

    GetMessageModificationToBeiDouD1NavPtr GetMessageModificationToBeiDouD1Nav::create(const std::string& id)
    {
      return std::make_shared<GetMessageModificationToBeiDouD1Nav>(id);
    }

    GetMessageModificationToBeiDouD1NavPtr GetMessageModificationToBeiDouD1Nav::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetMessageModificationToBeiDouD1Nav>(ptr);
    }

    bool GetMessageModificationToBeiDouD1Nav::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetMessageModificationToBeiDouD1Nav::documentation() const { return Documentation; }


    int GetMessageModificationToBeiDouD1Nav::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetMessageModificationToBeiDouD1Nav::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetMessageModificationToBeiDouD1Nav::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}


#include "gen/GetMessageModificationToBeiDouD2Nav.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetMessageModificationToBeiDouD2Nav
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetMessageModificationToBeiDouD2Nav::CmdName = "GetMessageModificationToBeiDouD2Nav";
    const char* const GetMessageModificationToBeiDouD2Nav::Documentation = "Get infos about the BeiDou D2 NAV message modification with this ID.";

    REGISTER_COMMAND_FACTORY(GetMessageModificationToBeiDouD2Nav);


    GetMessageModificationToBeiDouD2Nav::GetMessageModificationToBeiDouD2Nav()
      : CommandBase(CmdName)
    {}

    GetMessageModificationToBeiDouD2Nav::GetMessageModificationToBeiDouD2Nav(const std::string& id)
      : CommandBase(CmdName)
    {

      setId(id);
    }

    GetMessageModificationToBeiDouD2NavPtr GetMessageModificationToBeiDouD2Nav::create(const std::string& id)
    {
      return std::make_shared<GetMessageModificationToBeiDouD2Nav>(id);
    }

    GetMessageModificationToBeiDouD2NavPtr GetMessageModificationToBeiDouD2Nav::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetMessageModificationToBeiDouD2Nav>(ptr);
    }

    bool GetMessageModificationToBeiDouD2Nav::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetMessageModificationToBeiDouD2Nav::documentation() const { return Documentation; }


    int GetMessageModificationToBeiDouD2Nav::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetMessageModificationToBeiDouD2Nav::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetMessageModificationToBeiDouD2Nav::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

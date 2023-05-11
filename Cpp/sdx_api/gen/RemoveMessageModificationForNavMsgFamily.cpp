
#include "gen/RemoveMessageModificationForNavMsgFamily.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of RemoveMessageModificationForNavMsgFamily
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const RemoveMessageModificationForNavMsgFamily::CmdName = "RemoveMessageModificationForNavMsgFamily";
    const char* const RemoveMessageModificationForNavMsgFamily::Documentation = "Removes a message modification event for the navigation message family.";

    REGISTER_COMMAND_FACTORY(RemoveMessageModificationForNavMsgFamily);


    RemoveMessageModificationForNavMsgFamily::RemoveMessageModificationForNavMsgFamily()
      : CommandBase(CmdName)
    {}

    RemoveMessageModificationForNavMsgFamily::RemoveMessageModificationForNavMsgFamily(const std::string& navMsgFamily, const std::string& id)
      : CommandBase(CmdName)
    {

      setNavMsgFamily(navMsgFamily);
      setId(id);
    }

    RemoveMessageModificationForNavMsgFamilyPtr RemoveMessageModificationForNavMsgFamily::create(const std::string& navMsgFamily, const std::string& id)
    {
      return std::make_shared<RemoveMessageModificationForNavMsgFamily>(navMsgFamily, id);
    }

    RemoveMessageModificationForNavMsgFamilyPtr RemoveMessageModificationForNavMsgFamily::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<RemoveMessageModificationForNavMsgFamily>(ptr);
    }

    bool RemoveMessageModificationForNavMsgFamily::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["NavMsgFamily"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string RemoveMessageModificationForNavMsgFamily::documentation() const { return Documentation; }


    int RemoveMessageModificationForNavMsgFamily::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string RemoveMessageModificationForNavMsgFamily::navMsgFamily() const
    {
      return parse_json<std::string>::parse(m_values["NavMsgFamily"]);
    }

    void RemoveMessageModificationForNavMsgFamily::setNavMsgFamily(const std::string& navMsgFamily)
    {
      m_values.AddMember("NavMsgFamily", parse_json<std::string>::format(navMsgFamily, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string RemoveMessageModificationForNavMsgFamily::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void RemoveMessageModificationForNavMsgFamily::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

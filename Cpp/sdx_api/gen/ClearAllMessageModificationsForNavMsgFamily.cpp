
#include "gen/ClearAllMessageModificationsForNavMsgFamily.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of ClearAllMessageModificationsForNavMsgFamily
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ClearAllMessageModificationsForNavMsgFamily::CmdName = "ClearAllMessageModificationsForNavMsgFamily";
    const char* const ClearAllMessageModificationsForNavMsgFamily::Documentation = "Clear all message modification events for this navigation message family.";

    REGISTER_COMMAND_FACTORY(ClearAllMessageModificationsForNavMsgFamily);


    ClearAllMessageModificationsForNavMsgFamily::ClearAllMessageModificationsForNavMsgFamily()
      : CommandBase(CmdName)
    {}

    ClearAllMessageModificationsForNavMsgFamily::ClearAllMessageModificationsForNavMsgFamily(const std::string& navMsgFamily)
      : CommandBase(CmdName)
    {

      setNavMsgFamily(navMsgFamily);
    }

    ClearAllMessageModificationsForNavMsgFamilyPtr ClearAllMessageModificationsForNavMsgFamily::create(const std::string& navMsgFamily)
    {
      return std::make_shared<ClearAllMessageModificationsForNavMsgFamily>(navMsgFamily);
    }

    ClearAllMessageModificationsForNavMsgFamilyPtr ClearAllMessageModificationsForNavMsgFamily::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ClearAllMessageModificationsForNavMsgFamily>(ptr);
    }

    bool ClearAllMessageModificationsForNavMsgFamily::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["NavMsgFamily"])
        ;

    }

    std::string ClearAllMessageModificationsForNavMsgFamily::documentation() const { return Documentation; }


    int ClearAllMessageModificationsForNavMsgFamily::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string ClearAllMessageModificationsForNavMsgFamily::navMsgFamily() const
    {
      return parse_json<std::string>::parse(m_values["NavMsgFamily"]);
    }

    void ClearAllMessageModificationsForNavMsgFamily::setNavMsgFamily(const std::string& navMsgFamily)
    {
      m_values.AddMember("NavMsgFamily", parse_json<std::string>::format(navMsgFamily, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

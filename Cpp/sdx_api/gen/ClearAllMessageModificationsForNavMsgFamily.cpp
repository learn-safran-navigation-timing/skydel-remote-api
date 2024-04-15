
#include "ClearAllMessageModificationsForNavMsgFamily.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of ClearAllMessageModificationsForNavMsgFamily
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ClearAllMessageModificationsForNavMsgFamily::CmdName = "ClearAllMessageModificationsForNavMsgFamily";
    const char* const ClearAllMessageModificationsForNavMsgFamily::Documentation = "Clear all message modification events for this navigation message family.\n"
      "\n"
      "Name         Type   Description\n"
      "------------ ------ ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n"
      "NavMsgFamily string Navigation message family key, accepted values : \"GPS_LNAV\", \"GPS_CNAV\", \"GPS_CNAV2\", \"GPS_MNAV\", \"GLONASS_NAV\", \"GALILEO_FNAV\", \"GALILEO_INAV\", \"BEIDOU_D1_NAV\", \"BEIDOU_CNAV1\", \"BEIDOU_CNAV2\", \"QZSS_LNAV\", \"QZSS_SLAS\", \"NAVIC_NAV\" and \"SBAS_NAV\"";
    const char* const ClearAllMessageModificationsForNavMsgFamily::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(ClearAllMessageModificationsForNavMsgFamily);
    REGISTER_COMMAND_TO_FACTORY_IMPL(ClearAllMessageModificationsForNavMsgFamily);


    ClearAllMessageModificationsForNavMsgFamily::ClearAllMessageModificationsForNavMsgFamily()
      : CommandBase(CmdName, TargetId)
    {}

    ClearAllMessageModificationsForNavMsgFamily::ClearAllMessageModificationsForNavMsgFamily(const std::string& navMsgFamily)
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& ClearAllMessageModificationsForNavMsgFamily::fieldNames() const 
    { 
      static const std::vector<std::string> names {"NavMsgFamily"}; 
      return names; 
    }


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

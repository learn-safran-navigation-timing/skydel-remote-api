
#include "RemoveMessageModificationForNavMsgFamily.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of RemoveMessageModificationForNavMsgFamily
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const RemoveMessageModificationForNavMsgFamily::CmdName = "RemoveMessageModificationForNavMsgFamily";
    const char* const RemoveMessageModificationForNavMsgFamily::Documentation = "Removes a message modification event for the navigation message family.\n"
      "\n"
      "Name         Type   Description\n"
      "------------ ------ ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n"
      "NavMsgFamily string Navigation message family key, accepted values : \"GPS_LNAV\", \"GPS_CNAV\", \"GPS_CNAV2\", \"GPS_MNAV\", \"GLONASS_NAV\", \"GALILEO_FNAV\", \"GALILEO_INAV\", \"BEIDOU_D1_NAV\", \"BEIDOU_CNAV1\", \"BEIDOU_CNAV2\", \"QZSS_LNAV\", \"QZSS_SLAS\", \"NAVIC_NAV\" and \"SBAS_NAV\"\n"
      "Id           string Unique identifier";
    const char* const RemoveMessageModificationForNavMsgFamily::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(RemoveMessageModificationForNavMsgFamily);
    REGISTER_COMMAND_TO_FACTORY_IMPL(RemoveMessageModificationForNavMsgFamily);


    RemoveMessageModificationForNavMsgFamily::RemoveMessageModificationForNavMsgFamily()
      : CommandBase(CmdName, TargetId)
    {}

    RemoveMessageModificationForNavMsgFamily::RemoveMessageModificationForNavMsgFamily(const std::string& navMsgFamily, const std::string& id)
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& RemoveMessageModificationForNavMsgFamily::fieldNames() const 
    { 
      static const std::vector<std::string> names {"NavMsgFamily", "Id"}; 
      return names; 
    }


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

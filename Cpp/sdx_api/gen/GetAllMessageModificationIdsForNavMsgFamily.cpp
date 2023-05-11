
#include "gen/GetAllMessageModificationIdsForNavMsgFamily.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetAllMessageModificationIdsForNavMsgFamily
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetAllMessageModificationIdsForNavMsgFamily::CmdName = "GetAllMessageModificationIdsForNavMsgFamily";
    const char* const GetAllMessageModificationIdsForNavMsgFamily::Documentation = "Get all the message modification event's IDs for this navigation message family and SV ID.";

    REGISTER_COMMAND_FACTORY(GetAllMessageModificationIdsForNavMsgFamily);


    GetAllMessageModificationIdsForNavMsgFamily::GetAllMessageModificationIdsForNavMsgFamily()
      : CommandBase(CmdName)
    {}

    GetAllMessageModificationIdsForNavMsgFamily::GetAllMessageModificationIdsForNavMsgFamily(const std::string& navMsgFamily, int svId)
      : CommandBase(CmdName)
    {

      setNavMsgFamily(navMsgFamily);
      setSvId(svId);
    }

    GetAllMessageModificationIdsForNavMsgFamilyPtr GetAllMessageModificationIdsForNavMsgFamily::create(const std::string& navMsgFamily, int svId)
    {
      return std::make_shared<GetAllMessageModificationIdsForNavMsgFamily>(navMsgFamily, svId);
    }

    GetAllMessageModificationIdsForNavMsgFamilyPtr GetAllMessageModificationIdsForNavMsgFamily::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetAllMessageModificationIdsForNavMsgFamily>(ptr);
    }

    bool GetAllMessageModificationIdsForNavMsgFamily::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["NavMsgFamily"])
          && parse_json<int>::is_valid(m_values["SvId"])
        ;

    }

    std::string GetAllMessageModificationIdsForNavMsgFamily::documentation() const { return Documentation; }


    int GetAllMessageModificationIdsForNavMsgFamily::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetAllMessageModificationIdsForNavMsgFamily::navMsgFamily() const
    {
      return parse_json<std::string>::parse(m_values["NavMsgFamily"]);
    }

    void GetAllMessageModificationIdsForNavMsgFamily::setNavMsgFamily(const std::string& navMsgFamily)
    {
      m_values.AddMember("NavMsgFamily", parse_json<std::string>::format(navMsgFamily, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetAllMessageModificationIdsForNavMsgFamily::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetAllMessageModificationIdsForNavMsgFamily::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

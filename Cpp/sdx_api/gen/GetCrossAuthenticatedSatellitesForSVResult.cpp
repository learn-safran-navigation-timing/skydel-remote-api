
#include "GetCrossAuthenticatedSatellitesForSVResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetCrossAuthenticatedSatellitesForSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetCrossAuthenticatedSatellitesForSVResult::CmdName = "GetCrossAuthenticatedSatellitesForSVResult";
    const char* const GetCrossAuthenticatedSatellitesForSVResult::Documentation = "Result of GetCrossAuthenticatedSatellitesForSV.\n"
      "\n"
      "Name     Type      Description\n"
      "-------- --------- -------------------------------------------------------------------\n"
      "SvId     int       The satellite's SV ID (use 0 to apply on all Galileo's satellites).\n"
      "SvIdList array int A list of the cross-authenticated satellites' SV IDs.";
    const char* const GetCrossAuthenticatedSatellitesForSVResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetCrossAuthenticatedSatellitesForSVResult);


    GetCrossAuthenticatedSatellitesForSVResult::GetCrossAuthenticatedSatellitesForSVResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetCrossAuthenticatedSatellitesForSVResult::GetCrossAuthenticatedSatellitesForSVResult(int svId, const std::vector<int>& svIdList)
      : CommandResult(CmdName, TargetId)
    {

      setSvId(svId);
      setSvIdList(svIdList);
    }

    GetCrossAuthenticatedSatellitesForSVResult::GetCrossAuthenticatedSatellitesForSVResult(CommandBasePtr relatedCommand, int svId, const std::vector<int>& svIdList)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setSvId(svId);
      setSvIdList(svIdList);
    }


    GetCrossAuthenticatedSatellitesForSVResultPtr GetCrossAuthenticatedSatellitesForSVResult::create(int svId, const std::vector<int>& svIdList)
    {
      return std::make_shared<GetCrossAuthenticatedSatellitesForSVResult>(svId, svIdList);
    }

    GetCrossAuthenticatedSatellitesForSVResultPtr GetCrossAuthenticatedSatellitesForSVResult::create(CommandBasePtr relatedCommand, int svId, const std::vector<int>& svIdList)
    {
      return std::make_shared<GetCrossAuthenticatedSatellitesForSVResult>(relatedCommand, svId, svIdList);
    }

    GetCrossAuthenticatedSatellitesForSVResultPtr GetCrossAuthenticatedSatellitesForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetCrossAuthenticatedSatellitesForSVResult>(ptr);
    }

    bool GetCrossAuthenticatedSatellitesForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::vector<int>>::is_valid(m_values["SvIdList"])
        ;

    }

    std::string GetCrossAuthenticatedSatellitesForSVResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetCrossAuthenticatedSatellitesForSVResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "SvIdList"}; 
      return names; 
    }


    int GetCrossAuthenticatedSatellitesForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetCrossAuthenticatedSatellitesForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<int> GetCrossAuthenticatedSatellitesForSVResult::svIdList() const
    {
      return parse_json<std::vector<int>>::parse(m_values["SvIdList"]);
    }

    void GetCrossAuthenticatedSatellitesForSVResult::setSvIdList(const std::vector<int>& svIdList)
    {
      m_values.AddMember("SvIdList", parse_json<std::vector<int>>::format(svIdList, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

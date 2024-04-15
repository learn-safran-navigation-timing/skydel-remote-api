
#include "GetCrossAuthenticatedSatellitesForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetCrossAuthenticatedSatellitesForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetCrossAuthenticatedSatellitesForSV::CmdName = "GetCrossAuthenticatedSatellitesForSV";
    const char* const GetCrossAuthenticatedSatellitesForSV::Documentation = "Get the list of satellites that are cross-authenticated by the specified satellite.\n"
      "\n"
      "Name Type Description\n"
      "---- ---- -------------------------------------------------------------------\n"
      "SvId int  The satellite's SV ID (use 0 to apply on all Galileo's satellites).";
    const char* const GetCrossAuthenticatedSatellitesForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetCrossAuthenticatedSatellitesForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetCrossAuthenticatedSatellitesForSV);


    GetCrossAuthenticatedSatellitesForSV::GetCrossAuthenticatedSatellitesForSV()
      : CommandBase(CmdName, TargetId)
    {}

    GetCrossAuthenticatedSatellitesForSV::GetCrossAuthenticatedSatellitesForSV(int svId)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
    }

    GetCrossAuthenticatedSatellitesForSVPtr GetCrossAuthenticatedSatellitesForSV::create(int svId)
    {
      return std::make_shared<GetCrossAuthenticatedSatellitesForSV>(svId);
    }

    GetCrossAuthenticatedSatellitesForSVPtr GetCrossAuthenticatedSatellitesForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetCrossAuthenticatedSatellitesForSV>(ptr);
    }

    bool GetCrossAuthenticatedSatellitesForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
        ;

    }

    std::string GetCrossAuthenticatedSatellitesForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& GetCrossAuthenticatedSatellitesForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId"}; 
      return names; 
    }


    int GetCrossAuthenticatedSatellitesForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetCrossAuthenticatedSatellitesForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetCrossAuthenticatedSatellitesForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

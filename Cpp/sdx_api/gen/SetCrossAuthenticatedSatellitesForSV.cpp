
#include "SetCrossAuthenticatedSatellitesForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetCrossAuthenticatedSatellitesForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetCrossAuthenticatedSatellitesForSV::CmdName = "SetCrossAuthenticatedSatellitesForSV";
    const char* const SetCrossAuthenticatedSatellitesForSV::Documentation = "Set the list of satellites that are cross-authenticated by the specified satellite.\n"
      "\n"
      "Name     Type      Description\n"
      "-------- --------- -------------------------------------------------------------------\n"
      "SvId     int       The satellite's SV ID (use 0 to apply on all Galileo's satellites).\n"
      "SvIdList array int A list of the cross-authenticated satellites' SV IDs.";
    const char* const SetCrossAuthenticatedSatellitesForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetCrossAuthenticatedSatellitesForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetCrossAuthenticatedSatellitesForSV);


    SetCrossAuthenticatedSatellitesForSV::SetCrossAuthenticatedSatellitesForSV()
      : CommandBase(CmdName, TargetId)
    {}

    SetCrossAuthenticatedSatellitesForSV::SetCrossAuthenticatedSatellitesForSV(int svId, const std::vector<int>& svIdList)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setSvIdList(svIdList);
    }

    SetCrossAuthenticatedSatellitesForSVPtr SetCrossAuthenticatedSatellitesForSV::create(int svId, const std::vector<int>& svIdList)
    {
      return std::make_shared<SetCrossAuthenticatedSatellitesForSV>(svId, svIdList);
    }

    SetCrossAuthenticatedSatellitesForSVPtr SetCrossAuthenticatedSatellitesForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetCrossAuthenticatedSatellitesForSV>(ptr);
    }

    bool SetCrossAuthenticatedSatellitesForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::vector<int>>::is_valid(m_values["SvIdList"])
        ;

    }

    std::string SetCrossAuthenticatedSatellitesForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& SetCrossAuthenticatedSatellitesForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "SvIdList"}; 
      return names; 
    }


    int SetCrossAuthenticatedSatellitesForSV::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetCrossAuthenticatedSatellitesForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetCrossAuthenticatedSatellitesForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<int> SetCrossAuthenticatedSatellitesForSV::svIdList() const
    {
      return parse_json<std::vector<int>>::parse(m_values["SvIdList"]);
    }

    void SetCrossAuthenticatedSatellitesForSV::setSvIdList(const std::vector<int>& svIdList)
    {
      m_values.AddMember("SvIdList", parse_json<std::vector<int>>::format(svIdList, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

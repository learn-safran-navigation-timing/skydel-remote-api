
#include "GetGlonassAlmanacUnhealthyFlagForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGlonassAlmanacUnhealthyFlagForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGlonassAlmanacUnhealthyFlagForSV::CmdName = "GetGlonassAlmanacUnhealthyFlagForSV";
    const char* const GetGlonassAlmanacUnhealthyFlagForSV::Documentation = "Get GLONASS satellite Almanac Unhealthy Flag Cn\n"
      "\n"
      "Name Type Description\n"
      "---- ---- ---------------------------\n"
      "SvId int  The satellite's SV ID 1..24";
    const char* const GetGlonassAlmanacUnhealthyFlagForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetGlonassAlmanacUnhealthyFlagForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetGlonassAlmanacUnhealthyFlagForSV);


    GetGlonassAlmanacUnhealthyFlagForSV::GetGlonassAlmanacUnhealthyFlagForSV()
      : CommandBase(CmdName, TargetId)
    {}

    GetGlonassAlmanacUnhealthyFlagForSV::GetGlonassAlmanacUnhealthyFlagForSV(int svId)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
    }

    GetGlonassAlmanacUnhealthyFlagForSVPtr GetGlonassAlmanacUnhealthyFlagForSV::create(int svId)
    {
      return std::make_shared<GetGlonassAlmanacUnhealthyFlagForSV>(svId);
    }

    GetGlonassAlmanacUnhealthyFlagForSVPtr GetGlonassAlmanacUnhealthyFlagForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGlonassAlmanacUnhealthyFlagForSV>(ptr);
    }

    bool GetGlonassAlmanacUnhealthyFlagForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
        ;

    }

    std::string GetGlonassAlmanacUnhealthyFlagForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& GetGlonassAlmanacUnhealthyFlagForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId"}; 
      return names; 
    }


    int GetGlonassAlmanacUnhealthyFlagForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetGlonassAlmanacUnhealthyFlagForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetGlonassAlmanacUnhealthyFlagForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}


#include "gen/GetGlonassAlmanacUnhealthyFlagForSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGlonassAlmanacUnhealthyFlagForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGlonassAlmanacUnhealthyFlagForSV::CmdName = "GetGlonassAlmanacUnhealthyFlagForSV";
    const char* const GetGlonassAlmanacUnhealthyFlagForSV::Documentation = "Get GLONASS satellite Almanac Unhealthy Flag Cn";

    REGISTER_COMMAND_FACTORY(GetGlonassAlmanacUnhealthyFlagForSV);


    GetGlonassAlmanacUnhealthyFlagForSV::GetGlonassAlmanacUnhealthyFlagForSV()
      : CommandBase(CmdName)
    {}

    GetGlonassAlmanacUnhealthyFlagForSV::GetGlonassAlmanacUnhealthyFlagForSV(int svId)
      : CommandBase(CmdName)
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

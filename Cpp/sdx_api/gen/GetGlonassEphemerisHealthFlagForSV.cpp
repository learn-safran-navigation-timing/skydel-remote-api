
#include "gen/GetGlonassEphemerisHealthFlagForSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGlonassEphemerisHealthFlagForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGlonassEphemerisHealthFlagForSV::CmdName = "GetGlonassEphemerisHealthFlagForSV";
    const char* const GetGlonassEphemerisHealthFlagForSV::Documentation = "Get GLONASS satellite Ephemeris Health Flag Bn(ln)";

    REGISTER_COMMAND_FACTORY(GetGlonassEphemerisHealthFlagForSV);


    GetGlonassEphemerisHealthFlagForSV::GetGlonassEphemerisHealthFlagForSV()
      : CommandBase(CmdName)
    {}

    GetGlonassEphemerisHealthFlagForSV::GetGlonassEphemerisHealthFlagForSV(int svId)
      : CommandBase(CmdName)
    {

      setSvId(svId);
    }

    GetGlonassEphemerisHealthFlagForSVPtr GetGlonassEphemerisHealthFlagForSV::create(int svId)
    {
      return std::make_shared<GetGlonassEphemerisHealthFlagForSV>(svId);
    }

    GetGlonassEphemerisHealthFlagForSVPtr GetGlonassEphemerisHealthFlagForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGlonassEphemerisHealthFlagForSV>(ptr);
    }

    bool GetGlonassEphemerisHealthFlagForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
        ;

    }

    std::string GetGlonassEphemerisHealthFlagForSV::documentation() const { return Documentation; }


    int GetGlonassEphemerisHealthFlagForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetGlonassEphemerisHealthFlagForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetGlonassEphemerisHealthFlagForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}


#include "GetGlonassEphemerisHealthFlagForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGlonassEphemerisHealthFlagForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGlonassEphemerisHealthFlagForSV::CmdName = "GetGlonassEphemerisHealthFlagForSV";
    const char* const GetGlonassEphemerisHealthFlagForSV::Documentation = "Get GLONASS satellite Ephemeris Health Flag Bn(ln)\n"
      "\n"
      "Name Type Description\n"
      "---- ---- ---------------------------\n"
      "SvId int  The satellite's SV ID 1..24";
    const char* const GetGlonassEphemerisHealthFlagForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetGlonassEphemerisHealthFlagForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetGlonassEphemerisHealthFlagForSV);


    GetGlonassEphemerisHealthFlagForSV::GetGlonassEphemerisHealthFlagForSV()
      : CommandBase(CmdName, TargetId)
    {}

    GetGlonassEphemerisHealthFlagForSV::GetGlonassEphemerisHealthFlagForSV(int svId)
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& GetGlonassEphemerisHealthFlagForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId"}; 
      return names; 
    }


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

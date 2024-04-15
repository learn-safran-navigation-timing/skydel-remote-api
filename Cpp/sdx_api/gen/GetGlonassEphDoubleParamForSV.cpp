
#include "GetGlonassEphDoubleParamForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGlonassEphDoubleParamForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGlonassEphDoubleParamForSV::CmdName = "GetGlonassEphDoubleParamForSV";
    const char* const GetGlonassEphDoubleParamForSV::Documentation = "Get various parameters for GLONASS\n"
      "\n"
      "  ParamName       Unit               Range          Description\n"
      "  \"TauC\"          sec                +/- 1          GLONASS time scale correction to UTC(SU) time\n"
      "  \"TauGps\"        day                +/- 1.9x10^-3  Correction to GPS time relative to GLONASS time\n"
      "  \"TauN\"          sec                +/- 1.9x10^-3  Coarse value of satellite time correction to GLONASS time\n"
      "  \"TLambda\"       sec                0..44100       Time of the first ascending node passage\n"
      "  \"Lambda\"        semicircle         +/- 1          Longitude of the first ascending node\n"
      "  \"DeltaI\"        semicircle         +/- 0.067      Correction to the mean value of inclination\n"
      "  \"Omega\"         semicircle         +/- 1          Argument of perigee\n"
      "  \"Eccentricity\"  -                  0..0.03        Eccentricity\n"
      "  \"DeltaT\"        sec/orb. period    +/- 3.6x10^3   Correction to the mean value of Draconian period\n"
      "  \"DeltaTRate\"    sec/orb. period^2  +/- 2^-8       Rate of change of Draconian period\n"
      "\n"
      "Name      Type   Description\n"
      "--------- ------ --------------------------------------------------------------------\n"
      "SvId      int    Satellite SV ID 1..24, or use 0 to apply new value to all satellites\n"
      "ParamName string Parameter name (see table above for accepted names)";
    const char* const GetGlonassEphDoubleParamForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetGlonassEphDoubleParamForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetGlonassEphDoubleParamForSV);


    GetGlonassEphDoubleParamForSV::GetGlonassEphDoubleParamForSV()
      : CommandBase(CmdName, TargetId)
    {}

    GetGlonassEphDoubleParamForSV::GetGlonassEphDoubleParamForSV(int svId, const std::string& paramName)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setParamName(paramName);
    }

    GetGlonassEphDoubleParamForSVPtr GetGlonassEphDoubleParamForSV::create(int svId, const std::string& paramName)
    {
      return std::make_shared<GetGlonassEphDoubleParamForSV>(svId, paramName);
    }

    GetGlonassEphDoubleParamForSVPtr GetGlonassEphDoubleParamForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGlonassEphDoubleParamForSV>(ptr);
    }

    bool GetGlonassEphDoubleParamForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::string>::is_valid(m_values["ParamName"])
        ;

    }

    std::string GetGlonassEphDoubleParamForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& GetGlonassEphDoubleParamForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "ParamName"}; 
      return names; 
    }


    int GetGlonassEphDoubleParamForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetGlonassEphDoubleParamForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetGlonassEphDoubleParamForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetGlonassEphDoubleParamForSV::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetGlonassEphDoubleParamForSV::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

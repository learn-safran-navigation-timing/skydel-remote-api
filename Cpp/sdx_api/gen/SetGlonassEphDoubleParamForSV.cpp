
#include "gen/SetGlonassEphDoubleParamForSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGlonassEphDoubleParamForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGlonassEphDoubleParamForSV::CmdName = "SetGlonassEphDoubleParamForSV";
    const char* const SetGlonassEphDoubleParamForSV::Documentation = "Set various parameters for GLONASS\n\n  ParamName       Unit               Range          Description\n  \"TauC\"          sec                +/- 1          GLONASS time scale correction to UTC(SU) time\n  \"TauGps\"        day                +/- 1.9x10^-3  Correction to GPS time relative to GLONASS time\n  \"TauN\"          sec                +/- 1.9x10^-3  Coarse value of satellite time correction to GLONASS time\n  \"TLambda\"       sec                0..44100       Time of the first ascending node passage\n  \"Lambda\"        semicircle         +/- 1          Longitude of the first ascending node\n  \"DeltaI\"        semicircle         +/- 0.067      Correction to the mean value of inclination\n  \"Omega\"         semicircle         +/- 1          Argument of perigee\n  \"Eccentricity\"  -                  0..0.03        Eccentricity\n  \"DeltaT\"        sec/orb. period    +/- 3.6x10^3   Correction to the mean value of Draconian period\n  \"DeltaTRate\"    sec/orb. period^2  +/- 2^-8       Rate of change of Draconian period";

    REGISTER_COMMAND_FACTORY(SetGlonassEphDoubleParamForSV);


    SetGlonassEphDoubleParamForSV::SetGlonassEphDoubleParamForSV()
      : CommandBase(CmdName)
    {}

    SetGlonassEphDoubleParamForSV::SetGlonassEphDoubleParamForSV(int svId, const std::string& paramName, double val)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setParamName(paramName);
      setVal(val);
    }

    SetGlonassEphDoubleParamForSVPtr SetGlonassEphDoubleParamForSV::create(int svId, const std::string& paramName, double val)
    {
      return std::make_shared<SetGlonassEphDoubleParamForSV>(svId, paramName, val);
    }

    SetGlonassEphDoubleParamForSVPtr SetGlonassEphDoubleParamForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetGlonassEphDoubleParamForSV>(ptr);
    }

    bool SetGlonassEphDoubleParamForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<double>::is_valid(m_values["Val"])
        ;

    }

    std::string SetGlonassEphDoubleParamForSV::documentation() const { return Documentation; }


    int SetGlonassEphDoubleParamForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int SetGlonassEphDoubleParamForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetGlonassEphDoubleParamForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetGlonassEphDoubleParamForSV::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void SetGlonassEphDoubleParamForSV::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetGlonassEphDoubleParamForSV::val() const
    {
      return parse_json<double>::parse(m_values["Val"]);
    }

    void SetGlonassEphDoubleParamForSV::setVal(double val)
    {
      m_values.AddMember("Val", parse_json<double>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

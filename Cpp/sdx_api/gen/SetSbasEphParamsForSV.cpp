
#include "gen/SetSbasEphParamsForSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetSbasEphParamsForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetSbasEphParamsForSV::CmdName = "SetSbasEphParamsForSV";
    const char* const SetSbasEphParamsForSV::Documentation = "Set parameters for a SBAS satellite ephemeris (runtime modification only available for health parameter)";

    REGISTER_COMMAND_FACTORY(SetSbasEphParamsForSV);


    SetSbasEphParamsForSV::SetSbasEphParamsForSV()
      : CommandBase(CmdName)
    {}

    SetSbasEphParamsForSV::SetSbasEphParamsForSV(int svId, const std::map<std::string, double>& paramValueDict)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setParamValueDict(paramValueDict);
    }

    SetSbasEphParamsForSVPtr SetSbasEphParamsForSV::create(int svId, const std::map<std::string, double>& paramValueDict)
    {
      return std::make_shared<SetSbasEphParamsForSV>(svId, paramValueDict);
    }

    SetSbasEphParamsForSVPtr SetSbasEphParamsForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetSbasEphParamsForSV>(ptr);
    }

    bool SetSbasEphParamsForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::map<std::string, double>>::is_valid(m_values["ParamValueDict"])
        ;

    }

    std::string SetSbasEphParamsForSV::documentation() const { return Documentation; }


    int SetSbasEphParamsForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }


    int SetSbasEphParamsForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetSbasEphParamsForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::map<std::string, double> SetSbasEphParamsForSV::paramValueDict() const
    {
      return parse_json<std::map<std::string, double>>::parse(m_values["ParamValueDict"]);
    }

    void SetSbasEphParamsForSV::setParamValueDict(const std::map<std::string, double>& paramValueDict)
    {
      m_values.AddMember("ParamValueDict", parse_json<std::map<std::string, double>>::format(paramValueDict, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

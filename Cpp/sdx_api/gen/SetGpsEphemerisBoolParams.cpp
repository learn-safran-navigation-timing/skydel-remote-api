
#include "gen/SetGpsEphemerisBoolParams.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGpsEphemerisBoolParams
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGpsEphemerisBoolParams::CmdName = "SetGpsEphemerisBoolParams";
    const char* const SetGpsEphemerisBoolParams::Documentation = "Please note the command SetGpsEphemerisBoolParams is deprecated since 21.3. You may use SetGpsEphBoolParamForEachSV.\n\nPlease note the command SetGpsEphBoolParamForEachSV is deprecated since 23.11. You may use SetConstellationParameterForSV.\n\nSet GPS ephemeris boolean parameter value for all satellites";

    const char* const SetGpsEphemerisBoolParams::Deprecated = "Please note the command SetGpsEphemerisBoolParams is deprecated since 23.11. You may use SetConstellationParameterForSV.";

    REGISTER_COMMAND_FACTORY(SetGpsEphemerisBoolParams);


    SetGpsEphemerisBoolParams::SetGpsEphemerisBoolParams()
      : CommandBase(CmdName)
    {}

    SetGpsEphemerisBoolParams::SetGpsEphemerisBoolParams(const std::string& paramName, const std::vector<bool>& val, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }

    SetGpsEphemerisBoolParamsPtr SetGpsEphemerisBoolParams::create(const std::string& paramName, const std::vector<bool>& val, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetGpsEphemerisBoolParams>(paramName, val, dataSetName);
    }

    SetGpsEphemerisBoolParamsPtr SetGpsEphemerisBoolParams::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetGpsEphemerisBoolParams>(ptr);
    }

    bool SetGpsEphemerisBoolParams::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<std::vector<bool>>::is_valid(m_values["Val"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetGpsEphemerisBoolParams::documentation() const { return Documentation; }

    Sdx::optional<std::string> SetGpsEphemerisBoolParams::deprecated() const { return Sdx::optional<std::string>{Deprecated}; }


    int SetGpsEphemerisBoolParams::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetGpsEphemerisBoolParams::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void SetGpsEphemerisBoolParams::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<bool> SetGpsEphemerisBoolParams::val() const
    {
      return parse_json<std::vector<bool>>::parse(m_values["Val"]);
    }

    void SetGpsEphemerisBoolParams::setVal(const std::vector<bool>& val)
    {
      m_values.AddMember("Val", parse_json<std::vector<bool>>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> SetGpsEphemerisBoolParams::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetGpsEphemerisBoolParams::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

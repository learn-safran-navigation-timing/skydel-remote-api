
#include "gen/SetQzssEphemerisBoolParams.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetQzssEphemerisBoolParams
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetQzssEphemerisBoolParams::CmdName = "SetQzssEphemerisBoolParams";
    const char* const SetQzssEphemerisBoolParams::Documentation = "Please note the command SetQzssEphemerisBoolParams is deprecated since 21.3. You may use SetQzssEphBoolParamForEachSV.\n\nSet QZSS ephemeris boolean parameter value for all satellites";

    REGISTER_COMMAND_FACTORY(SetQzssEphemerisBoolParams);


    SetQzssEphemerisBoolParams::SetQzssEphemerisBoolParams()
      : CommandBase(CmdName)
    {}

    SetQzssEphemerisBoolParams::SetQzssEphemerisBoolParams(const std::string& paramName, const std::vector<bool>& val, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }

    SetQzssEphemerisBoolParamsPtr SetQzssEphemerisBoolParams::create(const std::string& paramName, const std::vector<bool>& val, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetQzssEphemerisBoolParams>(paramName, val, dataSetName);
    }

    SetQzssEphemerisBoolParamsPtr SetQzssEphemerisBoolParams::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetQzssEphemerisBoolParams>(ptr);
    }

    bool SetQzssEphemerisBoolParams::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<std::vector<bool>>::is_valid(m_values["Val"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetQzssEphemerisBoolParams::documentation() const { return Documentation; }


    int SetQzssEphemerisBoolParams::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetQzssEphemerisBoolParams::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void SetQzssEphemerisBoolParams::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<bool> SetQzssEphemerisBoolParams::val() const
    {
      return parse_json<std::vector<bool>>::parse(m_values["Val"]);
    }

    void SetQzssEphemerisBoolParams::setVal(const std::vector<bool>& val)
    {
      m_values.AddMember("Val", parse_json<std::vector<bool>>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> SetQzssEphemerisBoolParams::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetQzssEphemerisBoolParams::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

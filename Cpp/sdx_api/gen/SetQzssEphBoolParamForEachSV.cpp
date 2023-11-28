
#include "gen/SetQzssEphBoolParamForEachSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetQzssEphBoolParamForEachSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetQzssEphBoolParamForEachSV::CmdName = "SetQzssEphBoolParamForEachSV";
    const char* const SetQzssEphBoolParamForEachSV::Documentation = "Please note the command SetQzssEphBoolParamForEachSV is deprecated since 23.11. You may use SetConstellationParameterForSV.\n\nSet QZSS ephemeris boolean parameter value for all satellites";

    const char* const SetQzssEphBoolParamForEachSV::Deprecated = "Please note the command SetQzssEphBoolParamForEachSV is deprecated since 23.11. You may use SetConstellationParameterForSV.";

    REGISTER_COMMAND_FACTORY(SetQzssEphBoolParamForEachSV);


    SetQzssEphBoolParamForEachSV::SetQzssEphBoolParamForEachSV()
      : CommandBase(CmdName)
    {}

    SetQzssEphBoolParamForEachSV::SetQzssEphBoolParamForEachSV(const std::string& paramName, const std::vector<bool>& val, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }

    SetQzssEphBoolParamForEachSVPtr SetQzssEphBoolParamForEachSV::create(const std::string& paramName, const std::vector<bool>& val, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetQzssEphBoolParamForEachSV>(paramName, val, dataSetName);
    }

    SetQzssEphBoolParamForEachSVPtr SetQzssEphBoolParamForEachSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetQzssEphBoolParamForEachSV>(ptr);
    }

    bool SetQzssEphBoolParamForEachSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<std::vector<bool>>::is_valid(m_values["Val"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetQzssEphBoolParamForEachSV::documentation() const { return Documentation; }

    Sdx::optional<std::string> SetQzssEphBoolParamForEachSV::deprecated() const { return Sdx::optional<std::string>{Deprecated}; }


    int SetQzssEphBoolParamForEachSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetQzssEphBoolParamForEachSV::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void SetQzssEphBoolParamForEachSV::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<bool> SetQzssEphBoolParamForEachSV::val() const
    {
      return parse_json<std::vector<bool>>::parse(m_values["Val"]);
    }

    void SetQzssEphBoolParamForEachSV::setVal(const std::vector<bool>& val)
    {
      m_values.AddMember("Val", parse_json<std::vector<bool>>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> SetQzssEphBoolParamForEachSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetQzssEphBoolParamForEachSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

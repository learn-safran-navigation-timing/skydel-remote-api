
#include "GetQzssEphemerisDoubleParams.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetQzssEphemerisDoubleParams
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetQzssEphemerisDoubleParams::CmdName = "GetQzssEphemerisDoubleParams";
    const char* const GetQzssEphemerisDoubleParams::Documentation = "Please note the command GetQzssEphemerisDoubleParams is deprecated since 21.3. You may use GetQzssEphDoubleParamForEachSV.\n"
      "\n"
      "Please note the command GetQzssEphDoubleParamForEachSV is deprecated since 23.11. You may use GetConstellationParameterForSV.\n"
      "\n"
      "Get QZSS ephemeris parameter value for all satellites\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "ParamName   string          Refer to SetQzssEphDoubleParamForSV for accepted names\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetQzssEphemerisDoubleParams::TargetId = "";

    const char* const GetQzssEphemerisDoubleParams::Deprecated = "Please note the command GetQzssEphemerisDoubleParams is deprecated since 23.11. You may use GetConstellationParameterForSV.";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetQzssEphemerisDoubleParams);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetQzssEphemerisDoubleParams);


    GetQzssEphemerisDoubleParams::GetQzssEphemerisDoubleParams()
      : CommandBase(CmdName, TargetId)
    {}

    GetQzssEphemerisDoubleParams::GetQzssEphemerisDoubleParams(const std::string& paramName, const std::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setParamName(paramName);
      setDataSetName(dataSetName);
    }

    GetQzssEphemerisDoubleParamsPtr GetQzssEphemerisDoubleParams::create(const std::string& paramName, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetQzssEphemerisDoubleParams>(paramName, dataSetName);
    }

    GetQzssEphemerisDoubleParamsPtr GetQzssEphemerisDoubleParams::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetQzssEphemerisDoubleParams>(ptr);
    }

    bool GetQzssEphemerisDoubleParams::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetQzssEphemerisDoubleParams::documentation() const { return Documentation; }

    const std::vector<std::string>& GetQzssEphemerisDoubleParams::fieldNames() const 
    { 
      static const std::vector<std::string> names {"ParamName", "DataSetName"}; 
      return names; 
    }

    std::optional<std::string> GetQzssEphemerisDoubleParams::deprecated() const { return std::optional<std::string>{Deprecated}; }


    int GetQzssEphemerisDoubleParams::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetQzssEphemerisDoubleParams::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetQzssEphemerisDoubleParams::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> GetQzssEphemerisDoubleParams::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetQzssEphemerisDoubleParams::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}


#include "GetQzssEphemerisBoolParams.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetQzssEphemerisBoolParams
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetQzssEphemerisBoolParams::CmdName = "GetQzssEphemerisBoolParams";
    const char* const GetQzssEphemerisBoolParams::Documentation = "Please note the command GetQzssEphemerisBoolParams is deprecated since 21.3. You may use GetQzssEphBoolParamForEachSV.\n"
      "\n"
      "Please note the command GetQzssEphBoolParamForEachSV is deprecated since 23.11. You may use GetConstellationParameterForSV.\n"
      "\n"
      "Get QZSS ephemeris boolean parameter value for all satellites\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "ParamName   string          Refer to SetQzssEphemerisBoolParam for accepted names\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetQzssEphemerisBoolParams::TargetId = "";

    const char* const GetQzssEphemerisBoolParams::Deprecated = "Please note the command GetQzssEphemerisBoolParams is deprecated since 23.11. You may use GetConstellationParameterForSV.";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetQzssEphemerisBoolParams);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetQzssEphemerisBoolParams);


    GetQzssEphemerisBoolParams::GetQzssEphemerisBoolParams()
      : CommandBase(CmdName, TargetId)
    {}

    GetQzssEphemerisBoolParams::GetQzssEphemerisBoolParams(const std::string& paramName, const std::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setParamName(paramName);
      setDataSetName(dataSetName);
    }

    GetQzssEphemerisBoolParamsPtr GetQzssEphemerisBoolParams::create(const std::string& paramName, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetQzssEphemerisBoolParams>(paramName, dataSetName);
    }

    GetQzssEphemerisBoolParamsPtr GetQzssEphemerisBoolParams::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetQzssEphemerisBoolParams>(ptr);
    }

    bool GetQzssEphemerisBoolParams::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetQzssEphemerisBoolParams::documentation() const { return Documentation; }

    const std::vector<std::string>& GetQzssEphemerisBoolParams::fieldNames() const 
    { 
      static const std::vector<std::string> names {"ParamName", "DataSetName"}; 
      return names; 
    }

    std::optional<std::string> GetQzssEphemerisBoolParams::deprecated() const { return std::optional<std::string>{Deprecated}; }


    int GetQzssEphemerisBoolParams::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetQzssEphemerisBoolParams::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetQzssEphemerisBoolParams::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> GetQzssEphemerisBoolParams::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetQzssEphemerisBoolParams::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

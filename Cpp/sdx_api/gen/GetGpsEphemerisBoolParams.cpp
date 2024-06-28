
#include "GetGpsEphemerisBoolParams.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsEphemerisBoolParams
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsEphemerisBoolParams::CmdName = "GetGpsEphemerisBoolParams";
    const char* const GetGpsEphemerisBoolParams::Documentation = "Please note the command GetGpsEphemerisBoolParams is deprecated since 21.3. You may use GetGpsEphBoolParamForEachSV.\n"
      "\n"
      "Please note the command GetGpsEphBoolParamForEachSV is deprecated since 23.11. You may use GetConstellationParameterForSV.\n"
      "\n"
      "Get GPS ephemeris boolean parameter value for all satellites\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "ParamName   string          Refer to SetGpsEphBoolParamForSV for accepted names\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetGpsEphemerisBoolParams::TargetId = "";

    const char* const GetGpsEphemerisBoolParams::Deprecated = "Please note the command GetGpsEphemerisBoolParams is deprecated since 23.11. You may use GetConstellationParameterForSV.";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetGpsEphemerisBoolParams);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetGpsEphemerisBoolParams);


    GetGpsEphemerisBoolParams::GetGpsEphemerisBoolParams()
      : CommandBase(CmdName, TargetId)
    {}

    GetGpsEphemerisBoolParams::GetGpsEphemerisBoolParams(const std::string& paramName, const std::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setParamName(paramName);
      setDataSetName(dataSetName);
    }

    GetGpsEphemerisBoolParamsPtr GetGpsEphemerisBoolParams::create(const std::string& paramName, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetGpsEphemerisBoolParams>(paramName, dataSetName);
    }

    GetGpsEphemerisBoolParamsPtr GetGpsEphemerisBoolParams::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsEphemerisBoolParams>(ptr);
    }

    bool GetGpsEphemerisBoolParams::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetGpsEphemerisBoolParams::documentation() const { return Documentation; }

    const std::vector<std::string>& GetGpsEphemerisBoolParams::fieldNames() const 
    { 
      static const std::vector<std::string> names {"ParamName", "DataSetName"}; 
      return names; 
    }

    std::optional<std::string> GetGpsEphemerisBoolParams::deprecated() const { return std::optional<std::string>{Deprecated}; }


    int GetGpsEphemerisBoolParams::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetGpsEphemerisBoolParams::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetGpsEphemerisBoolParams::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> GetGpsEphemerisBoolParams::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetGpsEphemerisBoolParams::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

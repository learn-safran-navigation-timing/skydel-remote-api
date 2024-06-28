
#include "GetGpsEphDoubleParamForEachSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsEphDoubleParamForEachSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsEphDoubleParamForEachSV::CmdName = "GetGpsEphDoubleParamForEachSV";
    const char* const GetGpsEphDoubleParamForEachSV::Documentation = "Please note the command GetGpsEphDoubleParamForEachSV is deprecated since 23.11. You may use GetConstellationParameterForSV.\n"
      "\n"
      "Get GPS ephemeris parameter value for all satellites\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "ParamName   string          Refer to SetGpsEphDoubleParamForSV for accepted names\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetGpsEphDoubleParamForEachSV::TargetId = "";

    const char* const GetGpsEphDoubleParamForEachSV::Deprecated = "Please note the command GetGpsEphDoubleParamForEachSV is deprecated since 23.11. You may use GetConstellationParameterForSV.";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetGpsEphDoubleParamForEachSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetGpsEphDoubleParamForEachSV);


    GetGpsEphDoubleParamForEachSV::GetGpsEphDoubleParamForEachSV()
      : CommandBase(CmdName, TargetId)
    {}

    GetGpsEphDoubleParamForEachSV::GetGpsEphDoubleParamForEachSV(const std::string& paramName, const std::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setParamName(paramName);
      setDataSetName(dataSetName);
    }

    GetGpsEphDoubleParamForEachSVPtr GetGpsEphDoubleParamForEachSV::create(const std::string& paramName, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetGpsEphDoubleParamForEachSV>(paramName, dataSetName);
    }

    GetGpsEphDoubleParamForEachSVPtr GetGpsEphDoubleParamForEachSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsEphDoubleParamForEachSV>(ptr);
    }

    bool GetGpsEphDoubleParamForEachSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetGpsEphDoubleParamForEachSV::documentation() const { return Documentation; }

    const std::vector<std::string>& GetGpsEphDoubleParamForEachSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"ParamName", "DataSetName"}; 
      return names; 
    }

    std::optional<std::string> GetGpsEphDoubleParamForEachSV::deprecated() const { return std::optional<std::string>{Deprecated}; }


    int GetGpsEphDoubleParamForEachSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetGpsEphDoubleParamForEachSV::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetGpsEphDoubleParamForEachSV::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> GetGpsEphDoubleParamForEachSV::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetGpsEphDoubleParamForEachSV::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

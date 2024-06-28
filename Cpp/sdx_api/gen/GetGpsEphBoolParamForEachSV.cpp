
#include "GetGpsEphBoolParamForEachSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsEphBoolParamForEachSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsEphBoolParamForEachSV::CmdName = "GetGpsEphBoolParamForEachSV";
    const char* const GetGpsEphBoolParamForEachSV::Documentation = "Please note the command GetGpsEphBoolParamForEachSV is deprecated since 23.11. You may use GetConstellationParameterForSV.\n"
      "\n"
      "Get GPS ephemeris boolean parameter value for all satellites\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "ParamName   string          Refer to SetGpsEphBoolParamForSV for accepted names\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetGpsEphBoolParamForEachSV::TargetId = "";

    const char* const GetGpsEphBoolParamForEachSV::Deprecated = "Please note the command GetGpsEphBoolParamForEachSV is deprecated since 23.11. You may use GetConstellationParameterForSV.";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetGpsEphBoolParamForEachSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetGpsEphBoolParamForEachSV);


    GetGpsEphBoolParamForEachSV::GetGpsEphBoolParamForEachSV()
      : CommandBase(CmdName, TargetId)
    {}

    GetGpsEphBoolParamForEachSV::GetGpsEphBoolParamForEachSV(const std::string& paramName, const std::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setParamName(paramName);
      setDataSetName(dataSetName);
    }

    GetGpsEphBoolParamForEachSVPtr GetGpsEphBoolParamForEachSV::create(const std::string& paramName, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetGpsEphBoolParamForEachSV>(paramName, dataSetName);
    }

    GetGpsEphBoolParamForEachSVPtr GetGpsEphBoolParamForEachSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsEphBoolParamForEachSV>(ptr);
    }

    bool GetGpsEphBoolParamForEachSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetGpsEphBoolParamForEachSV::documentation() const { return Documentation; }

    const std::vector<std::string>& GetGpsEphBoolParamForEachSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"ParamName", "DataSetName"}; 
      return names; 
    }

    std::optional<std::string> GetGpsEphBoolParamForEachSV::deprecated() const { return std::optional<std::string>{Deprecated}; }


    int GetGpsEphBoolParamForEachSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetGpsEphBoolParamForEachSV::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetGpsEphBoolParamForEachSV::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> GetGpsEphBoolParamForEachSV::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetGpsEphBoolParamForEachSV::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

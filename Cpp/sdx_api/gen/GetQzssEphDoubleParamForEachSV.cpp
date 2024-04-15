
#include "GetQzssEphDoubleParamForEachSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetQzssEphDoubleParamForEachSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetQzssEphDoubleParamForEachSV::CmdName = "GetQzssEphDoubleParamForEachSV";
    const char* const GetQzssEphDoubleParamForEachSV::Documentation = "Please note the command GetQzssEphDoubleParamForEachSV is deprecated since 23.11. You may use GetConstellationParameterForSV.\n"
      "\n"
      "Get QZSS ephemeris parameter value for all satellites\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "ParamName   string          Refer to SetQzssEphDoubleParamForSV for accepted names\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetQzssEphDoubleParamForEachSV::TargetId = "";

    const char* const GetQzssEphDoubleParamForEachSV::Deprecated = "Please note the command GetQzssEphDoubleParamForEachSV is deprecated since 23.11. You may use GetConstellationParameterForSV.";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetQzssEphDoubleParamForEachSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetQzssEphDoubleParamForEachSV);


    GetQzssEphDoubleParamForEachSV::GetQzssEphDoubleParamForEachSV()
      : CommandBase(CmdName, TargetId)
    {}

    GetQzssEphDoubleParamForEachSV::GetQzssEphDoubleParamForEachSV(const std::string& paramName, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setParamName(paramName);
      setDataSetName(dataSetName);
    }

    GetQzssEphDoubleParamForEachSVPtr GetQzssEphDoubleParamForEachSV::create(const std::string& paramName, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetQzssEphDoubleParamForEachSV>(paramName, dataSetName);
    }

    GetQzssEphDoubleParamForEachSVPtr GetQzssEphDoubleParamForEachSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetQzssEphDoubleParamForEachSV>(ptr);
    }

    bool GetQzssEphDoubleParamForEachSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetQzssEphDoubleParamForEachSV::documentation() const { return Documentation; }

    const std::vector<std::string>& GetQzssEphDoubleParamForEachSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"ParamName", "DataSetName"}; 
      return names; 
    }

    Sdx::optional<std::string> GetQzssEphDoubleParamForEachSV::deprecated() const { return Sdx::optional<std::string>{Deprecated}; }


    int GetQzssEphDoubleParamForEachSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetQzssEphDoubleParamForEachSV::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetQzssEphDoubleParamForEachSV::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetQzssEphDoubleParamForEachSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetQzssEphDoubleParamForEachSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

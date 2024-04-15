
#include "GetBeiDouEphDoubleParamForEachSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetBeiDouEphDoubleParamForEachSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetBeiDouEphDoubleParamForEachSV::CmdName = "GetBeiDouEphDoubleParamForEachSV";
    const char* const GetBeiDouEphDoubleParamForEachSV::Documentation = "Please note the command GetBeiDouEphDoubleParamForEachSV is deprecated since 23.11. You may use GetConstellationParameterForSV.\n"
      "\n"
      "Get BeiDou ephemeris parameter value for all satellites\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "ParamName   string          Refer to SetBeiDouEphDoubleParamForSV for accepted names\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetBeiDouEphDoubleParamForEachSV::TargetId = "";

    const char* const GetBeiDouEphDoubleParamForEachSV::Deprecated = "Please note the command GetBeiDouEphDoubleParamForEachSV is deprecated since 23.11. You may use GetConstellationParameterForSV.";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetBeiDouEphDoubleParamForEachSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetBeiDouEphDoubleParamForEachSV);


    GetBeiDouEphDoubleParamForEachSV::GetBeiDouEphDoubleParamForEachSV()
      : CommandBase(CmdName, TargetId)
    {}

    GetBeiDouEphDoubleParamForEachSV::GetBeiDouEphDoubleParamForEachSV(const std::string& paramName, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setParamName(paramName);
      setDataSetName(dataSetName);
    }

    GetBeiDouEphDoubleParamForEachSVPtr GetBeiDouEphDoubleParamForEachSV::create(const std::string& paramName, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetBeiDouEphDoubleParamForEachSV>(paramName, dataSetName);
    }

    GetBeiDouEphDoubleParamForEachSVPtr GetBeiDouEphDoubleParamForEachSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetBeiDouEphDoubleParamForEachSV>(ptr);
    }

    bool GetBeiDouEphDoubleParamForEachSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetBeiDouEphDoubleParamForEachSV::documentation() const { return Documentation; }

    const std::vector<std::string>& GetBeiDouEphDoubleParamForEachSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"ParamName", "DataSetName"}; 
      return names; 
    }

    Sdx::optional<std::string> GetBeiDouEphDoubleParamForEachSV::deprecated() const { return Sdx::optional<std::string>{Deprecated}; }


    int GetBeiDouEphDoubleParamForEachSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetBeiDouEphDoubleParamForEachSV::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetBeiDouEphDoubleParamForEachSV::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetBeiDouEphDoubleParamForEachSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetBeiDouEphDoubleParamForEachSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}


#include "GetBeiDouEphBoolParamForEachSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetBeiDouEphBoolParamForEachSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetBeiDouEphBoolParamForEachSV::CmdName = "GetBeiDouEphBoolParamForEachSV";
    const char* const GetBeiDouEphBoolParamForEachSV::Documentation = "Please note the command GetBeiDouEphBoolParamForEachSV is deprecated since 23.11. You may use GetConstellationParameterForSV.\n"
      "\n"
      "Get BeiDou ephemeris boolean parameter value for all satellites\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "ParamName   string          Refer to SetBeiDouEphBoolParamForSV for accepted names\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetBeiDouEphBoolParamForEachSV::TargetId = "";

    const char* const GetBeiDouEphBoolParamForEachSV::Deprecated = "Please note the command GetBeiDouEphBoolParamForEachSV is deprecated since 23.11. You may use GetConstellationParameterForSV.";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetBeiDouEphBoolParamForEachSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetBeiDouEphBoolParamForEachSV);


    GetBeiDouEphBoolParamForEachSV::GetBeiDouEphBoolParamForEachSV()
      : CommandBase(CmdName, TargetId)
    {}

    GetBeiDouEphBoolParamForEachSV::GetBeiDouEphBoolParamForEachSV(const std::string& paramName, const std::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setParamName(paramName);
      setDataSetName(dataSetName);
    }

    GetBeiDouEphBoolParamForEachSVPtr GetBeiDouEphBoolParamForEachSV::create(const std::string& paramName, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetBeiDouEphBoolParamForEachSV>(paramName, dataSetName);
    }

    GetBeiDouEphBoolParamForEachSVPtr GetBeiDouEphBoolParamForEachSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetBeiDouEphBoolParamForEachSV>(ptr);
    }

    bool GetBeiDouEphBoolParamForEachSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetBeiDouEphBoolParamForEachSV::documentation() const { return Documentation; }

    const std::vector<std::string>& GetBeiDouEphBoolParamForEachSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"ParamName", "DataSetName"}; 
      return names; 
    }

    std::optional<std::string> GetBeiDouEphBoolParamForEachSV::deprecated() const { return std::optional<std::string>{Deprecated}; }


    int GetBeiDouEphBoolParamForEachSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetBeiDouEphBoolParamForEachSV::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetBeiDouEphBoolParamForEachSV::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> GetBeiDouEphBoolParamForEachSV::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetBeiDouEphBoolParamForEachSV::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}


#include "GetBeiDouEphemerisDoubleParams.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetBeiDouEphemerisDoubleParams
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetBeiDouEphemerisDoubleParams::CmdName = "GetBeiDouEphemerisDoubleParams";
    const char* const GetBeiDouEphemerisDoubleParams::Documentation = "Please note the command GetBeiDouEphemerisDoubleParams is deprecated since 21.3. You may use GetBeiDouEphDoubleParamForEachSV.\n"
      "\n"
      "Please note the command GetBeiDouEphDoubleParamForEachSV is deprecated since 23.11. You may use GetConstellationParameterForSV.\n"
      "\n"
      "Get BeiDou ephemeris parameter value for all satellites\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "ParamName   string          Refer to SetBeiDouEphDoubleParamForSV for accepted names\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetBeiDouEphemerisDoubleParams::TargetId = "";

    const char* const GetBeiDouEphemerisDoubleParams::Deprecated = "Please note the command GetBeiDouEphemerisDoubleParams is deprecated since 23.11. You may use GetConstellationParameterForSV.";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetBeiDouEphemerisDoubleParams);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetBeiDouEphemerisDoubleParams);


    GetBeiDouEphemerisDoubleParams::GetBeiDouEphemerisDoubleParams()
      : CommandBase(CmdName, TargetId)
    {}

    GetBeiDouEphemerisDoubleParams::GetBeiDouEphemerisDoubleParams(const std::string& paramName, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setParamName(paramName);
      setDataSetName(dataSetName);
    }

    GetBeiDouEphemerisDoubleParamsPtr GetBeiDouEphemerisDoubleParams::create(const std::string& paramName, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetBeiDouEphemerisDoubleParams>(paramName, dataSetName);
    }

    GetBeiDouEphemerisDoubleParamsPtr GetBeiDouEphemerisDoubleParams::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetBeiDouEphemerisDoubleParams>(ptr);
    }

    bool GetBeiDouEphemerisDoubleParams::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetBeiDouEphemerisDoubleParams::documentation() const { return Documentation; }

    const std::vector<std::string>& GetBeiDouEphemerisDoubleParams::fieldNames() const 
    { 
      static const std::vector<std::string> names {"ParamName", "DataSetName"}; 
      return names; 
    }

    Sdx::optional<std::string> GetBeiDouEphemerisDoubleParams::deprecated() const { return Sdx::optional<std::string>{Deprecated}; }


    int GetBeiDouEphemerisDoubleParams::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetBeiDouEphemerisDoubleParams::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetBeiDouEphemerisDoubleParams::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetBeiDouEphemerisDoubleParams::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetBeiDouEphemerisDoubleParams::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

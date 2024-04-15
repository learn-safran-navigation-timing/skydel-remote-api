
#include "GetGalileoEphDoubleParamForEachSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGalileoEphDoubleParamForEachSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGalileoEphDoubleParamForEachSV::CmdName = "GetGalileoEphDoubleParamForEachSV";
    const char* const GetGalileoEphDoubleParamForEachSV::Documentation = "Please note the command GetGalileoEphDoubleParamForEachSV is deprecated since 23.11. You may use GetConstellationParameterForSV.\n"
      "\n"
      "Get Galileo ephemeris parameter value for all satellites\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "ParamName   string          Refer to SetGalileoEphDoubleParamForSV for accepted names\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetGalileoEphDoubleParamForEachSV::TargetId = "";

    const char* const GetGalileoEphDoubleParamForEachSV::Deprecated = "Please note the command GetGalileoEphDoubleParamForEachSV is deprecated since 23.11. You may use GetConstellationParameterForSV.";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetGalileoEphDoubleParamForEachSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetGalileoEphDoubleParamForEachSV);


    GetGalileoEphDoubleParamForEachSV::GetGalileoEphDoubleParamForEachSV()
      : CommandBase(CmdName, TargetId)
    {}

    GetGalileoEphDoubleParamForEachSV::GetGalileoEphDoubleParamForEachSV(const std::string& paramName, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setParamName(paramName);
      setDataSetName(dataSetName);
    }

    GetGalileoEphDoubleParamForEachSVPtr GetGalileoEphDoubleParamForEachSV::create(const std::string& paramName, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetGalileoEphDoubleParamForEachSV>(paramName, dataSetName);
    }

    GetGalileoEphDoubleParamForEachSVPtr GetGalileoEphDoubleParamForEachSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGalileoEphDoubleParamForEachSV>(ptr);
    }

    bool GetGalileoEphDoubleParamForEachSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetGalileoEphDoubleParamForEachSV::documentation() const { return Documentation; }

    const std::vector<std::string>& GetGalileoEphDoubleParamForEachSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"ParamName", "DataSetName"}; 
      return names; 
    }

    Sdx::optional<std::string> GetGalileoEphDoubleParamForEachSV::deprecated() const { return Sdx::optional<std::string>{Deprecated}; }


    int GetGalileoEphDoubleParamForEachSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetGalileoEphDoubleParamForEachSV::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetGalileoEphDoubleParamForEachSV::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetGalileoEphDoubleParamForEachSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetGalileoEphDoubleParamForEachSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

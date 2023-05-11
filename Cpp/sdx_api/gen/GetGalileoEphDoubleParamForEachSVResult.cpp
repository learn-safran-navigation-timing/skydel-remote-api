
#include "gen/GetGalileoEphDoubleParamForEachSVResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGalileoEphDoubleParamForEachSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGalileoEphDoubleParamForEachSVResult::CmdName = "GetGalileoEphDoubleParamForEachSVResult";
    const char* const GetGalileoEphDoubleParamForEachSVResult::Documentation = "Result of GetGalileoEphDoubleParamForEachSV.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetGalileoEphDoubleParamForEachSVResult);


    GetGalileoEphDoubleParamForEachSVResult::GetGalileoEphDoubleParamForEachSVResult()
      : CommandResult(CmdName)
    {}

    GetGalileoEphDoubleParamForEachSVResult::GetGalileoEphDoubleParamForEachSVResult(const std::string& paramName, const std::vector<double>& val, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName)
    {

      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }

    GetGalileoEphDoubleParamForEachSVResult::GetGalileoEphDoubleParamForEachSVResult(CommandBasePtr relatedCommand, const std::string& paramName, const std::vector<double>& val, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName, relatedCommand)
    {

      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }


    GetGalileoEphDoubleParamForEachSVResultPtr GetGalileoEphDoubleParamForEachSVResult::create(const std::string& paramName, const std::vector<double>& val, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetGalileoEphDoubleParamForEachSVResult>(paramName, val, dataSetName);
    }

    GetGalileoEphDoubleParamForEachSVResultPtr GetGalileoEphDoubleParamForEachSVResult::create(CommandBasePtr relatedCommand, const std::string& paramName, const std::vector<double>& val, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetGalileoEphDoubleParamForEachSVResult>(relatedCommand, paramName, val, dataSetName);
    }

    GetGalileoEphDoubleParamForEachSVResultPtr GetGalileoEphDoubleParamForEachSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGalileoEphDoubleParamForEachSVResult>(ptr);
    }

    bool GetGalileoEphDoubleParamForEachSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<std::vector<double>>::is_valid(m_values["Val"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetGalileoEphDoubleParamForEachSVResult::documentation() const { return Documentation; }


    std::string GetGalileoEphDoubleParamForEachSVResult::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetGalileoEphDoubleParamForEachSVResult::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<double> GetGalileoEphDoubleParamForEachSVResult::val() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Val"]);
    }

    void GetGalileoEphDoubleParamForEachSVResult::setVal(const std::vector<double>& val)
    {
      m_values.AddMember("Val", parse_json<std::vector<double>>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetGalileoEphDoubleParamForEachSVResult::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetGalileoEphDoubleParamForEachSVResult::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}


#include "gen/GetConstellationParameterForSVResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetConstellationParameterForSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetConstellationParameterForSVResult::CmdName = "GetConstellationParameterForSVResult";
    const char* const GetConstellationParameterForSVResult::Documentation = "Result of GetConstellationParameterForSV.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetConstellationParameterForSVResult);


    GetConstellationParameterForSVResult::GetConstellationParameterForSVResult()
      : CommandResult(CmdName)
    {}

    GetConstellationParameterForSVResult::GetConstellationParameterForSVResult(const std::string& system, int svId, const std::string& paramName, double val, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName)
    {

      setSystem(system);
      setSvId(svId);
      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }

    GetConstellationParameterForSVResult::GetConstellationParameterForSVResult(CommandBasePtr relatedCommand, const std::string& system, int svId, const std::string& paramName, double val, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName, relatedCommand)
    {

      setSystem(system);
      setSvId(svId);
      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }

    GetConstellationParameterForSVResult::GetConstellationParameterForSVResult(const std::string& system, int svId, const std::string& paramName, int val, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName)
    {

      setSystem(system);
      setSvId(svId);
      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }

    GetConstellationParameterForSVResult::GetConstellationParameterForSVResult(CommandBasePtr relatedCommand, const std::string& system, int svId, const std::string& paramName, int val, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName, relatedCommand)
    {

      setSystem(system);
      setSvId(svId);
      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }

    GetConstellationParameterForSVResult::GetConstellationParameterForSVResult(const std::string& system, int svId, const std::string& paramName, bool val, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName)
    {

      setSystem(system);
      setSvId(svId);
      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }

    GetConstellationParameterForSVResult::GetConstellationParameterForSVResult(CommandBasePtr relatedCommand, const std::string& system, int svId, const std::string& paramName, bool val, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName, relatedCommand)
    {

      setSystem(system);
      setSvId(svId);
      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }


    GetConstellationParameterForSVResultPtr GetConstellationParameterForSVResult::create(const std::string& system, int svId, const std::string& paramName, double val, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetConstellationParameterForSVResult>(system, svId, paramName, val, dataSetName);
    }

    GetConstellationParameterForSVResultPtr GetConstellationParameterForSVResult::create(CommandBasePtr relatedCommand, const std::string& system, int svId, const std::string& paramName, double val, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetConstellationParameterForSVResult>(relatedCommand, system, svId, paramName, val, dataSetName);
    }


    GetConstellationParameterForSVResultPtr GetConstellationParameterForSVResult::create(const std::string& system, int svId, const std::string& paramName, int val, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetConstellationParameterForSVResult>(system, svId, paramName, val, dataSetName);
    }

    GetConstellationParameterForSVResultPtr GetConstellationParameterForSVResult::create(CommandBasePtr relatedCommand, const std::string& system, int svId, const std::string& paramName, int val, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetConstellationParameterForSVResult>(relatedCommand, system, svId, paramName, val, dataSetName);
    }


    GetConstellationParameterForSVResultPtr GetConstellationParameterForSVResult::create(const std::string& system, int svId, const std::string& paramName, bool val, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetConstellationParameterForSVResult>(system, svId, paramName, val, dataSetName);
    }

    GetConstellationParameterForSVResultPtr GetConstellationParameterForSVResult::create(CommandBasePtr relatedCommand, const std::string& system, int svId, const std::string& paramName, bool val, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetConstellationParameterForSVResult>(relatedCommand, system, svId, paramName, val, dataSetName);
    }

    GetConstellationParameterForSVResultPtr GetConstellationParameterForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetConstellationParameterForSVResult>(ptr);
    }

    bool GetConstellationParameterForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && (parse_json<double>::is_valid(m_values["Val"]) || parse_json<int>::is_valid(m_values["Val"]) || parse_json<bool>::is_valid(m_values["Val"]))
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetConstellationParameterForSVResult::documentation() const { return Documentation; }


    std::string GetConstellationParameterForSVResult::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetConstellationParameterForSVResult::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetConstellationParameterForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetConstellationParameterForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetConstellationParameterForSVResult::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetConstellationParameterForSVResult::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    template<typename Type>
    Type GetConstellationParameterForSVResult::val() const
    {
      return parse_json<Type>::parse(m_values["Val"]);
    }

    template<typename Type>
    void GetConstellationParameterForSVResult::setVal(Type val)
    {
      m_values.AddMember("Val", parse_json<Type>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetConstellationParameterForSVResult::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetConstellationParameterForSVResult::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

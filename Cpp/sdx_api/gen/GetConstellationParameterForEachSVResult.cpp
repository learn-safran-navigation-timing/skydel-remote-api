
#include "gen/GetConstellationParameterForEachSVResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetConstellationParameterForEachSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetConstellationParameterForEachSVResult::CmdName = "GetConstellationParameterForEachSVResult";
    const char* const GetConstellationParameterForEachSVResult::Documentation = "Result of GetConstellationParameterForEachSV.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetConstellationParameterForEachSVResult);


    GetConstellationParameterForEachSVResult::GetConstellationParameterForEachSVResult()
      : CommandResult(CmdName)
    {}

    GetConstellationParameterForEachSVResult::GetConstellationParameterForEachSVResult(const std::string& system, const std::string& paramName, const std::vector<double>& val, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName)
    {

      setSystem(system);
      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }

    GetConstellationParameterForEachSVResult::GetConstellationParameterForEachSVResult(CommandBasePtr relatedCommand, const std::string& system, const std::string& paramName, const std::vector<double>& val, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName, relatedCommand)
    {

      setSystem(system);
      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }

    GetConstellationParameterForEachSVResult::GetConstellationParameterForEachSVResult(const std::string& system, const std::string& paramName, const std::vector<int>& val, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName)
    {

      setSystem(system);
      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }

    GetConstellationParameterForEachSVResult::GetConstellationParameterForEachSVResult(CommandBasePtr relatedCommand, const std::string& system, const std::string& paramName, const std::vector<int>& val, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName, relatedCommand)
    {

      setSystem(system);
      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }

    GetConstellationParameterForEachSVResult::GetConstellationParameterForEachSVResult(const std::string& system, const std::string& paramName, const std::vector<bool>& val, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName)
    {

      setSystem(system);
      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }

    GetConstellationParameterForEachSVResult::GetConstellationParameterForEachSVResult(CommandBasePtr relatedCommand, const std::string& system, const std::string& paramName, const std::vector<bool>& val, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName, relatedCommand)
    {

      setSystem(system);
      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }


    GetConstellationParameterForEachSVResultPtr GetConstellationParameterForEachSVResult::create(const std::string& system, const std::string& paramName, const std::vector<double>& val, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetConstellationParameterForEachSVResult>(system, paramName, val, dataSetName);
    }

    GetConstellationParameterForEachSVResultPtr GetConstellationParameterForEachSVResult::create(CommandBasePtr relatedCommand, const std::string& system, const std::string& paramName, const std::vector<double>& val, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetConstellationParameterForEachSVResult>(relatedCommand, system, paramName, val, dataSetName);
    }


    GetConstellationParameterForEachSVResultPtr GetConstellationParameterForEachSVResult::create(const std::string& system, const std::string& paramName, const std::vector<int>& val, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetConstellationParameterForEachSVResult>(system, paramName, val, dataSetName);
    }

    GetConstellationParameterForEachSVResultPtr GetConstellationParameterForEachSVResult::create(CommandBasePtr relatedCommand, const std::string& system, const std::string& paramName, const std::vector<int>& val, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetConstellationParameterForEachSVResult>(relatedCommand, system, paramName, val, dataSetName);
    }


    GetConstellationParameterForEachSVResultPtr GetConstellationParameterForEachSVResult::create(const std::string& system, const std::string& paramName, const std::vector<bool>& val, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetConstellationParameterForEachSVResult>(system, paramName, val, dataSetName);
    }

    GetConstellationParameterForEachSVResultPtr GetConstellationParameterForEachSVResult::create(CommandBasePtr relatedCommand, const std::string& system, const std::string& paramName, const std::vector<bool>& val, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetConstellationParameterForEachSVResult>(relatedCommand, system, paramName, val, dataSetName);
    }

    GetConstellationParameterForEachSVResultPtr GetConstellationParameterForEachSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetConstellationParameterForEachSVResult>(ptr);
    }

    bool GetConstellationParameterForEachSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && (parse_json<std::vector<double>>::is_valid(m_values["Val"]) || parse_json<std::vector<int>>::is_valid(m_values["Val"]) || parse_json<std::vector<bool>>::is_valid(m_values["Val"]))
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetConstellationParameterForEachSVResult::documentation() const { return Documentation; }


    std::string GetConstellationParameterForEachSVResult::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetConstellationParameterForEachSVResult::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetConstellationParameterForEachSVResult::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetConstellationParameterForEachSVResult::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    template<typename Type>
    Type GetConstellationParameterForEachSVResult::val() const
    {
      return parse_json<Type>::parse(m_values["Val"]);
    }

    template<typename Type>
    void GetConstellationParameterForEachSVResult::setVal(Type val)
    {
      m_values.AddMember("Val", parse_json<Type>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetConstellationParameterForEachSVResult::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetConstellationParameterForEachSVResult::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

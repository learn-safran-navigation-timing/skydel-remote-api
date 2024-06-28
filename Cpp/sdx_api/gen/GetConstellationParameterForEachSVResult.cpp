
#include "GetConstellationParameterForEachSVResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetConstellationParameterForEachSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetConstellationParameterForEachSVResult::CmdName = "GetConstellationParameterForEachSVResult";
    const char* const GetConstellationParameterForEachSVResult::Documentation = "Result of GetConstellationParameterForEachSV.\n"
      "\n"
      "Name        Type                                    Description\n"
      "----------- --------------------------------------- ----------------------------------------------------------------------------------------------------\n"
      "System      string                                  \"GPS\", \"Galileo\", \"BeiDou\", \"QZSS\", \"NavIC\" or \"PULSAR\".\n"
      "ParamName   string                                  Refer to SetConstellationParameterForSV for accepted names.\n"
      "Val         array double or array int or array bool Parameter value for each satellite. Zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc.).\n"
      "DataSetName optional string                         Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetConstellationParameterForEachSVResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetConstellationParameterForEachSVResult);


    GetConstellationParameterForEachSVResult::GetConstellationParameterForEachSVResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetConstellationParameterForEachSVResult::GetConstellationParameterForEachSVResult(const std::string& system, const std::string& paramName, const std::vector<double>& val, const std::optional<std::string>& dataSetName)
      : CommandResult(CmdName, TargetId)
    {

      setSystem(system);
      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }

    GetConstellationParameterForEachSVResult::GetConstellationParameterForEachSVResult(CommandBasePtr relatedCommand, const std::string& system, const std::string& paramName, const std::vector<double>& val, const std::optional<std::string>& dataSetName)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setSystem(system);
      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }

    GetConstellationParameterForEachSVResult::GetConstellationParameterForEachSVResult(const std::string& system, const std::string& paramName, const std::vector<int>& val, const std::optional<std::string>& dataSetName)
      : CommandResult(CmdName, TargetId)
    {

      setSystem(system);
      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }

    GetConstellationParameterForEachSVResult::GetConstellationParameterForEachSVResult(CommandBasePtr relatedCommand, const std::string& system, const std::string& paramName, const std::vector<int>& val, const std::optional<std::string>& dataSetName)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setSystem(system);
      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }

    GetConstellationParameterForEachSVResult::GetConstellationParameterForEachSVResult(const std::string& system, const std::string& paramName, const std::vector<bool>& val, const std::optional<std::string>& dataSetName)
      : CommandResult(CmdName, TargetId)
    {

      setSystem(system);
      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }

    GetConstellationParameterForEachSVResult::GetConstellationParameterForEachSVResult(CommandBasePtr relatedCommand, const std::string& system, const std::string& paramName, const std::vector<bool>& val, const std::optional<std::string>& dataSetName)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setSystem(system);
      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }


    GetConstellationParameterForEachSVResultPtr GetConstellationParameterForEachSVResult::create(const std::string& system, const std::string& paramName, const std::vector<double>& val, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetConstellationParameterForEachSVResult>(system, paramName, val, dataSetName);
    }

    GetConstellationParameterForEachSVResultPtr GetConstellationParameterForEachSVResult::create(CommandBasePtr relatedCommand, const std::string& system, const std::string& paramName, const std::vector<double>& val, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetConstellationParameterForEachSVResult>(relatedCommand, system, paramName, val, dataSetName);
    }


    GetConstellationParameterForEachSVResultPtr GetConstellationParameterForEachSVResult::create(const std::string& system, const std::string& paramName, const std::vector<int>& val, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetConstellationParameterForEachSVResult>(system, paramName, val, dataSetName);
    }

    GetConstellationParameterForEachSVResultPtr GetConstellationParameterForEachSVResult::create(CommandBasePtr relatedCommand, const std::string& system, const std::string& paramName, const std::vector<int>& val, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetConstellationParameterForEachSVResult>(relatedCommand, system, paramName, val, dataSetName);
    }


    GetConstellationParameterForEachSVResultPtr GetConstellationParameterForEachSVResult::create(const std::string& system, const std::string& paramName, const std::vector<bool>& val, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetConstellationParameterForEachSVResult>(system, paramName, val, dataSetName);
    }

    GetConstellationParameterForEachSVResultPtr GetConstellationParameterForEachSVResult::create(CommandBasePtr relatedCommand, const std::string& system, const std::string& paramName, const std::vector<bool>& val, const std::optional<std::string>& dataSetName)
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
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetConstellationParameterForEachSVResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetConstellationParameterForEachSVResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "ParamName", "Val", "DataSetName"}; 
      return names; 
    }


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



    std::optional<std::string> GetConstellationParameterForEachSVResult::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetConstellationParameterForEachSVResult::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

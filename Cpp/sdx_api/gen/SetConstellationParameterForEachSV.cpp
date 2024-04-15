
#include "SetConstellationParameterForEachSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetConstellationParameterForEachSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetConstellationParameterForEachSV::CmdName = "SetConstellationParameterForEachSV";
    const char* const SetConstellationParameterForEachSV::Documentation = "Set \"GPS\", \"Galileo\", \"BeiDou\", \"QZSS\", \"NavIC\" or \"PULSAR\" constellation parameter value for all satellites.\n"
      "\n"
      "Name        Type                                    Description\n"
      "----------- --------------------------------------- ----------------------------------------------------------------------------------------------------\n"
      "System      string                                  \"GPS\", \"Galileo\", \"BeiDou\", \"QZSS\", \"NavIC\" or \"PULSAR\".\n"
      "ParamName   string                                  Refer to SetConstellationParameterForSV for accepted names.\n"
      "Val         array double or array int or array bool Parameter value for each satellite. Zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc.).\n"
      "DataSetName optional string                         Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const SetConstellationParameterForEachSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetConstellationParameterForEachSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetConstellationParameterForEachSV);


    SetConstellationParameterForEachSV::SetConstellationParameterForEachSV()
      : CommandBase(CmdName, TargetId)
    {}

    SetConstellationParameterForEachSV::SetConstellationParameterForEachSV(const std::string& system, const std::string& paramName, const std::vector<double>& val, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSystem(system);
      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }

    SetConstellationParameterForEachSV::SetConstellationParameterForEachSV(const std::string& system, const std::string& paramName, const std::vector<int>& val, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSystem(system);
      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }

    SetConstellationParameterForEachSV::SetConstellationParameterForEachSV(const std::string& system, const std::string& paramName, const std::vector<bool>& val, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSystem(system);
      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }

    SetConstellationParameterForEachSVPtr SetConstellationParameterForEachSV::create(const std::string& system, const std::string& paramName, const std::vector<double>& val, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetConstellationParameterForEachSV>(system, paramName, val, dataSetName);
    }

    SetConstellationParameterForEachSVPtr SetConstellationParameterForEachSV::create(const std::string& system, const std::string& paramName, const std::vector<int>& val, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetConstellationParameterForEachSV>(system, paramName, val, dataSetName);
    }

    SetConstellationParameterForEachSVPtr SetConstellationParameterForEachSV::create(const std::string& system, const std::string& paramName, const std::vector<bool>& val, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetConstellationParameterForEachSV>(system, paramName, val, dataSetName);
    }

    SetConstellationParameterForEachSVPtr SetConstellationParameterForEachSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetConstellationParameterForEachSV>(ptr);
    }

    bool SetConstellationParameterForEachSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && (parse_json<std::vector<double>>::is_valid(m_values["Val"]) || parse_json<std::vector<int>>::is_valid(m_values["Val"]) || parse_json<std::vector<bool>>::is_valid(m_values["Val"]))
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetConstellationParameterForEachSV::documentation() const { return Documentation; }

    const std::vector<std::string>& SetConstellationParameterForEachSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "ParamName", "Val", "DataSetName"}; 
      return names; 
    }


    int SetConstellationParameterForEachSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetConstellationParameterForEachSV::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void SetConstellationParameterForEachSV::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetConstellationParameterForEachSV::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void SetConstellationParameterForEachSV::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    template<typename Type>
    Type SetConstellationParameterForEachSV::val() const
    {
      return parse_json<Type>::parse(m_values["Val"]);
    }

    template<typename Type>
    void SetConstellationParameterForEachSV::setVal(Type val)
    {
      m_values.AddMember("Val", parse_json<Type>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> SetConstellationParameterForEachSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetConstellationParameterForEachSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

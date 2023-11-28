
#include "gen/SetConstellationParameterForEachSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetConstellationParameterForEachSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetConstellationParameterForEachSV::CmdName = "SetConstellationParameterForEachSV";
    const char* const SetConstellationParameterForEachSV::Documentation = "Set \"GPS\", \"Galileo\", \"BeiDou\", \"QZSS\" or \"NavIC\" constellation parameter value for all satellites.";

    REGISTER_COMMAND_FACTORY(SetConstellationParameterForEachSV);


    SetConstellationParameterForEachSV::SetConstellationParameterForEachSV()
      : CommandBase(CmdName)
    {}

    SetConstellationParameterForEachSV::SetConstellationParameterForEachSV(const std::string& system, const std::string& paramName, const std::vector<double>& val, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setSystem(system);
      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }

    SetConstellationParameterForEachSV::SetConstellationParameterForEachSV(const std::string& system, const std::string& paramName, const std::vector<int>& val, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setSystem(system);
      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }

    SetConstellationParameterForEachSV::SetConstellationParameterForEachSV(const std::string& system, const std::string& paramName, const std::vector<bool>& val, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
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

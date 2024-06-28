
#include "GetConstellationParameterForEachSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetConstellationParameterForEachSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetConstellationParameterForEachSV::CmdName = "GetConstellationParameterForEachSV";
    const char* const GetConstellationParameterForEachSV::Documentation = "Get \"GPS\", \"Galileo\", \"BeiDou\", \"QZSS\", \"NavIC\" or \"PULSAR\" constellation parameter value for all satellites.\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "System      string          \"GPS\", \"Galileo\", \"BeiDou\", \"QZSS\", \"NavIC\" or \"PULSAR\".\n"
      "ParamName   string          Refer to SetConstellationParameterForSV for accepted names.\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetConstellationParameterForEachSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetConstellationParameterForEachSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetConstellationParameterForEachSV);


    GetConstellationParameterForEachSV::GetConstellationParameterForEachSV()
      : CommandBase(CmdName, TargetId)
    {}

    GetConstellationParameterForEachSV::GetConstellationParameterForEachSV(const std::string& system, const std::string& paramName, const std::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSystem(system);
      setParamName(paramName);
      setDataSetName(dataSetName);
    }

    GetConstellationParameterForEachSVPtr GetConstellationParameterForEachSV::create(const std::string& system, const std::string& paramName, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetConstellationParameterForEachSV>(system, paramName, dataSetName);
    }

    GetConstellationParameterForEachSVPtr GetConstellationParameterForEachSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetConstellationParameterForEachSV>(ptr);
    }

    bool GetConstellationParameterForEachSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetConstellationParameterForEachSV::documentation() const { return Documentation; }

    const std::vector<std::string>& GetConstellationParameterForEachSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "ParamName", "DataSetName"}; 
      return names; 
    }


    int GetConstellationParameterForEachSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetConstellationParameterForEachSV::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetConstellationParameterForEachSV::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetConstellationParameterForEachSV::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetConstellationParameterForEachSV::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> GetConstellationParameterForEachSV::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetConstellationParameterForEachSV::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

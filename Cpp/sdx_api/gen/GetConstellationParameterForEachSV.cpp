
#include "gen/GetConstellationParameterForEachSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetConstellationParameterForEachSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetConstellationParameterForEachSV::CmdName = "GetConstellationParameterForEachSV";
    const char* const GetConstellationParameterForEachSV::Documentation = "Get \"GPS\", \"Galileo\", \"BeiDou\", \"QZSS\" or \"NavIC\" constellation parameter value for all satellites.";

    REGISTER_COMMAND_FACTORY(GetConstellationParameterForEachSV);


    GetConstellationParameterForEachSV::GetConstellationParameterForEachSV()
      : CommandBase(CmdName)
    {}

    GetConstellationParameterForEachSV::GetConstellationParameterForEachSV(const std::string& system, const std::string& paramName, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setSystem(system);
      setParamName(paramName);
      setDataSetName(dataSetName);
    }

    GetConstellationParameterForEachSVPtr GetConstellationParameterForEachSV::create(const std::string& system, const std::string& paramName, const Sdx::optional<std::string>& dataSetName)
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
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetConstellationParameterForEachSV::documentation() const { return Documentation; }


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



    Sdx::optional<std::string> GetConstellationParameterForEachSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetConstellationParameterForEachSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

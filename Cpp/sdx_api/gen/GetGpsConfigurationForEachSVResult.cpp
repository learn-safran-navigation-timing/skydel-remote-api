
#include "gen/GetGpsConfigurationForEachSVResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsConfigurationForEachSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsConfigurationForEachSVResult::CmdName = "GetGpsConfigurationForEachSVResult";
    const char* const GetGpsConfigurationForEachSVResult::Documentation = "Result of GetGpsConfigurationForEachSV.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetGpsConfigurationForEachSVResult);


    GetGpsConfigurationForEachSVResult::GetGpsConfigurationForEachSVResult()
      : CommandResult(CmdName)
    {}

    GetGpsConfigurationForEachSVResult::GetGpsConfigurationForEachSVResult(const std::vector<int>& svConfigs, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName)
    {

      setSvConfigs(svConfigs);
      setDataSetName(dataSetName);
    }

    GetGpsConfigurationForEachSVResult::GetGpsConfigurationForEachSVResult(CommandBasePtr relatedCommand, const std::vector<int>& svConfigs, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName, relatedCommand)
    {

      setSvConfigs(svConfigs);
      setDataSetName(dataSetName);
    }


    GetGpsConfigurationForEachSVResultPtr GetGpsConfigurationForEachSVResult::create(const std::vector<int>& svConfigs, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetGpsConfigurationForEachSVResult>(svConfigs, dataSetName);
    }

    GetGpsConfigurationForEachSVResultPtr GetGpsConfigurationForEachSVResult::create(CommandBasePtr relatedCommand, const std::vector<int>& svConfigs, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetGpsConfigurationForEachSVResult>(relatedCommand, svConfigs, dataSetName);
    }

    GetGpsConfigurationForEachSVResultPtr GetGpsConfigurationForEachSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsConfigurationForEachSVResult>(ptr);
    }

    bool GetGpsConfigurationForEachSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<int>>::is_valid(m_values["SvConfigs"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetGpsConfigurationForEachSVResult::documentation() const { return Documentation; }


    std::vector<int> GetGpsConfigurationForEachSVResult::svConfigs() const
    {
      return parse_json<std::vector<int>>::parse(m_values["SvConfigs"]);
    }

    void GetGpsConfigurationForEachSVResult::setSvConfigs(const std::vector<int>& svConfigs)
    {
      m_values.AddMember("SvConfigs", parse_json<std::vector<int>>::format(svConfigs, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetGpsConfigurationForEachSVResult::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetGpsConfigurationForEachSVResult::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

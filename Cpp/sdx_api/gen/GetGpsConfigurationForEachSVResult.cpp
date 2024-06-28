
#include "GetGpsConfigurationForEachSVResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsConfigurationForEachSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsConfigurationForEachSVResult::CmdName = "GetGpsConfigurationForEachSVResult";
    const char* const GetGpsConfigurationForEachSVResult::Documentation = "Result of GetGpsConfigurationForEachSV.\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvConfigs   array int       SV Config of all satellite\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetGpsConfigurationForEachSVResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetGpsConfigurationForEachSVResult);


    GetGpsConfigurationForEachSVResult::GetGpsConfigurationForEachSVResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetGpsConfigurationForEachSVResult::GetGpsConfigurationForEachSVResult(const std::vector<int>& svConfigs, const std::optional<std::string>& dataSetName)
      : CommandResult(CmdName, TargetId)
    {

      setSvConfigs(svConfigs);
      setDataSetName(dataSetName);
    }

    GetGpsConfigurationForEachSVResult::GetGpsConfigurationForEachSVResult(CommandBasePtr relatedCommand, const std::vector<int>& svConfigs, const std::optional<std::string>& dataSetName)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setSvConfigs(svConfigs);
      setDataSetName(dataSetName);
    }


    GetGpsConfigurationForEachSVResultPtr GetGpsConfigurationForEachSVResult::create(const std::vector<int>& svConfigs, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetGpsConfigurationForEachSVResult>(svConfigs, dataSetName);
    }

    GetGpsConfigurationForEachSVResultPtr GetGpsConfigurationForEachSVResult::create(CommandBasePtr relatedCommand, const std::vector<int>& svConfigs, const std::optional<std::string>& dataSetName)
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
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetGpsConfigurationForEachSVResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetGpsConfigurationForEachSVResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvConfigs", "DataSetName"}; 
      return names; 
    }


    std::vector<int> GetGpsConfigurationForEachSVResult::svConfigs() const
    {
      return parse_json<std::vector<int>>::parse(m_values["SvConfigs"]);
    }

    void GetGpsConfigurationForEachSVResult::setSvConfigs(const std::vector<int>& svConfigs)
    {
      m_values.AddMember("SvConfigs", parse_json<std::vector<int>>::format(svConfigs, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> GetGpsConfigurationForEachSVResult::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetGpsConfigurationForEachSVResult::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

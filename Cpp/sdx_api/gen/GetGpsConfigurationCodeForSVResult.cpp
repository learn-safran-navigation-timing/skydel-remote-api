
#include "GetGpsConfigurationCodeForSVResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsConfigurationCodeForSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsConfigurationCodeForSVResult::CmdName = "GetGpsConfigurationCodeForSVResult";
    const char* const GetGpsConfigurationCodeForSVResult::Documentation = "Result of GetGpsConfigurationCodeForSV.\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite SV ID 1..32\n"
      "SvConfig    int             SV Config 0..4\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetGpsConfigurationCodeForSVResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetGpsConfigurationCodeForSVResult);


    GetGpsConfigurationCodeForSVResult::GetGpsConfigurationCodeForSVResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetGpsConfigurationCodeForSVResult::GetGpsConfigurationCodeForSVResult(int svId, int svConfig, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName, TargetId)
    {

      setSvId(svId);
      setSvConfig(svConfig);
      setDataSetName(dataSetName);
    }

    GetGpsConfigurationCodeForSVResult::GetGpsConfigurationCodeForSVResult(CommandBasePtr relatedCommand, int svId, int svConfig, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setSvId(svId);
      setSvConfig(svConfig);
      setDataSetName(dataSetName);
    }


    GetGpsConfigurationCodeForSVResultPtr GetGpsConfigurationCodeForSVResult::create(int svId, int svConfig, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetGpsConfigurationCodeForSVResult>(svId, svConfig, dataSetName);
    }

    GetGpsConfigurationCodeForSVResultPtr GetGpsConfigurationCodeForSVResult::create(CommandBasePtr relatedCommand, int svId, int svConfig, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetGpsConfigurationCodeForSVResult>(relatedCommand, svId, svConfig, dataSetName);
    }

    GetGpsConfigurationCodeForSVResultPtr GetGpsConfigurationCodeForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsConfigurationCodeForSVResult>(ptr);
    }

    bool GetGpsConfigurationCodeForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<int>::is_valid(m_values["SvConfig"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetGpsConfigurationCodeForSVResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetGpsConfigurationCodeForSVResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "SvConfig", "DataSetName"}; 
      return names; 
    }


    int GetGpsConfigurationCodeForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetGpsConfigurationCodeForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetGpsConfigurationCodeForSVResult::svConfig() const
    {
      return parse_json<int>::parse(m_values["SvConfig"]);
    }

    void GetGpsConfigurationCodeForSVResult::setSvConfig(int svConfig)
    {
      m_values.AddMember("SvConfig", parse_json<int>::format(svConfig, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetGpsConfigurationCodeForSVResult::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetGpsConfigurationCodeForSVResult::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

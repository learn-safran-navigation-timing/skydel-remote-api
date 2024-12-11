
#include "GetPulsarX5AccuracyIntegrityForSVResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetPulsarX5AccuracyIntegrityForSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetPulsarX5AccuracyIntegrityForSVResult::CmdName = "GetPulsarX5AccuracyIntegrityForSVResult";
    const char* const GetPulsarX5AccuracyIntegrityForSVResult::Documentation = "Result of GetPulsarX5AccuracyIntegrityForSV.\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- ---------------------------------------------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite SV ID 1..258, or use 0 to apply new value to all satellites.\n"
      "Health      bool            X5 accuracy integrity, false = User Range Error exceeds alarm threshold, true = User Range Error does not exceed alarm threshold.\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetPulsarX5AccuracyIntegrityForSVResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetPulsarX5AccuracyIntegrityForSVResult);


    GetPulsarX5AccuracyIntegrityForSVResult::GetPulsarX5AccuracyIntegrityForSVResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetPulsarX5AccuracyIntegrityForSVResult::GetPulsarX5AccuracyIntegrityForSVResult(int svId, bool health, const std::optional<std::string>& dataSetName)
      : CommandResult(CmdName, TargetId)
    {

      setSvId(svId);
      setHealth(health);
      setDataSetName(dataSetName);
    }

    GetPulsarX5AccuracyIntegrityForSVResult::GetPulsarX5AccuracyIntegrityForSVResult(CommandBasePtr relatedCommand, int svId, bool health, const std::optional<std::string>& dataSetName)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setSvId(svId);
      setHealth(health);
      setDataSetName(dataSetName);
    }


    GetPulsarX5AccuracyIntegrityForSVResultPtr GetPulsarX5AccuracyIntegrityForSVResult::create(int svId, bool health, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetPulsarX5AccuracyIntegrityForSVResult>(svId, health, dataSetName);
    }

    GetPulsarX5AccuracyIntegrityForSVResultPtr GetPulsarX5AccuracyIntegrityForSVResult::create(CommandBasePtr relatedCommand, int svId, bool health, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetPulsarX5AccuracyIntegrityForSVResult>(relatedCommand, svId, health, dataSetName);
    }

    GetPulsarX5AccuracyIntegrityForSVResultPtr GetPulsarX5AccuracyIntegrityForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetPulsarX5AccuracyIntegrityForSVResult>(ptr);
    }

    bool GetPulsarX5AccuracyIntegrityForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Health"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetPulsarX5AccuracyIntegrityForSVResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetPulsarX5AccuracyIntegrityForSVResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "Health", "DataSetName"}; 
      return names; 
    }


    int GetPulsarX5AccuracyIntegrityForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetPulsarX5AccuracyIntegrityForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetPulsarX5AccuracyIntegrityForSVResult::health() const
    {
      return parse_json<bool>::parse(m_values["Health"]);
    }

    void GetPulsarX5AccuracyIntegrityForSVResult::setHealth(bool health)
    {
      m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> GetPulsarX5AccuracyIntegrityForSVResult::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetPulsarX5AccuracyIntegrityForSVResult::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}


#include "GetPulsarX1AccuracyIntegrityForSVResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetPulsarX1AccuracyIntegrityForSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetPulsarX1AccuracyIntegrityForSVResult::CmdName = "GetPulsarX1AccuracyIntegrityForSVResult";
    const char* const GetPulsarX1AccuracyIntegrityForSVResult::Documentation = "Result of GetPulsarX1AccuracyIntegrityForSV.\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- ---------------------------------------------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite SV ID 1..258, or use 0 to apply new value to all satellites.\n"
      "Health      bool            X1 accuracy integrity, false = User Range Error exceeds alarm threshold, true = User Range Error does not exceed alarm threshold.\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetPulsarX1AccuracyIntegrityForSVResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetPulsarX1AccuracyIntegrityForSVResult);


    GetPulsarX1AccuracyIntegrityForSVResult::GetPulsarX1AccuracyIntegrityForSVResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetPulsarX1AccuracyIntegrityForSVResult::GetPulsarX1AccuracyIntegrityForSVResult(int svId, bool health, const std::optional<std::string>& dataSetName)
      : CommandResult(CmdName, TargetId)
    {

      setSvId(svId);
      setHealth(health);
      setDataSetName(dataSetName);
    }

    GetPulsarX1AccuracyIntegrityForSVResult::GetPulsarX1AccuracyIntegrityForSVResult(CommandBasePtr relatedCommand, int svId, bool health, const std::optional<std::string>& dataSetName)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setSvId(svId);
      setHealth(health);
      setDataSetName(dataSetName);
    }


    GetPulsarX1AccuracyIntegrityForSVResultPtr GetPulsarX1AccuracyIntegrityForSVResult::create(int svId, bool health, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetPulsarX1AccuracyIntegrityForSVResult>(svId, health, dataSetName);
    }

    GetPulsarX1AccuracyIntegrityForSVResultPtr GetPulsarX1AccuracyIntegrityForSVResult::create(CommandBasePtr relatedCommand, int svId, bool health, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetPulsarX1AccuracyIntegrityForSVResult>(relatedCommand, svId, health, dataSetName);
    }

    GetPulsarX1AccuracyIntegrityForSVResultPtr GetPulsarX1AccuracyIntegrityForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetPulsarX1AccuracyIntegrityForSVResult>(ptr);
    }

    bool GetPulsarX1AccuracyIntegrityForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Health"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetPulsarX1AccuracyIntegrityForSVResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetPulsarX1AccuracyIntegrityForSVResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "Health", "DataSetName"}; 
      return names; 
    }


    int GetPulsarX1AccuracyIntegrityForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetPulsarX1AccuracyIntegrityForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetPulsarX1AccuracyIntegrityForSVResult::health() const
    {
      return parse_json<bool>::parse(m_values["Health"]);
    }

    void GetPulsarX1AccuracyIntegrityForSVResult::setHealth(bool health)
    {
      m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> GetPulsarX1AccuracyIntegrityForSVResult::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetPulsarX1AccuracyIntegrityForSVResult::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

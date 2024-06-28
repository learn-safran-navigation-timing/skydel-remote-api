
#include "GetBeiDouCNavHealthInfoForSVResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetBeiDouCNavHealthInfoForSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetBeiDouCNavHealthInfoForSVResult::CmdName = "GetBeiDouCNavHealthInfoForSVResult";
    const char* const GetBeiDouCNavHealthInfoForSVResult::Documentation = "Result of GetBeiDouCNavHealthInfoForSV.\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite SV ID 1..35, or use 0 to apply new value to all satellites.\n"
      "Health      int             Health Info, 8-bit integer : 0, 32, 64, 96, 128 or 255\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetBeiDouCNavHealthInfoForSVResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetBeiDouCNavHealthInfoForSVResult);


    GetBeiDouCNavHealthInfoForSVResult::GetBeiDouCNavHealthInfoForSVResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetBeiDouCNavHealthInfoForSVResult::GetBeiDouCNavHealthInfoForSVResult(int svId, int health, const std::optional<std::string>& dataSetName)
      : CommandResult(CmdName, TargetId)
    {

      setSvId(svId);
      setHealth(health);
      setDataSetName(dataSetName);
    }

    GetBeiDouCNavHealthInfoForSVResult::GetBeiDouCNavHealthInfoForSVResult(CommandBasePtr relatedCommand, int svId, int health, const std::optional<std::string>& dataSetName)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setSvId(svId);
      setHealth(health);
      setDataSetName(dataSetName);
    }


    GetBeiDouCNavHealthInfoForSVResultPtr GetBeiDouCNavHealthInfoForSVResult::create(int svId, int health, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetBeiDouCNavHealthInfoForSVResult>(svId, health, dataSetName);
    }

    GetBeiDouCNavHealthInfoForSVResultPtr GetBeiDouCNavHealthInfoForSVResult::create(CommandBasePtr relatedCommand, int svId, int health, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetBeiDouCNavHealthInfoForSVResult>(relatedCommand, svId, health, dataSetName);
    }

    GetBeiDouCNavHealthInfoForSVResultPtr GetBeiDouCNavHealthInfoForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetBeiDouCNavHealthInfoForSVResult>(ptr);
    }

    bool GetBeiDouCNavHealthInfoForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<int>::is_valid(m_values["Health"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetBeiDouCNavHealthInfoForSVResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetBeiDouCNavHealthInfoForSVResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "Health", "DataSetName"}; 
      return names; 
    }


    int GetBeiDouCNavHealthInfoForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetBeiDouCNavHealthInfoForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetBeiDouCNavHealthInfoForSVResult::health() const
    {
      return parse_json<int>::parse(m_values["Health"]);
    }

    void GetBeiDouCNavHealthInfoForSVResult::setHealth(int health)
    {
      m_values.AddMember("Health", parse_json<int>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> GetBeiDouCNavHealthInfoForSVResult::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetBeiDouCNavHealthInfoForSVResult::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

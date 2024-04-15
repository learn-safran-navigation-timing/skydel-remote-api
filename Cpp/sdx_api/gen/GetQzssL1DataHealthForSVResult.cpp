
#include "GetQzssL1DataHealthForSVResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetQzssL1DataHealthForSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetQzssL1DataHealthForSVResult::CmdName = "GetQzssL1DataHealthForSVResult";
    const char* const GetQzssL1DataHealthForSVResult::Documentation = "Result of GetQzssL1DataHealthForSV.\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite SV ID 1..10, or use 0 to apply new value to all satellites.\n"
      "Health      int             Data health 0..7\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetQzssL1DataHealthForSVResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetQzssL1DataHealthForSVResult);


    GetQzssL1DataHealthForSVResult::GetQzssL1DataHealthForSVResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetQzssL1DataHealthForSVResult::GetQzssL1DataHealthForSVResult(int svId, int health, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName, TargetId)
    {

      setSvId(svId);
      setHealth(health);
      setDataSetName(dataSetName);
    }

    GetQzssL1DataHealthForSVResult::GetQzssL1DataHealthForSVResult(CommandBasePtr relatedCommand, int svId, int health, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setSvId(svId);
      setHealth(health);
      setDataSetName(dataSetName);
    }


    GetQzssL1DataHealthForSVResultPtr GetQzssL1DataHealthForSVResult::create(int svId, int health, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetQzssL1DataHealthForSVResult>(svId, health, dataSetName);
    }

    GetQzssL1DataHealthForSVResultPtr GetQzssL1DataHealthForSVResult::create(CommandBasePtr relatedCommand, int svId, int health, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetQzssL1DataHealthForSVResult>(relatedCommand, svId, health, dataSetName);
    }

    GetQzssL1DataHealthForSVResultPtr GetQzssL1DataHealthForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetQzssL1DataHealthForSVResult>(ptr);
    }

    bool GetQzssL1DataHealthForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<int>::is_valid(m_values["Health"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetQzssL1DataHealthForSVResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetQzssL1DataHealthForSVResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "Health", "DataSetName"}; 
      return names; 
    }


    int GetQzssL1DataHealthForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetQzssL1DataHealthForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetQzssL1DataHealthForSVResult::health() const
    {
      return parse_json<int>::parse(m_values["Health"]);
    }

    void GetQzssL1DataHealthForSVResult::setHealth(int health)
    {
      m_values.AddMember("Health", parse_json<int>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetQzssL1DataHealthForSVResult::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetQzssL1DataHealthForSVResult::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

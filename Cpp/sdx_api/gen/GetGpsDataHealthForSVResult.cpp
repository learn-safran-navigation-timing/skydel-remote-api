
#include "GetGpsDataHealthForSVResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsDataHealthForSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsDataHealthForSVResult::CmdName = "GetGpsDataHealthForSVResult";
    const char* const GetGpsDataHealthForSVResult::Documentation = "Result of GetGpsDataHealthForSV.\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite's SV ID 1..32\n"
      "Health      int             Data health 0..7\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetGpsDataHealthForSVResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetGpsDataHealthForSVResult);


    GetGpsDataHealthForSVResult::GetGpsDataHealthForSVResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetGpsDataHealthForSVResult::GetGpsDataHealthForSVResult(int svId, int health, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName, TargetId)
    {

      setSvId(svId);
      setHealth(health);
      setDataSetName(dataSetName);
    }

    GetGpsDataHealthForSVResult::GetGpsDataHealthForSVResult(CommandBasePtr relatedCommand, int svId, int health, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setSvId(svId);
      setHealth(health);
      setDataSetName(dataSetName);
    }


    GetGpsDataHealthForSVResultPtr GetGpsDataHealthForSVResult::create(int svId, int health, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetGpsDataHealthForSVResult>(svId, health, dataSetName);
    }

    GetGpsDataHealthForSVResultPtr GetGpsDataHealthForSVResult::create(CommandBasePtr relatedCommand, int svId, int health, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetGpsDataHealthForSVResult>(relatedCommand, svId, health, dataSetName);
    }

    GetGpsDataHealthForSVResultPtr GetGpsDataHealthForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsDataHealthForSVResult>(ptr);
    }

    bool GetGpsDataHealthForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<int>::is_valid(m_values["Health"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetGpsDataHealthForSVResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetGpsDataHealthForSVResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "Health", "DataSetName"}; 
      return names; 
    }


    int GetGpsDataHealthForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetGpsDataHealthForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetGpsDataHealthForSVResult::health() const
    {
      return parse_json<int>::parse(m_values["Health"]);
    }

    void GetGpsDataHealthForSVResult::setHealth(int health)
    {
      m_values.AddMember("Health", parse_json<int>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetGpsDataHealthForSVResult::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetGpsDataHealthForSVResult::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

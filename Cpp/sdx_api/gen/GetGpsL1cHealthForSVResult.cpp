
#include "GetGpsL1cHealthForSVResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsL1cHealthForSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsL1cHealthForSVResult::CmdName = "GetGpsL1cHealthForSVResult";
    const char* const GetGpsL1cHealthForSVResult::Documentation = "Result of GetGpsL1cHealthForSV.\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite's SV ID 1..32, or use 0 to apply new value to all satellites.\n"
      "Health      bool            L1C health, false = signal OK, true = signal bad or unavailable\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetGpsL1cHealthForSVResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetGpsL1cHealthForSVResult);


    GetGpsL1cHealthForSVResult::GetGpsL1cHealthForSVResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetGpsL1cHealthForSVResult::GetGpsL1cHealthForSVResult(int svId, bool health, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName, TargetId)
    {

      setSvId(svId);
      setHealth(health);
      setDataSetName(dataSetName);
    }

    GetGpsL1cHealthForSVResult::GetGpsL1cHealthForSVResult(CommandBasePtr relatedCommand, int svId, bool health, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setSvId(svId);
      setHealth(health);
      setDataSetName(dataSetName);
    }


    GetGpsL1cHealthForSVResultPtr GetGpsL1cHealthForSVResult::create(int svId, bool health, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetGpsL1cHealthForSVResult>(svId, health, dataSetName);
    }

    GetGpsL1cHealthForSVResultPtr GetGpsL1cHealthForSVResult::create(CommandBasePtr relatedCommand, int svId, bool health, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetGpsL1cHealthForSVResult>(relatedCommand, svId, health, dataSetName);
    }

    GetGpsL1cHealthForSVResultPtr GetGpsL1cHealthForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsL1cHealthForSVResult>(ptr);
    }

    bool GetGpsL1cHealthForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Health"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetGpsL1cHealthForSVResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetGpsL1cHealthForSVResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "Health", "DataSetName"}; 
      return names; 
    }


    int GetGpsL1cHealthForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetGpsL1cHealthForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetGpsL1cHealthForSVResult::health() const
    {
      return parse_json<bool>::parse(m_values["Health"]);
    }

    void GetGpsL1cHealthForSVResult::setHealth(bool health)
    {
      m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetGpsL1cHealthForSVResult::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetGpsL1cHealthForSVResult::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

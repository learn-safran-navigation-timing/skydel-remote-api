
#include "GetQzssL1cHealthForSVResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetQzssL1cHealthForSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetQzssL1cHealthForSVResult::CmdName = "GetQzssL1cHealthForSVResult";
    const char* const GetQzssL1cHealthForSVResult::Documentation = "Result of GetQzssL1cHealthForSV.\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite SV ID 1..10, or use 0 to apply new value to all satellites.\n"
      "Health      bool            L1C health, false = signal OK, true = signal bad\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetQzssL1cHealthForSVResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetQzssL1cHealthForSVResult);


    GetQzssL1cHealthForSVResult::GetQzssL1cHealthForSVResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetQzssL1cHealthForSVResult::GetQzssL1cHealthForSVResult(int svId, bool health, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName, TargetId)
    {

      setSvId(svId);
      setHealth(health);
      setDataSetName(dataSetName);
    }

    GetQzssL1cHealthForSVResult::GetQzssL1cHealthForSVResult(CommandBasePtr relatedCommand, int svId, bool health, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setSvId(svId);
      setHealth(health);
      setDataSetName(dataSetName);
    }


    GetQzssL1cHealthForSVResultPtr GetQzssL1cHealthForSVResult::create(int svId, bool health, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetQzssL1cHealthForSVResult>(svId, health, dataSetName);
    }

    GetQzssL1cHealthForSVResultPtr GetQzssL1cHealthForSVResult::create(CommandBasePtr relatedCommand, int svId, bool health, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetQzssL1cHealthForSVResult>(relatedCommand, svId, health, dataSetName);
    }

    GetQzssL1cHealthForSVResultPtr GetQzssL1cHealthForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetQzssL1cHealthForSVResult>(ptr);
    }

    bool GetQzssL1cHealthForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Health"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetQzssL1cHealthForSVResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetQzssL1cHealthForSVResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "Health", "DataSetName"}; 
      return names; 
    }


    int GetQzssL1cHealthForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetQzssL1cHealthForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetQzssL1cHealthForSVResult::health() const
    {
      return parse_json<bool>::parse(m_values["Health"]);
    }

    void GetQzssL1cHealthForSVResult::setHealth(bool health)
    {
      m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetQzssL1cHealthForSVResult::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetQzssL1cHealthForSVResult::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

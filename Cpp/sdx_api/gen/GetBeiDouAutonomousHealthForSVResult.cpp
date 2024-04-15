
#include "GetBeiDouAutonomousHealthForSVResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetBeiDouAutonomousHealthForSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetBeiDouAutonomousHealthForSVResult::CmdName = "GetBeiDouAutonomousHealthForSVResult";
    const char* const GetBeiDouAutonomousHealthForSVResult::Documentation = "Result of GetBeiDouAutonomousHealthForSV.\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite SV ID 1..35, or use 0 to apply new value to all satellites.\n"
      "Health      bool            Status, false = Good, true = Not Good\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetBeiDouAutonomousHealthForSVResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetBeiDouAutonomousHealthForSVResult);


    GetBeiDouAutonomousHealthForSVResult::GetBeiDouAutonomousHealthForSVResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetBeiDouAutonomousHealthForSVResult::GetBeiDouAutonomousHealthForSVResult(int svId, bool health, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName, TargetId)
    {

      setSvId(svId);
      setHealth(health);
      setDataSetName(dataSetName);
    }

    GetBeiDouAutonomousHealthForSVResult::GetBeiDouAutonomousHealthForSVResult(CommandBasePtr relatedCommand, int svId, bool health, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setSvId(svId);
      setHealth(health);
      setDataSetName(dataSetName);
    }


    GetBeiDouAutonomousHealthForSVResultPtr GetBeiDouAutonomousHealthForSVResult::create(int svId, bool health, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetBeiDouAutonomousHealthForSVResult>(svId, health, dataSetName);
    }

    GetBeiDouAutonomousHealthForSVResultPtr GetBeiDouAutonomousHealthForSVResult::create(CommandBasePtr relatedCommand, int svId, bool health, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetBeiDouAutonomousHealthForSVResult>(relatedCommand, svId, health, dataSetName);
    }

    GetBeiDouAutonomousHealthForSVResultPtr GetBeiDouAutonomousHealthForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetBeiDouAutonomousHealthForSVResult>(ptr);
    }

    bool GetBeiDouAutonomousHealthForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Health"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetBeiDouAutonomousHealthForSVResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetBeiDouAutonomousHealthForSVResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "Health", "DataSetName"}; 
      return names; 
    }


    int GetBeiDouAutonomousHealthForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetBeiDouAutonomousHealthForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetBeiDouAutonomousHealthForSVResult::health() const
    {
      return parse_json<bool>::parse(m_values["Health"]);
    }

    void GetBeiDouAutonomousHealthForSVResult::setHealth(bool health)
    {
      m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetBeiDouAutonomousHealthForSVResult::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetBeiDouAutonomousHealthForSVResult::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

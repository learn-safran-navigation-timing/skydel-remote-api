
#include "GetGpsSignalHealthForSVResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsSignalHealthForSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsSignalHealthForSVResult::CmdName = "GetGpsSignalHealthForSVResult";
    const char* const GetGpsSignalHealthForSVResult::Documentation = "Result of GetGpsSignalHealthForSV.\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite's SV ID 1..32\n"
      "Health      int             Signal health 0..31\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetGpsSignalHealthForSVResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetGpsSignalHealthForSVResult);


    GetGpsSignalHealthForSVResult::GetGpsSignalHealthForSVResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetGpsSignalHealthForSVResult::GetGpsSignalHealthForSVResult(int svId, int health, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName, TargetId)
    {

      setSvId(svId);
      setHealth(health);
      setDataSetName(dataSetName);
    }

    GetGpsSignalHealthForSVResult::GetGpsSignalHealthForSVResult(CommandBasePtr relatedCommand, int svId, int health, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setSvId(svId);
      setHealth(health);
      setDataSetName(dataSetName);
    }


    GetGpsSignalHealthForSVResultPtr GetGpsSignalHealthForSVResult::create(int svId, int health, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetGpsSignalHealthForSVResult>(svId, health, dataSetName);
    }

    GetGpsSignalHealthForSVResultPtr GetGpsSignalHealthForSVResult::create(CommandBasePtr relatedCommand, int svId, int health, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetGpsSignalHealthForSVResult>(relatedCommand, svId, health, dataSetName);
    }

    GetGpsSignalHealthForSVResultPtr GetGpsSignalHealthForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsSignalHealthForSVResult>(ptr);
    }

    bool GetGpsSignalHealthForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<int>::is_valid(m_values["Health"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetGpsSignalHealthForSVResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetGpsSignalHealthForSVResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "Health", "DataSetName"}; 
      return names; 
    }


    int GetGpsSignalHealthForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetGpsSignalHealthForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetGpsSignalHealthForSVResult::health() const
    {
      return parse_json<int>::parse(m_values["Health"]);
    }

    void GetGpsSignalHealthForSVResult::setHealth(int health)
    {
      m_values.AddMember("Health", parse_json<int>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetGpsSignalHealthForSVResult::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetGpsSignalHealthForSVResult::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

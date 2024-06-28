
#include "GetNavICSHealthForSVResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetNavICSHealthForSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetNavICSHealthForSVResult::CmdName = "GetNavICSHealthForSVResult";
    const char* const GetNavICSHealthForSVResult::Documentation = "Result of GetNavICSHealthForSV.\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite SV ID 1..14, or use 0 to apply new value to all satellites.\n"
      "Health      bool            S health, false = signal OK, true = signal bad\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetNavICSHealthForSVResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetNavICSHealthForSVResult);


    GetNavICSHealthForSVResult::GetNavICSHealthForSVResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetNavICSHealthForSVResult::GetNavICSHealthForSVResult(int svId, bool health, const std::optional<std::string>& dataSetName)
      : CommandResult(CmdName, TargetId)
    {

      setSvId(svId);
      setHealth(health);
      setDataSetName(dataSetName);
    }

    GetNavICSHealthForSVResult::GetNavICSHealthForSVResult(CommandBasePtr relatedCommand, int svId, bool health, const std::optional<std::string>& dataSetName)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setSvId(svId);
      setHealth(health);
      setDataSetName(dataSetName);
    }


    GetNavICSHealthForSVResultPtr GetNavICSHealthForSVResult::create(int svId, bool health, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetNavICSHealthForSVResult>(svId, health, dataSetName);
    }

    GetNavICSHealthForSVResultPtr GetNavICSHealthForSVResult::create(CommandBasePtr relatedCommand, int svId, bool health, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetNavICSHealthForSVResult>(relatedCommand, svId, health, dataSetName);
    }

    GetNavICSHealthForSVResultPtr GetNavICSHealthForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetNavICSHealthForSVResult>(ptr);
    }

    bool GetNavICSHealthForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Health"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetNavICSHealthForSVResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetNavICSHealthForSVResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "Health", "DataSetName"}; 
      return names; 
    }


    int GetNavICSHealthForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetNavICSHealthForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetNavICSHealthForSVResult::health() const
    {
      return parse_json<bool>::parse(m_values["Health"]);
    }

    void GetNavICSHealthForSVResult::setHealth(bool health)
    {
      m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> GetNavICSHealthForSVResult::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetNavICSHealthForSVResult::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

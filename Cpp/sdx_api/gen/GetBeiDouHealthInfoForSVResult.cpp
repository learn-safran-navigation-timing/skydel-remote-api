
#include "GetBeiDouHealthInfoForSVResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetBeiDouHealthInfoForSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetBeiDouHealthInfoForSVResult::CmdName = "GetBeiDouHealthInfoForSVResult";
    const char* const GetBeiDouHealthInfoForSVResult::Documentation = "Result of GetBeiDouHealthInfoForSV.\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite SV ID 1..35, or use 0 to apply new value to all satellites.\n"
      "Health      int             Health Info, 9-bit integer : 0, 2, 64, 66, 128, 130, 192, 194, 256 or 511\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetBeiDouHealthInfoForSVResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetBeiDouHealthInfoForSVResult);


    GetBeiDouHealthInfoForSVResult::GetBeiDouHealthInfoForSVResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetBeiDouHealthInfoForSVResult::GetBeiDouHealthInfoForSVResult(int svId, int health, const std::optional<std::string>& dataSetName)
      : CommandResult(CmdName, TargetId)
    {

      setSvId(svId);
      setHealth(health);
      setDataSetName(dataSetName);
    }

    GetBeiDouHealthInfoForSVResult::GetBeiDouHealthInfoForSVResult(CommandBasePtr relatedCommand, int svId, int health, const std::optional<std::string>& dataSetName)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setSvId(svId);
      setHealth(health);
      setDataSetName(dataSetName);
    }


    GetBeiDouHealthInfoForSVResultPtr GetBeiDouHealthInfoForSVResult::create(int svId, int health, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetBeiDouHealthInfoForSVResult>(svId, health, dataSetName);
    }

    GetBeiDouHealthInfoForSVResultPtr GetBeiDouHealthInfoForSVResult::create(CommandBasePtr relatedCommand, int svId, int health, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetBeiDouHealthInfoForSVResult>(relatedCommand, svId, health, dataSetName);
    }

    GetBeiDouHealthInfoForSVResultPtr GetBeiDouHealthInfoForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetBeiDouHealthInfoForSVResult>(ptr);
    }

    bool GetBeiDouHealthInfoForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<int>::is_valid(m_values["Health"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetBeiDouHealthInfoForSVResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetBeiDouHealthInfoForSVResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "Health", "DataSetName"}; 
      return names; 
    }


    int GetBeiDouHealthInfoForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetBeiDouHealthInfoForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetBeiDouHealthInfoForSVResult::health() const
    {
      return parse_json<int>::parse(m_values["Health"]);
    }

    void GetBeiDouHealthInfoForSVResult::setHealth(int health)
    {
      m_values.AddMember("Health", parse_json<int>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> GetBeiDouHealthInfoForSVResult::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetBeiDouHealthInfoForSVResult::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

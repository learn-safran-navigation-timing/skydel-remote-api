
#include "GetGpsAntiSpoofingFlagForSVResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsAntiSpoofingFlagForSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsAntiSpoofingFlagForSVResult::CmdName = "GetGpsAntiSpoofingFlagForSVResult";
    const char* const GetGpsAntiSpoofingFlagForSVResult::Documentation = "Result of GetGpsAntiSpoofingFlagForSV.\n"
      "\n"
      "Name         Type            Description\n"
      "------------ --------------- -------------------------------------------------------------------------------------------\n"
      "SvId         int             Satellite's SV ID 1..32, or use 0 to apply new value to all satellites.\n"
      "AntiSpoofing GpsASFlag       GPS Anti-Spoofing Flag.\n"
      "DataSetName  optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetGpsAntiSpoofingFlagForSVResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetGpsAntiSpoofingFlagForSVResult);


    GetGpsAntiSpoofingFlagForSVResult::GetGpsAntiSpoofingFlagForSVResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetGpsAntiSpoofingFlagForSVResult::GetGpsAntiSpoofingFlagForSVResult(int svId, const Sdx::GpsASFlag& antiSpoofing, const std::optional<std::string>& dataSetName)
      : CommandResult(CmdName, TargetId)
    {

      setSvId(svId);
      setAntiSpoofing(antiSpoofing);
      setDataSetName(dataSetName);
    }

    GetGpsAntiSpoofingFlagForSVResult::GetGpsAntiSpoofingFlagForSVResult(CommandBasePtr relatedCommand, int svId, const Sdx::GpsASFlag& antiSpoofing, const std::optional<std::string>& dataSetName)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setSvId(svId);
      setAntiSpoofing(antiSpoofing);
      setDataSetName(dataSetName);
    }


    GetGpsAntiSpoofingFlagForSVResultPtr GetGpsAntiSpoofingFlagForSVResult::create(int svId, const Sdx::GpsASFlag& antiSpoofing, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetGpsAntiSpoofingFlagForSVResult>(svId, antiSpoofing, dataSetName);
    }

    GetGpsAntiSpoofingFlagForSVResultPtr GetGpsAntiSpoofingFlagForSVResult::create(CommandBasePtr relatedCommand, int svId, const Sdx::GpsASFlag& antiSpoofing, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetGpsAntiSpoofingFlagForSVResult>(relatedCommand, svId, antiSpoofing, dataSetName);
    }

    GetGpsAntiSpoofingFlagForSVResultPtr GetGpsAntiSpoofingFlagForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsAntiSpoofingFlagForSVResult>(ptr);
    }

    bool GetGpsAntiSpoofingFlagForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<Sdx::GpsASFlag>::is_valid(m_values["AntiSpoofing"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetGpsAntiSpoofingFlagForSVResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetGpsAntiSpoofingFlagForSVResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "AntiSpoofing", "DataSetName"}; 
      return names; 
    }


    int GetGpsAntiSpoofingFlagForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetGpsAntiSpoofingFlagForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::GpsASFlag GetGpsAntiSpoofingFlagForSVResult::antiSpoofing() const
    {
      return parse_json<Sdx::GpsASFlag>::parse(m_values["AntiSpoofing"]);
    }

    void GetGpsAntiSpoofingFlagForSVResult::setAntiSpoofing(const Sdx::GpsASFlag& antiSpoofing)
    {
      m_values.AddMember("AntiSpoofing", parse_json<Sdx::GpsASFlag>::format(antiSpoofing, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> GetGpsAntiSpoofingFlagForSVResult::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetGpsAntiSpoofingFlagForSVResult::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}


#include "gen/GetGpsAntiSpoofingFlagForSVResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsAntiSpoofingFlagForSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsAntiSpoofingFlagForSVResult::CmdName = "GetGpsAntiSpoofingFlagForSVResult";
    const char* const GetGpsAntiSpoofingFlagForSVResult::Documentation = "Result of GetGpsAntiSpoofingFlagForSV.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetGpsAntiSpoofingFlagForSVResult);


    GetGpsAntiSpoofingFlagForSVResult::GetGpsAntiSpoofingFlagForSVResult()
      : CommandResult(CmdName)
    {}

    GetGpsAntiSpoofingFlagForSVResult::GetGpsAntiSpoofingFlagForSVResult(int svId, const Sdx::GpsASFlag& antiSpoofing, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName)
    {

      setSvId(svId);
      setAntiSpoofing(antiSpoofing);
      setDataSetName(dataSetName);
    }

    GetGpsAntiSpoofingFlagForSVResult::GetGpsAntiSpoofingFlagForSVResult(CommandBasePtr relatedCommand, int svId, const Sdx::GpsASFlag& antiSpoofing, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName, relatedCommand)
    {

      setSvId(svId);
      setAntiSpoofing(antiSpoofing);
      setDataSetName(dataSetName);
    }


    GetGpsAntiSpoofingFlagForSVResultPtr GetGpsAntiSpoofingFlagForSVResult::create(int svId, const Sdx::GpsASFlag& antiSpoofing, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetGpsAntiSpoofingFlagForSVResult>(svId, antiSpoofing, dataSetName);
    }

    GetGpsAntiSpoofingFlagForSVResultPtr GetGpsAntiSpoofingFlagForSVResult::create(CommandBasePtr relatedCommand, int svId, const Sdx::GpsASFlag& antiSpoofing, const Sdx::optional<std::string>& dataSetName)
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
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetGpsAntiSpoofingFlagForSVResult::documentation() const { return Documentation; }


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



    Sdx::optional<std::string> GetGpsAntiSpoofingFlagForSVResult::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetGpsAntiSpoofingFlagForSVResult::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}


#include "gen/SetGpsAntiSpoofingFlagForSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGpsAntiSpoofingFlagForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGpsAntiSpoofingFlagForSV::CmdName = "SetGpsAntiSpoofingFlagForSV";
    const char* const SetGpsAntiSpoofingFlagForSV::Documentation = "Set GPS Anti-Spoofing Flag";

    REGISTER_COMMAND_FACTORY(SetGpsAntiSpoofingFlagForSV);


    SetGpsAntiSpoofingFlagForSV::SetGpsAntiSpoofingFlagForSV()
      : CommandBase(CmdName)
    {}

    SetGpsAntiSpoofingFlagForSV::SetGpsAntiSpoofingFlagForSV(int svId, const Sdx::GpsASFlag& antiSpoofing, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setAntiSpoofing(antiSpoofing);
      setDataSetName(dataSetName);
    }

    SetGpsAntiSpoofingFlagForSVPtr SetGpsAntiSpoofingFlagForSV::create(int svId, const Sdx::GpsASFlag& antiSpoofing, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetGpsAntiSpoofingFlagForSV>(svId, antiSpoofing, dataSetName);
    }

    SetGpsAntiSpoofingFlagForSVPtr SetGpsAntiSpoofingFlagForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetGpsAntiSpoofingFlagForSV>(ptr);
    }

    bool SetGpsAntiSpoofingFlagForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<Sdx::GpsASFlag>::is_valid(m_values["AntiSpoofing"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetGpsAntiSpoofingFlagForSV::documentation() const { return Documentation; }


    int SetGpsAntiSpoofingFlagForSV::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetGpsAntiSpoofingFlagForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetGpsAntiSpoofingFlagForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::GpsASFlag SetGpsAntiSpoofingFlagForSV::antiSpoofing() const
    {
      return parse_json<Sdx::GpsASFlag>::parse(m_values["AntiSpoofing"]);
    }

    void SetGpsAntiSpoofingFlagForSV::setAntiSpoofing(const Sdx::GpsASFlag& antiSpoofing)
    {
      m_values.AddMember("AntiSpoofing", parse_json<Sdx::GpsASFlag>::format(antiSpoofing, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> SetGpsAntiSpoofingFlagForSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetGpsAntiSpoofingFlagForSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

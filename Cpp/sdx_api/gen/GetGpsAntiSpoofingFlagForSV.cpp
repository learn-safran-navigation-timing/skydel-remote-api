
#include "gen/GetGpsAntiSpoofingFlagForSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsAntiSpoofingFlagForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsAntiSpoofingFlagForSV::CmdName = "GetGpsAntiSpoofingFlagForSV";
    const char* const GetGpsAntiSpoofingFlagForSV::Documentation = "Get GPS Anti-Spoofing Flag";

    REGISTER_COMMAND_FACTORY(GetGpsAntiSpoofingFlagForSV);


    GetGpsAntiSpoofingFlagForSV::GetGpsAntiSpoofingFlagForSV()
      : CommandBase(CmdName)
    {}

    GetGpsAntiSpoofingFlagForSV::GetGpsAntiSpoofingFlagForSV(int svId, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setDataSetName(dataSetName);
    }

    GetGpsAntiSpoofingFlagForSVPtr GetGpsAntiSpoofingFlagForSV::create(int svId, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetGpsAntiSpoofingFlagForSV>(svId, dataSetName);
    }

    GetGpsAntiSpoofingFlagForSVPtr GetGpsAntiSpoofingFlagForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsAntiSpoofingFlagForSV>(ptr);
    }

    bool GetGpsAntiSpoofingFlagForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetGpsAntiSpoofingFlagForSV::documentation() const { return Documentation; }


    int GetGpsAntiSpoofingFlagForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetGpsAntiSpoofingFlagForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetGpsAntiSpoofingFlagForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetGpsAntiSpoofingFlagForSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetGpsAntiSpoofingFlagForSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

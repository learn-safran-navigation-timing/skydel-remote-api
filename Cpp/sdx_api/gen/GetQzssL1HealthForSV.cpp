
#include "gen/GetQzssL1HealthForSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetQzssL1HealthForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetQzssL1HealthForSV::CmdName = "GetQzssL1HealthForSV";
    const char* const GetQzssL1HealthForSV::Documentation = "Get QZSS L1 health (Health of L1C/A signal)";

    REGISTER_COMMAND_FACTORY(GetQzssL1HealthForSV);


    GetQzssL1HealthForSV::GetQzssL1HealthForSV()
      : CommandBase(CmdName)
    {}

    GetQzssL1HealthForSV::GetQzssL1HealthForSV(int svId, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setDataSetName(dataSetName);
    }

    GetQzssL1HealthForSVPtr GetQzssL1HealthForSV::create(int svId, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetQzssL1HealthForSV>(svId, dataSetName);
    }

    GetQzssL1HealthForSVPtr GetQzssL1HealthForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetQzssL1HealthForSV>(ptr);
    }

    bool GetQzssL1HealthForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetQzssL1HealthForSV::documentation() const { return Documentation; }


    int GetQzssL1HealthForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetQzssL1HealthForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetQzssL1HealthForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetQzssL1HealthForSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetQzssL1HealthForSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

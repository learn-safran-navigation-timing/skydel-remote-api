
#include "gen/GetQzssL2HealthForSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetQzssL2HealthForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetQzssL2HealthForSV::CmdName = "GetQzssL2HealthForSV";
    const char* const GetQzssL2HealthForSV::Documentation = "Get QZSS L2 health (Health of L2C signal)";

    REGISTER_COMMAND_FACTORY(GetQzssL2HealthForSV);


    GetQzssL2HealthForSV::GetQzssL2HealthForSV()
      : CommandBase(CmdName)
    {}

    GetQzssL2HealthForSV::GetQzssL2HealthForSV(int svId, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setDataSetName(dataSetName);
    }

    GetQzssL2HealthForSVPtr GetQzssL2HealthForSV::create(int svId, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetQzssL2HealthForSV>(svId, dataSetName);
    }

    GetQzssL2HealthForSVPtr GetQzssL2HealthForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetQzssL2HealthForSV>(ptr);
    }

    bool GetQzssL2HealthForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetQzssL2HealthForSV::documentation() const { return Documentation; }


    int GetQzssL2HealthForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetQzssL2HealthForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetQzssL2HealthForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetQzssL2HealthForSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetQzssL2HealthForSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

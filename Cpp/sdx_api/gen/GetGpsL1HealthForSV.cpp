
#include "gen/GetGpsL1HealthForSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsL1HealthForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsL1HealthForSV::CmdName = "GetGpsL1HealthForSV";
    const char* const GetGpsL1HealthForSV::Documentation = "Get GPS L1 health (used with CNAV and CNAV2)";

    REGISTER_COMMAND_FACTORY(GetGpsL1HealthForSV);


    GetGpsL1HealthForSV::GetGpsL1HealthForSV()
      : CommandBase(CmdName)
    {}

    GetGpsL1HealthForSV::GetGpsL1HealthForSV(int svId, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setDataSetName(dataSetName);
    }

    GetGpsL1HealthForSVPtr GetGpsL1HealthForSV::create(int svId, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetGpsL1HealthForSV>(svId, dataSetName);
    }

    GetGpsL1HealthForSVPtr GetGpsL1HealthForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsL1HealthForSV>(ptr);
    }

    bool GetGpsL1HealthForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetGpsL1HealthForSV::documentation() const { return Documentation; }


    int GetGpsL1HealthForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetGpsL1HealthForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetGpsL1HealthForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetGpsL1HealthForSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetGpsL1HealthForSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

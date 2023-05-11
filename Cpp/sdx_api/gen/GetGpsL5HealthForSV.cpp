
#include "gen/GetGpsL5HealthForSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsL5HealthForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsL5HealthForSV::CmdName = "GetGpsL5HealthForSV";
    const char* const GetGpsL5HealthForSV::Documentation = "Get GPS L5 health (used with CNAV and CNAV2)";

    REGISTER_COMMAND_FACTORY(GetGpsL5HealthForSV);


    GetGpsL5HealthForSV::GetGpsL5HealthForSV()
      : CommandBase(CmdName)
    {}

    GetGpsL5HealthForSV::GetGpsL5HealthForSV(int svId, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setDataSetName(dataSetName);
    }

    GetGpsL5HealthForSVPtr GetGpsL5HealthForSV::create(int svId, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetGpsL5HealthForSV>(svId, dataSetName);
    }

    GetGpsL5HealthForSVPtr GetGpsL5HealthForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsL5HealthForSV>(ptr);
    }

    bool GetGpsL5HealthForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetGpsL5HealthForSV::documentation() const { return Documentation; }


    int GetGpsL5HealthForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetGpsL5HealthForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetGpsL5HealthForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetGpsL5HealthForSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetGpsL5HealthForSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

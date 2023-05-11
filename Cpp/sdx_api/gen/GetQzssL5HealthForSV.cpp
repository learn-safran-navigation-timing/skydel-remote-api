
#include "gen/GetQzssL5HealthForSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetQzssL5HealthForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetQzssL5HealthForSV::CmdName = "GetQzssL5HealthForSV";
    const char* const GetQzssL5HealthForSV::Documentation = "Get QZSS L5 health (Health of L5 signal)";

    REGISTER_COMMAND_FACTORY(GetQzssL5HealthForSV);


    GetQzssL5HealthForSV::GetQzssL5HealthForSV()
      : CommandBase(CmdName)
    {}

    GetQzssL5HealthForSV::GetQzssL5HealthForSV(int svId, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setDataSetName(dataSetName);
    }

    GetQzssL5HealthForSVPtr GetQzssL5HealthForSV::create(int svId, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetQzssL5HealthForSV>(svId, dataSetName);
    }

    GetQzssL5HealthForSVPtr GetQzssL5HealthForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetQzssL5HealthForSV>(ptr);
    }

    bool GetQzssL5HealthForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetQzssL5HealthForSV::documentation() const { return Documentation; }


    int GetQzssL5HealthForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetQzssL5HealthForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetQzssL5HealthForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetQzssL5HealthForSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetQzssL5HealthForSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

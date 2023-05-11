
#include "gen/GetGpsConfigurationCodeForSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsConfigurationCodeForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsConfigurationCodeForSV::CmdName = "GetGpsConfigurationCodeForSV";
    const char* const GetGpsConfigurationCodeForSV::Documentation = "Get GPS SV configuration flag for one satellite";

    REGISTER_COMMAND_FACTORY(GetGpsConfigurationCodeForSV);


    GetGpsConfigurationCodeForSV::GetGpsConfigurationCodeForSV()
      : CommandBase(CmdName)
    {}

    GetGpsConfigurationCodeForSV::GetGpsConfigurationCodeForSV(int svId, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setDataSetName(dataSetName);
    }

    GetGpsConfigurationCodeForSVPtr GetGpsConfigurationCodeForSV::create(int svId, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetGpsConfigurationCodeForSV>(svId, dataSetName);
    }

    GetGpsConfigurationCodeForSVPtr GetGpsConfigurationCodeForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsConfigurationCodeForSV>(ptr);
    }

    bool GetGpsConfigurationCodeForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetGpsConfigurationCodeForSV::documentation() const { return Documentation; }


    int GetGpsConfigurationCodeForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetGpsConfigurationCodeForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetGpsConfigurationCodeForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetGpsConfigurationCodeForSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetGpsConfigurationCodeForSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

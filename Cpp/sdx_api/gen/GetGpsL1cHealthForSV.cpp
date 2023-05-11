
#include "gen/GetGpsL1cHealthForSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsL1cHealthForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsL1cHealthForSV::CmdName = "GetGpsL1cHealthForSV";
    const char* const GetGpsL1cHealthForSV::Documentation = "Get GPS L1C health (used in CNAV2 only)";

    REGISTER_COMMAND_FACTORY(GetGpsL1cHealthForSV);


    GetGpsL1cHealthForSV::GetGpsL1cHealthForSV()
      : CommandBase(CmdName)
    {}

    GetGpsL1cHealthForSV::GetGpsL1cHealthForSV(int svId, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setDataSetName(dataSetName);
    }

    GetGpsL1cHealthForSVPtr GetGpsL1cHealthForSV::create(int svId, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetGpsL1cHealthForSV>(svId, dataSetName);
    }

    GetGpsL1cHealthForSVPtr GetGpsL1cHealthForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsL1cHealthForSV>(ptr);
    }

    bool GetGpsL1cHealthForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetGpsL1cHealthForSV::documentation() const { return Documentation; }


    int GetGpsL1cHealthForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetGpsL1cHealthForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetGpsL1cHealthForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetGpsL1cHealthForSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetGpsL1cHealthForSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

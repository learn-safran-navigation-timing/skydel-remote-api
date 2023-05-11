
#include "gen/GetQzssL1cHealthForSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetQzssL1cHealthForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetQzssL1cHealthForSV::CmdName = "GetQzssL1cHealthForSV";
    const char* const GetQzssL1cHealthForSV::Documentation = "Get QZSS L1C health (Health of L1C signal)";

    REGISTER_COMMAND_FACTORY(GetQzssL1cHealthForSV);


    GetQzssL1cHealthForSV::GetQzssL1cHealthForSV()
      : CommandBase(CmdName)
    {}

    GetQzssL1cHealthForSV::GetQzssL1cHealthForSV(int svId, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setDataSetName(dataSetName);
    }

    GetQzssL1cHealthForSVPtr GetQzssL1cHealthForSV::create(int svId, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetQzssL1cHealthForSV>(svId, dataSetName);
    }

    GetQzssL1cHealthForSVPtr GetQzssL1cHealthForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetQzssL1cHealthForSV>(ptr);
    }

    bool GetQzssL1cHealthForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetQzssL1cHealthForSV::documentation() const { return Documentation; }


    int GetQzssL1cHealthForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetQzssL1cHealthForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetQzssL1cHealthForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetQzssL1cHealthForSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetQzssL1cHealthForSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

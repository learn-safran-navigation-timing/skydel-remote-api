
#include "gen/GetGpsDataHealthForSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsDataHealthForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsDataHealthForSV::CmdName = "GetGpsDataHealthForSV";
    const char* const GetGpsDataHealthForSV::Documentation = "Get GPS nav data health";

    REGISTER_COMMAND_FACTORY(GetGpsDataHealthForSV);


    GetGpsDataHealthForSV::GetGpsDataHealthForSV()
      : CommandBase(CmdName)
    {}

    GetGpsDataHealthForSV::GetGpsDataHealthForSV(int svId, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setDataSetName(dataSetName);
    }

    GetGpsDataHealthForSVPtr GetGpsDataHealthForSV::create(int svId, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetGpsDataHealthForSV>(svId, dataSetName);
    }

    GetGpsDataHealthForSVPtr GetGpsDataHealthForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsDataHealthForSV>(ptr);
    }

    bool GetGpsDataHealthForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetGpsDataHealthForSV::documentation() const { return Documentation; }


    int GetGpsDataHealthForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetGpsDataHealthForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetGpsDataHealthForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetGpsDataHealthForSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetGpsDataHealthForSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

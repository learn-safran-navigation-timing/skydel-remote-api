
#include "gen/GetBeiDouHealthStatusForSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetBeiDouHealthStatusForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetBeiDouHealthStatusForSV::CmdName = "GetBeiDouHealthStatusForSV";
    const char* const GetBeiDouHealthStatusForSV::Documentation = "Get BeiDou satellite health status";

    REGISTER_COMMAND_FACTORY(GetBeiDouHealthStatusForSV);


    GetBeiDouHealthStatusForSV::GetBeiDouHealthStatusForSV()
      : CommandBase(CmdName)
    {}

    GetBeiDouHealthStatusForSV::GetBeiDouHealthStatusForSV(int svId, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setDataSetName(dataSetName);
    }

    GetBeiDouHealthStatusForSVPtr GetBeiDouHealthStatusForSV::create(int svId, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetBeiDouHealthStatusForSV>(svId, dataSetName);
    }

    GetBeiDouHealthStatusForSVPtr GetBeiDouHealthStatusForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetBeiDouHealthStatusForSV>(ptr);
    }

    bool GetBeiDouHealthStatusForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetBeiDouHealthStatusForSV::documentation() const { return Documentation; }


    int GetBeiDouHealthStatusForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetBeiDouHealthStatusForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetBeiDouHealthStatusForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetBeiDouHealthStatusForSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetBeiDouHealthStatusForSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

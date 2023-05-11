
#include "gen/GetBeiDouHealthInfoForSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetBeiDouHealthInfoForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetBeiDouHealthInfoForSV::CmdName = "GetBeiDouHealthInfoForSV";
    const char* const GetBeiDouHealthInfoForSV::Documentation = "Get BeiDou satellite health info";

    REGISTER_COMMAND_FACTORY(GetBeiDouHealthInfoForSV);


    GetBeiDouHealthInfoForSV::GetBeiDouHealthInfoForSV()
      : CommandBase(CmdName)
    {}

    GetBeiDouHealthInfoForSV::GetBeiDouHealthInfoForSV(int svId, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setDataSetName(dataSetName);
    }

    GetBeiDouHealthInfoForSVPtr GetBeiDouHealthInfoForSV::create(int svId, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetBeiDouHealthInfoForSV>(svId, dataSetName);
    }

    GetBeiDouHealthInfoForSVPtr GetBeiDouHealthInfoForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetBeiDouHealthInfoForSV>(ptr);
    }

    bool GetBeiDouHealthInfoForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetBeiDouHealthInfoForSV::documentation() const { return Documentation; }


    int GetBeiDouHealthInfoForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetBeiDouHealthInfoForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetBeiDouHealthInfoForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetBeiDouHealthInfoForSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetBeiDouHealthInfoForSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

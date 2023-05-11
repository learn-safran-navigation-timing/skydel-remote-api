
#include "gen/GetBeiDouCNavHealthInfoForSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetBeiDouCNavHealthInfoForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetBeiDouCNavHealthInfoForSV::CmdName = "GetBeiDouCNavHealthInfoForSV";
    const char* const GetBeiDouCNavHealthInfoForSV::Documentation = "Get BeiDou CNav satellite health info";

    REGISTER_COMMAND_FACTORY(GetBeiDouCNavHealthInfoForSV);


    GetBeiDouCNavHealthInfoForSV::GetBeiDouCNavHealthInfoForSV()
      : CommandBase(CmdName)
    {}

    GetBeiDouCNavHealthInfoForSV::GetBeiDouCNavHealthInfoForSV(int svId, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setDataSetName(dataSetName);
    }

    GetBeiDouCNavHealthInfoForSVPtr GetBeiDouCNavHealthInfoForSV::create(int svId, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetBeiDouCNavHealthInfoForSV>(svId, dataSetName);
    }

    GetBeiDouCNavHealthInfoForSVPtr GetBeiDouCNavHealthInfoForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetBeiDouCNavHealthInfoForSV>(ptr);
    }

    bool GetBeiDouCNavHealthInfoForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetBeiDouCNavHealthInfoForSV::documentation() const { return Documentation; }


    int GetBeiDouCNavHealthInfoForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetBeiDouCNavHealthInfoForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetBeiDouCNavHealthInfoForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetBeiDouCNavHealthInfoForSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetBeiDouCNavHealthInfoForSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

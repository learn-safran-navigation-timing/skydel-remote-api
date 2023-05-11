
#include "gen/GetBeiDouAutonomousHealthForSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetBeiDouAutonomousHealthForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetBeiDouAutonomousHealthForSV::CmdName = "GetBeiDouAutonomousHealthForSV";
    const char* const GetBeiDouAutonomousHealthForSV::Documentation = "Get BeiDou satellite autonomous health";

    REGISTER_COMMAND_FACTORY(GetBeiDouAutonomousHealthForSV);


    GetBeiDouAutonomousHealthForSV::GetBeiDouAutonomousHealthForSV()
      : CommandBase(CmdName)
    {}

    GetBeiDouAutonomousHealthForSV::GetBeiDouAutonomousHealthForSV(int svId, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setDataSetName(dataSetName);
    }

    GetBeiDouAutonomousHealthForSVPtr GetBeiDouAutonomousHealthForSV::create(int svId, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetBeiDouAutonomousHealthForSV>(svId, dataSetName);
    }

    GetBeiDouAutonomousHealthForSVPtr GetBeiDouAutonomousHealthForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetBeiDouAutonomousHealthForSV>(ptr);
    }

    bool GetBeiDouAutonomousHealthForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetBeiDouAutonomousHealthForSV::documentation() const { return Documentation; }


    int GetBeiDouAutonomousHealthForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetBeiDouAutonomousHealthForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetBeiDouAutonomousHealthForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetBeiDouAutonomousHealthForSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetBeiDouAutonomousHealthForSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

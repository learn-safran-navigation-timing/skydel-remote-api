
#include "gen/GetGpsSignalHealthForSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsSignalHealthForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsSignalHealthForSV::CmdName = "GetGpsSignalHealthForSV";
    const char* const GetGpsSignalHealthForSV::Documentation = "Get GPS signal health";

    REGISTER_COMMAND_FACTORY(GetGpsSignalHealthForSV);


    GetGpsSignalHealthForSV::GetGpsSignalHealthForSV()
      : CommandBase(CmdName)
    {}

    GetGpsSignalHealthForSV::GetGpsSignalHealthForSV(int svId, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setDataSetName(dataSetName);
    }

    GetGpsSignalHealthForSVPtr GetGpsSignalHealthForSV::create(int svId, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetGpsSignalHealthForSV>(svId, dataSetName);
    }

    GetGpsSignalHealthForSVPtr GetGpsSignalHealthForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsSignalHealthForSV>(ptr);
    }

    bool GetGpsSignalHealthForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetGpsSignalHealthForSV::documentation() const { return Documentation; }


    int GetGpsSignalHealthForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetGpsSignalHealthForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetGpsSignalHealthForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetGpsSignalHealthForSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetGpsSignalHealthForSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

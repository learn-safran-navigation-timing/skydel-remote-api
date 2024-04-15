
#include "GetGpsNavAlertFlagForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsNavAlertFlagForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsNavAlertFlagForSV::CmdName = "GetGpsNavAlertFlagForSV";
    const char* const GetGpsNavAlertFlagForSV::Documentation = "Get GPS NAV Alert Flag\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite's SV ID 1..32, or use 0 to apply new value to all satellites.\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetGpsNavAlertFlagForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetGpsNavAlertFlagForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetGpsNavAlertFlagForSV);


    GetGpsNavAlertFlagForSV::GetGpsNavAlertFlagForSV()
      : CommandBase(CmdName, TargetId)
    {}

    GetGpsNavAlertFlagForSV::GetGpsNavAlertFlagForSV(int svId, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setDataSetName(dataSetName);
    }

    GetGpsNavAlertFlagForSVPtr GetGpsNavAlertFlagForSV::create(int svId, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetGpsNavAlertFlagForSV>(svId, dataSetName);
    }

    GetGpsNavAlertFlagForSVPtr GetGpsNavAlertFlagForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsNavAlertFlagForSV>(ptr);
    }

    bool GetGpsNavAlertFlagForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetGpsNavAlertFlagForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& GetGpsNavAlertFlagForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "DataSetName"}; 
      return names; 
    }


    int GetGpsNavAlertFlagForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetGpsNavAlertFlagForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetGpsNavAlertFlagForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetGpsNavAlertFlagForSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetGpsNavAlertFlagForSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

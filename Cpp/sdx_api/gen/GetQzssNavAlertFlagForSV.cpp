
#include "GetQzssNavAlertFlagForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetQzssNavAlertFlagForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetQzssNavAlertFlagForSV::CmdName = "GetQzssNavAlertFlagForSV";
    const char* const GetQzssNavAlertFlagForSV::Documentation = "Get QZSS NAV Alert Flag\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite SV ID 1..10, or use 0 to apply new value to all satellites.\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetQzssNavAlertFlagForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetQzssNavAlertFlagForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetQzssNavAlertFlagForSV);


    GetQzssNavAlertFlagForSV::GetQzssNavAlertFlagForSV()
      : CommandBase(CmdName, TargetId)
    {}

    GetQzssNavAlertFlagForSV::GetQzssNavAlertFlagForSV(int svId, const std::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setDataSetName(dataSetName);
    }

    GetQzssNavAlertFlagForSVPtr GetQzssNavAlertFlagForSV::create(int svId, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetQzssNavAlertFlagForSV>(svId, dataSetName);
    }

    GetQzssNavAlertFlagForSVPtr GetQzssNavAlertFlagForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetQzssNavAlertFlagForSV>(ptr);
    }

    bool GetQzssNavAlertFlagForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetQzssNavAlertFlagForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& GetQzssNavAlertFlagForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "DataSetName"}; 
      return names; 
    }


    int GetQzssNavAlertFlagForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetQzssNavAlertFlagForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetQzssNavAlertFlagForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> GetQzssNavAlertFlagForSV::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetQzssNavAlertFlagForSV::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}


#include "GetNavICNavAlertFlagForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetNavICNavAlertFlagForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetNavICNavAlertFlagForSV::CmdName = "GetNavICNavAlertFlagForSV";
    const char* const GetNavICNavAlertFlagForSV::Documentation = "Get NavIC NAV Alert Flag\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite SV ID 1..14, or use 0 to apply new value to all satellites.\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetNavICNavAlertFlagForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetNavICNavAlertFlagForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetNavICNavAlertFlagForSV);


    GetNavICNavAlertFlagForSV::GetNavICNavAlertFlagForSV()
      : CommandBase(CmdName, TargetId)
    {}

    GetNavICNavAlertFlagForSV::GetNavICNavAlertFlagForSV(int svId, const std::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setDataSetName(dataSetName);
    }

    GetNavICNavAlertFlagForSVPtr GetNavICNavAlertFlagForSV::create(int svId, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetNavICNavAlertFlagForSV>(svId, dataSetName);
    }

    GetNavICNavAlertFlagForSVPtr GetNavICNavAlertFlagForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetNavICNavAlertFlagForSV>(ptr);
    }

    bool GetNavICNavAlertFlagForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetNavICNavAlertFlagForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& GetNavICNavAlertFlagForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "DataSetName"}; 
      return names; 
    }


    int GetNavICNavAlertFlagForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetNavICNavAlertFlagForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetNavICNavAlertFlagForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> GetNavICNavAlertFlagForSV::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetNavICNavAlertFlagForSV::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}


#include "GetGpsAntiSpoofingFlagForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsAntiSpoofingFlagForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsAntiSpoofingFlagForSV::CmdName = "GetGpsAntiSpoofingFlagForSV";
    const char* const GetGpsAntiSpoofingFlagForSV::Documentation = "Get GPS Anti-Spoofing Flag\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite's SV ID 1..32, or use 0 to apply new value to all satellites.\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetGpsAntiSpoofingFlagForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetGpsAntiSpoofingFlagForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetGpsAntiSpoofingFlagForSV);


    GetGpsAntiSpoofingFlagForSV::GetGpsAntiSpoofingFlagForSV()
      : CommandBase(CmdName, TargetId)
    {}

    GetGpsAntiSpoofingFlagForSV::GetGpsAntiSpoofingFlagForSV(int svId, const std::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setDataSetName(dataSetName);
    }

    GetGpsAntiSpoofingFlagForSVPtr GetGpsAntiSpoofingFlagForSV::create(int svId, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetGpsAntiSpoofingFlagForSV>(svId, dataSetName);
    }

    GetGpsAntiSpoofingFlagForSVPtr GetGpsAntiSpoofingFlagForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsAntiSpoofingFlagForSV>(ptr);
    }

    bool GetGpsAntiSpoofingFlagForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetGpsAntiSpoofingFlagForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& GetGpsAntiSpoofingFlagForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "DataSetName"}; 
      return names; 
    }


    int GetGpsAntiSpoofingFlagForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetGpsAntiSpoofingFlagForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetGpsAntiSpoofingFlagForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> GetGpsAntiSpoofingFlagForSV::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetGpsAntiSpoofingFlagForSV::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

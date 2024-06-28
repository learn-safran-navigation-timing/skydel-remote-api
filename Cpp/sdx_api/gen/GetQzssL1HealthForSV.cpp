
#include "GetQzssL1HealthForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetQzssL1HealthForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetQzssL1HealthForSV::CmdName = "GetQzssL1HealthForSV";
    const char* const GetQzssL1HealthForSV::Documentation = "Get QZSS L1 health (Health of L1C/A signal)\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite SV ID 1..10, or use 0 to apply new value to all satellites.\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetQzssL1HealthForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetQzssL1HealthForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetQzssL1HealthForSV);


    GetQzssL1HealthForSV::GetQzssL1HealthForSV()
      : CommandBase(CmdName, TargetId)
    {}

    GetQzssL1HealthForSV::GetQzssL1HealthForSV(int svId, const std::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setDataSetName(dataSetName);
    }

    GetQzssL1HealthForSVPtr GetQzssL1HealthForSV::create(int svId, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetQzssL1HealthForSV>(svId, dataSetName);
    }

    GetQzssL1HealthForSVPtr GetQzssL1HealthForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetQzssL1HealthForSV>(ptr);
    }

    bool GetQzssL1HealthForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetQzssL1HealthForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& GetQzssL1HealthForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "DataSetName"}; 
      return names; 
    }


    int GetQzssL1HealthForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetQzssL1HealthForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetQzssL1HealthForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> GetQzssL1HealthForSV::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetQzssL1HealthForSV::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

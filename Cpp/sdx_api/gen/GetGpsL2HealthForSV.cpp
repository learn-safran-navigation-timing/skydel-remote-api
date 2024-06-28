
#include "GetGpsL2HealthForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsL2HealthForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsL2HealthForSV::CmdName = "GetGpsL2HealthForSV";
    const char* const GetGpsL2HealthForSV::Documentation = "Get GPS L2 health (used with CNAV and CNAV2)\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite's SV ID 1..32, or use 0 to apply new value to all satellites.\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetGpsL2HealthForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetGpsL2HealthForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetGpsL2HealthForSV);


    GetGpsL2HealthForSV::GetGpsL2HealthForSV()
      : CommandBase(CmdName, TargetId)
    {}

    GetGpsL2HealthForSV::GetGpsL2HealthForSV(int svId, const std::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setDataSetName(dataSetName);
    }

    GetGpsL2HealthForSVPtr GetGpsL2HealthForSV::create(int svId, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetGpsL2HealthForSV>(svId, dataSetName);
    }

    GetGpsL2HealthForSVPtr GetGpsL2HealthForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsL2HealthForSV>(ptr);
    }

    bool GetGpsL2HealthForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetGpsL2HealthForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& GetGpsL2HealthForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "DataSetName"}; 
      return names; 
    }


    int GetGpsL2HealthForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetGpsL2HealthForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetGpsL2HealthForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> GetGpsL2HealthForSV::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetGpsL2HealthForSV::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

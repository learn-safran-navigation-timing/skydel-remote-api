
#include "GetGpsL5HealthForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsL5HealthForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsL5HealthForSV::CmdName = "GetGpsL5HealthForSV";
    const char* const GetGpsL5HealthForSV::Documentation = "Get GPS L5 health (used with CNAV and CNAV2)\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite's SV ID 1..32, or use 0 to apply new value to all satellites.\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetGpsL5HealthForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetGpsL5HealthForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetGpsL5HealthForSV);


    GetGpsL5HealthForSV::GetGpsL5HealthForSV()
      : CommandBase(CmdName, TargetId)
    {}

    GetGpsL5HealthForSV::GetGpsL5HealthForSV(int svId, const std::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setDataSetName(dataSetName);
    }

    GetGpsL5HealthForSVPtr GetGpsL5HealthForSV::create(int svId, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetGpsL5HealthForSV>(svId, dataSetName);
    }

    GetGpsL5HealthForSVPtr GetGpsL5HealthForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsL5HealthForSV>(ptr);
    }

    bool GetGpsL5HealthForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetGpsL5HealthForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& GetGpsL5HealthForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "DataSetName"}; 
      return names; 
    }


    int GetGpsL5HealthForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetGpsL5HealthForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetGpsL5HealthForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> GetGpsL5HealthForSV::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetGpsL5HealthForSV::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}


#include "GetPulsarX5HealthForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetPulsarX5HealthForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetPulsarX5HealthForSV::CmdName = "GetPulsarX5HealthForSV";
    const char* const GetPulsarX5HealthForSV::Documentation = "Get PULSAR X5 health (Health of X5 Signal)\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite SV ID 1..258, or use 0 to apply new value to all satellites.\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetPulsarX5HealthForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetPulsarX5HealthForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetPulsarX5HealthForSV);


    GetPulsarX5HealthForSV::GetPulsarX5HealthForSV()
      : CommandBase(CmdName, TargetId)
    {}

    GetPulsarX5HealthForSV::GetPulsarX5HealthForSV(int svId, const std::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setDataSetName(dataSetName);
    }

    GetPulsarX5HealthForSVPtr GetPulsarX5HealthForSV::create(int svId, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetPulsarX5HealthForSV>(svId, dataSetName);
    }

    GetPulsarX5HealthForSVPtr GetPulsarX5HealthForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetPulsarX5HealthForSV>(ptr);
    }

    bool GetPulsarX5HealthForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetPulsarX5HealthForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& GetPulsarX5HealthForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "DataSetName"}; 
      return names; 
    }


    int GetPulsarX5HealthForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetPulsarX5HealthForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetPulsarX5HealthForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> GetPulsarX5HealthForSV::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetPulsarX5HealthForSV::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

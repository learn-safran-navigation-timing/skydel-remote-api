
#include "GetPulsarX1HealthForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetPulsarX1HealthForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetPulsarX1HealthForSV::CmdName = "GetPulsarX1HealthForSV";
    const char* const GetPulsarX1HealthForSV::Documentation = "Get PULSAR X1 health (Health of X1 Signal)\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite SV ID 1..258, or use 0 to apply new value to all satellites.\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetPulsarX1HealthForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetPulsarX1HealthForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetPulsarX1HealthForSV);


    GetPulsarX1HealthForSV::GetPulsarX1HealthForSV()
      : CommandBase(CmdName, TargetId)
    {}

    GetPulsarX1HealthForSV::GetPulsarX1HealthForSV(int svId, const std::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setDataSetName(dataSetName);
    }

    GetPulsarX1HealthForSVPtr GetPulsarX1HealthForSV::create(int svId, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetPulsarX1HealthForSV>(svId, dataSetName);
    }

    GetPulsarX1HealthForSVPtr GetPulsarX1HealthForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetPulsarX1HealthForSV>(ptr);
    }

    bool GetPulsarX1HealthForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetPulsarX1HealthForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& GetPulsarX1HealthForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "DataSetName"}; 
      return names; 
    }


    int GetPulsarX1HealthForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetPulsarX1HealthForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetPulsarX1HealthForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> GetPulsarX1HealthForSV::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetPulsarX1HealthForSV::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

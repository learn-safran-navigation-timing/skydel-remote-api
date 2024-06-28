
#include "GetQzssL6HealthForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetQzssL6HealthForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetQzssL6HealthForSV::CmdName = "GetQzssL6HealthForSV";
    const char* const GetQzssL6HealthForSV::Documentation = "Get QZSS L6 health (Health of L6 signal).\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite SV ID 1..10, or use 0 to apply new value to all satellites.\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetQzssL6HealthForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetQzssL6HealthForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetQzssL6HealthForSV);


    GetQzssL6HealthForSV::GetQzssL6HealthForSV()
      : CommandBase(CmdName, TargetId)
    {}

    GetQzssL6HealthForSV::GetQzssL6HealthForSV(int svId, const std::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setDataSetName(dataSetName);
    }

    GetQzssL6HealthForSVPtr GetQzssL6HealthForSV::create(int svId, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetQzssL6HealthForSV>(svId, dataSetName);
    }

    GetQzssL6HealthForSVPtr GetQzssL6HealthForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetQzssL6HealthForSV>(ptr);
    }

    bool GetQzssL6HealthForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetQzssL6HealthForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& GetQzssL6HealthForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "DataSetName"}; 
      return names; 
    }


    int GetQzssL6HealthForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetQzssL6HealthForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetQzssL6HealthForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> GetQzssL6HealthForSV::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetQzssL6HealthForSV::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}


#include "GetQzssL5HealthForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetQzssL5HealthForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetQzssL5HealthForSV::CmdName = "GetQzssL5HealthForSV";
    const char* const GetQzssL5HealthForSV::Documentation = "Get QZSS L5 health (Health of L5 signal)\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite SV ID 1..10, or use 0 to apply new value to all satellites.\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetQzssL5HealthForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetQzssL5HealthForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetQzssL5HealthForSV);


    GetQzssL5HealthForSV::GetQzssL5HealthForSV()
      : CommandBase(CmdName, TargetId)
    {}

    GetQzssL5HealthForSV::GetQzssL5HealthForSV(int svId, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setDataSetName(dataSetName);
    }

    GetQzssL5HealthForSVPtr GetQzssL5HealthForSV::create(int svId, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetQzssL5HealthForSV>(svId, dataSetName);
    }

    GetQzssL5HealthForSVPtr GetQzssL5HealthForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetQzssL5HealthForSV>(ptr);
    }

    bool GetQzssL5HealthForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetQzssL5HealthForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& GetQzssL5HealthForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "DataSetName"}; 
      return names; 
    }


    int GetQzssL5HealthForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetQzssL5HealthForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetQzssL5HealthForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetQzssL5HealthForSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetQzssL5HealthForSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

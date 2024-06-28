
#include "GetGpsConfigurationCodeForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsConfigurationCodeForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsConfigurationCodeForSV::CmdName = "GetGpsConfigurationCodeForSV";
    const char* const GetGpsConfigurationCodeForSV::Documentation = "Get GPS SV configuration flag for one satellite\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite SV ID 1..32\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetGpsConfigurationCodeForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetGpsConfigurationCodeForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetGpsConfigurationCodeForSV);


    GetGpsConfigurationCodeForSV::GetGpsConfigurationCodeForSV()
      : CommandBase(CmdName, TargetId)
    {}

    GetGpsConfigurationCodeForSV::GetGpsConfigurationCodeForSV(int svId, const std::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setDataSetName(dataSetName);
    }

    GetGpsConfigurationCodeForSVPtr GetGpsConfigurationCodeForSV::create(int svId, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetGpsConfigurationCodeForSV>(svId, dataSetName);
    }

    GetGpsConfigurationCodeForSVPtr GetGpsConfigurationCodeForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsConfigurationCodeForSV>(ptr);
    }

    bool GetGpsConfigurationCodeForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetGpsConfigurationCodeForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& GetGpsConfigurationCodeForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "DataSetName"}; 
      return names; 
    }


    int GetGpsConfigurationCodeForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetGpsConfigurationCodeForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetGpsConfigurationCodeForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> GetGpsConfigurationCodeForSV::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetGpsConfigurationCodeForSV::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

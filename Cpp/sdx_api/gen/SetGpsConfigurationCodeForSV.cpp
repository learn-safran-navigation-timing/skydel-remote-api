
#include "SetGpsConfigurationCodeForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGpsConfigurationCodeForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGpsConfigurationCodeForSV::CmdName = "SetGpsConfigurationCodeForSV";
    const char* const SetGpsConfigurationCodeForSV::Documentation = "Set GPS SV configuration flag for one satellite\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite SV ID 1..32\n"
      "SvConfig    int             SV Config 0..4\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const SetGpsConfigurationCodeForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetGpsConfigurationCodeForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetGpsConfigurationCodeForSV);


    SetGpsConfigurationCodeForSV::SetGpsConfigurationCodeForSV()
      : CommandBase(CmdName, TargetId)
    {}

    SetGpsConfigurationCodeForSV::SetGpsConfigurationCodeForSV(int svId, int svConfig, const std::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setSvConfig(svConfig);
      setDataSetName(dataSetName);
    }

    SetGpsConfigurationCodeForSVPtr SetGpsConfigurationCodeForSV::create(int svId, int svConfig, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetGpsConfigurationCodeForSV>(svId, svConfig, dataSetName);
    }

    SetGpsConfigurationCodeForSVPtr SetGpsConfigurationCodeForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetGpsConfigurationCodeForSV>(ptr);
    }

    bool SetGpsConfigurationCodeForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<int>::is_valid(m_values["SvConfig"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetGpsConfigurationCodeForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& SetGpsConfigurationCodeForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "SvConfig", "DataSetName"}; 
      return names; 
    }


    int SetGpsConfigurationCodeForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }


    int SetGpsConfigurationCodeForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetGpsConfigurationCodeForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetGpsConfigurationCodeForSV::svConfig() const
    {
      return parse_json<int>::parse(m_values["SvConfig"]);
    }

    void SetGpsConfigurationCodeForSV::setSvConfig(int svConfig)
    {
      m_values.AddMember("SvConfig", parse_json<int>::format(svConfig, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> SetGpsConfigurationCodeForSV::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetGpsConfigurationCodeForSV::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

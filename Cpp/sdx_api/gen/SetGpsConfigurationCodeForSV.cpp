
#include "gen/SetGpsConfigurationCodeForSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGpsConfigurationCodeForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGpsConfigurationCodeForSV::CmdName = "SetGpsConfigurationCodeForSV";
    const char* const SetGpsConfigurationCodeForSV::Documentation = "Set GPS SV configuration flag for one satellite";

    REGISTER_COMMAND_FACTORY(SetGpsConfigurationCodeForSV);


    SetGpsConfigurationCodeForSV::SetGpsConfigurationCodeForSV()
      : CommandBase(CmdName)
    {}

    SetGpsConfigurationCodeForSV::SetGpsConfigurationCodeForSV(int svId, int svConfig, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setSvConfig(svConfig);
      setDataSetName(dataSetName);
    }

    SetGpsConfigurationCodeForSVPtr SetGpsConfigurationCodeForSV::create(int svId, int svConfig, const Sdx::optional<std::string>& dataSetName)
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
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetGpsConfigurationCodeForSV::documentation() const { return Documentation; }


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



    Sdx::optional<std::string> SetGpsConfigurationCodeForSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetGpsConfigurationCodeForSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

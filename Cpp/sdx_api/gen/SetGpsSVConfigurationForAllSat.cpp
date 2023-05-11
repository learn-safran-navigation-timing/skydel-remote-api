
#include "gen/SetGpsSVConfigurationForAllSat.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGpsSVConfigurationForAllSat
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGpsSVConfigurationForAllSat::CmdName = "SetGpsSVConfigurationForAllSat";
    const char* const SetGpsSVConfigurationForAllSat::Documentation = "Please note the command SetGpsSVConfigurationForAllSat is deprecated since 21.3. You may use SetGpsConfigurationForEachSV.\n\nSet GPS SV configuration flag for each SVs";

    REGISTER_COMMAND_FACTORY(SetGpsSVConfigurationForAllSat);


    SetGpsSVConfigurationForAllSat::SetGpsSVConfigurationForAllSat()
      : CommandBase(CmdName)
    {}

    SetGpsSVConfigurationForAllSat::SetGpsSVConfigurationForAllSat(const std::vector<int>& svConfigs, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setSvConfigs(svConfigs);
      setDataSetName(dataSetName);
    }

    SetGpsSVConfigurationForAllSatPtr SetGpsSVConfigurationForAllSat::create(const std::vector<int>& svConfigs, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetGpsSVConfigurationForAllSat>(svConfigs, dataSetName);
    }

    SetGpsSVConfigurationForAllSatPtr SetGpsSVConfigurationForAllSat::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetGpsSVConfigurationForAllSat>(ptr);
    }

    bool SetGpsSVConfigurationForAllSat::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<int>>::is_valid(m_values["SvConfigs"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetGpsSVConfigurationForAllSat::documentation() const { return Documentation; }


    int SetGpsSVConfigurationForAllSat::executePermission() const
    {
      return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }


    std::vector<int> SetGpsSVConfigurationForAllSat::svConfigs() const
    {
      return parse_json<std::vector<int>>::parse(m_values["SvConfigs"]);
    }

    void SetGpsSVConfigurationForAllSat::setSvConfigs(const std::vector<int>& svConfigs)
    {
      m_values.AddMember("SvConfigs", parse_json<std::vector<int>>::format(svConfigs, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> SetGpsSVConfigurationForAllSat::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetGpsSVConfigurationForAllSat::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

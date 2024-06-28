
#include "SetGpsSVConfigurationForAllSat.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGpsSVConfigurationForAllSat
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGpsSVConfigurationForAllSat::CmdName = "SetGpsSVConfigurationForAllSat";
    const char* const SetGpsSVConfigurationForAllSat::Documentation = "Please note the command SetGpsSVConfigurationForAllSat is deprecated since 21.3. You may use SetGpsConfigurationForEachSV.\n"
      "\n"
      "Set GPS SV configuration flag for each SVs\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvConfigs   array int       SV Config of all satellite\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const SetGpsSVConfigurationForAllSat::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetGpsSVConfigurationForAllSat);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetGpsSVConfigurationForAllSat);


    SetGpsSVConfigurationForAllSat::SetGpsSVConfigurationForAllSat()
      : CommandBase(CmdName, TargetId)
    {}

    SetGpsSVConfigurationForAllSat::SetGpsSVConfigurationForAllSat(const std::vector<int>& svConfigs, const std::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvConfigs(svConfigs);
      setDataSetName(dataSetName);
    }

    SetGpsSVConfigurationForAllSatPtr SetGpsSVConfigurationForAllSat::create(const std::vector<int>& svConfigs, const std::optional<std::string>& dataSetName)
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
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetGpsSVConfigurationForAllSat::documentation() const { return Documentation; }

    const std::vector<std::string>& SetGpsSVConfigurationForAllSat::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvConfigs", "DataSetName"}; 
      return names; 
    }


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



    std::optional<std::string> SetGpsSVConfigurationForAllSat::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetGpsSVConfigurationForAllSat::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

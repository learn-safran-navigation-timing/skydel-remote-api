
#include "GetGpsSVConfigurationForAllSat.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsSVConfigurationForAllSat
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsSVConfigurationForAllSat::CmdName = "GetGpsSVConfigurationForAllSat";
    const char* const GetGpsSVConfigurationForAllSat::Documentation = "Please note the command GetGpsSVConfigurationForAllSat is deprecated since 21.3. You may use GetGpsConfigurationForEachSV.\n"
      "\n"
      "Get GPS SV configuration flag for each SVs\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetGpsSVConfigurationForAllSat::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetGpsSVConfigurationForAllSat);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetGpsSVConfigurationForAllSat);


    GetGpsSVConfigurationForAllSat::GetGpsSVConfigurationForAllSat(const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setDataSetName(dataSetName);
    }

    GetGpsSVConfigurationForAllSatPtr GetGpsSVConfigurationForAllSat::create(const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetGpsSVConfigurationForAllSat>(dataSetName);
    }

    GetGpsSVConfigurationForAllSatPtr GetGpsSVConfigurationForAllSat::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsSVConfigurationForAllSat>(ptr);
    }

    bool GetGpsSVConfigurationForAllSat::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetGpsSVConfigurationForAllSat::documentation() const { return Documentation; }

    const std::vector<std::string>& GetGpsSVConfigurationForAllSat::fieldNames() const 
    { 
      static const std::vector<std::string> names {"DataSetName"}; 
      return names; 
    }


    int GetGpsSVConfigurationForAllSat::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    Sdx::optional<std::string> GetGpsSVConfigurationForAllSat::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetGpsSVConfigurationForAllSat::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

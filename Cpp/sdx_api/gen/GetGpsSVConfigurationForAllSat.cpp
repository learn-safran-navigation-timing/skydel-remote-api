
#include "gen/GetGpsSVConfigurationForAllSat.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsSVConfigurationForAllSat
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsSVConfigurationForAllSat::CmdName = "GetGpsSVConfigurationForAllSat";
    const char* const GetGpsSVConfigurationForAllSat::Documentation = "Please note the command GetGpsSVConfigurationForAllSat is deprecated since 21.3. You may use GetGpsConfigurationForEachSV.\n\nGet GPS SV configuration flag for each SVs";

    REGISTER_COMMAND_FACTORY(GetGpsSVConfigurationForAllSat);


    GetGpsSVConfigurationForAllSat::GetGpsSVConfigurationForAllSat(const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
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

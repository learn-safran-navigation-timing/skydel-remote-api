
#include "gen/GetAllVehicleAntennaNamesResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetAllVehicleAntennaNamesResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetAllVehicleAntennaNamesResult::CmdName = "GetAllVehicleAntennaNamesResult";
    const char* const GetAllVehicleAntennaNamesResult::Documentation = "Result of GetAllVehicleAntennaNames.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetAllVehicleAntennaNamesResult);


    GetAllVehicleAntennaNamesResult::GetAllVehicleAntennaNamesResult()
      : CommandResult(CmdName)
    {}

    GetAllVehicleAntennaNamesResult::GetAllVehicleAntennaNamesResult(const std::vector<std::string>& antennaNames)
      : CommandResult(CmdName)
    {

      setAntennaNames(antennaNames);
    }

    GetAllVehicleAntennaNamesResult::GetAllVehicleAntennaNamesResult(CommandBasePtr relatedCommand, const std::vector<std::string>& antennaNames)
      : CommandResult(CmdName, relatedCommand)
    {

      setAntennaNames(antennaNames);
    }


    GetAllVehicleAntennaNamesResultPtr GetAllVehicleAntennaNamesResult::create(const std::vector<std::string>& antennaNames)
    {
      return std::make_shared<GetAllVehicleAntennaNamesResult>(antennaNames);
    }

    GetAllVehicleAntennaNamesResultPtr GetAllVehicleAntennaNamesResult::create(CommandBasePtr relatedCommand, const std::vector<std::string>& antennaNames)
    {
      return std::make_shared<GetAllVehicleAntennaNamesResult>(relatedCommand, antennaNames);
    }

    GetAllVehicleAntennaNamesResultPtr GetAllVehicleAntennaNamesResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetAllVehicleAntennaNamesResult>(ptr);
    }

    bool GetAllVehicleAntennaNamesResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<std::string>>::is_valid(m_values["AntennaNames"])
        ;

    }

    std::string GetAllVehicleAntennaNamesResult::documentation() const { return Documentation; }


    std::vector<std::string> GetAllVehicleAntennaNamesResult::antennaNames() const
    {
      return parse_json<std::vector<std::string>>::parse(m_values["AntennaNames"]);
    }

    void GetAllVehicleAntennaNamesResult::setAntennaNames(const std::vector<std::string>& antennaNames)
    {
      m_values.AddMember("AntennaNames", parse_json<std::vector<std::string>>::format(antennaNames, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}


#include "GetAllVehicleAntennaNamesResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetAllVehicleAntennaNamesResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetAllVehicleAntennaNamesResult::CmdName = "GetAllVehicleAntennaNamesResult";
    const char* const GetAllVehicleAntennaNamesResult::Documentation = "Result of GetAllVehicleAntennaNames.\n"
      "\n"
      "Name         Type         Description\n"
      "------------ ------------ -----------------------------\n"
      "AntennaNames array string A list of antenna model names";
    const char* const GetAllVehicleAntennaNamesResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetAllVehicleAntennaNamesResult);


    GetAllVehicleAntennaNamesResult::GetAllVehicleAntennaNamesResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetAllVehicleAntennaNamesResult::GetAllVehicleAntennaNamesResult(const std::vector<std::string>& antennaNames)
      : CommandResult(CmdName, TargetId)
    {

      setAntennaNames(antennaNames);
    }

    GetAllVehicleAntennaNamesResult::GetAllVehicleAntennaNamesResult(CommandBasePtr relatedCommand, const std::vector<std::string>& antennaNames)
      : CommandResult(CmdName, TargetId, relatedCommand)
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

    const std::vector<std::string>& GetAllVehicleAntennaNamesResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"AntennaNames"}; 
      return names; 
    }


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

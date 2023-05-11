
#include "gen/GetAllVehicleAntennaNames.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetAllVehicleAntennaNames
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetAllVehicleAntennaNames::CmdName = "GetAllVehicleAntennaNames";
    const char* const GetAllVehicleAntennaNames::Documentation = "Get a list of all vehicle antenna names";

    REGISTER_COMMAND_FACTORY(GetAllVehicleAntennaNames);


    GetAllVehicleAntennaNames::GetAllVehicleAntennaNames()
      : CommandBase(CmdName)
    {

    }

    GetAllVehicleAntennaNamesPtr GetAllVehicleAntennaNames::create()
    {
      return std::make_shared<GetAllVehicleAntennaNames>();
    }

    GetAllVehicleAntennaNamesPtr GetAllVehicleAntennaNames::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetAllVehicleAntennaNames>(ptr);
    }

    bool GetAllVehicleAntennaNames::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetAllVehicleAntennaNames::documentation() const { return Documentation; }


    int GetAllVehicleAntennaNames::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}

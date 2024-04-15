
#include "GetAllVehicleAntennaNames.h"

#include "command_factory.h"
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
    const char* const GetAllVehicleAntennaNames::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetAllVehicleAntennaNames);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetAllVehicleAntennaNames);


    GetAllVehicleAntennaNames::GetAllVehicleAntennaNames()
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& GetAllVehicleAntennaNames::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetAllVehicleAntennaNames::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}

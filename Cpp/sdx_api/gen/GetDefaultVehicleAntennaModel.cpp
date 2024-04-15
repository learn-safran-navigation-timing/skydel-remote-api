
#include "GetDefaultVehicleAntennaModel.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetDefaultVehicleAntennaModel
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetDefaultVehicleAntennaModel::CmdName = "GetDefaultVehicleAntennaModel";
    const char* const GetDefaultVehicleAntennaModel::Documentation = "Get the default vehicle antenna model.";
    const char* const GetDefaultVehicleAntennaModel::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetDefaultVehicleAntennaModel);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetDefaultVehicleAntennaModel);


    GetDefaultVehicleAntennaModel::GetDefaultVehicleAntennaModel()
      : CommandBase(CmdName, TargetId)
    {

    }

    GetDefaultVehicleAntennaModelPtr GetDefaultVehicleAntennaModel::create()
    {
      return std::make_shared<GetDefaultVehicleAntennaModel>();
    }

    GetDefaultVehicleAntennaModelPtr GetDefaultVehicleAntennaModel::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetDefaultVehicleAntennaModel>(ptr);
    }

    bool GetDefaultVehicleAntennaModel::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetDefaultVehicleAntennaModel::documentation() const { return Documentation; }

    const std::vector<std::string>& GetDefaultVehicleAntennaModel::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetDefaultVehicleAntennaModel::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}

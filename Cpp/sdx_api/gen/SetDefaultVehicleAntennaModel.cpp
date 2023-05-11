
#include "gen/SetDefaultVehicleAntennaModel.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetDefaultVehicleAntennaModel
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetDefaultVehicleAntennaModel::CmdName = "SetDefaultVehicleAntennaModel";
    const char* const SetDefaultVehicleAntennaModel::Documentation = "Set the default vehicle antenna model.";

    REGISTER_COMMAND_FACTORY(SetDefaultVehicleAntennaModel);


    SetDefaultVehicleAntennaModel::SetDefaultVehicleAntennaModel()
      : CommandBase(CmdName)
    {}

    SetDefaultVehicleAntennaModel::SetDefaultVehicleAntennaModel(const std::string& name)
      : CommandBase(CmdName)
    {

      setName(name);
    }

    SetDefaultVehicleAntennaModelPtr SetDefaultVehicleAntennaModel::create(const std::string& name)
    {
      return std::make_shared<SetDefaultVehicleAntennaModel>(name);
    }

    SetDefaultVehicleAntennaModelPtr SetDefaultVehicleAntennaModel::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetDefaultVehicleAntennaModel>(ptr);
    }

    bool SetDefaultVehicleAntennaModel::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Name"])
        ;

    }

    std::string SetDefaultVehicleAntennaModel::documentation() const { return Documentation; }


    int SetDefaultVehicleAntennaModel::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetDefaultVehicleAntennaModel::name() const
    {
      return parse_json<std::string>::parse(m_values["Name"]);
    }

    void SetDefaultVehicleAntennaModel::setName(const std::string& name)
    {
      m_values.AddMember("Name", parse_json<std::string>::format(name, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}


#include "SetDefaultVehicleAntennaModel.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetDefaultVehicleAntennaModel
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetDefaultVehicleAntennaModel::CmdName = "SetDefaultVehicleAntennaModel";
    const char* const SetDefaultVehicleAntennaModel::Documentation = "Set the default vehicle antenna model.\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ ---------------------------\n"
      "Name string Default antenna model name.";
    const char* const SetDefaultVehicleAntennaModel::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetDefaultVehicleAntennaModel);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetDefaultVehicleAntennaModel);


    SetDefaultVehicleAntennaModel::SetDefaultVehicleAntennaModel()
      : CommandBase(CmdName, TargetId)
    {}

    SetDefaultVehicleAntennaModel::SetDefaultVehicleAntennaModel(const std::string& name)
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& SetDefaultVehicleAntennaModel::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Name"}; 
      return names; 
    }


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

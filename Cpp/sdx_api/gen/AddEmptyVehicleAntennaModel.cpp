
#include "AddEmptyVehicleAntennaModel.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of AddEmptyVehicleAntennaModel
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const AddEmptyVehicleAntennaModel::CmdName = "AddEmptyVehicleAntennaModel";
    const char* const AddEmptyVehicleAntennaModel::Documentation = "Create an empty vehicle antenna model.\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ --------------------------\n"
      "Name string Vehicle antenna model name";
    const char* const AddEmptyVehicleAntennaModel::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(AddEmptyVehicleAntennaModel);
    REGISTER_COMMAND_TO_FACTORY_IMPL(AddEmptyVehicleAntennaModel);


    AddEmptyVehicleAntennaModel::AddEmptyVehicleAntennaModel()
      : CommandBase(CmdName, TargetId)
    {}

    AddEmptyVehicleAntennaModel::AddEmptyVehicleAntennaModel(const std::string& name)
      : CommandBase(CmdName, TargetId)
    {

      setName(name);
    }

    AddEmptyVehicleAntennaModelPtr AddEmptyVehicleAntennaModel::create(const std::string& name)
    {
      return std::make_shared<AddEmptyVehicleAntennaModel>(name);
    }

    AddEmptyVehicleAntennaModelPtr AddEmptyVehicleAntennaModel::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<AddEmptyVehicleAntennaModel>(ptr);
    }

    bool AddEmptyVehicleAntennaModel::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Name"])
        ;

    }

    std::string AddEmptyVehicleAntennaModel::documentation() const { return Documentation; }

    const std::vector<std::string>& AddEmptyVehicleAntennaModel::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Name"}; 
      return names; 
    }


    int AddEmptyVehicleAntennaModel::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string AddEmptyVehicleAntennaModel::name() const
    {
      return parse_json<std::string>::parse(m_values["Name"]);
    }

    void AddEmptyVehicleAntennaModel::setName(const std::string& name)
    {
      m_values.AddMember("Name", parse_json<std::string>::format(name, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

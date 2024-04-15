
#include "DeleteVehicleAntennaModel.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of DeleteVehicleAntennaModel
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const DeleteVehicleAntennaModel::CmdName = "DeleteVehicleAntennaModel";
    const char* const DeleteVehicleAntennaModel::Documentation = "Delete a vehicle antenna model. The default vehicle antenna model can't be deleted.\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ --------------------------\n"
      "Name string Vehicle antenna model name";
    const char* const DeleteVehicleAntennaModel::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(DeleteVehicleAntennaModel);
    REGISTER_COMMAND_TO_FACTORY_IMPL(DeleteVehicleAntennaModel);


    DeleteVehicleAntennaModel::DeleteVehicleAntennaModel()
      : CommandBase(CmdName, TargetId)
    {}

    DeleteVehicleAntennaModel::DeleteVehicleAntennaModel(const std::string& name)
      : CommandBase(CmdName, TargetId)
    {

      setName(name);
    }

    DeleteVehicleAntennaModelPtr DeleteVehicleAntennaModel::create(const std::string& name)
    {
      return std::make_shared<DeleteVehicleAntennaModel>(name);
    }

    DeleteVehicleAntennaModelPtr DeleteVehicleAntennaModel::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<DeleteVehicleAntennaModel>(ptr);
    }

    bool DeleteVehicleAntennaModel::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Name"])
        ;

    }

    std::string DeleteVehicleAntennaModel::documentation() const { return Documentation; }

    const std::vector<std::string>& DeleteVehicleAntennaModel::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Name"}; 
      return names; 
    }


    int DeleteVehicleAntennaModel::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string DeleteVehicleAntennaModel::name() const
    {
      return parse_json<std::string>::parse(m_values["Name"]);
    }

    void DeleteVehicleAntennaModel::setName(const std::string& name)
    {
      m_values.AddMember("Name", parse_json<std::string>::format(name, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

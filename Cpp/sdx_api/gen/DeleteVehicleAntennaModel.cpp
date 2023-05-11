
#include "gen/DeleteVehicleAntennaModel.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of DeleteVehicleAntennaModel
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const DeleteVehicleAntennaModel::CmdName = "DeleteVehicleAntennaModel";
    const char* const DeleteVehicleAntennaModel::Documentation = "Delete a vehicle antenna model. The default vehicle antenna model can't be deleted.";

    REGISTER_COMMAND_FACTORY(DeleteVehicleAntennaModel);


    DeleteVehicleAntennaModel::DeleteVehicleAntennaModel()
      : CommandBase(CmdName)
    {}

    DeleteVehicleAntennaModel::DeleteVehicleAntennaModel(const std::string& name)
      : CommandBase(CmdName)
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


#include "gen/AddEmptyVehicleAntennaModel.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of AddEmptyVehicleAntennaModel
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const AddEmptyVehicleAntennaModel::CmdName = "AddEmptyVehicleAntennaModel";
    const char* const AddEmptyVehicleAntennaModel::Documentation = "Create an empty vehicle antenna model.";

    REGISTER_COMMAND_FACTORY(AddEmptyVehicleAntennaModel);


    AddEmptyVehicleAntennaModel::AddEmptyVehicleAntennaModel()
      : CommandBase(CmdName)
    {}

    AddEmptyVehicleAntennaModel::AddEmptyVehicleAntennaModel(const std::string& name)
      : CommandBase(CmdName)
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

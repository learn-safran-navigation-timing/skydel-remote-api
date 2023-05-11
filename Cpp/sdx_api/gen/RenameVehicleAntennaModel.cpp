
#include "gen/RenameVehicleAntennaModel.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of RenameVehicleAntennaModel
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const RenameVehicleAntennaModel::CmdName = "RenameVehicleAntennaModel";
    const char* const RenameVehicleAntennaModel::Documentation = "Rename a vehicle antenna model.";

    REGISTER_COMMAND_FACTORY(RenameVehicleAntennaModel);


    RenameVehicleAntennaModel::RenameVehicleAntennaModel()
      : CommandBase(CmdName)
    {}

    RenameVehicleAntennaModel::RenameVehicleAntennaModel(const std::string& name, const std::string& newName)
      : CommandBase(CmdName)
    {

      setName(name);
      setNewName(newName);
    }

    RenameVehicleAntennaModelPtr RenameVehicleAntennaModel::create(const std::string& name, const std::string& newName)
    {
      return std::make_shared<RenameVehicleAntennaModel>(name, newName);
    }

    RenameVehicleAntennaModelPtr RenameVehicleAntennaModel::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<RenameVehicleAntennaModel>(ptr);
    }

    bool RenameVehicleAntennaModel::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Name"])
          && parse_json<std::string>::is_valid(m_values["NewName"])
        ;

    }

    std::string RenameVehicleAntennaModel::documentation() const { return Documentation; }


    int RenameVehicleAntennaModel::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string RenameVehicleAntennaModel::name() const
    {
      return parse_json<std::string>::parse(m_values["Name"]);
    }

    void RenameVehicleAntennaModel::setName(const std::string& name)
    {
      m_values.AddMember("Name", parse_json<std::string>::format(name, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string RenameVehicleAntennaModel::newName() const
    {
      return parse_json<std::string>::parse(m_values["NewName"]);
    }

    void RenameVehicleAntennaModel::setNewName(const std::string& newName)
    {
      m_values.AddMember("NewName", parse_json<std::string>::format(newName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

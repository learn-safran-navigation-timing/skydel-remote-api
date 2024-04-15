
#include "RenameVehicleAntennaModel.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of RenameVehicleAntennaModel
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const RenameVehicleAntennaModel::CmdName = "RenameVehicleAntennaModel";
    const char* const RenameVehicleAntennaModel::Documentation = "Rename a vehicle antenna model.\n"
      "\n"
      "Name    Type   Description\n"
      "------- ------ ------------------------------------\n"
      "Name    string Reference vehicle antenna model name\n"
      "NewName string New vehicle antenna model name";
    const char* const RenameVehicleAntennaModel::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(RenameVehicleAntennaModel);
    REGISTER_COMMAND_TO_FACTORY_IMPL(RenameVehicleAntennaModel);


    RenameVehicleAntennaModel::RenameVehicleAntennaModel()
      : CommandBase(CmdName, TargetId)
    {}

    RenameVehicleAntennaModel::RenameVehicleAntennaModel(const std::string& name, const std::string& newName)
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& RenameVehicleAntennaModel::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Name", "NewName"}; 
      return names; 
    }


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

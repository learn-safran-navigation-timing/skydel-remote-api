
#include "GetVehicleAntennaModel.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetVehicleAntennaModel
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetVehicleAntennaModel::CmdName = "GetVehicleAntennaModel";
    const char* const GetVehicleAntennaModel::Documentation = "Get  all infos about this antenna model.\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ --------------------------\n"
      "Name string Vehicle antenna model name";
    const char* const GetVehicleAntennaModel::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetVehicleAntennaModel);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetVehicleAntennaModel);


    GetVehicleAntennaModel::GetVehicleAntennaModel()
      : CommandBase(CmdName, TargetId)
    {}

    GetVehicleAntennaModel::GetVehicleAntennaModel(const std::string& name)
      : CommandBase(CmdName, TargetId)
    {

      setName(name);
    }

    GetVehicleAntennaModelPtr GetVehicleAntennaModel::create(const std::string& name)
    {
      return std::make_shared<GetVehicleAntennaModel>(name);
    }

    GetVehicleAntennaModelPtr GetVehicleAntennaModel::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetVehicleAntennaModel>(ptr);
    }

    bool GetVehicleAntennaModel::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Name"])
        ;

    }

    std::string GetVehicleAntennaModel::documentation() const { return Documentation; }

    const std::vector<std::string>& GetVehicleAntennaModel::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Name"}; 
      return names; 
    }


    int GetVehicleAntennaModel::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetVehicleAntennaModel::name() const
    {
      return parse_json<std::string>::parse(m_values["Name"]);
    }

    void GetVehicleAntennaModel::setName(const std::string& name)
    {
      m_values.AddMember("Name", parse_json<std::string>::format(name, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

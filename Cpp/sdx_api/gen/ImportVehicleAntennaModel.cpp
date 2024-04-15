
#include "ImportVehicleAntennaModel.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of ImportVehicleAntennaModel
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ImportVehicleAntennaModel::CmdName = "ImportVehicleAntennaModel";
    const char* const ImportVehicleAntennaModel::Documentation = "Import a vehicle antenna model from a XML file.\n"
      "\n"
      "Name     Type   Description\n"
      "-------- ------ ------------------------------\n"
      "FilePath string File path of the antenna model";
    const char* const ImportVehicleAntennaModel::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(ImportVehicleAntennaModel);
    REGISTER_COMMAND_TO_FACTORY_IMPL(ImportVehicleAntennaModel);


    ImportVehicleAntennaModel::ImportVehicleAntennaModel()
      : CommandBase(CmdName, TargetId)
    {}

    ImportVehicleAntennaModel::ImportVehicleAntennaModel(const std::string& filePath)
      : CommandBase(CmdName, TargetId)
    {

      setFilePath(filePath);
    }

    ImportVehicleAntennaModelPtr ImportVehicleAntennaModel::create(const std::string& filePath)
    {
      return std::make_shared<ImportVehicleAntennaModel>(filePath);
    }

    ImportVehicleAntennaModelPtr ImportVehicleAntennaModel::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ImportVehicleAntennaModel>(ptr);
    }

    bool ImportVehicleAntennaModel::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["FilePath"])
        ;

    }

    std::string ImportVehicleAntennaModel::documentation() const { return Documentation; }

    const std::vector<std::string>& ImportVehicleAntennaModel::fieldNames() const 
    { 
      static const std::vector<std::string> names {"FilePath"}; 
      return names; 
    }


    int ImportVehicleAntennaModel::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string ImportVehicleAntennaModel::filePath() const
    {
      return parse_json<std::string>::parse(m_values["FilePath"]);
    }

    void ImportVehicleAntennaModel::setFilePath(const std::string& filePath)
    {
      m_values.AddMember("FilePath", parse_json<std::string>::format(filePath, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

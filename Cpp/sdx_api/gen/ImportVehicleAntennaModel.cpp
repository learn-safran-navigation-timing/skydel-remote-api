
#include "gen/ImportVehicleAntennaModel.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of ImportVehicleAntennaModel
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ImportVehicleAntennaModel::CmdName = "ImportVehicleAntennaModel";
    const char* const ImportVehicleAntennaModel::Documentation = "Import a vehicle antenna model from a XML file.";

    REGISTER_COMMAND_FACTORY(ImportVehicleAntennaModel);


    ImportVehicleAntennaModel::ImportVehicleAntennaModel()
      : CommandBase(CmdName)
    {}

    ImportVehicleAntennaModel::ImportVehicleAntennaModel(const std::string& filePath)
      : CommandBase(CmdName)
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

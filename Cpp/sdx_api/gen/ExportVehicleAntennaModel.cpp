
#include "ExportVehicleAntennaModel.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of ExportVehicleAntennaModel
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ExportVehicleAntennaModel::CmdName = "ExportVehicleAntennaModel";
    const char* const ExportVehicleAntennaModel::Documentation = "Export a vehicle antenna model in a XML file.\n"
      "\n"
      "Name        Type   Description\n"
      "----------- ------ -----------------------------------------------------\n"
      "AntennaName string Vehicle antenna model name\n"
      "FilePath    string The antenna model will be exported in this file path.\n"
      "Overwriting bool   Overwrite the old file if true.";
    const char* const ExportVehicleAntennaModel::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(ExportVehicleAntennaModel);
    REGISTER_COMMAND_TO_FACTORY_IMPL(ExportVehicleAntennaModel);


    ExportVehicleAntennaModel::ExportVehicleAntennaModel()
      : CommandBase(CmdName, TargetId)
    {}

    ExportVehicleAntennaModel::ExportVehicleAntennaModel(const std::string& antennaName, const std::string& filePath, bool overwriting)
      : CommandBase(CmdName, TargetId)
    {

      setAntennaName(antennaName);
      setFilePath(filePath);
      setOverwriting(overwriting);
    }

    ExportVehicleAntennaModelPtr ExportVehicleAntennaModel::create(const std::string& antennaName, const std::string& filePath, bool overwriting)
    {
      return std::make_shared<ExportVehicleAntennaModel>(antennaName, filePath, overwriting);
    }

    ExportVehicleAntennaModelPtr ExportVehicleAntennaModel::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ExportVehicleAntennaModel>(ptr);
    }

    bool ExportVehicleAntennaModel::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["AntennaName"])
          && parse_json<std::string>::is_valid(m_values["FilePath"])
          && parse_json<bool>::is_valid(m_values["Overwriting"])
        ;

    }

    std::string ExportVehicleAntennaModel::documentation() const { return Documentation; }

    const std::vector<std::string>& ExportVehicleAntennaModel::fieldNames() const 
    { 
      static const std::vector<std::string> names {"AntennaName", "FilePath", "Overwriting"}; 
      return names; 
    }


    int ExportVehicleAntennaModel::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string ExportVehicleAntennaModel::antennaName() const
    {
      return parse_json<std::string>::parse(m_values["AntennaName"]);
    }

    void ExportVehicleAntennaModel::setAntennaName(const std::string& antennaName)
    {
      m_values.AddMember("AntennaName", parse_json<std::string>::format(antennaName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string ExportVehicleAntennaModel::filePath() const
    {
      return parse_json<std::string>::parse(m_values["FilePath"]);
    }

    void ExportVehicleAntennaModel::setFilePath(const std::string& filePath)
    {
      m_values.AddMember("FilePath", parse_json<std::string>::format(filePath, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool ExportVehicleAntennaModel::overwriting() const
    {
      return parse_json<bool>::parse(m_values["Overwriting"]);
    }

    void ExportVehicleAntennaModel::setOverwriting(bool overwriting)
    {
      m_values.AddMember("Overwriting", parse_json<bool>::format(overwriting, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

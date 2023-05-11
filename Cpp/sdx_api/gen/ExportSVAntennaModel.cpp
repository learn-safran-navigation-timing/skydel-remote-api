
#include "gen/ExportSVAntennaModel.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of ExportSVAntennaModel
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ExportSVAntennaModel::CmdName = "ExportSVAntennaModel";
    const char* const ExportSVAntennaModel::Documentation = "Export a space vehicle antenna model in a XML file.";

    REGISTER_COMMAND_FACTORY(ExportSVAntennaModel);


    ExportSVAntennaModel::ExportSVAntennaModel()
      : CommandBase(CmdName)
    {}

    ExportSVAntennaModel::ExportSVAntennaModel(const std::string& antennaName, const std::string& system, const std::string& filePath, bool overwriting)
      : CommandBase(CmdName)
    {

      setAntennaName(antennaName);
      setSystem(system);
      setFilePath(filePath);
      setOverwriting(overwriting);
    }

    ExportSVAntennaModelPtr ExportSVAntennaModel::create(const std::string& antennaName, const std::string& system, const std::string& filePath, bool overwriting)
    {
      return std::make_shared<ExportSVAntennaModel>(antennaName, system, filePath, overwriting);
    }

    ExportSVAntennaModelPtr ExportSVAntennaModel::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ExportSVAntennaModel>(ptr);
    }

    bool ExportSVAntennaModel::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["AntennaName"])
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<std::string>::is_valid(m_values["FilePath"])
          && parse_json<bool>::is_valid(m_values["Overwriting"])
        ;

    }

    std::string ExportSVAntennaModel::documentation() const { return Documentation; }


    int ExportSVAntennaModel::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string ExportSVAntennaModel::antennaName() const
    {
      return parse_json<std::string>::parse(m_values["AntennaName"]);
    }

    void ExportSVAntennaModel::setAntennaName(const std::string& antennaName)
    {
      m_values.AddMember("AntennaName", parse_json<std::string>::format(antennaName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string ExportSVAntennaModel::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void ExportSVAntennaModel::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string ExportSVAntennaModel::filePath() const
    {
      return parse_json<std::string>::parse(m_values["FilePath"]);
    }

    void ExportSVAntennaModel::setFilePath(const std::string& filePath)
    {
      m_values.AddMember("FilePath", parse_json<std::string>::format(filePath, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool ExportSVAntennaModel::overwriting() const
    {
      return parse_json<bool>::parse(m_values["Overwriting"]);
    }

    void ExportSVAntennaModel::setOverwriting(bool overwriting)
    {
      m_values.AddMember("Overwriting", parse_json<bool>::format(overwriting, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

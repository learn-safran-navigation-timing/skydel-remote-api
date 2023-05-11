
#include "gen/ImportSVAntennaModel.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of ImportSVAntennaModel
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ImportSVAntennaModel::CmdName = "ImportSVAntennaModel";
    const char* const ImportSVAntennaModel::Documentation = "Import a space vehicle antenna model from a XML file.";

    REGISTER_COMMAND_FACTORY(ImportSVAntennaModel);


    ImportSVAntennaModel::ImportSVAntennaModel()
      : CommandBase(CmdName)
    {}

    ImportSVAntennaModel::ImportSVAntennaModel(const std::string& filePath, const std::string& system)
      : CommandBase(CmdName)
    {

      setFilePath(filePath);
      setSystem(system);
    }

    ImportSVAntennaModelPtr ImportSVAntennaModel::create(const std::string& filePath, const std::string& system)
    {
      return std::make_shared<ImportSVAntennaModel>(filePath, system);
    }

    ImportSVAntennaModelPtr ImportSVAntennaModel::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ImportSVAntennaModel>(ptr);
    }

    bool ImportSVAntennaModel::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["FilePath"])
          && parse_json<std::string>::is_valid(m_values["System"])
        ;

    }

    std::string ImportSVAntennaModel::documentation() const { return Documentation; }


    int ImportSVAntennaModel::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string ImportSVAntennaModel::filePath() const
    {
      return parse_json<std::string>::parse(m_values["FilePath"]);
    }

    void ImportSVAntennaModel::setFilePath(const std::string& filePath)
    {
      m_values.AddMember("FilePath", parse_json<std::string>::format(filePath, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string ImportSVAntennaModel::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void ImportSVAntennaModel::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

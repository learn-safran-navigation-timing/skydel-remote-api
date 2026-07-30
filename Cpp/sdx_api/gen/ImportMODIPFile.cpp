
#include "ImportMODIPFile.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of ImportMODIPFile
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ImportMODIPFile::CmdName = "ImportMODIPFile";
    const char* const ImportMODIPFile::Documentation = "Import MODIP data file.\n"
      "\n"
      "Name      Type            Description\n"
      "--------- --------------- --------------------------------------------------------------------------------------------------------------------------------------------------\n"
      "Path      string          File path.\n"
      "IonoModel optional string Ionospheric model, accepted values are \"NeQuick\" and \"NeQuick2-MLF2\". If no value is provided, the modification will be appllied to NeQuick model.";
    const char* const ImportMODIPFile::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(ImportMODIPFile);
    REGISTER_COMMAND_TO_FACTORY_IMPL(ImportMODIPFile);


    ImportMODIPFile::ImportMODIPFile()
      : CommandBase(CmdName, TargetId)
    {}

    ImportMODIPFile::ImportMODIPFile(const std::string& path, const std::optional<std::string>& ionoModel)
      : CommandBase(CmdName, TargetId)
    {

      setPath(path);
      setIonoModel(ionoModel);
    }

    ImportMODIPFilePtr ImportMODIPFile::create(const std::string& path, const std::optional<std::string>& ionoModel)
    {
      return std::make_shared<ImportMODIPFile>(path, ionoModel);
    }

    ImportMODIPFilePtr ImportMODIPFile::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ImportMODIPFile>(ptr);
    }

    bool ImportMODIPFile::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Path"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["IonoModel"])
        ;

    }

    std::string ImportMODIPFile::documentation() const { return Documentation; }

    const std::vector<std::string>& ImportMODIPFile::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Path", "IonoModel"}; 
      return names; 
    }


    int ImportMODIPFile::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string ImportMODIPFile::path() const
    {
      return parse_json<std::string>::parse(m_values["Path"]);
    }

    void ImportMODIPFile::setPath(const std::string& path)
    {
      setValue("Path", parse_json<std::string>::format(path, m_values.GetAllocator()));
    }



    std::optional<std::string> ImportMODIPFile::ionoModel() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["IonoModel"]);
    }

    void ImportMODIPFile::setIonoModel(const std::optional<std::string>& ionoModel)
    {
      setValue("IonoModel", parse_json<std::optional<std::string>>::format(ionoModel, m_values.GetAllocator()));
    }


  }
}

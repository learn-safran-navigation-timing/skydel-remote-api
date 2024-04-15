
#include "ImportCCIRFilesFromDirectory.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of ImportCCIRFilesFromDirectory
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ImportCCIRFilesFromDirectory::CmdName = "ImportCCIRFilesFromDirectory";
    const char* const ImportCCIRFilesFromDirectory::Documentation = "Import all the CCIR data files from the specified directory.\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ ---------------\n"
      "Path string Directory path.";
    const char* const ImportCCIRFilesFromDirectory::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(ImportCCIRFilesFromDirectory);
    REGISTER_COMMAND_TO_FACTORY_IMPL(ImportCCIRFilesFromDirectory);


    ImportCCIRFilesFromDirectory::ImportCCIRFilesFromDirectory()
      : CommandBase(CmdName, TargetId)
    {}

    ImportCCIRFilesFromDirectory::ImportCCIRFilesFromDirectory(const std::string& path)
      : CommandBase(CmdName, TargetId)
    {

      setPath(path);
    }

    ImportCCIRFilesFromDirectoryPtr ImportCCIRFilesFromDirectory::create(const std::string& path)
    {
      return std::make_shared<ImportCCIRFilesFromDirectory>(path);
    }

    ImportCCIRFilesFromDirectoryPtr ImportCCIRFilesFromDirectory::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ImportCCIRFilesFromDirectory>(ptr);
    }

    bool ImportCCIRFilesFromDirectory::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Path"])
        ;

    }

    std::string ImportCCIRFilesFromDirectory::documentation() const { return Documentation; }

    const std::vector<std::string>& ImportCCIRFilesFromDirectory::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Path"}; 
      return names; 
    }


    int ImportCCIRFilesFromDirectory::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string ImportCCIRFilesFromDirectory::path() const
    {
      return parse_json<std::string>::parse(m_values["Path"]);
    }

    void ImportCCIRFilesFromDirectory::setPath(const std::string& path)
    {
      m_values.AddMember("Path", parse_json<std::string>::format(path, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

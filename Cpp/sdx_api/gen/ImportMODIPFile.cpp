
#include "gen/ImportMODIPFile.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of ImportMODIPFile
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ImportMODIPFile::CmdName = "ImportMODIPFile";
    const char* const ImportMODIPFile::Documentation = "Import MODIP data file.";

    REGISTER_COMMAND_FACTORY(ImportMODIPFile);


    ImportMODIPFile::ImportMODIPFile()
      : CommandBase(CmdName)
    {}

    ImportMODIPFile::ImportMODIPFile(const std::string& path)
      : CommandBase(CmdName)
    {

      setPath(path);
    }

    ImportMODIPFilePtr ImportMODIPFile::create(const std::string& path)
    {
      return std::make_shared<ImportMODIPFile>(path);
    }

    ImportMODIPFilePtr ImportMODIPFile::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ImportMODIPFile>(ptr);
    }

    bool ImportMODIPFile::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Path"])
        ;

    }

    std::string ImportMODIPFile::documentation() const { return Documentation; }


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
      m_values.AddMember("Path", parse_json<std::string>::format(path, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

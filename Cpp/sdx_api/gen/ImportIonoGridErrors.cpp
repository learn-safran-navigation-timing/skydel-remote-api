
#include "gen/ImportIonoGridErrors.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of ImportIonoGridErrors
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ImportIonoGridErrors::CmdName = "ImportIonoGridErrors";
    const char* const ImportIonoGridErrors::Documentation = "Import ionospheric grid errors.";

    REGISTER_COMMAND_FACTORY(ImportIonoGridErrors);


    ImportIonoGridErrors::ImportIonoGridErrors()
      : CommandBase(CmdName)
    {}

    ImportIonoGridErrors::ImportIonoGridErrors(bool overwriting, const std::string& path)
      : CommandBase(CmdName)
    {

      setOverwriting(overwriting);
      setPath(path);
    }

    ImportIonoGridErrorsPtr ImportIonoGridErrors::create(bool overwriting, const std::string& path)
    {
      return std::make_shared<ImportIonoGridErrors>(overwriting, path);
    }

    ImportIonoGridErrorsPtr ImportIonoGridErrors::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ImportIonoGridErrors>(ptr);
    }

    bool ImportIonoGridErrors::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Overwriting"])
          && parse_json<std::string>::is_valid(m_values["Path"])
        ;

    }

    std::string ImportIonoGridErrors::documentation() const { return Documentation; }


    int ImportIonoGridErrors::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    bool ImportIonoGridErrors::overwriting() const
    {
      return parse_json<bool>::parse(m_values["Overwriting"]);
    }

    void ImportIonoGridErrors::setOverwriting(bool overwriting)
    {
      m_values.AddMember("Overwriting", parse_json<bool>::format(overwriting, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string ImportIonoGridErrors::path() const
    {
      return parse_json<std::string>::parse(m_values["Path"]);
    }

    void ImportIonoGridErrors::setPath(const std::string& path)
    {
      m_values.AddMember("Path", parse_json<std::string>::format(path, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

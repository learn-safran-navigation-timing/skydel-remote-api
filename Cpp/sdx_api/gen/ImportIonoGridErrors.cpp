
#include "ImportIonoGridErrors.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of ImportIonoGridErrors
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ImportIonoGridErrors::CmdName = "ImportIonoGridErrors";
    const char* const ImportIonoGridErrors::Documentation = "Import ionospheric grid errors.\n"
      "\n"
      "Name        Type   Description\n"
      "----------- ------ ------------------------------------\n"
      "Overwriting bool   Overwrite the previous grid if true.\n"
      "Path        string Grid file path";
    const char* const ImportIonoGridErrors::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(ImportIonoGridErrors);
    REGISTER_COMMAND_TO_FACTORY_IMPL(ImportIonoGridErrors);


    ImportIonoGridErrors::ImportIonoGridErrors()
      : CommandBase(CmdName, TargetId)
    {}

    ImportIonoGridErrors::ImportIonoGridErrors(bool overwriting, const std::string& path)
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& ImportIonoGridErrors::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Overwriting", "Path"}; 
      return names; 
    }


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

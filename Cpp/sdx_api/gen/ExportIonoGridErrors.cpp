
#include "ExportIonoGridErrors.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of ExportIonoGridErrors
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ExportIonoGridErrors::CmdName = "ExportIonoGridErrors";
    const char* const ExportIonoGridErrors::Documentation = "Export ionospheric grid errors.\n"
      "\n"
      "Name        Type   Description\n"
      "----------- ------ -------------------------------\n"
      "Overwriting bool   Overwrite the old file if true.\n"
      "Path        string Grid file path";
    const char* const ExportIonoGridErrors::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(ExportIonoGridErrors);
    REGISTER_COMMAND_TO_FACTORY_IMPL(ExportIonoGridErrors);


    ExportIonoGridErrors::ExportIonoGridErrors()
      : CommandBase(CmdName, TargetId)
    {}

    ExportIonoGridErrors::ExportIonoGridErrors(bool overwriting, const std::string& path)
      : CommandBase(CmdName, TargetId)
    {

      setOverwriting(overwriting);
      setPath(path);
    }

    ExportIonoGridErrorsPtr ExportIonoGridErrors::create(bool overwriting, const std::string& path)
    {
      return std::make_shared<ExportIonoGridErrors>(overwriting, path);
    }

    ExportIonoGridErrorsPtr ExportIonoGridErrors::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ExportIonoGridErrors>(ptr);
    }

    bool ExportIonoGridErrors::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Overwriting"])
          && parse_json<std::string>::is_valid(m_values["Path"])
        ;

    }

    std::string ExportIonoGridErrors::documentation() const { return Documentation; }

    const std::vector<std::string>& ExportIonoGridErrors::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Overwriting", "Path"}; 
      return names; 
    }


    int ExportIonoGridErrors::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    bool ExportIonoGridErrors::overwriting() const
    {
      return parse_json<bool>::parse(m_values["Overwriting"]);
    }

    void ExportIonoGridErrors::setOverwriting(bool overwriting)
    {
      m_values.AddMember("Overwriting", parse_json<bool>::format(overwriting, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string ExportIonoGridErrors::path() const
    {
      return parse_json<std::string>::parse(m_values["Path"]);
    }

    void ExportIonoGridErrors::setPath(const std::string& path)
    {
      m_values.AddMember("Path", parse_json<std::string>::format(path, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}


#include "gen/ImportIonoParameters.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of ImportIonoParameters
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ImportIonoParameters::CmdName = "ImportIonoParameters";
    const char* const ImportIonoParameters::Documentation = "Import ionospheric parameters from a Rinex file.";

    REGISTER_COMMAND_FACTORY(ImportIonoParameters);


    ImportIonoParameters::ImportIonoParameters()
      : CommandBase(CmdName)
    {}

    ImportIonoParameters::ImportIonoParameters(const std::string& path, const Sdx::optional<std::string>& type)
      : CommandBase(CmdName)
    {

      setPath(path);
      setType(type);
    }

    ImportIonoParametersPtr ImportIonoParameters::create(const std::string& path, const Sdx::optional<std::string>& type)
    {
      return std::make_shared<ImportIonoParameters>(path, type);
    }

    ImportIonoParametersPtr ImportIonoParameters::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ImportIonoParameters>(ptr);
    }

    bool ImportIonoParameters::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Path"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["Type"])
        ;

    }

    std::string ImportIonoParameters::documentation() const { return Documentation; }


    int ImportIonoParameters::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string ImportIonoParameters::path() const
    {
      return parse_json<std::string>::parse(m_values["Path"]);
    }

    void ImportIonoParameters::setPath(const std::string& path)
    {
      m_values.AddMember("Path", parse_json<std::string>::format(path, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> ImportIonoParameters::type() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["Type"]);
    }

    void ImportIonoParameters::setType(const Sdx::optional<std::string>& type)
    {
      m_values.AddMember("Type", parse_json<Sdx::optional<std::string>>::format(type, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

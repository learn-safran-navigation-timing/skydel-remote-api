
#include "ImportIonoParameters.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of ImportIonoParameters
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ImportIonoParameters::CmdName = "ImportIonoParameters";
    const char* const ImportIonoParameters::Documentation = "Import ionospheric parameters from a Rinex file.\n"
      "\n"
      "Name Type            Description\n"
      "---- --------------- ------------------------------------------------------------------------------\n"
      "Path string          File path\n"
      "Type optional string Ionospheric parameters type: \"Klobuchar\" or \"BDGIM\". The default is Klobuchar.";
    const char* const ImportIonoParameters::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(ImportIonoParameters);
    REGISTER_COMMAND_TO_FACTORY_IMPL(ImportIonoParameters);


    ImportIonoParameters::ImportIonoParameters()
      : CommandBase(CmdName, TargetId)
    {}

    ImportIonoParameters::ImportIonoParameters(const std::string& path, const Sdx::optional<std::string>& type)
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& ImportIonoParameters::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Path", "Type"}; 
      return names; 
    }


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

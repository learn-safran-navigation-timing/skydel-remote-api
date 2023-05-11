
#include "gen/ImportGlonassAlmanac.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of ImportGlonassAlmanac
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ImportGlonassAlmanac::CmdName = "ImportGlonassAlmanac";
    const char* const ImportGlonassAlmanac::Documentation = "Import GLONASS almanac file";

    REGISTER_COMMAND_FACTORY(ImportGlonassAlmanac);


    ImportGlonassAlmanac::ImportGlonassAlmanac()
      : CommandBase(CmdName)
    {}

    ImportGlonassAlmanac::ImportGlonassAlmanac(const std::string& path)
      : CommandBase(CmdName)
    {

      setPath(path);
    }

    ImportGlonassAlmanacPtr ImportGlonassAlmanac::create(const std::string& path)
    {
      return std::make_shared<ImportGlonassAlmanac>(path);
    }

    ImportGlonassAlmanacPtr ImportGlonassAlmanac::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ImportGlonassAlmanac>(ptr);
    }

    bool ImportGlonassAlmanac::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Path"])
        ;

    }

    std::string ImportGlonassAlmanac::documentation() const { return Documentation; }


    int ImportGlonassAlmanac::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string ImportGlonassAlmanac::path() const
    {
      return parse_json<std::string>::parse(m_values["Path"]);
    }

    void ImportGlonassAlmanac::setPath(const std::string& path)
    {
      m_values.AddMember("Path", parse_json<std::string>::format(path, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

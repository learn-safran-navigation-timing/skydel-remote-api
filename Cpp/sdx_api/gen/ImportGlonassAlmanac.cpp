
#include "ImportGlonassAlmanac.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of ImportGlonassAlmanac
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ImportGlonassAlmanac::CmdName = "ImportGlonassAlmanac";
    const char* const ImportGlonassAlmanac::Documentation = "Import GLONASS almanac file\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ -----------------\n"
      "Path string Almanac file path";
    const char* const ImportGlonassAlmanac::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(ImportGlonassAlmanac);
    REGISTER_COMMAND_TO_FACTORY_IMPL(ImportGlonassAlmanac);


    ImportGlonassAlmanac::ImportGlonassAlmanac()
      : CommandBase(CmdName, TargetId)
    {}

    ImportGlonassAlmanac::ImportGlonassAlmanac(const std::string& path)
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& ImportGlonassAlmanac::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Path"}; 
      return names; 
    }


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

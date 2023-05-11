
#include "gen/ImportIonoGridGIVEI.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of ImportIonoGridGIVEI
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ImportIonoGridGIVEI::CmdName = "ImportIonoGridGIVEI";
    const char* const ImportIonoGridGIVEI::Documentation = "Import ionospheric grid GIVEI.";

    REGISTER_COMMAND_FACTORY(ImportIonoGridGIVEI);


    ImportIonoGridGIVEI::ImportIonoGridGIVEI()
      : CommandBase(CmdName)
    {}

    ImportIonoGridGIVEI::ImportIonoGridGIVEI(bool overwriting, const std::string& path, const Sdx::optional<std::string>& serviceProvider)
      : CommandBase(CmdName)
    {

      setOverwriting(overwriting);
      setPath(path);
      setServiceProvider(serviceProvider);
    }

    ImportIonoGridGIVEIPtr ImportIonoGridGIVEI::create(bool overwriting, const std::string& path, const Sdx::optional<std::string>& serviceProvider)
    {
      return std::make_shared<ImportIonoGridGIVEI>(overwriting, path, serviceProvider);
    }

    ImportIonoGridGIVEIPtr ImportIonoGridGIVEI::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ImportIonoGridGIVEI>(ptr);
    }

    bool ImportIonoGridGIVEI::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Overwriting"])
          && parse_json<std::string>::is_valid(m_values["Path"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["ServiceProvider"])
        ;

    }

    std::string ImportIonoGridGIVEI::documentation() const { return Documentation; }


    int ImportIonoGridGIVEI::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    bool ImportIonoGridGIVEI::overwriting() const
    {
      return parse_json<bool>::parse(m_values["Overwriting"]);
    }

    void ImportIonoGridGIVEI::setOverwriting(bool overwriting)
    {
      m_values.AddMember("Overwriting", parse_json<bool>::format(overwriting, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string ImportIonoGridGIVEI::path() const
    {
      return parse_json<std::string>::parse(m_values["Path"]);
    }

    void ImportIonoGridGIVEI::setPath(const std::string& path)
    {
      m_values.AddMember("Path", parse_json<std::string>::format(path, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> ImportIonoGridGIVEI::serviceProvider() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["ServiceProvider"]);
    }

    void ImportIonoGridGIVEI::setServiceProvider(const Sdx::optional<std::string>& serviceProvider)
    {
      m_values.AddMember("ServiceProvider", parse_json<Sdx::optional<std::string>>::format(serviceProvider, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}


#include "ImportIonoGridGIVEI.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of ImportIonoGridGIVEI
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ImportIonoGridGIVEI::CmdName = "ImportIonoGridGIVEI";
    const char* const ImportIonoGridGIVEI::Documentation = "Import ionospheric grid GIVEI.\n"
      "\n"
      "Name            Type            Description\n"
      "--------------- --------------- ------------------------------------\n"
      "Overwriting     bool            Overwrite the previous grid if true.\n"
      "Path            string          Grid file path\n"
      "ServiceProvider optional string The service provider (optional)";
    const char* const ImportIonoGridGIVEI::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(ImportIonoGridGIVEI);
    REGISTER_COMMAND_TO_FACTORY_IMPL(ImportIonoGridGIVEI);


    ImportIonoGridGIVEI::ImportIonoGridGIVEI()
      : CommandBase(CmdName, TargetId)
    {}

    ImportIonoGridGIVEI::ImportIonoGridGIVEI(bool overwriting, const std::string& path, const std::optional<std::string>& serviceProvider)
      : CommandBase(CmdName, TargetId)
    {

      setOverwriting(overwriting);
      setPath(path);
      setServiceProvider(serviceProvider);
    }

    ImportIonoGridGIVEIPtr ImportIonoGridGIVEI::create(bool overwriting, const std::string& path, const std::optional<std::string>& serviceProvider)
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
          && parse_json<std::optional<std::string>>::is_valid(m_values["ServiceProvider"])
        ;

    }

    std::string ImportIonoGridGIVEI::documentation() const { return Documentation; }

    const std::vector<std::string>& ImportIonoGridGIVEI::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Overwriting", "Path", "ServiceProvider"}; 
      return names; 
    }


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



    std::optional<std::string> ImportIonoGridGIVEI::serviceProvider() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["ServiceProvider"]);
    }

    void ImportIonoGridGIVEI::setServiceProvider(const std::optional<std::string>& serviceProvider)
    {
      m_values.AddMember("ServiceProvider", parse_json<std::optional<std::string>>::format(serviceProvider, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

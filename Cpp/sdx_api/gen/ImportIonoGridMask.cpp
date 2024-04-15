
#include "ImportIonoGridMask.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of ImportIonoGridMask
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ImportIonoGridMask::CmdName = "ImportIonoGridMask";
    const char* const ImportIonoGridMask::Documentation = "Import ionospheric grid mask for a giver service provider.\n"
      "\n"
      "Name            Type   Description\n"
      "--------------- ------ ------------------------------------\n"
      "ServiceProvider string The service provider\n"
      "Overwriting     bool   Overwrite the previous mask if true.\n"
      "Path            string Grid file path";
    const char* const ImportIonoGridMask::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(ImportIonoGridMask);
    REGISTER_COMMAND_TO_FACTORY_IMPL(ImportIonoGridMask);


    ImportIonoGridMask::ImportIonoGridMask()
      : CommandBase(CmdName, TargetId)
    {}

    ImportIonoGridMask::ImportIonoGridMask(const std::string& serviceProvider, bool overwriting, const std::string& path)
      : CommandBase(CmdName, TargetId)
    {

      setServiceProvider(serviceProvider);
      setOverwriting(overwriting);
      setPath(path);
    }

    ImportIonoGridMaskPtr ImportIonoGridMask::create(const std::string& serviceProvider, bool overwriting, const std::string& path)
    {
      return std::make_shared<ImportIonoGridMask>(serviceProvider, overwriting, path);
    }

    ImportIonoGridMaskPtr ImportIonoGridMask::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ImportIonoGridMask>(ptr);
    }

    bool ImportIonoGridMask::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ServiceProvider"])
          && parse_json<bool>::is_valid(m_values["Overwriting"])
          && parse_json<std::string>::is_valid(m_values["Path"])
        ;

    }

    std::string ImportIonoGridMask::documentation() const { return Documentation; }

    const std::vector<std::string>& ImportIonoGridMask::fieldNames() const 
    { 
      static const std::vector<std::string> names {"ServiceProvider", "Overwriting", "Path"}; 
      return names; 
    }


    int ImportIonoGridMask::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string ImportIonoGridMask::serviceProvider() const
    {
      return parse_json<std::string>::parse(m_values["ServiceProvider"]);
    }

    void ImportIonoGridMask::setServiceProvider(const std::string& serviceProvider)
    {
      m_values.AddMember("ServiceProvider", parse_json<std::string>::format(serviceProvider, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool ImportIonoGridMask::overwriting() const
    {
      return parse_json<bool>::parse(m_values["Overwriting"]);
    }

    void ImportIonoGridMask::setOverwriting(bool overwriting)
    {
      m_values.AddMember("Overwriting", parse_json<bool>::format(overwriting, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string ImportIonoGridMask::path() const
    {
      return parse_json<std::string>::parse(m_values["Path"]);
    }

    void ImportIonoGridMask::setPath(const std::string& path)
    {
      m_values.AddMember("Path", parse_json<std::string>::format(path, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

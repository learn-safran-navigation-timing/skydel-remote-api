
#include "ExportIonoGridMask.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of ExportIonoGridMask
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ExportIonoGridMask::CmdName = "ExportIonoGridMask";
    const char* const ExportIonoGridMask::Documentation = "Export ionospheric grid mask for a given service provider.\n"
      "\n"
      "Name            Type   Description\n"
      "--------------- ------ -------------------------------\n"
      "ServiceProvider string The service provider\n"
      "Overwriting     bool   Overwrite the old file if true.\n"
      "Path            string Grid file path";
    const char* const ExportIonoGridMask::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(ExportIonoGridMask);
    REGISTER_COMMAND_TO_FACTORY_IMPL(ExportIonoGridMask);


    ExportIonoGridMask::ExportIonoGridMask()
      : CommandBase(CmdName, TargetId)
    {}

    ExportIonoGridMask::ExportIonoGridMask(const std::string& serviceProvider, bool overwriting, const std::string& path)
      : CommandBase(CmdName, TargetId)
    {

      setServiceProvider(serviceProvider);
      setOverwriting(overwriting);
      setPath(path);
    }

    ExportIonoGridMaskPtr ExportIonoGridMask::create(const std::string& serviceProvider, bool overwriting, const std::string& path)
    {
      return std::make_shared<ExportIonoGridMask>(serviceProvider, overwriting, path);
    }

    ExportIonoGridMaskPtr ExportIonoGridMask::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ExportIonoGridMask>(ptr);
    }

    bool ExportIonoGridMask::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ServiceProvider"])
          && parse_json<bool>::is_valid(m_values["Overwriting"])
          && parse_json<std::string>::is_valid(m_values["Path"])
        ;

    }

    std::string ExportIonoGridMask::documentation() const { return Documentation; }

    const std::vector<std::string>& ExportIonoGridMask::fieldNames() const 
    { 
      static const std::vector<std::string> names {"ServiceProvider", "Overwriting", "Path"}; 
      return names; 
    }


    int ExportIonoGridMask::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string ExportIonoGridMask::serviceProvider() const
    {
      return parse_json<std::string>::parse(m_values["ServiceProvider"]);
    }

    void ExportIonoGridMask::setServiceProvider(const std::string& serviceProvider)
    {
      m_values.AddMember("ServiceProvider", parse_json<std::string>::format(serviceProvider, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool ExportIonoGridMask::overwriting() const
    {
      return parse_json<bool>::parse(m_values["Overwriting"]);
    }

    void ExportIonoGridMask::setOverwriting(bool overwriting)
    {
      m_values.AddMember("Overwriting", parse_json<bool>::format(overwriting, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string ExportIonoGridMask::path() const
    {
      return parse_json<std::string>::parse(m_values["Path"]);
    }

    void ExportIonoGridMask::setPath(const std::string& path)
    {
      m_values.AddMember("Path", parse_json<std::string>::format(path, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

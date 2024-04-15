
#include "SaveAs.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SaveAs
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SaveAs::CmdName = "SaveAs";
    const char* const SaveAs::Documentation = "Save configuration with new name.\n"
      "\n"
      "Name      Type   Description\n"
      "--------- ------ ---------------------------------------------------------------------------------------------------------\n"
      "Path      string Configuration path. Automatically add file suffix if missing. If folder not defined, user default folder.\n"
      "Overwrite bool   Overwrite existing configuration if is exists";
    const char* const SaveAs::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SaveAs);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SaveAs);


    SaveAs::SaveAs()
      : CommandBase(CmdName, TargetId)
    {}

    SaveAs::SaveAs(const std::string& path, bool overwrite)
      : CommandBase(CmdName, TargetId)
    {

      setPath(path);
      setOverwrite(overwrite);
    }

    SaveAsPtr SaveAs::create(const std::string& path, bool overwrite)
    {
      return std::make_shared<SaveAs>(path, overwrite);
    }

    SaveAsPtr SaveAs::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SaveAs>(ptr);
    }

    bool SaveAs::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Path"])
          && parse_json<bool>::is_valid(m_values["Overwrite"])
        ;

    }

    std::string SaveAs::documentation() const { return Documentation; }

    const std::vector<std::string>& SaveAs::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Path", "Overwrite"}; 
      return names; 
    }


    int SaveAs::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SaveAs::path() const
    {
      return parse_json<std::string>::parse(m_values["Path"]);
    }

    void SaveAs::setPath(const std::string& path)
    {
      m_values.AddMember("Path", parse_json<std::string>::format(path, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SaveAs::overwrite() const
    {
      return parse_json<bool>::parse(m_values["Overwrite"]);
    }

    void SaveAs::setOverwrite(bool overwrite)
    {
      m_values.AddMember("Overwrite", parse_json<bool>::format(overwrite, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

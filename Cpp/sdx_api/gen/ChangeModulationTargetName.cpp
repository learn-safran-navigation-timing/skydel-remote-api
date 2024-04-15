
#include "ChangeModulationTargetName.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of ChangeModulationTargetName
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ChangeModulationTargetName::CmdName = "ChangeModulationTargetName";
    const char* const ChangeModulationTargetName::Documentation = "Change the modulation target name. The name is only used for display purpose.\n"
      "\n"
      "Name       Type   Description\n"
      "---------- ------ -----------------\n"
      "TargetName string New target name\n"
      "Id         string Target identifier";
    const char* const ChangeModulationTargetName::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(ChangeModulationTargetName);
    REGISTER_COMMAND_TO_FACTORY_IMPL(ChangeModulationTargetName);


    ChangeModulationTargetName::ChangeModulationTargetName()
      : CommandBase(CmdName, TargetId)
    {}

    ChangeModulationTargetName::ChangeModulationTargetName(const std::string& targetName, const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setTargetName(targetName);
      setId(id);
    }

    ChangeModulationTargetNamePtr ChangeModulationTargetName::create(const std::string& targetName, const std::string& id)
    {
      return std::make_shared<ChangeModulationTargetName>(targetName, id);
    }

    ChangeModulationTargetNamePtr ChangeModulationTargetName::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ChangeModulationTargetName>(ptr);
    }

    bool ChangeModulationTargetName::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["TargetName"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string ChangeModulationTargetName::documentation() const { return Documentation; }

    const std::vector<std::string>& ChangeModulationTargetName::fieldNames() const 
    { 
      static const std::vector<std::string> names {"TargetName", "Id"}; 
      return names; 
    }


    int ChangeModulationTargetName::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string ChangeModulationTargetName::targetName() const
    {
      return parse_json<std::string>::parse(m_values["TargetName"]);
    }

    void ChangeModulationTargetName::setTargetName(const std::string& targetName)
    {
      m_values.AddMember("TargetName", parse_json<std::string>::format(targetName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string ChangeModulationTargetName::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void ChangeModulationTargetName::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

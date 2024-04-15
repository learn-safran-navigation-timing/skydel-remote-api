
#include "RemoveModulationTarget.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of RemoveModulationTarget
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const RemoveModulationTarget::CmdName = "RemoveModulationTarget";
    const char* const RemoveModulationTarget::Documentation = "Remove a modulation target.\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ -----------------\n"
      "Id   string Target identifier";
    const char* const RemoveModulationTarget::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(RemoveModulationTarget);
    REGISTER_COMMAND_TO_FACTORY_IMPL(RemoveModulationTarget);


    RemoveModulationTarget::RemoveModulationTarget()
      : CommandBase(CmdName, TargetId)
    {}

    RemoveModulationTarget::RemoveModulationTarget(const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setId(id);
    }

    RemoveModulationTargetPtr RemoveModulationTarget::create(const std::string& id)
    {
      return std::make_shared<RemoveModulationTarget>(id);
    }

    RemoveModulationTargetPtr RemoveModulationTarget::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<RemoveModulationTarget>(ptr);
    }

    bool RemoveModulationTarget::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string RemoveModulationTarget::documentation() const { return Documentation; }

    const std::vector<std::string>& RemoveModulationTarget::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Id"}; 
      return names; 
    }


    int RemoveModulationTarget::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string RemoveModulationTarget::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void RemoveModulationTarget::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

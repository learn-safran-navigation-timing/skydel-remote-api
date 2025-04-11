
#include "RemoveInterference.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of RemoveInterference
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const RemoveInterference::CmdName = "RemoveInterference";
    const char* const RemoveInterference::Documentation = "Removes a specific interference signal.\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ -------------------------------------------------------\n"
      "Id   string Unique identifier of the interference signal to remove.";
    const char* const RemoveInterference::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(RemoveInterference);
    REGISTER_COMMAND_TO_FACTORY_IMPL(RemoveInterference);


    RemoveInterference::RemoveInterference()
      : CommandBase(CmdName, TargetId)
    {}

    RemoveInterference::RemoveInterference(const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setId(id);
    }

    RemoveInterferencePtr RemoveInterference::create(const std::string& id)
    {
      return std::make_shared<RemoveInterference>(id);
    }

    RemoveInterferencePtr RemoveInterference::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<RemoveInterference>(ptr);
    }

    bool RemoveInterference::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string RemoveInterference::documentation() const { return Documentation; }

    const std::vector<std::string>& RemoveInterference::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Id"}; 
      return names; 
    }


    int RemoveInterference::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string RemoveInterference::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void RemoveInterference::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

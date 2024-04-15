
#include "RemoveCustomSignal.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of RemoveCustomSignal
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const RemoveCustomSignal::CmdName = "RemoveCustomSignal";
    const char* const RemoveCustomSignal::Documentation = "Removes the custom signal with the given ID\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ ----------------\n"
      "Id   string Custom signal ID";
    const char* const RemoveCustomSignal::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(RemoveCustomSignal);
    REGISTER_COMMAND_TO_FACTORY_IMPL(RemoveCustomSignal);


    RemoveCustomSignal::RemoveCustomSignal()
      : CommandBase(CmdName, TargetId)
    {}

    RemoveCustomSignal::RemoveCustomSignal(const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setId(id);
    }

    RemoveCustomSignalPtr RemoveCustomSignal::create(const std::string& id)
    {
      return std::make_shared<RemoveCustomSignal>(id);
    }

    RemoveCustomSignalPtr RemoveCustomSignal::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<RemoveCustomSignal>(ptr);
    }

    bool RemoveCustomSignal::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string RemoveCustomSignal::documentation() const { return Documentation; }

    const std::vector<std::string>& RemoveCustomSignal::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Id"}; 
      return names; 
    }


    int RemoveCustomSignal::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string RemoveCustomSignal::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void RemoveCustomSignal::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

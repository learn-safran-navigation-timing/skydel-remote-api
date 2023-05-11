
#include "gen/RemoveMessageModification.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of RemoveMessageModification
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const RemoveMessageModification::CmdName = "RemoveMessageModification";
    const char* const RemoveMessageModification::Documentation = "Please note the command RemoveMessageModification is deprecated since 21.3. You may use RemoveMessageModificationForSignal.\n\nRemoves the signal for the message modification.";

    REGISTER_COMMAND_FACTORY(RemoveMessageModification);


    RemoveMessageModification::RemoveMessageModification()
      : CommandBase(CmdName)
    {}

    RemoveMessageModification::RemoveMessageModification(const std::string& signal, const std::string& id)
      : CommandBase(CmdName)
    {

      setSignal(signal);
      setId(id);
    }

    RemoveMessageModificationPtr RemoveMessageModification::create(const std::string& signal, const std::string& id)
    {
      return std::make_shared<RemoveMessageModification>(signal, id);
    }

    RemoveMessageModificationPtr RemoveMessageModification::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<RemoveMessageModification>(ptr);
    }

    bool RemoveMessageModification::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Signal"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string RemoveMessageModification::documentation() const { return Documentation; }


    int RemoveMessageModification::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string RemoveMessageModification::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void RemoveMessageModification::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string RemoveMessageModification::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void RemoveMessageModification::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

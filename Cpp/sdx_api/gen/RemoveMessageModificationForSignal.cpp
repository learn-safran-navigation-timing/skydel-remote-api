
#include "gen/RemoveMessageModificationForSignal.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of RemoveMessageModificationForSignal
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const RemoveMessageModificationForSignal::CmdName = "RemoveMessageModificationForSignal";
    const char* const RemoveMessageModificationForSignal::Documentation = "Removes the signal for the message modification.";

    REGISTER_COMMAND_FACTORY(RemoveMessageModificationForSignal);


    RemoveMessageModificationForSignal::RemoveMessageModificationForSignal()
      : CommandBase(CmdName)
    {}

    RemoveMessageModificationForSignal::RemoveMessageModificationForSignal(const std::string& signal, const std::string& id)
      : CommandBase(CmdName)
    {

      setSignal(signal);
      setId(id);
    }

    RemoveMessageModificationForSignalPtr RemoveMessageModificationForSignal::create(const std::string& signal, const std::string& id)
    {
      return std::make_shared<RemoveMessageModificationForSignal>(signal, id);
    }

    RemoveMessageModificationForSignalPtr RemoveMessageModificationForSignal::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<RemoveMessageModificationForSignal>(ptr);
    }

    bool RemoveMessageModificationForSignal::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Signal"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string RemoveMessageModificationForSignal::documentation() const { return Documentation; }


    int RemoveMessageModificationForSignal::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string RemoveMessageModificationForSignal::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void RemoveMessageModificationForSignal::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string RemoveMessageModificationForSignal::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void RemoveMessageModificationForSignal::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

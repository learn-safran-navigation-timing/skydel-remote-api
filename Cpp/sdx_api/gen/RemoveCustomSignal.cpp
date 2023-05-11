
#include "gen/RemoveCustomSignal.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of RemoveCustomSignal
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const RemoveCustomSignal::CmdName = "RemoveCustomSignal";
    const char* const RemoveCustomSignal::Documentation = "Removes the custom signal with the given ID";

    REGISTER_COMMAND_FACTORY(RemoveCustomSignal);


    RemoveCustomSignal::RemoveCustomSignal()
      : CommandBase(CmdName)
    {}

    RemoveCustomSignal::RemoveCustomSignal(const std::string& id)
      : CommandBase(CmdName)
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

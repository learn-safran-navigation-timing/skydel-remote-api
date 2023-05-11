
#include "gen/RemoveAntennaChange.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of RemoveAntennaChange
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const RemoveAntennaChange::CmdName = "RemoveAntennaChange";
    const char* const RemoveAntennaChange::Documentation = "Removes an antenna change.";

    REGISTER_COMMAND_FACTORY(RemoveAntennaChange);


    RemoveAntennaChange::RemoveAntennaChange()
      : CommandBase(CmdName)
    {}

    RemoveAntennaChange::RemoveAntennaChange(const std::string& id)
      : CommandBase(CmdName)
    {

      setId(id);
    }

    RemoveAntennaChangePtr RemoveAntennaChange::create(const std::string& id)
    {
      return std::make_shared<RemoveAntennaChange>(id);
    }

    RemoveAntennaChangePtr RemoveAntennaChange::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<RemoveAntennaChange>(ptr);
    }

    bool RemoveAntennaChange::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string RemoveAntennaChange::documentation() const { return Documentation; }


    int RemoveAntennaChange::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string RemoveAntennaChange::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void RemoveAntennaChange::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

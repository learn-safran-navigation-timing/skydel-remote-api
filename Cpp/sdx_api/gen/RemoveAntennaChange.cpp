
#include "RemoveAntennaChange.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of RemoveAntennaChange
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const RemoveAntennaChange::CmdName = "RemoveAntennaChange";
    const char* const RemoveAntennaChange::Documentation = "Removes an antenna change.\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ -------------------------------------\n"
      "Id   string Unique identifier (see AntennaChange)";
    const char* const RemoveAntennaChange::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(RemoveAntennaChange);
    REGISTER_COMMAND_TO_FACTORY_IMPL(RemoveAntennaChange);


    RemoveAntennaChange::RemoveAntennaChange()
      : CommandBase(CmdName, TargetId)
    {}

    RemoveAntennaChange::RemoveAntennaChange(const std::string& id)
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& RemoveAntennaChange::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Id"}; 
      return names; 
    }


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


#include "gen/CommandGroup.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of CommandGroup
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const CommandGroup::CmdName = "CommandGroup";
    const char* const CommandGroup::Documentation = "Group multiple commands as one";

    REGISTER_COMMAND_FACTORY(CommandGroup);


    CommandGroup::CommandGroup()
      : CommandBase(CmdName)
    {}

    CommandGroup::CommandGroup(const std::vector<Sdx::CommandBasePtr>& commands)
      : CommandBase(CmdName)
    {

      setCommands(commands);
    }

    CommandGroupPtr CommandGroup::create(const std::vector<Sdx::CommandBasePtr>& commands)
    {
      return std::make_shared<CommandGroup>(commands);
    }

    CommandGroupPtr CommandGroup::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<CommandGroup>(ptr);
    }

    bool CommandGroup::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<Sdx::CommandBasePtr>>::is_valid(m_values["Commands"])
        ;

    }

    std::string CommandGroup::documentation() const { return Documentation; }


    int CommandGroup::executePermission() const
    {
      return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }


    std::vector<Sdx::CommandBasePtr> CommandGroup::commands() const
    {
      return parse_json<std::vector<Sdx::CommandBasePtr>>::parse(m_values["Commands"]);
    }

    void CommandGroup::setCommands(const std::vector<Sdx::CommandBasePtr>& commands)
    {
      m_values.AddMember("Commands", parse_json<std::vector<Sdx::CommandBasePtr>>::format(commands, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

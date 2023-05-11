
#include "gen/PlugInCommand.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of PlugInCommand
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const PlugInCommand::CmdName = "PlugInCommand";
    const char* const PlugInCommand::Documentation = "Sends a command to a plug-in instance.";

    REGISTER_COMMAND_FACTORY(PlugInCommand);


    PlugInCommand::PlugInCommand()
      : CommandBase(CmdName)
    {}

    PlugInCommand::PlugInCommand(const std::string& name, const std::string& command)
      : CommandBase(CmdName)
    {

      setName(name);
      setCommand(command);
    }

    PlugInCommandPtr PlugInCommand::create(const std::string& name, const std::string& command)
    {
      return std::make_shared<PlugInCommand>(name, command);
    }

    PlugInCommandPtr PlugInCommand::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<PlugInCommand>(ptr);
    }

    bool PlugInCommand::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Name"])
          && parse_json<std::string>::is_valid(m_values["Command"])
        ;

    }

    std::string PlugInCommand::documentation() const { return Documentation; }


    int PlugInCommand::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    std::string PlugInCommand::name() const
    {
      return parse_json<std::string>::parse(m_values["Name"]);
    }

    void PlugInCommand::setName(const std::string& name)
    {
      m_values.AddMember("Name", parse_json<std::string>::format(name, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string PlugInCommand::command() const
    {
      return parse_json<std::string>::parse(m_values["Command"]);
    }

    void PlugInCommand::setCommand(const std::string& command)
    {
      m_values.AddMember("Command", parse_json<std::string>::format(command, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

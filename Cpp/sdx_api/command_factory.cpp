#include "command_factory.h"

#include <iostream>
#include <map>

#include "rapidjson/document.h"

namespace Sdx
{

struct CommandFactory::Pimpl
{
  typedef std::map<std::string, FactoryFunction> FactoryMap;
  FactoryMap factory;
};

CommandFactory* CommandFactory::instance()
{
  static CommandFactory uniqueInstance;
  return &uniqueInstance;
}

CommandFactory::CommandFactory()
{
  m = new Pimpl;
}

CommandFactory::~CommandFactory()
{
  delete m;
  m = 0;
}

CommandBasePtr CommandFactory::createCommand(const std::string& serializedCommand, std::string* errorMsg)
{
  if (errorMsg)
    errorMsg->clear();

  rapidjson::Document doc;
  if (!Sdx::CommandBase::parse(serializedCommand, doc, errorMsg))
  {
    return CommandBasePtr();
  }
  std::string cmdName = doc[Sdx::CommandBase::CmdNameKey.c_str()].GetString();

  if (m->factory.find(cmdName) != m->factory.end())
  {
    FactoryFunction fct = m->factory[cmdName];
    CommandBasePtr cmd = (*fct)();
    cmd->m_values.CopyFrom(doc, cmd->m_values.GetAllocator());
    rapidjson::Value& uuidValue = doc[CommandBase::CmdUuidKey.c_str()];
    cmd->m_cmdUuid = uuidValue.GetString();
    rapidjson::Value newValue;
    newValue.SetString(cmd->m_cmdUuid.c_str(),
                       (rapidjson::SizeType)cmd->m_cmdUuid.size(),
                       cmd->m_values.GetAllocator());
    cmd->setValue(CommandBase::CmdUuidKey, newValue);
    if (cmd->isValid())
    {
      return cmd;
    }
    if (errorMsg)
      *errorMsg = "Invalid command: " + serializedCommand;
  }
  else
  {
    if (errorMsg)
      *errorMsg = "Factory function not found for " + cmdName;
  }
  return CommandBasePtr();
}

void CommandFactory::registerFactoryFunction(const std::string& cmdName, CommandFactory::FactoryFunction fct)
{
  if (m->factory.find(cmdName) == m->factory.end())
  {
    m->factory[cmdName] = fct;
  }
  else
  {
    std::cout << "Can't register factory function for command " << cmdName
              << " because a function is already registered." << std::endl;
  }
}

} // namespace Sdx

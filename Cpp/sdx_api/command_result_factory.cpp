#include "command_result_factory.h"
#include <map>
#include <iostream>
#include "rapidjson/document.h"
#include "command_factory.h"

namespace Sdx
{

struct CommandResultFactory::Pimpl
{
  typedef std::map<std::string, FactoryFunction> FactoryMap;
  FactoryMap factory;
};

CommandResultFactory* CommandResultFactory::instance()
{
  static CommandResultFactory uniqueInstance;
  return &uniqueInstance;
}

CommandResultFactory::CommandResultFactory()
{
  m = new Pimpl;
}

CommandResultFactory::~CommandResultFactory()
{
  delete m;
  m = 0;
}

CommandResultPtr CommandResultFactory::createCommandResult(const std::string& serializedCommand, std::string* errorMsg)
{
  if (errorMsg)
    errorMsg->clear();

  rapidjson::Document doc;
  if (!Sdx::CommandBase::parse(serializedCommand, doc, errorMsg))
  {
    return CommandResultPtr();
  }
  std::string cmdName = doc[Sdx::CommandBase::CmdNameKey.c_str()].GetString();

  if (m->factory.find(cmdName) != m->factory.end())
  {
    FactoryFunction fct = m->factory[cmdName];
    CommandResultPtr result = (*fct)();
    result->m_values.CopyFrom(doc, result->m_values.GetAllocator());
    rapidjson::Value& uuidValue = doc[CommandBase::CmdUuidKey.c_str()];
    result->m_cmdUuid = uuidValue.GetString();
    rapidjson::Value newValue;
    newValue.SetString(result->m_cmdUuid.c_str(), (rapidjson::SizeType) result->m_cmdUuid.size(), result->m_values.GetAllocator());
    result->setValue(CommandBase::CmdUuidKey, newValue);
    result->m_relatedCommand = CommandFactory::instance()->createCommand(
      result->value(CommandResult::RelatedCommand).GetString(), errorMsg);
    if(!result->m_relatedCommand)
    {
      return CommandResultPtr();
    }
    if (result->isValid())
    {
      return result;
    }
    if (errorMsg)
      *errorMsg = "Invalid command: " + serializedCommand;
  }
  else
  {
    if (errorMsg)
      *errorMsg = "Factory function not found for " + cmdName;
  }
  return CommandResultPtr();
}

void CommandResultFactory::registerFactoryFunction(const std::string &cmdName, CommandResultFactory::FactoryFunction fct)
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

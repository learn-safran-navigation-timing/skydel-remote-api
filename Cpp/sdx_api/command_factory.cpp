#include "command_factory.h"

#include <rapidjson/document.h>

#include <iostream>
#include <unordered_map>

#include "command_base.h"
#include "command_result.h"

namespace Sdx
{

struct CommandFactory::Pimpl
{
  using FactoryMap = std::unordered_map<std::string, FactoryFunction>;
  using TargetFactoryMap = std::unordered_map<std::string, FactoryMap>;

  const FactoryMap& getFactoryFromJson(const rapidjson::Document& doc)
  {
    if (doc.HasMember(CommandBase::CmdTargetIdKey.c_str()))
    {
      const std::string targetID = doc[CommandBase::CmdTargetIdKey.c_str()].GetString();

      if (const auto it = targetFactory.find(targetID); it != targetFactory.end())
      {
        return it->second;
      }
    }

    return factory;
  }

  FactoryMap factory;
  TargetFactoryMap targetFactory;
};

CommandFactory* CommandFactory::instance()
{
  static CommandFactory uniqueInstance;
  return &uniqueInstance;
}

CommandFactory::CommandFactory() : m(std::make_unique<Pimpl>())
{
}

CommandFactory::~CommandFactory() = default;

CommandBasePtr CommandFactory::createCommand(const std::string& serializedCommand, std::string* errorMsg)
{
  if (errorMsg)
  {
    errorMsg->clear();
  }

  rapidjson::Document doc;
  if (!CommandBase::parse(serializedCommand, doc, errorMsg))
  {
    return nullptr;
  }

  const auto& factory = m->getFactoryFromJson(doc);
  const std::string cmdName = doc[CommandBase::CmdNameKey.c_str()].GetString();

  if (const auto it = factory.find(cmdName); it != m->factory.end())
  {
    auto cmd = it->second();
    cmd->m_values.CopyFrom(doc, cmd->m_values.GetAllocator());

    rapidjson::Value& uuidValue = doc[CommandBase::CmdUuidKey.c_str()];
    cmd->m_cmdUuid = uuidValue.GetString();

    rapidjson::Value newValue;
    newValue.SetString(cmd->m_cmdUuid.c_str(),
                       static_cast<rapidjson::SizeType>(cmd->m_cmdUuid.size()),
                       cmd->m_values.GetAllocator());
    cmd->setValue(CommandBase::CmdUuidKey, newValue);

    if (cmd->isValid())
    {
      return cmd;
    }

    if (errorMsg)
    {
      *errorMsg = "Invalid command: " + serializedCommand;
    }
  }
  else
  {
    if (errorMsg)
    {
      *errorMsg = "Factory function not found for " + cmdName;
    }
  }
  return nullptr;
}

CommandResultPtr CommandFactory::createCommandResult(const std::string& serializedCommand, std::string* errorMsg)
{
  if (auto result = CommandResult::dynamicCast(createCommand(serializedCommand, errorMsg)))
  {
    result->m_relatedCommand = createCommand(result->value(CommandResult::RelatedCommand).GetString(), errorMsg);

    if (result->m_relatedCommand)
    {
      return result;
    }
  }

  return nullptr;
}

void CommandFactory::registerFactoryFunction(const std::string& targetID,
                                             const std::string& cmdName,
                                             FactoryFunction fct)
{
  auto& factory = targetID.empty() ? m->factory : m->targetFactory[targetID];

  if (factory.find(cmdName) == factory.end())
  {
    factory[cmdName] = fct;
  }
  else
  {
    std::cout << "Can't register factory function for command " << cmdName
              << " because a function is already registered." << std::endl;
  }
}

} // namespace Sdx

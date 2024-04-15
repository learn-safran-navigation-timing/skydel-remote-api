#include "command_result.h"

#include <rapidjson/document.h>
#include <rapidjson/writer.h>

#include "date_time.h"

namespace Sdx
{
//
// Sdx::msg::CommandResult
//
const std::string CommandResult::RelatedCommand("RelatedCommand");

CommandResult::CommandResult(const std::string& cmdName, const std::string& targetId) : CommandBase(cmdName, targetId)
{
}

CommandResult::CommandResult(const std::string& cmdName, const std::string& targetId, CommandBasePtr relatedCmd) :
  CommandBase(cmdName, targetId),
  m_relatedCommand(relatedCmd)
{
  rapidjson::Value value;
  value.SetString(relatedCmd->toString().c_str(),
                  static_cast<rapidjson::SizeType>(relatedCmd->toString().size()),
                  m_values.GetAllocator());
  setValue(RelatedCommand, value);
}

bool CommandResult::isValid() const
{
  return value(RelatedCommand).IsString();
}

double CommandResult::timestamp() const
{
  return m_relatedCommand->timestamp();
}

Sdx::DateTime CommandResult::gpsTimestamp() const
{
  return m_relatedCommand->gpsTimestamp();
}

void CommandResult::setTimestamp(double)
{
}

void CommandResult::setGpsTimestamp(const Sdx::DateTime&)
{
}

std::string CommandResult::toReadableCommand(bool includeName) const
{
  rapidjson::Document doc;
  doc.Parse(toString(true).c_str());
  doc.RemoveMember(CmdNameKey.c_str());
  doc.RemoveMember(CmdUuidKey.c_str());
  if (hasExecutePermission(EXECUTE_IF_SIMULATING))
    doc.RemoveMember(CmdTimestampKey.c_str());
  doc.RemoveMember(RelatedCommand.c_str());
  rapidjson::StringBuffer sb;
  rapidjson::Writer<rapidjson::StringBuffer> writer(sb);
  doc.Accept(writer);
  std::string command = sb.GetString();
  command = command.substr(1, command.size() - 2);
  return includeName ? name() + "(" + command + ")" : command;
}

CommandResultPtr CommandResult::dynamicCast(CommandBasePtr ptr)
{
  return std::dynamic_pointer_cast<CommandResult>(ptr);
}

std::string CommandResult::message() const
{
  if (!isSuccess())
    return errorMsg();
  else if (name() == "SuccessResult")
    return "Success";
  else
    return toReadableCommand();
}

void CommandResult::setRelatedCommand(CommandBasePtr relatedCommand)
{
  m_relatedCommand = std::move(relatedCommand);
  rapidjson::Value value;
  value.SetString(m_relatedCommand->toString().c_str(),
                  static_cast<rapidjson::SizeType>(m_relatedCommand->toString().size()),
                  m_values.GetAllocator());
  setValue(RelatedCommand, value);
}

} // namespace Sdx

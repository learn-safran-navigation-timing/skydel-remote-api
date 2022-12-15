#include "command_base.h"
#include "rapidjson/document.h"
#include "rapidjson/prettywriter.h"
#include "rapidjson/writer.h"
#include "command_result.h"
#include "guid.h"
#include <regex>

namespace Sdx
{
const std::string CommandBase::CmdNameKey("CmdName");
const std::string CommandBase::CmdUuidKey("CmdUuid");
const std::string CommandBase::CmdTimestampKey("CmdTimestamp");
const std::string CommandBase::CmdHidden("CmdHidden");


CommandBase::CommandBase(const std::string &cmdName) :
  m_cmdName(cmdName)
{
  m_values.SetObject();
  rapidjson::Value value;
  value.SetString(cmdName.c_str(), (rapidjson::SizeType) cmdName.size(), m_values.GetAllocator());
  setValue(CmdNameKey, value);
  generateUuid();

  m_cmdSplittedName += m_cmdName[0];
  for(size_t i = 1; i < m_cmdName.size(); ++i)
  {
    char letter = m_cmdName[i];
    if(letter >= 'A' && letter <= 'Z')
      m_cmdSplittedName += ' ';
    m_cmdSplittedName += letter;
  }
}

void CommandBase::generateUuid()
{
  Guid newGuid = GuidGenerator().newGuid();
  std::stringstream stream;
  stream << newGuid;
  m_cmdUuid = stream.str();

  rapidjson::Value value;
  value.SetString(m_cmdUuid.c_str(), (rapidjson::SizeType) m_cmdUuid.size(), m_values.GetAllocator());
  setValue(CmdUuidKey, value);
}

const rapidjson::Document & CommandBase::values() const
{
  return m_values;
}

bool CommandBase::isGuiNavigation() const
{
  return false;
}

int CommandBase::executePermission() const
{
  return EXECUTE_IF_IDLE;
}

bool CommandBase::hasExecutePermission(int flags) const
{
  return (executePermission() & flags) == flags;
}

std::string CommandBase::documentation() const
{
  return "Documentation not available.";
}

Sdx::optional<std::string> CommandBase::deprecated() const
{
  return {};
}

void CommandBase::setHidden(bool isHidden)
{
  rapidjson::Value value(isHidden);
  setValue(CmdHidden, value);
}

bool CommandBase::isHidden() const
{
  return value(CmdHidden).GetBool();
}

bool CommandBase::hasTimestamp() const
{
  return m_values.HasMember(CmdTimestampKey.c_str()) && hasExecutePermission(EXECUTE_IF_SIMULATING);
}

double CommandBase::timestamp() const
{
  return hasTimestamp() ? value(CmdTimestampKey).GetDouble() : 0;
}

void CommandBase::setTimestamp(double secs)
{
  if(!hasExecutePermission(EXECUTE_IF_SIMULATING))
    throw std::runtime_error("Cannot set timestamp to this command");

  rapidjson::Value value(secs);
  setValue(CmdTimestampKey, value);
}

std::string CommandBase::toString(bool compact) const
{
  rapidjson::StringBuffer sb;

  if(compact)
  {
    rapidjson::Writer<rapidjson::StringBuffer> writer(sb);
    m_values.Accept(writer);
  }
  else
  {
    rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(sb);
    m_values.Accept(writer);
  }

  return sb.GetString();
}

std::string CommandBase::toReadableCommand(bool includeName) const
{
  rapidjson::Document doc;
  doc.Parse(toString(true).c_str());
  doc.RemoveMember(CmdNameKey.c_str());
  doc.RemoveMember(CmdUuidKey.c_str());
  if(hasExecutePermission(EXECUTE_IF_SIMULATING))
    doc.RemoveMember(CmdTimestampKey.c_str());
  rapidjson::StringBuffer sb;
  rapidjson::Writer<rapidjson::StringBuffer> writer(sb);
  doc.Accept(writer);
  std::string command = sb.GetString();
  command = command.substr(1, command.size()-2);
  return includeName ? name() + "(" + command + ")" : command;
}

const rapidjson::Value& CommandBase::value(const std::string& key) const
{
	if (contains(key))
		return m_values[key.c_str()];
	else
		throw std::runtime_error("Cannot find " + key);
}

rapidjson::Value& CommandBase::value(const std::string& key)
{
	static rapidjson::Value defaultValue;
	if (contains(key))
		return m_values[key.c_str()];
	else
		throw std::runtime_error("Cannot find " + key);
}

void CommandBase::setValue(const std::string& key, rapidjson::Value& value)
{
	if (contains(key))
		m_values[key.c_str()] = value;
	else
		m_values.AddMember(rapidjson::StringRef(key.c_str()), value, m_values.GetAllocator());
}

bool CommandBase::parse(const std::string &serializedCommand, std::string* errorMsg)
{
  m_values.Parse(serializedCommand.c_str());
  if (m_values.HasParseError())
  {
    if(errorMsg)
    {
      std::stringstream ss;
      ss << "JSON parse error: " << m_values.GetParseError() << "at offset " << m_values.GetErrorOffset();
      *errorMsg = ss.str();
    }
    return false;
  }

  std::string name = m_values[CmdNameKey.c_str()].GetString();
  if (name != m_cmdName)
  {
    if (errorMsg)
      *errorMsg = "Unexpected command name: " + name + " (expecting " + m_cmdName + ")";
    return false;
  }
  return true;
}

bool CommandBase::parse(const std::string& serializedCommand, rapidjson::Document& doc, std::string* errorMsg)
{
  doc.Parse(serializedCommand.c_str());
  if (doc.HasParseError())
  {
    if(errorMsg)
    {
      std::stringstream ss;
      ss << "JSON parse error: " << doc.GetParseError() << " at offset " << doc.GetErrorOffset();
      *errorMsg = ss.str();
    }
    return false;
  }

  return true;
}

bool CommandBase::contains(const std::string &key) const
{
  return m_values.HasMember(key.c_str());
}

} // namespace Sdx

#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include <rapidjson/document.h>

#include <memory>
#include <string>
#include <vector>

#include "sdx_optional.h"

namespace Sdx
{
class CommandBase;
typedef std::shared_ptr<CommandBase> CommandBasePtr;

class CommandResult;
typedef std::shared_ptr<CommandResult> CommandResultPtr;

struct DateTime;

class CommandBase
{
public:
  enum ExecutePermission
  {
    EXECUTE_IF_IDLE = 1 << 1,
    EXECUTE_IF_SIMULATING = 1 << 2,
    EXECUTE_IF_NO_CONFIG = 1 << 3
  };

  static const std::string CmdNameKey;
  static const std::string CmdTargetIdKey;
  static const std::string CmdUuidKey;
  static const std::string CmdTimestampKey;
  static const std::string CmdHidden;

  explicit CommandBase(const std::string& cmdName, const std::string& targetId);
  virtual ~CommandBase() {}
  virtual bool isValid() const = 0;
  virtual bool isGuiNavigation() const;
  virtual int executePermission() const;
  virtual bool hasExecutePermission(int flags) const;
  virtual std::string documentation() const;
  virtual Sdx::optional<std::string> deprecated() const;
  inline const std::string& name() const { return m_cmdName; }
  inline const std::string& splittedName() const { return m_cmdSplittedName; }
  inline const std::string& uuid() const { return m_cmdUuid; }

  void setHidden(bool isHidden);
  bool isHidden() const;
  virtual double timestamp() const;
  virtual Sdx::DateTime gpsTimestamp() const;
  virtual void setTimestamp(double secs);
  virtual void setGpsTimestamp(const Sdx::DateTime& gpsTimestamp);
  bool hasTimestamp() const;

  std::string toString(bool compact = true) const;
  virtual std::string toReadableCommand(bool includeName = true) const;

  const rapidjson::Value& value(const std::string& key) const;
  rapidjson::Value& value(const std::string& key);
  void setValue(const std::string& key, rapidjson::Value& value);

  bool parse(const std::string& serializedCommand, std::string* errorMsg = nullptr);
  static bool parse(const std::string& serializedCommand, rapidjson::Document& doc, std::string* errorMsg = nullptr);
  bool contains(const std::string& key) const;
  void generateUuid();

  const rapidjson::Document& values() const;
  virtual const std::vector<std::string>& fieldNames() const = 0;

protected:
  std::string m_cmdName;
  std::string m_cmdSplittedName;
  std::string m_cmdUuid;
  rapidjson::Document m_values;
  friend class CommandFactory;
  friend class CommandResultFactory;
};

} // namespace Sdx

#endif // COMMAND_BASE_H

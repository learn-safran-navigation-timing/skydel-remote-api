using System;
using Newtonsoft.Json;
using Newtonsoft.Json.Linq;
using System.Collections.Generic;

namespace Sdx
{
  public abstract class CommandBase
  {
    public static JsonSerializer Serializer = new JsonSerializer();

    static CommandBase()
    {
      Serializer.Converters.Add(new DateTimeConverter());
      Serializer.Converters.Add(new CommandBaseConverter());
    }

    internal const string CmdNameKey = "CmdName";
    protected const string CmdUuidKey = "CmdUuid";
    protected const string CmdTimestampKey = "CmdTimestamp";
    protected const string CmdHidden = "CmdHidden";
    internal const string CmdTargetIdKey = "CmdTargetId";

    public const int EXECUTE_IF_IDLE = 1 << 1;
    public const int EXECUTE_IF_SIMULATING = 1 << 2;
    public const int EXECUTE_IF_NO_CONFIG = 1 << 3;

    public virtual string Name { get; protected set; }
    public virtual string SplittedName { get; private set; }
    public virtual string Uuid { get { return (string)GetValue(CmdUuidKey); } }
    public virtual bool IsGuiNavigation { get { return false; } }
    public virtual int ExecutePermission { get { return EXECUTE_IF_IDLE; } }
    public virtual string Documentation { get { return "Documentation not available."; } }
    public virtual string Deprecated { get { return null; } }
    public virtual bool HasTimestamp { get { return Contains(CmdTimestampKey) && HasExecutePermission(EXECUTE_IF_SIMULATING); } }
    public virtual double Timestamp
    {
      get { return HasTimestamp ? (double)GetValue(CmdTimestampKey) : 0; }
      set
      {
        if (!HasExecutePermission(EXECUTE_IF_SIMULATING))
          throw new Exception("Cannot set timestamp to this command");
        SetValue(CmdTimestampKey, value);
      }
    }
    public virtual DateTime GpsTimestamp
    {
        get { return HasTimestamp ? GetValue(CmdTimestampKey).ToObject<DateTime>(Serializer) : new DateTime(); }
        set
        {
            if (!HasExecutePermission(EXECUTE_IF_SIMULATING))
                throw new Exception("Cannot set timestamp to this command");
            SetValue(CmdTimestampKey, JToken.FromObject(value, Serializer));
        }
    }
    public virtual bool IsValid { get { return true; } }

    private JObject m_json;

    public JObject Json
    {
      get { return m_json; }
    }

    public CommandBase(string cmdName, string targetId)
    {
      Name = cmdName;
      m_json = new JObject();
      SetValue(CmdNameKey, cmdName);

      if (!String.IsNullOrEmpty(targetId))
        SetValue(CmdTargetIdKey, targetId);

      Guid newGuid = Guid.NewGuid();
      SetValue(CmdUuidKey, "{" + newGuid.ToString() + "}");

      string splittedName = "";
      splittedName += Name[0];
      for (int i = 1; i < Name.Length; ++i)
      {
        char letter = Name[i];
        if (letter >= 'A' && letter <= 'Z')
          splittedName += ' ';
        splittedName += letter;
      }
      SplittedName = splittedName;
    }

    public virtual void GenUuid()
    {
      Guid newGuid = Guid.NewGuid();
      SetValue(CmdUuidKey, "{" + newGuid.ToString() + "}");
    }

    public virtual JToken GetValue(string key)
    {
      return m_json[key];
    }

    public virtual void SetValue(string key, JToken value)
    {
      m_json[key] = value;
    }

    public virtual void RemoveValue(string key)
    {
      m_json.Remove(key);
    }

    public virtual string ToString(bool compact = true)
    {
      return m_json.ToString(compact ? Formatting.None : Formatting.Indented);
    }

    public virtual string ToReadableCommand(bool includeName = true)
    {
      JObject json = JObject.Parse(ToString(true));
      json.Remove(CmdNameKey);
      json.Remove(CmdUuidKey);
      if (HasExecutePermission(EXECUTE_IF_SIMULATING))
        json.Remove(CmdTimestampKey);
      string command = json.ToString(Formatting.None);
      command = command.Substring(1, command.Length - 2);
      return includeName ? Name + "(" + command + ")" : command;
    }

    public virtual void Parse(JObject json)
    {
      string name = (string)json[CmdNameKey];
      if (name != Name)
      {
        throw new Exception("Unexpected command name: " + name + " (expecting " + Name + ")");
      }

      m_json = json;
    }

    public virtual bool Contains(string key)
    {
      JToken value;
      return m_json.TryGetValue(key, out value);
    }

    public virtual bool HasExecutePermission(int flags)
    {
      return (ExecutePermission & flags) == flags;
    }
  }
} // namespace Bb

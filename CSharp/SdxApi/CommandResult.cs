using System;
using Newtonsoft.Json;
using Newtonsoft.Json.Linq;

namespace Sdx
{
  public class CommandResult : CommandBase
  {
    //
    // Bb::msg::CommandResult
    //
    internal const string CmdRelatedCommand = "RelatedCommand";

    public virtual bool IsSuccess { get { return true; } }
    public virtual string ErrorMsg { get { return ""; } set { } }
    public virtual CommandBase RelatedCommand { get; internal set; }
    public override double Timestamp { get { return RelatedCommand.Timestamp; } set { } }
    public override bool IsValid { get { return Contains(CmdRelatedCommand); } }

    public string Message
    {
      get
      {
        if (!IsSuccess)
          return ErrorMsg;
        else if (Name == "SuccessResult")
          return "Success";
        else
          return ToReadableCommand();
      }
    }

    public CommandResult(string cmdName) :
      base(cmdName)
    {
    }

    public CommandResult(string cmdName, CommandBase relatedCmd) :
      base(cmdName)
    {
      RelatedCommand = relatedCmd;
      SetValue(CmdRelatedCommand, relatedCmd.ToString());
    }

    public override string ToReadableCommand(bool includeName = true)
    {
      JObject json = JObject.Parse(ToString(true));
      json.Remove(CmdNameKey);
      json.Remove(CmdUuidKey);
      if (HasExecutePermission(EXECUTE_IF_SIMULATING))
        json.Remove(CmdTimestampKey);
      json.Remove(CmdRelatedCommand);
      string command = json.ToString(Formatting.None);
      command = command.Substring(1, command.Length - 2);
      return includeName ? Name + "(" + command + ")" : command;
    }

    public override void Parse(JObject json)
    {
      base.Parse(json);

      string cmdJsonStr = (string)GetValue(CmdRelatedCommand);
      JObject cmdJson = JObject.Parse(cmdJsonStr);

      string cmdName = (string)cmdJson[CmdNameKey];
      CommandBase cmd = (CommandBase)Activator.CreateInstance(Type.GetType("Sdx.Cmd." + cmdName), true);
      cmd.Parse(cmdJson);
      RelatedCommand = cmd;
    }
  }
}
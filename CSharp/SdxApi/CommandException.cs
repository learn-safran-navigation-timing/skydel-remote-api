using System;

namespace Sdx
{
public class CommandException : Exception
{
  public CommandResult Result {get; set;}
  public CommandException(CommandResult cmdResult, string simulatorError)
    : base(cmdResult.RelatedCommand.Name + " command failed => " + cmdResult.Message + simulatorError)
  {
    Result = cmdResult;
  }
}
}
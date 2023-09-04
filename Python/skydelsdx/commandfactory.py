#!/usr/bin/env python3

from .commandbase import CommandBase, obj_hook
from .commandresult import CommandResult
import json

class Empty:
  pass

def classFromName(className):
  return getattr(getattr(__import__("skydelsdx"), "commands"), className)

def createCommand(jsonStr):
  try:
    values = json.loads(jsonStr, object_hook=obj_hook)
  except Exception:
    print("Failed to parse json {}".format(jsonStr))
    raise
  class_name = values[CommandBase.CmdNameKey]
  MyClass = classFromName(class_name)
  command = Empty()
  command.__class__ = MyClass
  command.values = values
  return command

def createCommandResult(jsonStr):
    type(jsonStr)
    commandResult = createCommand(jsonStr.decode("UTF-8"))
    relatedCmdJson = commandResult.values[CommandResult.RelatedCommandKey]
    commandResult.setRelatedCommand(createCommand(relatedCmdJson))
    return commandResult

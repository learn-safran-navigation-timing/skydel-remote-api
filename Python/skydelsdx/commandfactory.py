#!/usr/bin/env python3

import importlib
import json
from .commandbase import CommandBase, obj_hook
from .commandresult import CommandResult

ROOT_PACKAGE = __package__.split('.')[0] if __package__ else "skydelsdx"


class Empty:
    pass


def classFromName(className):
    try:
        module = importlib.import_module(f"{ROOT_PACKAGE}.commands")
        return getattr(module, className)
    except (ModuleNotFoundError, AttributeError) as e:
        raise ImportError(f"Failed to load command '{className}' from {ROOT_PACKAGE}.commands") from e


def targetClassFromName(className, targetId):
    try:
        module_name = f"{ROOT_PACKAGE}.plugins.{targetId}.commands"
        module = importlib.import_module(module_name)
        return getattr(module, className)
    except (ModuleNotFoundError, AttributeError) as e:
        raise ImportError(f"Failed to load command '{className}' from plugin '{targetId}'") from e


def createCommand(jsonStr):
    try:
        values = json.loads(jsonStr, object_hook=obj_hook)
    except Exception:
        print(f"Failed to parse json {jsonStr}")
        raise

    class_name = values[CommandBase.CmdNameKey]
    if CommandBase.CmdTargetId in values:
        MyClass = targetClassFromName(class_name, values[CommandBase.CmdTargetId])
    else:
        MyClass = classFromName(class_name)

    command = Empty()
    command.__class__ = MyClass
    command.values = values
    return command


def createCommandResult(jsonStr):
    commandResult = createCommand(jsonStr.decode("UTF-8"))
    relatedCmdJson = commandResult.values[CommandResult.RelatedCommandKey]
    commandResult.setRelatedCommand(createCommand(relatedCmdJson))
    return commandResult

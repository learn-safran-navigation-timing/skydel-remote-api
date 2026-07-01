#!/usr/bin/env python3

import json
import importlib
from .commandbase import CommandBase, obj_hook
from .commandresult import CommandResult


class Empty:
    pass


def classFromName(className):
    try:
        module = importlib.import_module(".commands", package=__package__)
        return getattr(module, className)
    except (ModuleNotFoundError, AttributeError) as e:
        raise ImportError(f"Relative command '{className}' could not be found.") from e


def targetClassFromName(className, targetId):
    module_path = f".plugins.{targetId}.commands"
    try:
        module = importlib.import_module(module_path, package=__package__)
        return getattr(module, className)
    except (ModuleNotFoundError, AttributeError) as e:
        raise ImportError(f"Plugin command '{className}' could not be found at relative path '{module_path}'.") from e


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


def createCommandResult(jsonBytes):
    commandResult = createCommand(jsonBytes.decode("UTF-8"))
    relatedCmdJson = commandResult.values[CommandResult.RelatedCommandKey]
    commandResult.setRelatedCommand(createCommand(relatedCmdJson))
    return commandResult

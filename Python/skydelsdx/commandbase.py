#!/usr/bin/env python3

import uuid
import json
import datetime
import inspect
import types

class ExecutePermission:
  EXECUTE_IF_IDLE = 1 << 1
  EXECUTE_IF_SIMULATING = 1 << 2
  EXECUTE_IF_NO_CONFIG = 1 << 3

class Encoder(json.JSONEncoder):

  def default(self, val):
    if isinstance(val, datetime.datetime):
      return {"Spec":"UTC", "Year":val.year, "Month":val.month, "Day":val.day, "Hour":val.hour, "Minute":val.minute, "Second":val.second}
    elif isinstance(val, datetime.date):
      return {"Year":val.year, "Month":val.month, "Day":val.day}
    elif isinstance(val, CommandBase):
      return val.values
    elif hasattr(val, '__dict__'):
      return val.__dict__
    else:
      return json.JSONEncoder.default(self, val)

class MakeObj:
  def __init__(self, dict):
    self.__dict__ = dict

  def __len__(self):
    return len(self.__dict__)

  def __repr__(self):
    return repr(self.__dict__)

  def __setitem__(self, key, item):
    self.__dict__[key] = item

  def __getitem__(self, key):
      return self.__dict__[key]

  def __eq__(self, other):
    if isinstance(other, MakeObj):
      return self.items() == other.items()
    return False

  def __contains__(self, key):
    return key in self.__dict__

  def iteritems(self):
    return self.__dict__.items()

  def items(self):
    return self.__dict__.items()

def obj_hook(d):
  if all(field in d for field in ["Year", "Month", "Day"]):
    if all(field in d for field in ["Spec", "Hour", "Minute", "Second"]):
      return datetime.datetime(d["Year"], d["Month"], d["Day"], d["Hour"], d["Minute"], d["Second"])
    else:
      return datetime.date(d["Year"], d["Month"], d["Day"])
  else:
    return MakeObj(d)

class CommandBase: 
  CmdNameKey = "CmdName"
  CmdUuidKey = "CmdUuid"
  CmdTimestampKey = "CmdTimestamp"
  CmdTargetId = "CmdTargetId"
 
  def __init__(self, cmd_name, target_id = None):
    self.values = {}
    if cmd_name:
      self.values[CommandBase.CmdNameKey] = cmd_name
      self.values[CommandBase.CmdUuidKey] = "{" + uuid.uuid1().urn[9:] + "}"
    if target_id:
      self.values[CommandBase.CmdTargetId] = target_id
  
  def executePermission(self):
    return ExecutePermission.EXECUTE_IF_IDLE

  def hasExecutePermission(self, flags):
    return (self.executePermission() & flags) == flags

  def setTimestamp(self, timestamp):
    self.values[CommandBase.CmdTimestampKey] = timestamp
  
  def set(self, key, val):
    self.values[key] = val

  def get(self, key):
    return self.values[key]
  
  def getName(self):
    return self.values[CommandBase.CmdNameKey]
    
  def getUuid(self):
    return self.values[CommandBase.CmdUuidKey]
 
  def parse(self, jsonStr):
    print("Parsing", jsonStr)
    self.values = json.loads(jsonStr, object_hook=obj_hook)
 
  def toJson(self):
    return json.dumps(self.values, cls=Encoder)
    
  def toString(self):
    if len(self.values) == 2:
      return self.getName() + "()"
    cmdStr = self.getName() + "("
    for key, value in self.values.items():
      if key != CommandBase.CmdNameKey and key != CommandBase.CmdUuidKey:
        cmdStr += key + ": " + str(value) + ", "
    return cmdStr[:-2] + ")"

  def deprecated(self):
    return None

#!/usr/bin/env python3

from .commandbase import CommandBase
import json
import ast

class CommandResult(CommandBase): 
  RelatedCommandKey = "RelatedCommand"
 
  def __init__(self):
    CommandBase.__init__(self)
    self.command = None
   
  def isSuccess(self):
    return True
  
  def getMessage(self):
   if not self.isSuccess():
     return self.errorMsg()
   elif self.__class__.__name__ == "SuccessResult":
     return "Success"
   else:
     return self.toString()  
  
  def setRelatedCommand(self, cmd):
    self.command = cmd
    
  def getRelatedCommand(self):
    return self.command
    
  def toString(self):
    if len(self.values) == 2:
      return self.getName() + "()"
    cmdStr = self.getName() + "("
    for key, value in self.values.items():
      if key != CommandBase.CmdNameKey and key != CommandBase.CmdUuidKey and key != CommandResult.RelatedCommandKey:
        cmdStr += key + ": " + str(value) + ", "
    return cmdStr[:-2] + ")"

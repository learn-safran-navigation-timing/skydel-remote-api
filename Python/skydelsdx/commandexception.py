class CommandException(Exception):
  def __init__(self, command_result, simulation_error_msg):
    # Call the base class constructor with the parameters it needs
    msg = command_result.getRelatedCommand().getName() + " failed: " + command_result.getMessage() +  simulation_error_msg
    super(CommandException, self).__init__(msg)
    self.command_result = command_result
    self.simulation_error_msg = simulation_error_msg
  
  def getCommandResult(self):
    return self.command_result

  def getSimulationErrorMsg(self):
    return self.simulation_error_msg

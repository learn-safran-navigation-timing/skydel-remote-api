namespace Bb
{
enum SocketState
{
  Disconnected,
  HostLookup,
  Connecting,
  Connected,
  Bound,
  Closing,
  Listening
};

enum SimulatorState
{
  SimulatorError = -1,
  SimulatorUnknown = 0,
  SimulatorIdle = 1,
  SimulatorInitHardware = 2,
  SimulatorArmed = 3,
  SimulatorRunning = 4
};
}

using Sdx;
using Sdx.Cmd;
using SdxKeyboard.Properties;
using System;
using System.Threading;
using System.Windows;
using System.Windows.Input;
using System.Windows.Threading;

namespace SdxKeyboard
{
  /// <summary>
  /// Interaction logic for SimulationDialog.xaml
  /// </summary>
  public sealed partial class SimulationDialog : Window, IDisposable
  {
    private MotionModel _motion;
    private RemoteSimulator _simulator;

    public SimulationDialog()
    {
      InitializeComponent();

      _simulator = new RemoteSimulator()
      {
        IsVerbose = false
      };

      _motion = new MotionModel(_simulator, 45, -74);
      _motion.Exception += _motion_Exception;
      this.MotionControl.DataContext = _motion;

      _simulator.Connect(Settings.Default.SdxAddress);

      _simulator.Call(new New(true));
      _simulator.Call(new SetModulationTarget(Settings.Default.TargetType, "", Settings.Default.TargetAddress, Settings.Default.ClockIsExternal, "radio1"));
      _simulator.Call(new ChangeModulationTargetSignals(0, 12500000, 12500000, "UpperL", "L1CA", -1, false, "radio1"));
      _simulator.Call(new SetVehicleTrajectory("HIL"));
      _simulator.Call(new EnableLogRaw(Settings.Default.RawLogging));
      _simulator.Call(new SetLogRawRate(Settings.Default.LoggingRate));
      _simulator.Start();

      _motion.Start();
    }

    private void _motion_Exception(object sender, ThreadExceptionEventArgs e)
    {
      Dispatcher.BeginInvoke(new Action(() =>
      {
        _motion.Stop();
        throw e.Exception;
      }));
    }

    protected override void OnClosed(EventArgs e)
    {
      base.OnClosed(e);
      _motion.Stop();
      _simulator.Stop();
      _simulator.Disconnect();
    }

    protected override void OnKeyDown(KeyEventArgs e)
    {
      base.OnKeyDown(e);
      switch (e.Key)
      {
        case Key.Up:
          _motion.Accelerate = true;
          break;
        case Key.Down:
          _motion.Decelerate = true;
          break;
        case Key.Left:
          _motion.TurnLeft = true;
          break;
        case Key.Right:
          _motion.TurnRight = true;
          break;
        default:
          break;
      }
    }

    protected override void OnKeyUp(KeyEventArgs e)
    {
      base.OnKeyDown(e);
      switch (e.Key)
      {
        case Key.Up:
          _motion.Accelerate = false;
          break;
        case Key.Down:
          _motion.Decelerate = false;
          break;
        case Key.Left:
          _motion.TurnLeft = false;
          break;
        case Key.Right:
          _motion.TurnRight = false;
          break;
        default:
          break;
      }
    }

    public void Dispose()
    {
      _motion.Dispose();
    }
  }
}

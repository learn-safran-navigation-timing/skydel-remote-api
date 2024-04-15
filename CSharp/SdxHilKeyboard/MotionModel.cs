using Sdx;
using Sdx.Cmd;
using System;
using System.Threading;

namespace SdxKeyboard
{
    public sealed class MotionModel : ANotifyPropertyChanged, IDisposable
    {
        public event EventHandler<ThreadExceptionEventArgs> Exception;

        private bool _accelerate = false;
        public bool Accelerate
        {
            get { return _accelerate; }
            set { AssignAndNotify(ref _accelerate, value); }
        }

        private bool _decelerate = false;
        public bool Decelerate
        {
            get { return _decelerate; }
            set { AssignAndNotify(ref _decelerate, value); }
        }

        private bool _turnLeft = false;
        public bool TurnLeft
        {
            get { return _turnLeft; }
            set { AssignAndNotify(ref _turnLeft, value); }
        }

        private bool _turnRight = false;
        public bool TurnRight
        {
            get { return _turnRight; }
            set { AssignAndNotify(ref _turnRight, value); }
        }

        private long _elapsed = 0;
        public long Elapsed
        {
            get { return _elapsed; }
            private set { AssignAndNotify(ref _elapsed, value); }
        }

        private Lla _position;
        public Lla Position
        {
            get { return _position; }
            set { AssignAndNotify(ref _position, value); }
        }

        private double _speed;
        public double Speed
        {
            get { return _speed; }
            private set { AssignAndNotify(ref _speed, value); }
        }

        private double _targetSpeed;
        public double TargetSpeed
        {
            get { return _targetSpeed; }
            private set { AssignAndNotify(ref _targetSpeed, value); }
        }

        private double _angle;
        public double Angle
        {
            get { return _angle; }
            private set { AssignAndNotify(ref _angle, value); }
        }

        private int? _lastExtrapolation = null;
        public int? LastExtrapolation
        {
            get { return _lastExtrapolation; }
            set { AssignAndNotify(ref _lastExtrapolation, value); }
        }

        private RemoteSimulator _simulator;
        private MyTimer _timer;
        private int _tickCount = 0;
        private long _prevTime = 0;

        public MotionModel(RemoteSimulator simulator, double latDeg, double lonDeg)
        {
            _simulator = simulator;
            _timer = new MyTimer(_TimerTick, new TimeSpan(0, 0, 0, 0, 10));
            _timer.Exception += _timer_Exception;
            _position.Lat = Angles.ToRadian(latDeg);
            _position.Lon = Angles.ToRadian(lonDeg);
        }

        private void _timer_Exception(object sender, ThreadExceptionEventArgs e)
        {
            Exception?.Invoke(this, e);
        }

        public void Start()
        {
            _prevTime = DateTime.Now.Ticks / TimeSpan.TicksPerMillisecond;
            _PushPosition();
            _timer.Start();
        }

        public void Stop()
        {
            _timer.Stop();
        }

        private void _TimerTick()
        {
            _UpdatePosition();
            _PushPosition();
            if (++_tickCount == 100)
            {
                _CheckErrors();
                _tickCount = 0;
            }
        }

        private void _CheckErrors()
        {
            var result = _simulator.Call(new GetHilExtrapolationState()) as GetHilExtrapolationStateResult;
            if (result != null && result.State != HilExtrapolationState.Deterministic)
                LastExtrapolation = result.ElapsedTime;
        }

        private void _PushPosition()
        {
            _simulator.PushLla(_elapsed, _position);
        }

        private void _UpdatePosition()
        {
            long now = DateTime.Now.Ticks / TimeSpan.TicksPerMillisecond;

            _UpdatePosition(now - _prevTime);
            _prevTime = now;
        }

        private void _UpdatePosition(long elapsed)
        {
            // Change of speed by 10km/h per second
            // Change of angle by 45 deg per second

            if (Accelerate)
                TargetSpeed += 10.0 * elapsed / 1000.0;
            if (Decelerate)
                TargetSpeed -= Math.Min(10.0 * elapsed / 1000.0, TargetSpeed); // Prevents target speed to go below 0.
            if (TurnLeft)
                Angle = Angles.ClampDeg(Angle + elapsed * 45.0 / 1000.0);
            if (TurnRight)
                Angle = Angles.ClampDeg(Angle - elapsed * 45.0 / 1000.0);

            _UpdateSpeed(elapsed);

            double angle = Angles.ToRadian(Angle);
            Position = Position.AddEnu(new Enu(Speed * Math.Cos(angle) * elapsed / 3600.0, Speed * elapsed / 3600.0 * Math.Sin(angle), 0));

            Elapsed += elapsed;
        }

        private void _UpdateSpeed(long elapsed)
        {
            Speed += (TargetSpeed - Speed) * elapsed / 1000.0;
        }

        public void Dispose()
        {
            _timer.Dispose();
        }
    }
}

using System;
using System.Threading;

namespace SdxKeyboard
{
    // This class creates a thread that will call a function repeatedly after a certain interval. 
    class MyTimer : IDisposable
    {
        public delegate void CallBack();
        public event EventHandler<ThreadExceptionEventArgs> Exception;

        private EventWaitHandle _conditonalVariable;
        private CallBack _cb;
        private TimeSpan _interval;
        private volatile bool _stop;
        private Thread _th;

        public MyTimer(CallBack cb, TimeSpan interval)
        {
            _conditonalVariable = new EventWaitHandle(false, EventResetMode.ManualReset);
            _cb = cb;
            _interval = interval;
            _stop = true;
            _th = null;
        }

        private void _ThreadLoop()
        {
            while (!_stop)
            {
                _conditonalVariable.WaitOne(_interval);
                if (!_stop)
                {
                    try
                    {
                        _cb();
                    }
                    catch (Exception e)
                    {
                        Exception?.Invoke(this, new ThreadExceptionEventArgs(e));
                    }
                }
            }
        }

        public void Start()
        {
            if (_th == null)
            {
                _stop = false;
                _conditonalVariable.Reset();
                _th = new Thread(_ThreadLoop)
                {
                    IsBackground = true,
                    Name = "TimerThread"
                };
                _th.Start();
            }
        }

        public void Stop()
        {
            if (_th != null)
            {
                _stop = true;
                _conditonalVariable.Set();
                _th.Join();
                _th = null;
            }
        }

        #region IDisposable Support
        private bool disposedValue = false; // To detect redundant calls

        protected virtual void Dispose(bool disposing)
        {
            if (!disposedValue)
            {
                if (disposing)
                {
                    Stop();
                    _conditonalVariable.Dispose();
                }

                disposedValue = true;
            }
        }

        // This code added to correctly implement the disposable pattern.
        public void Dispose()
        {
            // Do not change this code. Put cleanup code in Dispose(bool disposing) above.
            Dispose(true);
        }
        #endregion
    }
}
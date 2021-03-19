using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace SdxKeyboard
{
    // Base class for object implementing INotifyPropertyChanged
    public abstract class ANotifyPropertyChanged : INotifyPropertyChanged
    {
        protected bool AssignAndNotify<T>(ref T field, T value, [CallerMemberName] string propertyName = null)
        {
            if (value.Equals(field))
                return false;
            field = value;
            this.Notify(propertyName);
            return true;
        }

        protected void Notify([CallerMemberName] string propertyName = null)
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
        }

        public event PropertyChangedEventHandler PropertyChanged;
    }
}

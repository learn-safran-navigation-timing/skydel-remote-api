using System;

namespace SdxKeyboard
{
    public static class Angles
    {
        public static double ToRadian(double degree)
        {
            return (Math.PI / 180) * degree;
        }

        public static double ClampDeg(double degree)
        {
            if (degree < 0)
                return degree + 360;
            if (degree >= 360)
                return degree - 360;
            return degree;
        }
    }
}

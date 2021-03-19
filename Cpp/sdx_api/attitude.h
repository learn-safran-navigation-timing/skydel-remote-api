#ifndef ATTITUDE_H
#define ATTITUDE_H

namespace Sdx
{

class Attitude
{
public:
  Attitude();
  Attitude(double yaw, double pitch, double roll);
  inline void clear() { yaw = pitch = roll = 0; }

  double yawDeg() const;
  double pitchDeg() const;
  double rollDeg() const;

  bool operator==(const Attitude& other) const;
  bool operator!=(const Attitude& other) const;

  double yaw;
  double pitch;
  double roll;
};

} // namespace Sdx

#endif // ATTITUDE_H

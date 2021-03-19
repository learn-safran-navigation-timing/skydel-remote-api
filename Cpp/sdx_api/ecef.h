#ifndef ECEF_H
#define ECEF_H

namespace Sdx
{

class Lla;
class Ecef
{
public:
    Ecef();
    Ecef(double x, double y, double z);
    explicit Ecef(const Sdx::Lla& lla);
    inline void clear() { x = y = z = 0; }
    void toLla(Sdx::Lla& lla) const;
    bool operator==(const Ecef& other) const;
    bool operator!=(const Ecef& other) const;

    double x;
    double y;
    double z;
};

} // namespace Sdx

#endif // ECEF_H

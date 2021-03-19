#ifndef ENU_H
#define ENU_H

namespace Sdx
{

class Lla;
class Ecef;

/*
 * Enu contains East, North and Up triplet. The origin (0,0,0) is not attached to any
 * specific earth coordinate. Therefore, to convert enu to lla, you need to specify the
 * Enu origin.
 */

class Enu
{
public:
    Enu();
    Enu(double e, double n, double u);
    void toEcef(const Lla& origin, Ecef& ecef) const;
    void toLla(const Lla& origin, Lla& lla) const;
    bool operator==(const Enu& other) const;
    bool operator!=(const Enu& other) const;

    double e; // east  (meter)
    double n; // north (meter)
    double u; // up    (meter)
};

} // namespace Sdx

#endif // ENU_H

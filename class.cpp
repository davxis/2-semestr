#include "class.h"
class Angle {
private:
    Point a, b, c;
public:
    // angle between `ba` and `bc`. Angle ABC
    Angle(Point a, Point b, Point c) : a(a), b(b), c(c) {}

    // Возвращает true, если угол ABC - прямой.
    bool isRight() {
        Point ba(a.getX() - b.getX(), a.getY() - b.getY());
        Point bc(c.getX() - b.getX(), c.getY() - b.getY());
        double scalarProduct = ba.getX() * bc.getX() + ba.getY() * bc.getY();
        double epsilon = 0.0000001;
        return abs(scalarProduct) < epsilon;
    }
};

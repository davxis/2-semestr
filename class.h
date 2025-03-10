#pragma once
#include <iostream>
#include <cmath>

using namespace std;

class Point {
private:
    double x;
    double y;
public:
    Point() : x(0), y(0) {}

    Point(double x, double y) : x(x), y(y) {}

    double getX() {
        return x;
    }

    double getY() {
        return y;
    }

    friend std::istream& operator>>(std::istream& in, Point& p) {
        in >> p.x >> p.y;
        return in;
    }

    friend std::ostream& operator<<(std::ostream& out, const Point& p) {
        out << '(' << p.x << "; " << p.y << ')';
        return out;
    }

    bool operator==(const Point& other) {
        return this->x == other.x && this->y == other.y;
    }
};

#include "Point.h"

#include "helpers.h"

/*
 * @brief Конструктор по умолчанию, инициализирующий точку в (0, 0).
 */
Point::Point() : x(0), y(0) {}

/*
 * @brief Конструктор, инициализирующий точку заданными координатами.
 * @param x Координата X.
 * @param y Координата Y.
 */
Point::Point(const double x, const double y) : x(x), y(y) {}

/*
 * @brief Получить координату X точки.
 * @return Координата X.
 */
double Point::getX() const {
    return x;
}

/*
 * @brief Получить координату Y точки.
 * @return Координата Y.
 */
double Point::getY() const {
    return y;
}

/*
 * @brief Оператор ввода для класса Point.
 * Позволяет вводить координаты точки через поток ввода.
 * @param in Поток ввода.
 * @param p Ссылка на объект Point, в который будут записаны координаты.
 * @return Ссылка на поток ввода.
 */
std::istream& operator>>(std::istream& in, Point& p) {
    in >> p.x >> p.y;
    return in;
}

/*
 * @brief Оператор вывода для класса Point.
 * Позволяет выводить координаты точки через поток вывода.
 * @param out Поток вывода.
 * @param p Константная ссылка на объект Point, координаты которого будут выведены.
 * @return Ссылка на поток вывода.
 */
std::ostream& operator<<(std::ostream& out, const Point& p) {
    out << '(' << p.x << "; " << p.y << ')';
    return out;
}

/*
 * @brief Оператор сравнения для класса Point.
 * Позволяет сравнивать две точки на равенство.
 * @param other Константная ссылка на другую точку для сравнения.
 * @return true, если точки равны; false в противном случае.
 */
bool Point::operator==(const Point& other) const {
    return doublesEquals(this->x, other.x)
        && doublesEquals(this->y, other.y);
}

/*
 * @brief Оператор сравнения для класса Point.
 * Позволяет сравнивать две точки на неравенство.
 * @param other Константная ссылка на другую точку для сравнения.
 * @return true, если точки не равны; false в противном случае.
 */
bool Point::operator!=(const Point& other) const {
    return !doublesEquals(this->x, other.x)
        || !doublesEquals(this->y, other.y);
}
bool Point::operator!=(const Point& other) const {
    return !(*this == other);  // Теперь используем operator==
}

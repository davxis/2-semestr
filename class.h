#pragma once
#include <iostream>
#include <cmath>

using namespace std;

/*
 * @class Point
 * @brief Класс, представляющий точку в двумерном пространстве.
 */
class Point {
private:
    double x; ///< Координата X точки.
    double y; ///< Координата Y точки.
public:
    /*
     * @brief Конструктор по умолчанию, инициализирующий точку в (0, 0).
     */
    Point() : x(0), y(0) {}

    /*
     * @brief Конструктор, инициализирующий точку заданными координатами.
     * @param x Координата X.
     * @param y Координата Y.
     */
    Point(double x, double y) : x(x), y(y) {}

    /*
     * @brief Получить координату X точки.
     * @return Координата X.
     */
    double getX() {
        return x;
    }

    /*
     * @brief Получить координату Y точки.
     * @return Координата Y.
     */
    double getY() {
        return y;
    }

    /*
     * @brief Оператор ввода для класса Point.
     * Позволяет вводить координаты точки через поток ввода.
     * @param in Поток ввода.
     * @param p Ссылка на объект Point, в который будут записаны координаты.
     * @return Ссылка на поток ввода.
     */
    friend std::istream& operator>>(std::istream& in, Point& p) {
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
    friend std::ostream& operator<<(std::ostream& out, const Point& p) {
        out << '(' << p.x << "; " << p.y << ')';
        return out;
    }

    /*
     * @brief Оператор сравнения для класса Point.
     * Позволяет сравнивать две точки на равенство.
     * @param other Константная ссылка на другую точку для сравнения.
     * @return true, если точки равны; false в противном случае.
     */
    bool operator==(const Point& other) {
        return this->x == other.x && this->y == other.y;
    }
};

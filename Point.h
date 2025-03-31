#pragma once

#include <iostream>

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
    Point();

    /*
     * @brief Конструктор, инициализирующий точку заданными координатами.
     * @param x Координата X.
     * @param y Координата Y.
     */
    Point(double x, double y);

    /*
     * @brief Получить координату X точки.
     * @return Координата X.
     */
    double getX();

    /*
     * @brief Получить координату Y точки.
     * @return Координата Y.
     */
    double getY();

    /*
     * @brief Оператор ввода для класса Point.
     * Позволяет вводить координаты точки через поток ввода.
     * @param in Поток ввода.
     * @param p Ссылка на объект Point, в который будут записаны координаты.
     * @return Ссылка на поток ввода.
     */
    friend std::istream& operator>>(std::istream& in, Point& p);

    /*
     * @brief Оператор вывода для класса Point.
     * Позволяет выводить координаты точки через поток вывода.
     * @param out Поток вывода.
     * @param p Константная ссылка на объект Point, координаты которого будут выведены.
     * @return Ссылка на поток вывода.
     */
    friend std::ostream& operator<<(std::ostream& out, const Point& p);

    /*
     * @brief Оператор сравнения для класса Point.
     * Позволяет сравнивать две точки на равенство.
     * @param other Константная ссылка на другую точку для сравнения.
     * @return true, если точки равны; false в противном случае.
     */
    bool operator==(const Point& other) const;
};

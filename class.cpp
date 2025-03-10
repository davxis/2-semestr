#include "class.h"
class Angle {
private:
    Point a, b, c;
public:
    /*
     * @brief Конструктор, инициализирующий угол заданными тремя точками.
     * @param a Первая точка (A) угла.
     * @param b Вторая точка (B) угла (вершина).
     * @param c Третья точка (C) угла.
     */
    Angle(Point a, Point b, Point c) : a(a), b(b), c(c) {}

    /*
     * @brief Проверяет, является ли угол ABC прямым.
     * @return true, если угол ABC - прямой; false в противном случае.
     *
     * Угол считается прямым, если скалярное произведение векторов BA и BC равно нулю.
     * Для проверки используется небольшой порог (epsilon) для учета возможных ошибок округления.
     */
    bool isRight() {
        Point ba(a.getX() - b.getX(), a.getY() - b.getY()); 
        Point bc(c.getX() - b.getX(), c.getY() - b.getY()); 
        double scalarProduct = ba.getX() * bc.getX() + ba.getY() * bc.getY(); 
        double epsilon = 0.0000001; 
        return abs(scalarProduct) < epsilon; 
    }
};

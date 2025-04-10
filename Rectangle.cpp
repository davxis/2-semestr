#include "Rectangle.h"

/*
 * @brief Конструктор для создания прямоугольника с заданными вершинами. 
 * @param maxScreenResolution Максимальное разрешение экрана для проверки допустимых координат.
 * @param a Первая вершина прямоугольника.
 * @param b Вторая вершина прямоугольника.
 * @param c Третья вершина прямоугольника.
 */
Rectangle::Rectangle(Point maxScreenResolution, Point a, Point b, Point c) : a(a), b(b), c(c) {
    validate(maxScreenResolution);
}

/*
 * @brief Проверяет, является ли угол ABC прямым. 
 * Угол считается прямым, если скалярное произведение векторов BA и BC близко к нулю.
 * @param a Первая точка.
 * @param b Вторая точка (вершина угла).
 * @param c Третья точка.
 * @return true Если угол ABC прямой.
 * @return false Если угол ABC не прямой.
 */
bool isRightAngle(Point a, Point b, Point c) {
    double ax = a.x, ay = a.y, bx = b.x, by = b.y, cx = c.x, cy = c.y;
    double bax = ax - bx;
    double bay = ay - by;
    double bcx = cx - bx;
    double bcy = cy - by;
    double scalarProduct = bax * bcx + bay * bcy;
    double epsilon = std::numeric_limits<double>::epsilon();
    return abs(scalarProduct) < epsilon;
}

/*
 * @brief Проверяет корректность координат вершин прямоугольника.
 * Проверяет, что ни одна из координат не превышает максимальные значения,
 * что все три точки различны и что они образуют прямоугольный треугольник.
 * @param maxScreenResolution Максимальное разрешение экрана для проверки допустимых координат.
 * @throws const char* Если координаты выходят за пределы или точки не образуют прямоугольник.
 */
void Rectangle::validate(Point maxScreenResolution) {
    if (a >= maxScreenResolution || b >= maxScreenResolution || c >= maxScreenResolution) {
        throw "1 из координат одной из вершин преодолела максимальное значение";
    }
    if (a == b || b == c || a == c) {
        throw "2 точки прямоугольника не могут быть идентичными";
    }
    bool aIsRight = isRightAngle(b, a, c);
    bool bIsRight = isRightAngle(a, b, c);
    bool cIsRight = isRightAngle(a, c, b);
    if (!aIsRight && !bIsRight && !cIsRight) {
        throw "3 вершины прямоугольника должны образовывать прямоугольный треугольник";
    }
}

/*
 * @brief Возвращает строковое представление прямоугольника. 
 * Переопределяет метод ToString из базового класса Figure2D.
 * @return Строковое представление прямоугольника.
 */
std::string Rectangle::ToString() const {
    return "Rectangle(a = " + a.ToString() + ", b = " +
        b.ToString() + ", c = " + c.ToString() + ")";
}

/*
 * @brief Перегрузка оператора ввода для прямоугольника. 
 * Считывает данные о вершинах прямоугольника из потока ввода.
 * @param is Поток ввода, из которого будут считаны данные о прямоугольнике.
 * @param rect Прямоугольник, в который будут записаны считанные значения.
 * @return Ссылку на поток ввода для поддержки цепочки операций.
 */
std::istream& operator>>(std::istream& is, Rectangle& rect) {
    is >> rect.a >> rect.b >> rect.c;
    return is;
}

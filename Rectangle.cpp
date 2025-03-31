#include "Rectangle.h"

#include <iostream>
#include "Angle.h"

using namespace std;

// Создаёт прямоугольник с точками a, b, c, d так,
// что угол около abc всегда прямой.
// Из 3х переданных точек, одна из них станет точкой b.
// Также, вычисляется точка d.
//
// Если по заданным трём точкам нельзя построить прямоугольник,
// то выбрасывается исключение.
Rectangle::Rectangle(const Point& a, const Point& b, const Point& c) {
    validateForEqualPoints(a, b, c);
    setABCChooseBAsRightAngle(a, b, c);
    setD();
}

/**
 * @brief Вычисляет радиус описанной около прямоугольника окружности.
 * 
 * @return Радиус описанной окружности.
 */
double Rectangle::getCircumscribedCircleRadius() {
    // Вычисляем диаметр окружности, описанной около прямоугольника.
    double dx = a.getX() - c.getX();
    double dy = a.getY() - c.getY();
    double diameter = sqrt(dx * dx + dy * dy);

    // Вычисляем радиус этой окружности
    double radius = diameter / 2;

    return radius;
}

/**
 * @brief Проверяет, что никакие из 3х точек не находятся в одном и том же месте.
 * 
 * @param a Первая точка.
 * @param b Вторая точка.
 * @param c Третья точка.
 * 
 * @throws const char* Исключение, если точки совпадают.
 */
void Rectangle::validateForEqualPoints(const Point& a, const Point& b, const Point& c) {
    // Проверка, что точки не совпадают
    if (a == b) {
        throw "Point A should not be the same as B";
    }
    if (a == c) {
        throw "Point A should not be the same as C";
    }
    if (b == c) {
        throw "Point B should not be the same as C";
    }
}

/**
 * @brief Задаёт значения полей a, b, c на основе значений параметров
 * так, что поле b будет ссылаться на точку с прямым углом.
 *
 * @param a Первая точка.
 * @param b Вторая точка (угол с прямым углом).
 * @param c Третья точка.
 * 
 * @throws const char* Исключение, если ни один из углов не является прямым.
 */
void Rectangle::setABCChooseBAsRightAngle(const Point& a, const Point& b, const Point& c) {
    // Вычисление углов: являются ли прямые.
    //
    // ВАЖНО! Если ни один из углов не прямой,
    // то это означает, что нельзя построить прямоугольник по
    // заданным точкам.
    Angle angleA(b, a, c), angleB(a, b, c), angleC(a, c, b);
    bool aIsRight = angleA.isRight();
    bool bIsRight = angleB.isRight();
    bool cIsRight = angleC.isRight();

    // Проверка, что хотя бы 1 из углов прямой
    if (!aIsRight && !bIsRight && !cIsRight) {
        throw "There should be at least 1 angle between points which is right";
    }

    if (aIsRight) {
        this->a = b;
        this->b = a;
        this->c = c;
    } else if (bIsRight) {
        this->a = a;
        this->b = b;
        this->c = c;
    } else {
        this->a = a;
        this->b = c;
        this->c = b;
    }
}

/**
 * @brief Задаёт значение поля d на основе значений полей a, b, c.
 */
void Rectangle::setD() {
    double ax = a.getX(), ay = a.getY(), bx = b.getX(), by = b.getY(),
           cx = c.getX(), cy = c.getY();
    double dx = ax + cx - bx;
    double dy = ay + cy - by;
    this->d = Point(dx, dy);
}

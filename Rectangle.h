#pragma once

#include "Point.h"

class Rectangle {
private:
    /** 
     * @brief Углы прямоугольника: 
     * угол abc - всегда прямой.
     */
    Point a, b, c, d;

public:
    // Создаёт прямоугольник с точками `a`, `b`, `c`, `d` так,
    // что угол около `abc` всегда прямой.
    // Из 3х переданных точек, одна из них станет точкой `b`.
    // Также, вычисляется точка `d`.
    //
    // Если по заданным трём точкам нельзя построить прямоугольник,
    // то выбрасывается исключение.
    Rectangle(const Point& a, const Point& b, const Point& c);

    /** 
     * @brief Возвращает радиус описанной окружности вокруг прямоугольника.
     * 
     * @return Радиус описанной окружности.
     */
    double getCircumscribedCircleRadius() const;

    /** 
     * @brief Возвращает площадь описанной окружности вокруг прямоугольника.
     * 
     * @return Площадь описанной окружности.
     */
    double getCircumscribedCircleSquare() const;

private:
    // Проверяет, что никакие из 3х точек не находятся в одном и том же месте.
    static void validateForEqualPoints(const Point& a, const Point& b, const Point& c);

    /** 
     * @brief Устанавливает значения a, b и c, выбирая b как угол с прямым углом.
     */
    void setABCChooseBAsRightAngle();

    /** 
     * @brief Вычисляет точку d на основе a, b и c.
     */
    void setD();
};

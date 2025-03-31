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
    /** 
     * @brief Возвращает радиус описанной окружности вокруг прямоугольника.
     * 
     * @return Радиус описанной окружности.
     */
    double getCircumscribedCircleRadius();

private:
    /** 
     * @brief Устанавливает значения a, b и c, выбирая b как угол с прямым углом.
     * 
     * @param a Первая точка.
     * @param b Вторая точка (угол с прямым углом).
     * @param c Третья точка.
     */
    void setABCChooseBAsRightAngle(const Point& a, const Point& b, const Point& c);

    /** 
     * @brief Вычисляет точку d на основе a, b и c.
     */
    void setD();
};



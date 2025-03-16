#pragma once

#include "Figure2D.h"
#include "Point.h"
#include <iostream>

/*
 * @brief Класс, представляющий прямоугольник в двумерном пространстве. 
 * Наследует от класса Figure2D и содержит три точки, представляющие вершины прямоугольника.
 */
class Rectangle : public Figure2D {
    Point a; ///< Первая вершина прямоугольника.
    Point b; ///< Вторая вершина прямоугольника.
    Point c; ///< Третья вершина прямоугольника.

    /*
     * @brief Проверяет, что вершины a, b, c могут быть вершинами корректного прямоугольника. 
     * Если это не так, то выбрасывается исключение.
     * @param maxScreenResolution Максимальное разрешение экрана для проверки допустимых координат.
     */
    void validate(Point maxScreenResolution);

public:
    /*
     * @brief Конструктор для создания прямоугольника с заданными вершинами. 
     * @param maxScreenResolution Максимальное разрешение экрана для проверки допустимых координат.
     * @param a Первая вершина прямоугольника.
     * @param b Вторая вершина прямоугольника.
     * @param c Третья вершина прямоугольника.
     */
    Rectangle(Point maxScreenResolution, Point a, Point b, Point c);
    
    /*
     * @brief Конструктор для создания прямоугольника с заданными координатами вершин. 
     * @param maxScreenResolution Максимальное разрешение экрана для проверки допустимых координат.
     * @param ax Координата X первой вершины.
     * @param ay Координата Y первой вершины.
     * @param bx Координата X второй вершины.
     * @param by Координата Y второй вершины.
     * @param cx Координата X третьей вершины.
     * @param cy Координата Y третьей вершины.
     */
    Rectangle(Point maxScreenResolution, unsigned ax, unsigned ay, unsigned bx, unsigned by,
              unsigned cx, unsigned cy);
    
    /*
     * @brief Возвращает строковое представление прямоугольника. 
     * Переопределяет метод ToString из базового класса Figure2D.
     * @return Строковое представление прямоугольника.
     */
    std::string ToString() const override;

    /*
     * @brief Перегрузка оператора ввода для прямоугольника. 
     * Считывает данные о вершинах прямоугольника из потока ввода.
     * @param is Поток ввода, из которого будут считаны данные о прямоугольнике.
     * @param rect Прямоугольник, в который будут записаны считанные значения.
     * @return Ссылку на поток ввода для поддержки цепочки операций.
     */
    friend std::istream& operator>>(std::istream& is, Rectangle& rect);
};

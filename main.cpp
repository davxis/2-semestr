#include <iostream>
#include <clocale>
#include "Point.h"
#include "Rectangle.h"
#include "Figure2D.h"

using namespace std;

/**
 * @brief Точка входа в программу.
 * Устанавливает русскую локаль, создает объект прямоугольника,
 * позволяет пользователю вводить новые координаты и выводит
 * информацию о прямоугольнике.
 * @return Код завершения.
 */

int main() {
    setlocale(LC_ALL, "rus"); 
    try {
        const Point maxScreenResolution(640, 480); // Максимальное разрешение экрана
        Rectangle rect1(maxScreenResolution, Point(0, 2), Point(0, 5), Point(2, 5)); // Создаем прямоугольник
        Figure2D* fig = &rect1; // Указатель на фигуру
        cout << *fig << endl; // Выводим информацию о прямоугольнике

        cout << "Введите координаты 3х вершин прямоугольника: "; // Запрашиваем ввод координат
        cin >> rect1; // Считываем новые координаты вершин
        cout << *fig << endl; // Выводим обновленную информацию о прямоугольнике

    } catch (const char* msg) { // Обработка исключений
        cout << "Ошибка: " << msg << endl; // Выводим сообщение об ошибке
    }
    return 0; // Возвращаем код завершения
}

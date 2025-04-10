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
    // Настройка локали для корректного вывода кириллицы
    setlocale(LC_ALL, "ru_RU.UTF-8");
    cout.precision(numeric_limits<double>::max_digits10); // Точность вывода чисел

    try {
        // Максимальное разрешение экрана
        const Point maxScreenResolution(640, 480);
        
        // Создаем прямоугольник с 4 вершинами
        Rectangle rect(maxScreenResolution,
                     Point(0, 0),    // Левый верхний угол
                     Point(100, 0),  // Правый верхний
                     Point(100, 50), // Правый нижний
                     Point(0, 50));  // Левый нижний

        // Выводим информацию о прямоугольнике
        cout << "Создан прямоугольник:\n" << rect << endl;
        
        // Демонстрация полиморфизма
        Figure2D* figure = &rect;
        cout << "Площадь фигуры: " << figure->area() << endl;

        // Ввод нового прямоугольника с клавиатуры
        cout << "\nВведите 4 вершины прямоугольника в порядке:\n"
             << "1. Левый верхний\n2. Правый верхний\n"
             << "3. Правый нижний\n4. Левый нижний\n";
        
        Rectangle userRect(maxScreenResolution, Point(), Point(), Point(), Point());
        cin >> userRect;
        
        cout << "\nВведенный прямоугольник:\n" << userRect << endl;
        cout << "Площадь: " << userRect.area() << endl;
        cout << "Периметр: " << userRect.perimeter() << endl;

    } catch (const invalid_argument& e) {
        cerr << "Ошибка: " << e.what() << endl;
        return 1;
    } catch (const exception& e) {
        cerr << "Неожиданная ошибка: " << e.what() << endl;
        return 2;
    } catch (...) {
        cerr << "Неизвестная ошибка" << endl;
        return 3;
    }

    return 0;
}

// M_PI
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include "Point.h"
#include "Angle.h"
#include "Rectangle.h"

using namespace std;

/*
 * @brief Основная функция программы.
 * @return Возвращает 0 в случае успешного завершения программы.
 */
int main() {
    // Ввод 3х точек.
    Point a, b, c;

    cout << "A (x, y): ";
    cin >> a;
    if (!cin) {
        cerr << "number expected\n";
        return 1;
    }

    cout << "B (x, y): ";
    cin >> b;
    if (!cin) {
        cerr << "number expected\n";
        return 1;
    }

    cout << "C (x, y): ";
    cin >> c;
    if (!cin) {
        cerr << "number expected\n";
        return 1;
    }

    // Вывод введённых точек.
    cout << "A = " << a << endl;
    cout << "B = " << b << endl;
    cout << "C = " << c << endl;

    Rectangle* rect = nullptr;

    try {
        rect = new Rectangle(a, b, c);
    } catch (const char* erMsg) {
        cerr << "Error: " << erMsg << endl;
        if (rect) {
            delete rect;
        }
        return 1;
    }

    // Вычисляем радиус окружности, описанной около прямоугольника
    double radius = rect->getCircumscribedCircleRadius();

    // Вычисляем площадь круга
    double square = M_PI * radius * radius;

    // Вывод ответа
    cout << "Radius = " << radius << endl;
    cout << "Square = " << square << endl;

    // Очистка памяти на куче
    delete rect;

    return 0;
}

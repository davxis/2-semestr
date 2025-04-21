// M_PI
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include "Point.h"
#include "Angle.h"
#include "Rectangle.h"
#include <cstdlib> // exit()

using namespace std;

Point readPoint();

/*
 * @brief Основная функция программы.
 * @return Возвращает 0 в случае успешного завершения программы.
 */
int main() {
    // Ввод 3х точек.
    Point a, b, c;

    cout << "A (x, y): ";
    Point a = readPoint();
    
    cout << "B (x, y): ";
    Point b = readPoint();

    cout << "C (x, y): ";
    Point c = readPoint();

    // Вывод введённых точек.
    cout << "A = " << a << endl;
    cout << "B = " << b << endl;
    cout << "C = " << c << endl;

    double radius;
    double square;
    try {
        Rectangle rect(a, b, c);

        // Вычисляем радиус окружности, описанной около прямоугольника
        radius = rect.getCircumscribedCircleRadius();

        // Вычисляем площадь круга
        square = rect.getCircumscribedCircleSquare();
    } catch (const char* erMsg) {
        cerr << "Error: " << erMsg << endl;
        return 1;
    }


    // Вывод ответа
    cout << "Radius = " << radius << endl;
    cout << "Square = " << square << endl;

    return 0;
}

// readPoint считывает точку с устройства ввода по умолчанию.
// Если не удалось считать, то происходит выход из программы и сообщение об ошибке.
Point readPoint() {
    Point resultPoint;
    cin >> resultPoint;
    if (!cin) {
        cerr << "number expected\n";
        exit(EXIT_FAILURE);
    }
    return resultPoint;
}

#include "class.cpp"
/*
 * @brief Основная функция программы.
 * @return Возвращает 0 в случае успешного завершения программы.
 */

int main() {
    // Ввод 3х точек.
    Point a, b, c;
    cout << "A (x, y): ";
    cin >> a;
    cout << "B (x, y): ";
    cin >> b;
    cout << "C (x, y): ";
    cin >> c;

    // Вывод введённых точек.
    cout << "A = " << a << endl;
    cout << "B = " << b << endl;
    cout << "C = " << c << endl;

    // Проверка, что точки не совпадают
    if (a == b) {
        cout << "Point A should not be the same as B" << endl;
        return 1;
    }
    if (a == c) {
        cout << "Point A should not be the same as C" << endl;
        return 1;
    }
    if (b == c) {
        cout << "Point B should not be the same as C" << endl;
        return 1;
    }

    // Вычисление углов: являются ли прямые
    Angle angleA(b, a, c), angleB(a, b, c), angleC(a, c, b);
    bool aIsRight, bIsRight, cIsRight;
    aIsRight = angleA.isRight();
    bIsRight = angleB.isRight();
    cIsRight = angleC.isRight();

    // Проверка, что хотя бы 1 из углов прямой
    if (!aIsRight && !bIsRight && !cIsRight) {
        cout << "There should be at least 1 angle between points which is right" << endl;
        return 1;
    }

    // Выбираем точки `p` и `q` не того угла, который прямой
    Point p, q;
    if (aIsRight) {
        p = b;
        q = c;
    } else if (bIsRight) {
        p = a;
        q = c;
    } else {
        p = a;
        q = b;
    }

    // Вычисляем диаметр окружности, описанной около прямоугольника.
    double dx = p.getX() - q.getX();
    double dy = p.getY() - q.getY();
    double diameter = sqrt(dx * dx + dy * dy);

    // Вычисляем радиус этой окружности
    double radius = diameter / 2;

    // Вычисляем площадь круга
    double square = M_PI * radius * radius;

    // Вывод ответа
    cout << "Radius = " << radius << endl;
    cout << "Square = " << square << endl;

    return 0;
}

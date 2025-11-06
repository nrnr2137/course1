#include <iostream>
#include "functions.h"
#include "lab1_functions.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    int choice;
    cout << "Введите номер пункта для выполнения (1 или 2): ";
    cin >> choice;

    if (choice == 1) {
        int a, b, c;
        cout << "Введите три целых числа (через пробел): ";
        cin >> a >> b >> c;

        // Определяем количество чисел по правилу "если число = 0, считаем что его нет"
        int count = 0;
        if (a != 0) count++;
        if (b != 0) count++;
        if (c != 0) count++;

        cout << "Количество ненулевых чисел: " << count << endl;

        int result;
        if (count == 1) {
            // Находим ненулевое число
            int num = (a != 0) ? a : ((b != 0) ? b : c);
            result = processNumber(num);
        }
        else if (count == 2) {
            // Для двух чисел - просто вызываем функцию без условий
            // Находим два ненулевых числа
            int num1, num2;
            if (a != 0 && b != 0) {
                num1 = a; num2 = b;
            }
            else if (a != 0 && c != 0) {
                num1 = a; num2 = c;
            }
            else {
                num1 = b; num2 = c;
            }
            result = processNumbers(num1, num2);
        }
        else if (count == 3) {
            result = processNumbers(a, b, c);
        }
        else {
            // Все числа нули
            cout << "Все числа равны нулю! Используется функция для одного числа с нулем." << endl;
            result = processNumber(0);
        }

        cout << "Результат вычисления: " << result << endl;

    }
    else if (choice == 2) {
        int radius;
        cout << "Введите радиус сферы: ";
        cin >> radius;
        Sphere(radius);
    }
    else {
        cout << "Неверный выбор! Допустимые значения: 1 или 2." << endl;
    }

    return 0;
}
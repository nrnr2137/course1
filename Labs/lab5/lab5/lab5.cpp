#include <iostream>
#include "functions.h"
#include "lab1_functions.h"

using namespace std;

int main() 
{
    setlocale(LC_ALL, "Russian");

    int choice;
    cout << "Введите номер пункта для выполнения (1 или 2): ";
    cin >> choice;

    if (choice == 1)
    {
        int a, b, c;
        cout << "Введите три целых числа: ";
        cin >> a >> b >> c;

        int count = 0;
        if (a != 0) count++;
        if (b != 0) count++;
        if (c != 0) count++;

        cout << "Количество ненулевых чисел: " << count << endl;

        int result;
        if (count == 1)
        {
            int num = (a != 0) ? a : ((b != 0) ? b : c);
            result = processNumber(num);
        }
        else if (count == 2) 
        {
            int num1 = ((a != 0) ? a : b), num2 = ((c != 0) ? c : b);
            result = processNumbers(num1, num2);
        }
        else if (count == 3) 
        {
            result = processNumbers(a, b, c);
        }
        else
        {
            cout << "Все числа равны нулю! " << endl;
            result = 0;
        }

        cout << "Результат вычисления: " << result << endl;

    }
    else if (choice == 2)
    {
        int radius;
        cout << "Введите радиус сферы: ";
        cin >> radius;
        Sphere(radius);
    }
    else 
    {
        cout << "Неверный выбор! Допустимые значения: 1 или 2." << endl;
    }

    return 0;
}
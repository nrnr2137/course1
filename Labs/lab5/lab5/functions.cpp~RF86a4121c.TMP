#include <iostream>
#include <cmath>
#include <algorithm>
#include "functions.h"

using namespace std;

int processNumber(int a) {
    cout << "исп. функция для одного числа - подсчет повторений максимальной цифры" << endl;

    cout << "Число: " << a << endl;

    int temp = abs(a);
    int count = 0;
    int maxDigit = 0;
    while (temp > 0) {
        int digit = temp % 10;
        if (digit > maxDigit) {

            maxDigit = digit;
        }
        else if (digit == maxDigit) {
            count++;
        }
        temp /= 10;
    }

    cout << "Максимальная цифра: " << maxDigit << ", повторяется " << count << " раз(а)" << endl;

    return count;
}

int processNumbers(int a, int b) {
    cout << "исп. функция для двух чисел" << endl;
    cout << "Числа: " << a << ", " << b << endl;

    // Для двух чисел не выполняем никаких условий - просто возвращаем 0
    // или можно вернуть какое-то базовое значение
    int result = 0;
    cout << "Для двух чисел не выполняются условия - возвращаем: " << result << endl;

    return result;
}

int processNumbers(int a, int b, int c) {
    cout << "исп. функция для трех чисел" << endl;
    cout << "Числа: " << a << ", " << b << ", " << c << endl;

    if (a != b && a != c && b != c) {
        cout << "Все числа разные - вычисляем среднюю по модулю величину" << endl;

        int absA = abs(a);
        int absB = abs(b);
        int absC = abs(c);

        // Находим максимальное и минимальное по модулю
        int maxAbs = max({ absA, absB, absC });
        int minAbs = min({ absA, absB, absC });

        // Средняя по модулю величина - находим число, которое не макс и не мин
        int result;
        if (absA != maxAbs && absA != minAbs) {
            result = a;
            cout << "Средняя по модулю величина: " << a << " (между " << minAbs << " и " << maxAbs << ")" << endl;
        }
        else if (absB != maxAbs && absB != minAbs) {
            result = b;
            cout << "Средняя по модулю величина: " << b << " (между " << minAbs << " и " << maxAbs << ")" << endl;
        }
        else {
            result = c;
            cout << "Средняя по модулю величина: " << c << " (между " << minAbs << " и " << maxAbs << ")" << endl;
        }

        return result;
    }
    else {
        // Есть одинаковые числа - возвращаем минимальное
        cout << "Есть одинаковые числа - возвращаем минимальное" << endl;
        int result = min({ a, b, c });
        cout << "Минимальное число: " << result << endl;
        return result;
    }
}
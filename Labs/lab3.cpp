#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    int N;
    cout << "введите количество чисел в последовательности: " ;
    cin >> N;

    //Пункт 1

    int sum = 0; /* сумма всех отрицательных чисел */
    int max = INT_MIN; /*наибольшее отрицательное число*/
    int povtr = 0; /*  количество повторений наибольшего отрицательного числа */

    for (int i = 0; i < N; i++)
    {
        int num;
        cout << "введите число A" << (i + 1) << ": ";
        cin >> num;

        if (num >= 0) 
        {
            continue;
        }

        sum += num;

        if (num > max) 
        {
            max = num;
            povtr += 1;
        }
        else if (num == max)
        {
            povtr++;
        }
    }

    if (povtr == 0)
    {
        cout << "в последовательности нет отрицательных чисел." << endl;
    }
    else
    {
        cout << "сумма всех отрицательных чисел: " << sum << endl;
        cout << "наибольшее отрицательное число: " << max << endl;
        cout << "количество повторений наибольшего отрицательного числа: " << povtr << endl;
    }

    //пункт 2
    int X;
    cout << "введите целое число |X| < 1000: ";
    cin >> X;


    while (abs(X) >= 1000)
    {
        cout << "введите число от -999 до 999: ";
        cin >> X;
    }

    int n = abs(X);
    int m = 0; // максимальная цифра
    do
    {
        int c = n % 10;
        if (c > m)
        {
            m = c;
        }
        n/= 10;
    } while (n > 0);

    cout << "Наибольшая цифра числа " << X << ": " << m << endl;

    return 0;

}
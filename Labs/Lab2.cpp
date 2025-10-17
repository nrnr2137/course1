#include <iostream>
#include <locale>
#include <bitset>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int i;
    short A;
    cout << "Введите число A: ";
    cin >> A;
    cout << "Введите число i [0-7]: ";
    cin >> i;
    // проверка i 
    if (i < 0 || i >7)
    {
        cout << " Ошибка!  Введите число от 0 до 7:";
    }
    cout << "A в двоичной = " << bitset<8>(A) << endl;
    short bit = (A >> i) & 1;
    cout << "Значение " << i << " бита: " << bit << endl;
    // пункт 1 (основа) 
    if (bit != 0) {
        int A, B, C;
        cout << "Введите A (целое число) :";
        cin >> A;
        cout << "Введите B (целое число) :";
        cin >> B;
        cout << "Введите C (целое число) :";
        cin >> C;
        if (A < B && B < C) {
            cout << C - B - A << " , " << bitset<8>(C - B - A) << endl;
        }
        else if (A % C == 0) {
            cout << A / C + B << " , " << bitset<8>(A / C + B) << endl;
        }
        else
        {
            cout << A + B + C << " , " << bitset<8>(A + B + C) << endl;
        }
    }
    // побитовое сложение A с самим собой
    else
    {
        bitset<8> r = bitset<8>(A) | bitset<8>(A);
        cout << "Побитовая сумма A с самим собой:" << r << endl;
    }
    // пункт 2
    int N;
    cout << "Введите номер несяца [1-12] :";
    cin >> N;

    switch (N)
    {
    case 1:case 3:case 5:case 7:case 8:case 10:case 12:
        cout << "31 день" << " , " << bitset<8>(31) << endl;
        break;

    case 4:case 6:case 9:case 11:
        cout << "30 дней" << " , " << bitset<8>(30) << endl;
        break;

    case 2:
        cout << "28 дней" << " , " << bitset<8>(28) << endl;
        break;

    default:
        cout << " Ошибка!  Введите число от 1 до 12: ";
        break;

    }
    return 0;


}

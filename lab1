/* используя радиус сферы и свою константу вычислить:
 1. объем сферы
 2. площадь сферы */

#include <iostream>
#include <locale>
#include <cmath>
#include <limits>
#include <typeinfo>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian"); 
    const float n = 13.1415; // тип данных для дробной константы
    int r;
    cout << "Введите радиус: ";
    cin >> r;
    float v = (4 * n * pow(r, 3)) / 3;
    float s = 4 * n * pow(r, 2);
    cout << "Объем = " << v<< " " << typeid(v).name() << endl;
    cout << "Площадь = " << s << " " << typeid(v).name() << endl;
    cout << "Мининальное значение int: " << numeric_limits<int>::min()<<endl;
    cout << "Мининальное значение float: " << - numeric_limits<float>::max() << endl;
    cout << "Максимальное значение int: " << numeric_limits<int>::max() << endl;
    cout << "Максимальное значение float: " << numeric_limits<float>::max() << endl;
    cout << "Размер int в битах " << sizeof(int) * 8<< endl;
    cout << "Размер float в битах " << sizeof(float) * 8 << endl;

    return 0;
}

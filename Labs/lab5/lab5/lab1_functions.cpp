/* использу€ радиус сферы и свою константу вычислить:
 1. объем сферы
 2. площадь сферы */

#include <iostream>
#include <locale>
#include <cmath>
#include <limits>
#include <typeinfo>
using namespace std;

void Sphere(int r)
{
    cout << "используетс€ функци€ из лабораторной работы 1" << endl;
    //setlocale(LC_ALL, "Russian");
    const double n = 13.1415; // тип данных дл€ дробной константы
    double v = (4 * n * pow(r, 3)) / 3;
    double s = 4 * n * pow(r, 2);
    cout << "ѕлощадь:"<< s << endl;
    cout << "ќбъем:"<< v << endl;
}
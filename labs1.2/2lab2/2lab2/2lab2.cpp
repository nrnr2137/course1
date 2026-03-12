#include <iostream>
#include <string>
#include <vector>
#include "Book.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    vector<string> titl1 = {"Преступление и наказание", "Белые ночи", "Бесы"};
    Book book1("Федор Достоевский", titl1, 672, 500.0);

    vector<string> titl2 = { "Бесы", "Братья Карамазовы", "Записки из подполья" };
    Book book2("Федор Достоевский", titl2, 928, 600.0);

    vector<string> titl3 = { "Война и мир", "Анна Каренина", "Воскресение" };
    Book book3("Лев Толстой", titl3, 1225, 700.0);

    cout << "Информация о книге 1:" << endl;
    book1.v();

    cout << "\nИнформация о книге 2:" << endl;
    book2.v();

    cout << "\nИнформация о книге 3:" << endl;
    book3.v();

    // тесты
    cout << "\nТест оператора + с одним автором " << endl;
    Book result1 = book1 + book2;
    result1.v();

    cout << "\nТест оператора + с разными авторами" << endl;
    Book result2 = book1 + book3;
    result2.v();

    cout << "\nТест оператора += с одним автором " << endl;
    Book book4 = book1;
    book4 += book2;
    book4.v();

    cout << "\nТест оператора += с разными авторами " << endl;
    Book book5 = book1;
    book5 += book3;
    book5.v();


    cout << "\nТест оператора / с одним автором" << endl;
    Book result4 = book1 / book2;
    result4.v();

    cout << "\nТест оператора / с разными авторами" << endl;
    Book result3 = book1 / book3;
    result3.v();

    cout << "\nТест правила трёх" << endl;
    Book book6(book3);
    cout << "Копия book3 через конструктор копирования:" << endl;
    book6.v();

    return 0;
}
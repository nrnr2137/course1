#include <iostream>
#include <string>
#include <vector>
#include "Book.hpp"
#include "Shelf.hpp"
#include "Bookmark.hpp"

using namespace std;

void rating()
{
    cout << "\nОценка лабораторнгй работы" << endl;
    cout << "Интерес: да" << endl;
    cout << "Наполненность: да" << endl;
    cout << "Сложность: да" << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    // Создаем оригиналы книг в стеке
    vector<string> titl1 = { "Преступление и наказание", "Белые ночи", "Бесы" };
    Book book1("Федор Достоевский", titl1, 672, 500.0);

    vector<string> titl2 = { "Бесы", "Братья Карамазовы", "Записки из подполья" };
    Book book2("Федор Достоевский", titl2, 928, 600.0);

    vector<string> titl3 = { "Война и мир", "Анна Каренина", "Воскресение" };
    Book book3("Лев Толстой", titl3, 1225, 700.0);

    cout << "\nИнформация о книге 1:" << endl;
    book1.print();

    cout << "\nИнформация о книге 2:" << endl;
    book2.print();

    cout << "\nИнформация о книге 3:" << endl;
    book3.print();

    cout << "\nТест оператора + с одним автором:" << endl;
    Book result1 = book1 + book2;
    result1.print();

    cout << "\nТест оператора / с разными авторами:" << endl;
    Book result2 = book1 / book3;
    result2.print();

    book1.ratepositive();
    book1.ratepositive();
    book1.ratenegative();
    cout << "\nТекущий рейтинг книги 1: " << book1.getrating() << endl;

    cout << "\nТекущая стоимость книги 2: " << book2.getprice() << " руб." << endl;
    book2.changeprice(50.0);
    cout << "+50руб: " << book2.getprice() << " руб." << endl;
    book2.changeprice(-100.0);
    cout << "-100руб: " << book2.getprice() << " руб." << endl;

    cout << "\nУстанавливаем флажок в книгу 1:" << endl;
    book1.setbookmark(150, "синий", "пластик");
    book1.printwithbm();

    cout << "\nПеремещаем флажок на 50 страниц вперед:" << endl;
    book1.movebookmark(50);
    book1.printwithbm();

    cout << "\nИспользуем операторы ++ и -- для флажка:" << endl;
    Bookmark* bm = book1.getbookmark();
    if (bm != nullptr)
    {
        ++(*bm);
        cout << "После префиксного ++: ";
        bm->print();

        (*bm)++;
        cout << "После постфиксного ++: ";
        bm->print();

        --(*bm);
        cout << "После префиксного --: ";
        bm->print();

        (*bm)--;
        cout << "После постфиксного --: ";
        bm->print();
    }

    cout << "\nУдаляем флажок:" << endl;
    book1.removebookmark();

    // Создаем полку
    Shelf shelf(5);
    cout << "\nСоздана полка вместимостью 5 книг:" << endl;
    shelf.print();

    cout << "\nДобавляем книги на полку (только указатели на оригиналы):" << endl;
    shelf.addBook(&book1);
    shelf.addBook(&book2);
    shelf.addBook(&book3);

    cout << "\nПопытка добавить книгу 1 повторно:" << endl;
    shelf.addBook(&book1);
    cout << "\nСостояние полки после добавления:" << endl;
    shelf.printDetailed();

    cout << "\nСортируем книги по автору:" << endl;
    shelf.sortByAuthor();
    shelf.printDetailed();

    cout << "\nСортируем книги по названию:" << endl;
    shelf.sortByTitle();
    shelf.printDetailed();

    cout << "\nПроверка вместимости:" << endl;
    cout << "Полка заполнена? " << (shelf.isFull() ? "Да" : "Нет") << endl;
    cout << "Книг на полке: " << shelf.getBookCount() << "/" << shelf.getCapacity() << endl;

    cout << "\nУдаляем книгу с индексом 1:" << endl;
    shelf.removeBook(1);
    shelf.print();

    cout << "\nОчищаем полку (убираем все указатели):" << endl;
    shelf.clear();
    shelf.print();

    cout << "\nПроверка оригиналов книг после очистки полки:" << endl;
    cout << "Книга 1: " << endl;
    book1.print();
  
    rating();

    cout << "\nПрограмма завершена. Деструкторы оригиналов будут вызваны автоматически." << endl;
    return 0;
}
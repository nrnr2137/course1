#include <iostream>
#include <string>

using namespace std;

class Book 
{
private:
    string author;
    string title;
    int pagecount;
    double rating;
    double price;

public:
    // конструктор по умолчанию
    Book() 
    {
        author = "";
        title = "";
        pagecount = 0;
        rating = 0.0;
        price = 0.0;
    }

    // конструктор полного заполнения
    Book(string auth, string titl, int pages, double rate, double pr) 
    {
        setauthor(auth);
        settitle(titl);
        setpage(pages);
        setrating(rate);
        setprice(pr);
    }

    // конструктор копирования
    Book(const Book& cop)
    {
        author = cop.author;
        title = cop.title;
        pagecount = cop.pagecount;
        rating = cop.rating;
        price = cop.price;
    }

    // деструктор
    ~Book()
    {
        cout << "Деструктор для книги: " << title << endl;
    }

    // сеттеры

    void setauthor(const string& auth) 
    {
        if (!auth.empty())
        {
            author = auth;
        }
    }

    void settitle(const string& ttl) 
    {
        if (!ttl.empty())
        {
            title = ttl;
        }
    }

    void setpage(int pages)
    {
        if (pages > 0) 
        {
            pagecount = pages;
        }
    }

    void setrating(double rat)
    {
        if (rat >= 0.0 && rat <= 10.0) 
        {
            rating = rat;
        }
    }

    void setprice(double prc)
    {
        if (prc >= 0.0) 
        {
            price = prc;
        }
    }

    // геттеры
    string getauthor() const { return author; }
    string gettitle() const { return title; }
    int getpagecount() const { return pagecount; }
    double getrating() const { return rating; }
    double getprice() const { return price; }

    // вывод
    void v() const
    {
        cout << "\nИнформация о книге" << endl;
        cout << "Автор: " << author << endl;
        cout << "Название: " << title << endl;
        cout << "Количество страниц: " << pagecount << endl;
        cout << "Оценка: " << rating << "/10" << endl;
        cout << "Стоимость: " << price << " руб." << endl;
    }

    // Изменение стоимости (с параметром)
    void changeprice(double npr)
    {
        if (npr > 0.0)
        {
            price = npr;
            cout << "Стоимость изменена на: " << npr << " руб." << endl;
        }
        else 
        {
            cout << "Ошибка: стоимость не может быть отрицательной" << endl;
        }
    }
};

int main() 
{
    setlocale(LC_ALL, "Russian");

    Book book1;

    Book book2("Федор Достоевский", "Преступление и наказание",
        672, 9.5, 450.0);

    book1.setauthor("Лев Толстой");
    book1.settitle("Война и мир");
    book1.setpage(1225);
    book1.setrating(9.8);
    book1.setprice(1200.0);

    cout << "Демонстрация геттеров" << endl;
    cout << "Автор книги: " << book1.getauthor() << endl;
    cout << "Оценка книги: " << book1.getrating() << endl;

    // вывод информации
    cout << "\nИнформация о книге 1:" << endl;
    book1.v();

    cout << "\nИнформация о книге 2:" << endl;
    book2.v();

    // изменение стоимости
    cout << "\nИзменение стоимости книги 1:" << endl;
    cout << "Старая стоимость: " << book1.getprice() << endl;
    book1.changeprice(999.99);
    cout << "Новая стоимость: " << book1.getprice() << endl;

    // конструктор копирования
    Book book3(book2);
    cout << "\nСкопированная книга:" << endl;
    book3.v();

    // тестирование некорректных данных
    cout << "\nТестирование некорректных данных" << endl;
    Book testBook;
    testBook.setrating(15.0);
    testBook.setprice(-100.0);
    testBook.setpage(-50);

    cout << "\nПроверка значений после некорректного ввода:" << endl;
    cout << "Оценка: " << testBook.getrating() << " (15.0)" << endl;
    cout << "Цена: " << testBook.getprice() << " (-100.0)" << endl;
    cout << "Страниц: " << testBook.getpagecount() << " (-50)" << endl;

    return 0;
}
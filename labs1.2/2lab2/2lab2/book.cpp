#include "Book.h"
#include <algorithm>

// конструктор по умолчанию
Book::Book()
{
    author = "";
    titles.clear();
    pagecount = 0;
    price = 0.0;
}

// конструктор полного заполнения
Book::Book(string auth, vector<string> titl, int pages, double pr)
{
    setauthor(auth);
    setworks(titl);
    setpage(pages);
    setprice(pr);
}

// конструктор копирования
Book::Book(const Book& cop)
{
    author = cop.author;
    titles = cop.titles;
    pagecount = cop.pagecount;
    price = cop.price;
}

// деструктор
Book::~Book()
{
    titles.clear();
    cout << "Деструктор для книги. Автор: " << author << endl;
}

// оператор присваивания (правило трёх)
Book& Book::operator=(const Book& other)
{
    if (this != &other)
    {
        author = other.author;
        titles = other.titles;
        pagecount = other.pagecount;
        price = other.price;
    }
    return *this;
}

// оператор + (только для разных авторов)
Book Book::operator+(const Book& other) const
{
    if (author == other.author)
    {
        cout << "Ошибка: оператор + можно использовать только для книг разных авторов!" << endl;
        cout << "Вывод первой книги:" << endl;
        return *this;
    }

    Book result;

    result.author = author + " и " + other.author;
    result.pagecount = pagecount + other.pagecount;
    result.price = (price + other.price) * 0.85;

    vector<string> alltitl;

    for (int i = 0; i < titles.size(); i++)
    {
        string formatted = author + " " + titles[i];
        if (find(alltitl.begin(), alltitl.end(), formatted) == alltitl.end())
        {
            alltitl.push_back(formatted);
        }
    }

    for (int i = 0; i < other.titles.size(); i++)
    {
        string formatted = other.author + " " + other.titles[i];
        if (find(alltitl.begin(), alltitl.end(), formatted) == alltitl.end())
        {
            alltitl.push_back(formatted);
        }
    }

    result.titles = alltitl;
    return result;
}

// оператор += (только для одного автора)
Book& Book::operator+=(const Book& other)
{
    if (author != other.author)
    {
        cout << "Ошибка: оператор += можно использовать только для книг одного автора!" << endl;
        return *this;
    }

    Book result;
    result.author = author; 
    result.pagecount = pagecount + other.pagecount;
    result.price = (price + other.price) * 0.85;

    vector<string> allWorks;

    for (int i = 0; i < titles.size(); i++)
    {
        if (find(allWorks.begin(), allWorks.end(), titles[i]) == allWorks.end())
        {
            allWorks.push_back(titles[i]);
        }
    }

    for (int i = 0; i < other.titles.size(); i++)
    {
        if (find(allWorks.begin(), allWorks.end(), other.titles[i]) == allWorks.end())
        {
            allWorks.push_back(other.titles[i]);
        }
    }

    result.titles = allWorks;

    *this = result;
    return *this;
}

// оператор /
Book Book::operator/(const Book& other) const
{
    Book result;

    if (author == other.author)
    {
        result.author = author;
    }
    else
    {
        result.author = author + " и " + other.author;
    }

    result.pagecount = pagecount + other.pagecount;
    result.pagecount = result.pagecount * 0.7;
    result.price = (price + other.price) * 1.1;

    vector<string> parttitl;

    if (author == other.author)
    {
        int maxs;
        if (titles.size() < other.titles.size())
            maxs = titles.size();
        else
            maxs = other.titles.size();

        for (int i = 0; i < maxs; i += 2)
        {
            if (i < titles.size() && find(parttitl.begin(), parttitl.end(), titles[i]) == parttitl.end())
            {
                parttitl.push_back(titles[i]);
            }
            if (i < other.titles.size() && find(parttitl.begin(), parttitl.end(), other.titles[i]) == parttitl.end())
            {
                parttitl.push_back(other.titles[i]);
            }
        }
    }
    else
    {
        int maxs;
        if (titles.size() < other.titles.size())
            maxs = titles.size();
        else
            maxs = other.titles.size();

        for (int i = 0; i < maxs; i += 2)
        {
            if (i < titles.size())
            {
                string form = author + " " + titles[i];
                if (find(parttitl.begin(), parttitl.end(), form) == parttitl.end())
                {
                    parttitl.push_back(form);
                }
            }
            if (i < other.titles.size())
            {
                string form = other.author + other.titles[i];
                if (find(parttitl.begin(), parttitl.end(), form) == parttitl.end())
                {
                    parttitl.push_back(form);
                }
            }
        }
    }

    result.titles = parttitl;
    return result;
}

// сеттеры
void Book::setauthor(const string& auth)
{
    if (!auth.empty())
    {
        author = auth;
    }
}

void Book::setworks(const vector<string>& wrks)
{
    titles = wrks;
}

void Book::setpage(int pages)
{
    if (pages > 0)
    {
        pagecount = pages;
    }
}

void Book::setprice(double pr)
{
    if (pr >= 0.0)
    {
        price = pr;
    }
}

// геттеры
string Book::getauthor() const { return author; }
vector<string> Book::getworks() const { return titles; }
int Book::getpagecount() const { return pagecount; }
double Book::getprice() const { return price; }

// вывод
void Book::v() const
{
    cout << "Автор: " << author << endl;
    cout << "Произведения: ";
    for (int i = 0; i < titles.size(); i++)
    {
        if (i > 0) cout << ", ";
        cout << titles[i];
    }
    cout << endl;
    cout << "Количество страниц: " << pagecount << endl;
    cout << "Стоимость: " << price << " руб." << endl;
}
#include "Book.h"
#include <algorithm>
#include <cstdlib>
#include <ctime>

Book::Book()
{
    author = "";
    titles.clear();
    pagecount = 0;
    price = 0.0;
}
Book::Book(string auth, vector<string> titl, int pages, double pr)
{
    setauthor(auth);
    setworks(titl);
    setpage(pages);
    setprice(pr);
}
Book::Book(const Book& cop)
{
    author = cop.author;
    titles = cop.titles;
    pagecount = cop.pagecount;
    price = cop.price;
}
Book::~Book()
{
    titles.clear();
    cout << "Деструктор для книги. Автор: " << author << endl;
}
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
Book Book::operator+(const Book& other) const
{
    Book result;

    result.pagecount = pagecount + other.pagecount;
    result.price = (price + other.price) * 0.85;
    vector<string> alltitl;

    if (author == other.author)
    {
        result.author = author;
        for (int i = 0; i < titles.size(); i++)
        {
            if (find(alltitl.begin(), alltitl.end(), titles[i]) == alltitl.end())
            {
                alltitl.push_back(titles[i]);
            }
        }

        for (int i = 0; i < other.titles.size(); i++)
        {
            if (find(alltitl.begin(), alltitl.end(), other.titles[i]) == alltitl.end())
            {
                alltitl.push_back(other.titles[i]);
            }
        }

    }
    else
    {
        for (int i = 0; i < titles.size(); i++)
        {
            string at = author + " " + titles[i];
            if (find(alltitl.begin(), alltitl.end(), at) == alltitl.end())
            {
                alltitl.push_back(at);
            }
        }

        for (int i = 0; i < other.titles.size(); i++)
        {
            string at = other.author + " " + other.titles[i];
            if (find(alltitl.begin(), alltitl.end(), at) == alltitl.end())
            {
                alltitl.push_back(at);
            }
        }
        result.author = author + " и " + other.author;
    }

    result.titles = alltitl;
    return result;
}
Book& Book::operator+=(const Book& other)
{
    pagecount += other.pagecount;
    price = (price + other.price) * 0.85;

    if (author == other.author)
    {
        for (int i = 0; i < other.titles.size(); i++)
        {
            titles.push_back(other.titles[i]);
        }

        sort(titles.begin(), titles.end());
        titles.erase(unique(titles.begin(), titles.end()), titles.end());
    }
    else
    {
        for (int i = 0; i < titles.size(); i++)
        {
            titles[i] = author + " " + titles[i];
        }

        for (int i = 0; i < other.titles.size(); i++)
        {
            titles.push_back(other.author + " " + other.titles[i]);
        }

        sort(titles.begin(), titles.end());
        titles.erase(unique(titles.begin(), titles.end()), titles.end());

        author = author + " и " + other.author;
    }

    return *this;
}

Book Book::operator/(const Book& other) const
{
    Book result;

    result.pagecount = (pagecount + other.pagecount) * 0.7;
    result.price = (price + other.price) * 1.1;
    vector<string> alltitl;

    srand(time(0));

    int fir = 1 + rand() % max(1, (int)titles.size());
    int sec = 1 + rand() % max(1, (int)other.titles.size());

    if (author == other.author)
    {
        result.author = author;

        vector<string> firtitl = titles;
        random_shuffle(firtitl.begin(), firtitl.end());

        for (int i = 0; i < fir && i < firtitl.size(); i++)
        {
            if (find(alltitl.begin(), alltitl.end(), firtitl[i]) == alltitl.end())
            {
                alltitl.push_back(firtitl[i]);
            }
        }

        vector<string> sectitl = other.titles;
        random_shuffle(sectitl.begin(), sectitl.end());

        for (int i = 0; i < sec && i < sectitl.size(); i++)
        {
            if (find(alltitl.begin(), alltitl.end(), sectitl[i]) == alltitl.end())
            {
                alltitl.push_back(sectitl[i]);
            }
        }
    }
    else
    {
        result.author = author + " и " + other.author; 

        vector<string> firtitl = titles;
        random_shuffle(firtitl.begin(), firtitl.end());

        for (int i = 0; i < fir && i < firtitl.size(); i++)
        {
            string at = author + " " + firtitl[i];
            if (find(alltitl.begin(), alltitl.end(), at) == alltitl.end())
            {
                alltitl.push_back(at);
            }
        }

        vector<string> sectitl = other.titles;
        random_shuffle(sectitl.begin(), sectitl.end());

        for (int i = 0; i < sec && i < sectitl.size(); i++)
        {
            string at = other.author + " " + sectitl[i];
            if (find(alltitl.begin(), alltitl.end(), at) == alltitl.end())
            {
                alltitl.push_back(at);
            }
        }
    }

    random_shuffle(alltitl.begin(), alltitl.end());
    result.titles = alltitl;
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
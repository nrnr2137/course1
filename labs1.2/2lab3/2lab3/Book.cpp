#include "Book.hpp"
#include <algorithm>
#include <cstdlib>
#include <ctime>

Book::Book()
{
    author = "";
    titles.clear();
    pagecount = 0;
    price = 0.0;
    rating = 0;
    bookmark = nullptr;
}

Book::Book(string auth, vector<string> titl, int pages, double pr)
{
    setauthor(auth);
    setworks(titl);
    setpage(pages);
    setprice(pr);
    rating = 0;
    bookmark = nullptr;
}

Book::Book(const Book& cop)
{
    author = cop.author;
    titles = cop.titles;
    pagecount = cop.pagecount;
    price = cop.price;
    rating = cop.rating;

    if (cop.bookmark != nullptr) 
    {
        bookmark = new Bookmark(*cop.bookmark);
    }
    else
    {
        bookmark = nullptr;
    }
}

Book::~Book()
{
    titles.clear();
    delete bookmark; 
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
        rating = other.rating;

        delete bookmark;
        if (other.bookmark != nullptr) 
        {
            bookmark = new Bookmark(*other.bookmark);
        }
        else {
            bookmark = nullptr;
        }
    }
    return *this;
}

Book Book::operator+(const Book& other) const
{
    Book result;

    result.pagecount = pagecount + other.pagecount;
    result.price = (price + other.price) * 0.85;
    result.rating = rating + other.rating;
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
    rating += other.rating;

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
    result.rating = (rating + other.rating) / 2;
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

// Сеттеры
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

void Book::setrating(int rate)
{
    rating = rate;
}

// Изменение стоимости
void Book::changeprice(double x)
{
    if (price + x >= 0) 
    {
        price += x;
    }
    else
    {
        price = 0;
    }
}

// Оценить книгу
void Book::ratepositive()
{
    rating++;
    cout << "Книга \"" << author << "\" получила +1 к рейтингу! Текущий рейтинг: " << rating << endl;
}

void Book::ratenegative()
{
    rating--;
    cout << "Книга \"" << author << "\" получила -1 к рейтингу. Текущий рейтинг: " << rating << endl;
}

// Работа с флажком
void Book::setbookmark(int page, string color, string material)
{
    if (page > 0 && page <= pagecount) 
    {
        delete bookmark;
        bookmark = new Bookmark(page, color, material);
        cout << "Флажок установлен на странице " << page << endl;
    }
    else {
        cout << "Cтраница " << page << " не существует в книге!" << endl;
    }
}

void Book::removebookmark()
{
    if (bookmark != nullptr)
    {
        delete bookmark;
        bookmark = nullptr;
        cout << "Флажок удален" << endl;
    }
    else 
    {
        cout << "В книге нет флажка" << endl;
    }
}

void Book::movebookmark(int pages)
{
    if (bookmark != nullptr)
    {
        int newPage = bookmark->getPage() + pages;
        if (newPage > 0 && newPage <= pagecount) 
        {
            bookmark->setPage(newPage);
            cout << "Флажок перемещен на страницу " << newPage << endl;
        }
        else 
        {
            cout << "Нельзя переместить флажок за пределы книги!" << endl;
        }
    }
    else
    {
        cout << "В книге нет флажка" << endl;
    }
}

// Геттеры
string Book::getauthor() const { return author; }
vector<string> Book::getworks() const { return titles; }
int Book::getpagecount() const { return pagecount; }
double Book::getprice() const { return price; }
int Book::getrating() const { return rating; }
Bookmark* Book::getbookmark() const { return bookmark; }

// Вывод информации
void Book::print() const
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
    cout << "Рейтинг: " << rating << endl;
}

void Book::printwithbm() const
{
    print();
    if (bookmark != nullptr) {
        cout << "Флажок: ";
        bookmark->print();
    }
    else {
        cout << "Флажок: отсутствует" << endl;
    }
}
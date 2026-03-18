#include "Shelf.hpp"

Shelf::Shelf()
{
    maxS = 10;
    books.clear();
}

Shelf::Shelf(int capacity)
{
    if (capacity > 0)
    {
        maxS = capacity;
    }
    else
    {
        maxS = 10;
    }
    books.clear();
}

Shelf::~Shelf()
{
    books.clear(); // Просто очищаем вектор, не удаляя книги
    cout << "Деструктор полки" << endl;
}

// Добавление книги на полку (только по указателю на оригинал)
bool Shelf::addBook(Book* book)
{
    if (book == nullptr)
    {
        cout << "Ошибка: книга не существует" << endl;
        return false;
    }

    if (books.size() >= maxS)
    {
        cout << "Ошибка: полка заполнена, максимум " << maxS << " книг" << endl;
        return false;
    }

    // Проверка на уникальность (поиск по адресу)
    for (Book* existingBook : books)
    {
        if (existingBook == book)
        {
            cout << "Ошибка: эта книга уже находится на полке!" << endl;
            return false;
        }
    }

    books.push_back(book);
    cout << "Книга \"" << book->getauthor() << "\" добавлена на полку" << endl;
    return true;
}

// Убрать книгу с полки (только убирает указатель)
bool Shelf::removeBook(int index)
{
    if (index < 0 || index >= books.size())
    {
        cout << "Ошибка: неверный индекс книги" << endl;
        return false;
    }

    cout << "Книга \"" << books[index]->getauthor() << "\" удалена с полки" << endl;
    books.erase(books.begin() + index);
    return true;
}

void Shelf::sortByTitle()
{
    sort(books.begin(), books.end(), [](Book* a, Book* b)
        {
            if (a == nullptr || b == nullptr) return false;
            vector<string> worksA = a->getworks();
            vector<string> worksB = b->getworks();

            if (worksA.empty() && worksB.empty()) return false;
            if (worksA.empty()) return false;
            if (worksB.empty()) return true;

            return worksA[0] < worksB[0];
        });

    cout << "Полка отсортирована по названиям книг" << endl;
}

void Shelf::sortByAuthor()
{
    sort(books.begin(), books.end(), [](Book* a, Book* b)
        {
            if (a == nullptr || b == nullptr) return false;
            return a->getauthor() < b->getauthor();
        });

    cout << "Полка отсортирована по авторам" << endl;
}

Book* Shelf::getBook(int index) const
{
    if (index >= 0 && index < books.size())
    {
        return books[index];
    }
    return nullptr;
}

int Shelf::getBookCount() const
{
    return books.size();
}

int Shelf::getCapacity() const
{
    return maxS;
}

bool Shelf::isEmpty() const
{
    return books.empty();
}

bool Shelf::isFull() const
{
    return books.size() >= maxS;
}

void Shelf::clear()
{
    books.clear();
    cout << "Полка очищена" << endl;
}

void Shelf::print() const
{
    cout << "Полка" << endl;
    cout << "Вместимость: " << maxS << " книг" << endl;
    cout << "Книг на полке: " << books.size() << endl;

    if (books.empty())
    {
        cout << "Полка пуста" << endl;
    }
    else
    {
        cout << "Список книг:" << endl;
        for (int i = 0; i < books.size(); i++)
        {
            if (books[i] != nullptr)
            {
                cout << i + 1 << ". " << books[i]->getauthor()
                    << " - \"" << books[i]->getworks()[0] << "\""
                    << " (стр. " << books[i]->getpagecount() << ")" << endl;
            }
        }
    }
}

void Shelf::printDetailed() const
{
    cout << "Полка(подробно)" << endl;
    cout << "Вместимость: " << maxS << " книг" << endl;
    cout << "Книг на полке: " << books.size() << endl;

    if (books.empty())
    {
        cout << "Полка пуста" << endl;
    }
    else {
        for (int i = 0; i < books.size(); i++)
        {
            cout << "\nКнига " << i + 1 << endl;
            if (books[i] != nullptr)
            {
                books[i]->printwithbm();
            }
            else {
                cout << "Ошибка: нулевой указатель" << endl;
            }
        }
    }
}
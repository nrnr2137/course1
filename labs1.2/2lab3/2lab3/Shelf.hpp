#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include "Book.hpp"

using namespace std;

class Shelf
{
private:
    vector<Book*> books;  // Только указатели на оригиналы
    int maxS;       

public:
    Shelf();
    Shelf(int capacity); 
    Shelf(const Shelf& other) = delete; // Запрещаем копирование
    ~Shelf();

    Shelf& operator=(const Shelf& other) = delete; // Запрещаем присваивание

    // Добавление книги (только по указателю на оригинал)
    bool addBook(Book* book);
    
    // Удаление книги (только убирает указатель)
    bool removeBook(int index);

    // Сортировка
    void sortByTitle();
    void sortByAuthor();

    // По индексу
    Book* getBook(int index) const;

    // Количество книг на полке
    int getBookCount() const;

    // Вместимость
    int getCapacity() const;

    // Пуста ли полка
    bool isEmpty() const;

    // Заполнена ли полка
    bool isFull() const;

    // Очистить полку (только убирает указатели)
    void clear();

    // Вывод информации о полке
    void print() const;
    void printDetailed() const;
};
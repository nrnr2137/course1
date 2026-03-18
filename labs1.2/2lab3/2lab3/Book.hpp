#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Bookmark.hpp"

using namespace std;

class Book
{
private:
    string author;
    vector<string> titles;
    int pagecount;
    double price;

    int rating; 
    Bookmark* bookmark;

public:
    Book(); 
    Book(string auth, vector<string> titl, int pages, double pr); 
    Book(const Book& cop); 

    // Деструктор
    ~Book();

    // Правило трёх
    Book& operator=(const Book& other);

    // Операторы
    Book operator+(const Book& other) const;
    Book& operator+=(const Book& other);
    Book operator/(const Book& other) const;

    // Сеттеры
    void setauthor(const string& auth);
    void setworks(const vector<string>& titl);
    void setpage(int pages);
    void setprice(double pr);

    void setrating(int rate);

    // Изменение стоимости
    void changeprice(double x);

    // Оценить книгу
    void ratepositive(); 
    void ratenegative(); 

    // Флажок
    void setbookmark(int page, string color, string material);
    void removebookmark();
    void movebookmark(int pages); 

    // Геттеры
    string getauthor() const;
    vector<string> getworks() const;
    int getpagecount() const;
    double getprice() const;

    int getrating() const;
    Bookmark* getbookmark() const;

    // Вывод информации
    void print() const;
    void printwithbm() const;
};
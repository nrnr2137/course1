#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Book
{
private:
    string author;
    vector<string> titles;
    int pagecount;
    double price;

public:
    // конструктор по умолчанию
    Book();
    // конструктор полного заполнения
    Book(string auth, vector<string> titl, int pages, double pr);
    // конструктор копирования
    Book(const Book& cop);
    // деструктор
    ~Book();
    // (правило трёх)
    Book& operator=(const Book& other);

    // операторы
    Book operator+(const Book& other) const;
    Book& operator+=(const Book& other);
    Book operator/(const Book& other) const;

    // сеттеры
    void setauthor(const string& auth);
    void setworks(const vector<string>& titl);
    void setpage(int pages);
    void setprice(double pr);

    // геттеры
    string getauthor() const;
    vector<string> getworks() const;
    int getpagecount() const;
    double getprice() const;

    // вывод
    void v() const;
};
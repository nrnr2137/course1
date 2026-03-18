#pragma once

#include <iostream>
#include <string>

using namespace std;

struct Bookmark
{
private:
    string color;
    string material;
    int page;

public:
    Bookmark();
    Bookmark(int p, string c, string m);
    Bookmark(const Bookmark& other);

    ~Bookmark();

    Bookmark& operator++();   
    Bookmark operator++(int); 
    Bookmark& operator--();    
    Bookmark operator--(int);  

    // Сеттеры
    void setColor(string c);
    void setMaterial(string m);
    void setPage(int p);

    // Геттеры
    string getColor() const;
    string getMaterial() const;
    int getPage() const;

    // Вывод информации
    void print() const;
};
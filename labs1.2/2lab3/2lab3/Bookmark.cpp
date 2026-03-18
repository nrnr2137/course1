#include "Bookmark.hpp"

Bookmark::Bookmark()
{
    color = "красный";
    material = "бумага";
    page = 1;
}

Bookmark::Bookmark(int p, string c, string m)
{
    setPage(p);
    setColor(c);
    setMaterial(m);
}

Bookmark::Bookmark(const Bookmark& other)
{
    color = other.color;
    material = other.material;
    page = other.page;
}

Bookmark::~Bookmark()
{
    cout << "Деструктор флажка (страница " << page << ")" << endl;
}

Bookmark& Bookmark::operator++()
{
    page++;
    return *this;
}

Bookmark Bookmark::operator++(int)
{
    Bookmark temp = *this;
    page++;
    return temp;
}

Bookmark& Bookmark::operator--()
{
    if (page > 1)
    {
        page--;
    }
    return *this;
}

Bookmark Bookmark::operator--(int)
{
    Bookmark temp = *this;
    if (page > 1)
    {
        page--;
    }
    return temp;
}

void Bookmark::setColor(string c)
{
    if (!c.empty()) 
    {
        color = c;
    }
}

void Bookmark::setMaterial(string m)
{
    if (!m.empty())
    {
        material = m;
    }
}

void Bookmark::setPage(int p)
{
    if (p > 0) 
    {
        page = p;
    }
}

string Bookmark::getColor() const { return color; }
string Bookmark::getMaterial() const { return material; }
int Bookmark::getPage() const { return page; }

void Bookmark::print() const
{
    cout << "страница " << page << ", цвет: " << color << ", материал: " << material << endl;
}
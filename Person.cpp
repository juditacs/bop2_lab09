#include <iostream>
#include <fstream>
#include "Person.h"

using namespace std;

void Person::save(std::ostream& os) const {
    os << (int)age << ';' << height << ';' << weight << endl;
}

void Person::load(std::istream &is)
{
    double height;
    double weight;
    int age;
    char c;
    is >> age;
    is >> c;
    if (c != ';')
        is.clear(ios::failbit);
    is >> height;
    is >> c;
    if (c != ';')
        is.clear(ios::failbit);
    is >> weight;
    if (is)
    {
        this->age = age;
        this->height = height;
        this->weight = weight;
    }
    else
    {
        cerr << "Error in input format." << endl;
    }
}
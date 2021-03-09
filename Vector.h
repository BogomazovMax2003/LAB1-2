#pragma once
#include <iostream>
using namespace std;
class Vector
{
    int size;
    int* myVec;
public:
    friend ostream& operator<<(ostream& out, const Vector& vector);
    Vector();
    Vector(const Vector& other);
    Vector(const size_t& size, const int& initValue);
    Vector& operator=(const Vector& other);
    ~Vector();
    int& operator [](size_t& index);
    size_t Size() const;
    int Find(const int& value) const;
    void push_back(const int& value);
    void replace(const int& oldValue, const int& newValue);

};
ostream& operator<<(ostream& out,const Vector& vector);




#include"Vector.h"
#include <iostream>
using namespace std;
// 1) ����������� �� ���������.
Vector::Vector():size(10) {

}

// 2) ����������� �����������.
Vector::Vector(const Vector& other) {
	int * c = new int(size);
	for (size_t i = 0; i < size; i++) {
		c[i] = other.myVec[i];	  
	}
}
// 3) ����������� � �����������.
Vector::Vector(const size_t& size, const int& initValue) {
	int* c = new int(size);
	for (size_t i = 0; i < size; i++) {
		c[i] = initValue;
	}
}
// 4) �������� ��������������� �����������.
Vector& Vector::operator = (const Vector& other) {
	if (this == &other) {
		return * this;
	}
	delete[] this->myVec;
	this->myVec = new int[other.size];
	this->size = other.size;
	for (size_t i = 0; i < other.size; i++) {
		this->myVec[i] = other.myVec[i];
	}
	return *this;
}
// 5) ����������.
Vector::~Vector() {
	delete[] myVec;
}

//6)�������� [].
int& Vector::operator []( size_t& index) {
	return myVec[index];
}
//7)������� ������� ����-�� ���������.
size_t Vector::Size() const {
	return this->size;
}
//8)������� ������.
int Vector::Find(const int& value) const {
	int z = 0;
	for (int i = 0; i < this->size; i++) {
		if (z == 0 and this->myVec[i] == value) {
			return i;
			z++;
		}
	}
}
//9) ������� ���������� �������� � �����.
void Vector::push_back(const int& value) {
	int* c = new int(size+10);
	for (size_t i = 0; i < size; i++) {
		c[i] = this->myVec[i];
	}
	c[size + 1] = value;
	delete[] this;
	size += 10;
}
//10)������� ������ ������ �������� �� ������.
void Vector::replace(const int& oldValue, const int& newValue) {
	int g = 0;
	g=Find(oldValue);
	myVec[g] = newValue;
}
//11) �������� ������ �� �������.
ostream& operator<<(ostream& out, const Vector& vector) {
	int z = 0;
	z = vector.Size();
		for (size_t i = 0; i < z;z++) {
			out << vector.myVec[i] << ' ';
	}
		return out;
}
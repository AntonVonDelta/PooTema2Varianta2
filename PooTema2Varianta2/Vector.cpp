#include "Vector.h"

Vector::Vector():capacity(0), memory(nullptr) {}

Vector::Vector(int dimension,Complex* memory){
	this->capacity = dimension;
	this->memory = new Complex[dimension];
	memcpy(this->memory, memory, dimension * sizeof(Complex));
}
Vector::Vector(const Vector& other) {
	this->capacity = other.capacity;
	this->memory = new Complex[capacity];
	memcpy(this->memory, other.memory, capacity * sizeof(Complex));
}
Vector::~Vector() {
	delete[] this->memory;
}

Vector& Vector::operator=(const Vector& other) {
	delete[] this->memory;
	this->capacity = other.capacity;
	this->memory = new Complex[capacity];
	memcpy(this->memory, other.memory, this->capacity * sizeof(Complex));

	return *this;
}

std::ostream& operator<<(std::ostream& cout, const Vector& obj) {
	for (int i = 0; i < obj.capacity; i++) {
		cout << obj.memory[i];
		if (i != obj.capacity - 1) cout << ",";
	}
	return cout;
}
std::istream& operator>>(std::istream& cin, Vector& obj) {
	cin >> obj.capacity;
	delete[] obj.memory;
	obj.memory = new Complex[obj.capacity];

	for (int i = 0; i < obj.capacity; i++) {
		cin >> obj.memory[i];
	}
	return cin;
}
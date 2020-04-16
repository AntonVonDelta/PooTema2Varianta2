#include "Stiva.h"

Stiva::Stiva():Vector(),front(-1) {
	this->capacity = 4;		// Add first memory
	this->memory = new Complex[this->capacity];
}
Stiva::Stiva(int capacity, Complex* memory) : Vector(capacity, memory),front(capacity-1) {}
Stiva::Stiva(const Stiva& other):Vector(other),front(other.front) {}

Stiva& Stiva::operator=(const Stiva& other) {
	delete[] this->memory;
	this->capacity = other.capacity;
	this->memory = new Complex[this->capacity];
	memcpy(this->memory, other.memory, other.capacity * sizeof(Complex));

	front = other.front;

	return *this;
}

Complex Stiva::pop() {
	if (front == -1) throw 10;
	Complex res = memory[front--];

	return res;
}
void Stiva::push(Complex nr) {
	if (front == capacity - 1) {
		// Buffer full
		// Allocate new memory to accomodate the size
		Complex* old_memory = this->memory;
		int old_capacity = this->capacity;

		this->capacity = old_capacity+4;		// Add Inertial memory
		this->memory = new Complex[this->capacity];
		memcpy(this->memory, old_memory, old_capacity * sizeof(Complex));
		delete[] old_memory;
	}

	memory[++front] = nr;
}

bool Stiva::isCompletelyImaginary() {
	if (isEmpty()) return false;

	for (int i = 0; i < front + 1; i++) {
		if (!memory[i].isImaginary()) return false;
	}

	return true;
}

std::ostream& operator<<(std::ostream& cout, const Stiva& obj) {
	if (obj.isEmpty()) {
		cout << "(empty)";
		return cout;
	}
	Vector temp(obj.front + 1, obj.memory);

	cout << temp;
	return cout;
}
std::istream& operator>>(std::istream& cin, Stiva& obj) {
	int count = 0;
	cin >> count;

	for (int i = 0; i < count; i++) {
		Complex temp;
		cin >> temp;
		obj.push(temp);
	}

	return cin;
}
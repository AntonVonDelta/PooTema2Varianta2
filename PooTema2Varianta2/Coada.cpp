#include "Coada.h"
#include "Exceptions.h"

Coada::Coada():Vector(),end(0),front(-1){
	capacity = 4;
	memory = new Complex[capacity];
}
Coada::Coada(int capacity, Complex* memory) : Vector(capacity, memory), end(0),front(capacity-1) {}
Coada::Coada(const Coada& other) : Vector(other), end(other.end),front(other.front) {}

Coada& Coada::operator=(const Coada& other) {
	delete[] this->memory;
	this->capacity = other.capacity;
	this->memory = new Complex[other.capacity];
	memcpy(this->memory, other.memory, other.capacity * sizeof(Complex));

	end = other.end;
	front = other.front;

	return *this;
}

void Coada::push(Complex nr) {
	if (front==capacity-1) {
		// Buffer full
		// Allocate new memory to accomodate the size
		Complex* old_memory = memory;
		int old_capacity = capacity;

		capacity += 2;
		memory = new Complex[capacity];
		memcpy(memory, old_memory, old_capacity * sizeof(Complex));
		delete[] old_memory;
	}
	
	memory[++front] = nr;
	remap();
}

Complex Coada::pop() {
	if (end > front) throw ExceptionOutOfMemory();
	if (end == capacity) throw ExceptionOutOfMemory();
	
	Complex res=memory[end++];
	remap();

	return res;
}

void Coada::remap() {
	if (end == front && end != -1) {
		memory[0] = memory[end];
		end = 0;
		front = 0;
	}
	if (end > front && front!=-1) {
		end = 0;
		front = -1;
	}
}

bool Coada::isCompletelyImaginary() {
	if (isEmpty()) return false;

	for (int i = end; i < front + 1; i++) {
		if (!memory[i].isImaginary()) return false;
	}

	return true;
}

std::ostream& operator<<(std::ostream& cout, const Coada& obj) {
	if (obj.isEmpty()) {
		cout << "(empty)";
		return cout;
	}

	Vector temp(obj.front - obj.end+1, obj.memory + obj.end);
	cout << temp;

	return cout;
}
std::istream& operator>>(std::istream& cin, Coada& obj) {
	int count = 0;
	cin >> count;

	for (int i = 0; i < count; i++) {
		Complex temp;
		cin >> temp;
		obj.push(temp);
	}
	return cin;
}
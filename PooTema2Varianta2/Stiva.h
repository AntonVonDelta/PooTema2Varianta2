#pragma once
#include "Vector.h"

class Stiva :public Vector {
	int front;			// The front index of the stack

public:
	Stiva();
	Stiva(int, Complex*);
	Stiva(const Stiva&);
	~Stiva() = default;

	Stiva& operator=(const Stiva&);
	void push(Complex);
	Complex pop();
	bool isEmpty() const { return front == -1; }
	bool isCompletelyImaginary();

	friend std::ostream& operator<<(std::ostream&, const Stiva&);
	friend std::istream& operator>>(std::istream&, Stiva&);
};

#pragma once
#include "Vector.h"
class Coada :public Vector {
	int end;
	int front;

public:
	Coada();
	Coada(int, Complex*);
	Coada(const Coada&);
	~Coada()=default;

	Coada& operator=(const Coada&);

	void push(Complex);
	Complex pop();
	bool isEmpty() const { return end>front; }
	void remap();
	bool isCompletelyImaginary();

	friend std::ostream& operator<<(std::ostream&, const Coada&);
	friend std::istream& operator>>(std::istream&, Coada&);
};


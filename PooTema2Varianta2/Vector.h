#pragma once
#include "Complex.h"
#include <iostream>

class Vector {
protected:
	int capacity;
	Complex* memory;

public:
	Vector();
	Vector(int, Complex*);
	Vector(const Vector&);
	~Vector();

	Vector& operator=(const Vector&);

	// I need this class NOT to be abstract otherwise I can't use in in the extended classes
	// Thus I can't make these two methods abstract...nevermind..just throw error
	virtual void push(Complex) {
		throw 22;		// Not implemented
	}
	virtual Complex pop() {
		throw 22;		// Not implemented
	}

	friend std::ostream& operator<<(std::ostream&, const Vector&);
	friend std::istream& operator>>(std::istream&, Vector&);
};


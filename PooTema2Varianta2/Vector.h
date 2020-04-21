#pragma once
#include "Complex.h"
#include "Exceptions.h"
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

	// I need this class NOT to be abstract otherwise I can't use in in the extended classes (e.g in cout and cin I construct a temp array of objects of this class)
	// Thus I can't make these two methods abstract...nevermind..just throw error
	virtual void push(Complex) {
		throw NotImplemented();		// Not implemented
	}
	virtual Complex pop() {
		throw NotImplemented();		// Not implemented
	}

	friend std::ostream& operator<<(std::ostream&, const Vector&);
	friend std::istream& operator>>(std::istream&, Vector&);
};


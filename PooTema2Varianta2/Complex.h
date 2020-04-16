#pragma once
#include <iostream>

class Complex {
	private:
		float re, img;

public:
	Complex();
	Complex(float, float);
	Complex(const Complex&);
	~Complex() = default;

	Complex& operator=(const Complex&);
	bool isImaginary() const { return re == 0 && img != 0; }
	friend std::ostream& operator<<(std::ostream&, const Complex&);
	friend std::istream& operator>>(std::istream&, Complex&);
};


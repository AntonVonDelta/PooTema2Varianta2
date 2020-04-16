#include "Complex.h"

Complex::Complex():re(0),img(0) {}
Complex::Complex(float re, float img) {
	this->re = re;
	this->img = img;
}
Complex::Complex(const Complex& other) {
	re = other.re;
	img = other.img;
}

Complex& Complex::operator=(const Complex& other) {
	re = other.re;
	img = other.img;
	return *this;
}

std::ostream& operator<<(std::ostream& cout, const Complex& obj) {
	cout << obj.re << "+" << obj.img << "*i";
	return cout;
}
std::istream& operator>>(std::istream& cin, Complex& obj) {
	cin >> obj.re >> obj.img;
	return cin;
}
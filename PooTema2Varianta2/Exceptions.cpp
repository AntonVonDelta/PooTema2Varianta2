#include <iostream>
#include <exception>
#include "Exceptions.h"
using namespace std;

const char* ExceptionOutOfMemory::what() const throw() {
    return "Not enough memory! Buffer overflow/underflow";
}

const char* NotImplemented::what() const throw() {
    return "This function is not implemented yet!";
}
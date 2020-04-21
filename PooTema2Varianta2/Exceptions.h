#pragma once

#include <iostream>
#include <exception>

class ExceptionOutOfMemory :public std::exception {
public:
    const char* what() const throw();
};

class NotImplemented : public std::exception {
public:
    const char* what() const throw();
};
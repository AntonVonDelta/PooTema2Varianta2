#pragma once

#include <iostream>
#include <exception>

class ExceptionOutOfMemory :public std::exception {
public:
    ExceptionOutOfMemory() noexcept {}
    ExceptionOutOfMemory(const ExceptionOutOfMemory&) noexcept = default;
    ExceptionOutOfMemory& operator= (const ExceptionOutOfMemory&) noexcept = default;
    virtual ~ExceptionOutOfMemory() noexcept = default;
    const char* what() const throw();
};

class NotImplemented : public std::exception {
public:
    NotImplemented() noexcept {}
    NotImplemented(const NotImplemented&) noexcept = default;
    NotImplemented& operator= (const NotImplemented&) noexcept = default;
    virtual ~NotImplemented() noexcept = default;
    const char* what() const throw();
};
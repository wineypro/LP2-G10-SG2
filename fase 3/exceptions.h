#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>
#include <string>
#include <limits>
#include <iostream>

class SistemaCriticalException : public std::runtime_error {
public:
    SistemaCriticalException(const std::string& msg) : std::runtime_error(msg) {}
};

class InputDataException : public SistemaCriticalException {
public:
    InputDataException() : SistemaCriticalException("Error crítico en entrada de datos") {}
};

class MemoryAllocationException : public SistemaCriticalException {
public:
    MemoryAllocationException() : SistemaCriticalException("Error de asignación de memoria") {}
};

#endif
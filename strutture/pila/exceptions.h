#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <stdexcept>

struct emptyStack : public std::domain_error {
    emptyStack() : domain_error(
        "Pila vuota.") {};
};

#endif

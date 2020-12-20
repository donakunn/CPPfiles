#ifndef DICT_EXCEPTIONS_H
#define DICT_EXCEPTIONS_H
#include <stdexcept>

struct FullSize : public std::invalid_argument {
    FullSize() : invalid_argument(
        "Dimensione massima raggiunta.") {};
};

#endif

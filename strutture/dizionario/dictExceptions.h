#ifndef DICT_EXCEPTIONS_H
#define DICT_EXCEPTIONS_H
#include <stdexcept>

struct hash_table_full : public std::invalid_argument {
    hash_table_full() : invalid_argument(
        "Dimensione massima raggiunta.") {};
};

#endif

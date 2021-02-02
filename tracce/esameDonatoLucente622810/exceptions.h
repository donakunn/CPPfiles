#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <stdexcept>

struct AlreadyOnHead : public std::invalid_argument {
    AlreadyOnHead() : invalid_argument(
        "Already on the head of the list") {};
};

struct EndOfList : public std::invalid_argument {
    EndOfList() : invalid_argument(
        "Can't read from the end of list") {};
};

struct AliveCell : public std::domain_error {
    AliveCell() : domain_error(
        "Impossibile spostare, cella viva sulla cella di destinazione") {};
};

#endif

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

struct WrongRating : public std::domain_error {
    WrongRating() : domain_error(
        "Rating must be an integer 1 to 5") {};
};

#endif
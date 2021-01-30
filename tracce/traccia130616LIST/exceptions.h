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

struct EmptyGraph : public std::domain_error {
    EmptyGraph() : domain_error(
        "Grafo vuoto.") {};
};

struct NodeExists : public std::domain_error {
    NodeExists() : domain_error(
        "Nodo già presente.") {};
};

struct ArcExists : public std::domain_error {
    ArcExists() : domain_error(
        "Arco già presente.") {};
};

struct ArcExistsOnDel : public std::domain_error {
    ArcExistsOnDel() : domain_error(
        "Impossibile cancellare.esiste arco collegato al nodo") {};
};

struct ArcDoesntExists : public std::domain_error {
    ArcDoesntExists() : domain_error(
        "Arco già presente.") {};
};

#endif

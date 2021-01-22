#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <stdexcept>

struct NullNode : public std::invalid_argument {
    NullNode() : invalid_argument(
        "Parametro nodo nullo.") {};
};

struct EmptyGraph : public std::domain_error {
    EmptyTree() : domain_error(
        "Albero vuoto.") {};
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
        "Impossibile cancellare. 
        esiste arco collegato al nodo") {};
};

struct ArcDoesntExists : public std::domain_error {
    ArcDoesntExists() : domain_error(
        "Arco già presente.") {};
};

#endif

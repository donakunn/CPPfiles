#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <stdexcept>

struct NullNode : public std::invalid_argument {
    NullNode() : invalid_argument(
        "Parametro nodo nullo.") {};
};

struct RootExists : public std::domain_error {
    RootExists() : domain_error(
        "Radice già presente.") {};
};

struct EmptyTree : public std::domain_error {
    EmptyTree() : domain_error(
        "Albero vuoto.") {};
};

struct NodeExists : public std::domain_error {
    NodeExists() : domain_error(
        "Nodo già presente.") {};
};

struct LeafNode : public std::domain_error {
    LeafNode() : domain_error(
        "Nodo foglia.") {};
};

struct rootNode : public std::domain_error {
    rootNode() : domain_error(
        "Impossibile aggiungere fratello a radice.") {};
};


#endif

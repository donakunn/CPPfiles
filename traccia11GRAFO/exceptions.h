#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <stdexcept>

struct NullNode : public std::invalid_argument {
    NullNode() : invalid_argument(
        "Nodo non presente nel grafo.") {};
};

struct FullArray : public std::invalid_argument {
    FullArray() : invalid_argument(
        "Array pieno. impossibile aggiungere nodo") {};
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

#ifndef MSTACKS_
#define MSTACKS_
#include "pilapt.h"
#include <vector>

template <class T>
class MultipleStack
{
private:
    std::vector<Pila<T>> MS;

public:
    MultipleStack(const unsigned int);
    void Push(const T &, const unsigned int);
    T pop(const unsigned int);
    ~MultipleStack();
};

template <class T>
MultipleStack<T>::MultipleStack(const unsigned int n)
{
    for (int i = 0; i < n; i++)
    {
        MS.push_back(new Pila<T>);
    }
}

template <class T>
void MultipleStack<T>::Push(const T &elem, const unsigned int n)
{
    MS[n].inPila(T);
}

template<class T>
T MultipleStack<T>::pop(const unsigned int n){
    return MS[n].leggiPila();
}

template<class T>
MultipleStack<T>::~MultipleStack() {
    for (int i = 0; i < MS.size; i++) {
        delete MS[i];
    }

    delete MS;
}
#endif
#include <iostream>
#include "linked_list.h"

template <class T>
class Ordered_list
{
public:
    Ordered_list(const Linked_list<T> &);
    void insert(const T &);        // inserisce un elemento
    void remove(const T &);        // rimuove un elemento
    bool search(const T &) const;  // cerca un elemento
    void merge(Ordered_list<T> &); // fonde con una lista ordinata

private:
    Linked_list<T> L;
};

template <class T>
Ordered_list<T>::Ordered_list(const Linked_list<T> &orderedList)
{
    L = orderedList;
}

template <class T>
void Ordered_list<T>::insert(const T &element)
{
    typename Linked_list<T>::position position = L.begin();
    while (L.read(position) < element && !L.end(position))
    {
        position = next(position);
    }
    L.insert(element, position);
}
template <class T>
void Ordered_list<T>::remove(const T &element)
{
    typename Linked_list<T>::position position = L.begin();
    while (L.read(position) > element && !L.end(position))
    {
        if (L.read() == element)
            L.erase(position);
        else
            position = next(position);
    }
}

template <class T>
bool Ordered_list<T>::search(const T &element) const
{
    typename Linked_list<T>::position position = L.begin();
    while (L.read(position) > element && !L.end(position))
    {
        if (L.read() == element)
            return true;
        else
            position = next(position);
    }
    return false;
}

template <class T>
void Ordered_list<T>::merge(Ordered_list<T> &L2)
{
    typename Linked_list<T>::position pB = L2.L.begin();
    while (!L2.end(pB))
    {
        this.insert(L2.read(pB));
        pB = L2.next(pB);
    }
}


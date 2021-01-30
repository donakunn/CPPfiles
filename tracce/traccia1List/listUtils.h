#ifndef LIST_UTILS_H
#define LIST_UTILS_H

#include "linked_list.h"

class listUtils
{
public:
    int freq(Linked_list<int> &, int);
    void hist(Linked_list<int> &);
    void remp(Linked_list<int> &);
};

int listUtils::freq(Linked_list<int> &L, int k)
{
    int freq = 0;
    Linked_list<int>::position pos;
    pos = L.begin();
    while (!L.end(pos))
    {
        if (L.read(pos) % k == 0)
            freq++;
        pos = L.next(pos);
    }
    return freq;
}
void listUtils::hist(Linked_list<int> &L)
{
    int freq;
    int currentValue;
    Linked_list<int>::position pos,posIn;
    pos = L.begin();
    while (!L.end(pos))
    {
        freq = 0;
        currentValue = L.read(pos);
        posIn = L.begin();
        while (!L.end(posIn)) {
            if (currentValue == L.read(posIn)) 
                freq++;
            posIn = L.next(posIn);
        }
        std::cout << "frequenza di " << currentValue << " = " << freq << endl;
        pos = L.next(pos);
    }
}
void listUtils::remp(Linked_list<int> &L)
{
    Linked_list<int>::position pos;
    pos = L.begin();
    while (!L.end(pos))
    {
        if (L.read(pos) % 2)
        {
            if (!L.end(L.previous(pos)))
                L.erase(L.previous(pos));
        }
        pos = L.next(pos);
    }
}

#endif
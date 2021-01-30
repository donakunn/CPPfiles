#include "listUtils.h"

int main() {
    Linked_list<int> L;
    typename Linked_list<int>::position pos;
    pos = L.begin();
    L.insert(2,L.begin());
    L.insert(4,L.begin());
    L.insert(8,L.begin());
    L.insert(3,L.begin());
    L.insert(5,L.begin());
    L.insert(23,L.begin());
    L.insert(12,L.begin());
    L.insert(11,L.begin());
    L.insert(7,L.begin());
    L.insert(19,L.begin());
    L.insert(4,L.begin());
    L.insert(4,L.begin());
    L.insert(2,L.begin());
    cout << L;
    listUtils utils;
    utils.remp(L);
    cout << L;
}
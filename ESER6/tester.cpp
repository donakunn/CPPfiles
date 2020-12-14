#include "dequeue.h"
#include <iostream>
using namespace std;

int main(){
    dequeue<int> coda;
    coda.push_back(3);
    coda.push_front(7);
    coda.push_front(8);
    int tmp;
    while (!coda.dequeueVuota()) {
        tmp = coda.pop_front();
        cout << tmp << " ";
    }
return 0;
}
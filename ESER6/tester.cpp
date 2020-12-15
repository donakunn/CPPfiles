#include "codapt.h"
#include <iostream>
using namespace std;

int main(){
    Coda<int> coda;
    coda.inCoda(3);
    coda.inCoda(7);
    coda.inCoda(8);

    Coda<int> coda2;
    coda2.inCoda(4);
    coda2.inCoda(4);
    coda2.inCoda(4);
    coda2 = coda;
    stampaCoda(coda2);
    int tmp;
    while (!coda2.codaVuota()) {
        tmp = coda2.leggiCoda();
        cout << tmp << " ";
        coda2.fuoriCoda();
    }
return 0;
}
#include "pilapt.h"
#include <iostream>
using namespace std;

int main(){
    Pila<int> coda;
    coda.inPila(3);
    coda.fuoriPila();
    if (coda.pilaVuota())
        cout << "pila vuota" << endl;
    coda.inPila(7);
     if (!coda.pilaVuota())
        cout << "pila vuota" << endl;
    coda.inPila(8);

    Pila<int> coda2(coda);
    stampaPila(coda2);
    int tmp;
    while (!coda2.pilaVuota()) {
        tmp = coda2.leggiPila();
        cout << tmp << " ";
        coda2.fuoriPila();
    }
return 0;
}
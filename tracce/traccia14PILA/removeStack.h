#ifndef REMOVE_STACK_H
#define REMOVE_STACK_H

#include "pilapt.h"
class remove_Stack
{
public:
    void rimuoviDaPila(Pila<int> &P, int k)
    {
        Pila<int> tmpStack;
        int actual;
        while (!P.pilaVuota())
        {
            actual = P.leggiPila();
            P.fuoriPila();
            if (actual <=k)
                tmpStack.inPila(actual);
        }

        while (!tmpStack.pilaVuota()) {
            P.inPila(tmpStack.leggiPila());
            tmpStack.fuoriPila();
        }
    }
};

#endif
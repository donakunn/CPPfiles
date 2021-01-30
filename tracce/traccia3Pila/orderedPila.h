#ifndef ORDERED_PILA_H
#define ORDERED_PILA_H

#include "pilapt.h"
class ordered_pila
{
public:
    void ordinaPila(Pila<int> &P)
    {

        Pila<int> tmpStack;
        while (!P.pilaVuota())
        {
            int actual = P.leggiPila();
            P.fuoriPila();
            while (!tmpStack.pilaVuota() && tmpStack.leggiPila() > actual)
            {
                P.inPila(tmpStack.leggiPila());
                tmpStack.fuoriPila();
            }
            tmpStack.inPila(actual);
        }
        P = tmpStack;
    }
};

#endif
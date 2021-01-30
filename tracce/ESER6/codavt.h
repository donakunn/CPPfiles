/***************************************************************************
 *   Copyright (C) 2005 by Nicola Di Mauro                                 *
 *   ndm@di.uniba.it                                                       *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#ifndef _CODAVT_
#define _CODAVT_

#include <iostream>

template <class tipoelem>
class Coda
{

public:
    Coda(int n)
    {
        maxlung = n;
        creaCoda();
    }

    ~Coda() { delete[] elementi; }

    void creaCoda()
    {
        elementi = new tipoelem[maxlung];
        testa = 0;
        lung = 0;
    }

    Coda(const Coda<tipoelem> &C) //Costruttore di copia
    {
        this->maxlung = C.maxlung;
        creaCoda();
        this->testa = C.testa;
        this->lung = C.lung;
        for (int i = 0; i < maxlung; i++)
        {
            this->elementi[i] = C.elementi[i];
        }
    }

    Coda<tipoelem> &operator=(const Coda<tipoelem> &C) //sovraccarico assegnamento
    {
        if (this != &C)
        {
            delete[] elementi;
            this->maxlung = C.maxlung;
            creaCoda();
            this->testa = C.testa;
            this->lung = C.lung;
            for (int i = 0; i < maxlung; i++)
            {
                this->elementi[i] = C.elementi[i];
            }
        }
        return *this;
    }

    bool codaVuota()
    {
        return (lung == 0);
    }

    tipoelem leggiCoda()
    {
        if (!codaVuota())
            return (elementi[testa]);
        else throw "Coda vuota";
    }

    void fuoriCoda()
    {
        if (!codaVuota())
        {
            testa = (testa + 1) % maxlung;
            lung--;
        }
    }

    void inCoda(tipoelem a)
    {
        if (lung != maxlung)
        {
            elementi[(testa + lung) % maxlung] = a;
            lung++;
        }
    }

    //data una coda di interi ne costruisca un'altra ottenuta dalla
    //prima considerando solo i valori positivi e conservando la coda originaria.
    Coda<int> soloPositivi(Coda<int> &C)
    {
        Coda<int> positiv(C.maxlung);
        Coda<int> codaTMP(C.maxlung);
        int tmp;
        while (!C.codaVuota())
        {
            tmp = C.leggiCoda();
            if (tmp > 0)
                positiv.inCoda(tmp);
            C.fuoriCoda();
            codaTMP.inCoda(tmp);
        }
        C = codaTMP;
        return positiv;
    }
template <class T>
friend void stampaCoda(Coda<T> &);

private:
    tipoelem *elementi;
    int testa, lung, maxlung;
};

template <class T>
void stampaCoda(Coda<T> &C) {
    Coda<T> tmpC = C;
    while(!tmpC.codaVuota()) {
        std::cout << tmpC.leggiCoda() << " ";
        tmpC.fuoriCoda();
    }
}

#endif //CODAVT_
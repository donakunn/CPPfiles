#ifndef BINS_H
#define BINS_H
#include "codapt.h"
#include <iostream>
#include <vector>

class Bins
{
public:
    Bins()
    {
         for (int i = 0; i < 3; i++)
        {
            bin.push_back(Coda<int>());
        }
    }
    ~Bins()
    {
    }
    // inserisce l’intero k nella corrispondente coda
    void insert(int k);
    // effettua un fuoriCoda dalla coda c
    void deleteVal(int c);
    // restituisce la media dei valori attualmente memorizzati nella coda c
    double mean(int c);
    // restituisce il numero di elementi inseriti nella coda c
    int freq(int c);

    void print()
    {
        for (int i = 0; i < 3; i++)
        {
            stampaCoda(bin[i]);
            std::cout << std::endl;
        }
    }

private:
    std::vector<Coda<int>> bin;
};

void Bins::insert(int k)
{
    if (k > 0 && k < 4)
        bin[0].inCoda(k);
    else if (k < 7)
        bin[1].inCoda(k);
    else if (k < 10)
        bin[2].inCoda(k);
    else
        throw "Numero non compreso tra 1 e 9";
}

void Bins::deleteVal(int c)
{
    bin[c].fuoriCoda();
}

double Bins::mean(int c)
{
    Coda<int> tmp;
    int sommaVal = 0;
    int curr;
    while (!bin[c].codaVuota())
    {
        curr = bin[c].leggiCoda();
        bin[c].fuoriCoda();
        sommaVal += curr;
        tmp.inCoda(curr);
    }
    while (!tmp.codaVuota())
    {
        bin[c].inCoda(tmp.leggiCoda());
        tmp.fuoriCoda();
    }
    return (sommaVal / freq(c));
}

int Bins::freq(int c)
{
    Coda<int> tmp;
    int nVal = 0;
    int curr;
    while (!bin[c].codaVuota())
    {
        curr = bin[c].leggiCoda();
        bin[c].fuoriCoda();
        nVal++;
        tmp.inCoda(curr);
    }
    while (!tmp.codaVuota())
    {
        bin[c].inCoda(tmp.leggiCoda());
        tmp.fuoriCoda();
    }
    return (nVal);
}
#endif
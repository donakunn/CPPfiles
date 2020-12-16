#ifndef _CODAPT_
#define _CODAPT_

#include <iostream>

template <class T>
class Coda;

template <class T>
class cella
{
    friend class Coda<T>;

private:
    T e;
    cella *prev;
    cella *succ;
};
template <class T>
class Coda
{

public:
    Coda();
    ~Coda();
    Coda(const Coda<T> &);               //Costruttore di copia
    Coda<T> &operator=(const Coda<T> &); //sovraccarico assegnamento
    bool codaVuota() const;
    T leggiCoda() const;
    void fuoriCoda();
    void inCoda(T a);

    //funzioni di utilità
    template <class elem>
    friend void stampaCoda(Coda<elem> &);
    int elementiInCoda();

private:
    cella<T> *testa;
    cella<T> *coda;
    int size;
};

template <class T>
Coda<T>::Coda()
{
    testa = nullptr;
    coda = nullptr;
    size = 0;
}

template <class T>
Coda<T>::~Coda()
{
    while (!codaVuota())
    {
        fuoriCoda();
    }
}

template <class T>
Coda<T>::Coda(const Coda<T> &C) //Costruttore di copia
{
    testa = nullptr;
    coda = nullptr;
    size = 0;

    cella<T> *t = C.testa;
    while (t != nullptr)
    {
        inCoda(t->e);
        t = t->succ;
    }
}

template <class T>
Coda<T> &Coda<T>::operator=(const Coda<T> &C) //sovraccarico assegnamento
{
    if (this != &C)
    {

        while (!codaVuota())
        {
            fuoriCoda();
        }

        cella<T> *t = C.testa;
        while (t != nullptr)
        {
            inCoda(t->e);
            t = t->succ;
        }
    }

    return *this;
}

template <class T>
bool Coda<T>::codaVuota() const
{
    return testa == nullptr;
}

template <class T>
T Coda<T>::leggiCoda() const
{
    if (!codaVuota())
        return testa->e;
    else
        throw "Coda vuota";
}

template <class T>
void Coda<T>::fuoriCoda()
{
    if (!codaVuota())
    {
        cella<T> *t = testa;
        testa = testa->succ;
        delete t;
        size--;
        if (size == 0)
            coda = nullptr;
    }
}

template <class T>
void Coda<T>::inCoda(T a)
{
    cella<T> *tmp = new cella<T>;
    if (codaVuota())
    {
        testa = tmp;
        coda = tmp;
    }
    else
        coda->succ = tmp;
    tmp->e = a;
    tmp->prev = coda;
    tmp->succ = nullptr;
    coda = tmp;
    size++;
}

template <class T>
int Coda<T>::elementiInCoda() { return size; }

template <class elem>
void stampaCoda(Coda<elem> &C)
{
    Coda<elem> tmpC = C;
    while (!tmpC.codaVuota())
    {
        std::cout << tmpC.leggiCoda() << " ";
        tmpC.fuoriCoda();
    }
}

#endif //CODAVT_
#ifndef GRAFOLIST_H
#define GRAFOLIST_H

#include "Grafo.h"
#include "linked_list.h"
#include "exceptions.h"
#include <iostream>

class NodoG
{
public:
    NodoG(int i)
    {
        nodoId = i;
    }
    NodoG()
    {
    }
    int getId() { return nodoId; }
    void setId(int id) { nodoId = id; }
    bool operator==(const NodoG &node) const
    {
        if (this->nodoId == node.nodoId)
            return true;
        else
            return false;
    }

private:
    int nodoId;
};

template <class P>
class InfoArco
{
public:
    P peso;
    NodoG _to;
};

template <class E, class P>
class InfoNodo
{
public:
    E etichetta;
    bool vuoto;
    void *info;
    Linked_list<InfoArco<P>> archi;

    InfoNodo()
    {
        info = 0;
        vuoto = true;
    }
    InfoNodo(const InfoNodo<E, P> &N)
    {
        this.etichetta = N.etichetta;
        this.vuoto = N.vuoto;
        this.info = N.info;
        this.archi = N.archi;
    }
    InfoNodo<E, P> &operator=(const InfoNodo<E, P> &N)
    {
        if (this != &N)
        {
            this->etichetta = N.etichetta;
            this->vuoto = N.vuoto;
            this->info = N.info;
            this->archi = N.archi;
        }
        return *this;
    }
};

template <class E, class P>
class GrafoList : public Grafo<E, P, NodoG>
{
public:
    typedef E Etichetta;
    typedef P Peso;
    typedef NodoG Nodo;
    typedef Arco_<Peso, Nodo> Arco;
    typedef Grafo<Etichetta, Peso, Nodo> Grafo_;
    typedef typename Grafo_::ListaNodi ListaNodi;
    typedef typename Grafo_::ListaNodiPos ListaNodiPos;

    GrafoList(int);
    GrafoList(const GrafoList<E, P> &);
    GrafoList<E, P> &operator=(const GrafoList<E, P> &);
    ~GrafoList();

    bool vuoto() const;
    void insNodo(NodoG &);
    void insArco(Nodo, Nodo, Peso);
    void cancNodo(Nodo);
    void cancArco(Nodo, Nodo);
    bool esisteNodo(Nodo);
    bool esisteArco(Nodo, Nodo);
    ListaNodi Adiacenti(Nodo);
    ListaNodi list_nodi() const;
    Etichetta leggiEtichetta(Nodo) const;
    void scriviEtichetta(Nodo, Etichetta);
    Peso leggiPeso(Nodo, Nodo) const;
    void scriviPeso(Nodo, Nodo, Peso);
    void print();

    int numNodi()
    {
        return nodi;
    };
    int numArchi()
    {
        return archi;
    };

private:
    InfoNodo<E, P> *arrayNodi;
    int dimensione;
    int nodi;
    int archi;
};

template <class E, class P>
GrafoList<E, P>::GrafoList(int _dimensione)
{
    dimensione = _dimensione;
    nodi = 0;
    archi = 0;
    arrayNodi = new InfoNodo<E, P>[dimensione];
    for (int i = 0; i < dimensione; i++)
        arrayNodi[i].archi.create();
}

template <class E, class P>
GrafoList<E, P>::GrafoList(const GrafoList<E, P> &G)
{
    this->dimensione = G.dimensione;
    this->nodi = G.nodi;
    this->archi = G.archi;
    arrayNodi = new InfoNodo<E, P>[dimensione];
    for (int i = 0; i < dimensione; i++)
    {
        this->arrayNodi[i] = G.arrayNodi[i];
    }
}

template <class E, class P>
GrafoList<E, P> &GrafoList<E, P>::operator=(const GrafoList<E, P> &G)
{
    if (this != &G)
    {
        delete[] arrayNodi;
        this->dimensione = G.dimensione;
        this->nodi = G.nodi;
        this->archi = G.archi;
        arrayNodi = new InfoNodo<E, P>[dimensione];
        for (int i = 0; i < dimensione; i++)
        {
            this->arrayNodi[i] = G.arrayNodi[i];
        }
    }
    return *this;
}

template <class E, class P>
GrafoList<E, P>::~GrafoList()
{
    delete[] arrayNodi;
}

template <class E, class P>
bool GrafoList<E, P>::vuoto() const
{
    return (nodi == 0);
}

template <class E, class P>
void GrafoList<E, P>::insNodo(Nodo &N)
{
    int n = 0;
    if (nodi < dimensione)
    {
        while (arrayNodi[n].vuoto == false)
            n++;
        nodi++;
        arrayNodi[n].vuoto = false;
        N.setId(n);
    }
    else
        throw FullArray();
}

template <class E, class P>
void GrafoList<E, P>::insArco(Nodo n1, Nodo n2, P peso)
{
    if (!esisteNodo(n1) || !esisteNodo(n2))
        throw NullNode();
    if (esisteArco(n1, n2))
        throw ArcExists();
    InfoArco<P> I;
    I.peso = peso;
    I._to = n2;
    arrayNodi[n1.getId()].archi.insert(I, arrayNodi[n1.getId()].archi.begin());
    archi++;
}

template <class E, class P>
void GrafoList<E, P>::cancNodo(Nodo n)
{
    if (!arrayNodi[n.getId()].archi.empty())
        throw ArcExistsOnDel();
    int i;
    typename Linked_list<InfoArco<P>>::position p;
    for (i = 0; i < dimensione; i++)
    {
        if (!arrayNodi[i].archi.empty())
        {
            p = arrayNodi[i].archi.begin();
            while (!arrayNodi[i].archi.end(p))
            {
                if (arrayNodi[i].archi.read(p)._to.getId() == n.getId())
                    throw ArcExistsOnDel();
                p = arrayNodi[i].archi.next(p);
            }
        }
    }
    arrayNodi[n.getId()].vuoto = true;
    nodi--;
}

template <class E, class P>
void GrafoList<E, P>::cancArco(Nodo n1, Nodo n2)
{
    typename Linked_list<InfoArco<P>>::position p;
    p = arrayNodi[n1.getId()].archi.begin();
    while (!arrayNodi[n1.getId()].archi.end(p))
    {
        if (arrayNodi[n1.getId()].archi.read(p)._to.getId() == n2.getId())
        {
            arrayNodi[n1.getId()].archi.erase(p);
            archi--;
            return;
        }
        else
            p = arrayNodi[n1.getId()].archi.next(p);
    }
}

template <class E, class P>
bool GrafoList<E, P>::esisteNodo(Nodo n)
{
    if (arrayNodi[n.getId()].vuoto == true)
    {
        return false;
    }
    else
        return true;
}

template <class E, class P>
bool GrafoList<E, P>::esisteArco(Nodo n1, Nodo n2)
{
    if (!esisteNodo(n1) || !esisteNodo(n2))
        throw NullNode();
    typename Linked_list<InfoArco<P>>::position p;
    p = arrayNodi[n1.getId()].archi.begin();
    while (!arrayNodi[n1.getId()].archi.end(p))
    {
        if (arrayNodi[n1.getId()].archi.read(p)._to.getId() == n2.getId())
            return true;
        else
            p = arrayNodi[n1.getId()].archi.next(p);
    }
    return false;
}

template <class E, class P>
typename GrafoList<E, P>::ListaNodi GrafoList<E, P>::Adiacenti(Nodo n)
{
    if (!esisteNodo(n))
        throw NullNode();
    ListaNodi list;
    typename Linked_list<InfoArco<P>>::position p;
    p = arrayNodi[n.getId()].archi.begin();
    while (!arrayNodi[n.getId()].archi.end(p))
    {
        list.insert(new NodoG(arrayNodi[n.getId()].archi.read(p)._to.getId()), list.begin());
        p = arrayNodi[n.getId()].archi.next(p);
    }
    return list;
}

template <class E, class P>
typename GrafoList<E, P>::ListaNodi GrafoList<E, P>::list_nodi() const
{
    ListaNodi list;
    for (int i = 0; i < dimensione; i++)
        if (!arrayNodi[i].vuoto)
            list.insert(new NodoG(i), list.begin());
    return list;
}

template <class E, class P>
E GrafoList<E, P>::leggiEtichetta(Nodo n) const
{
    return arrayNodi[n.getId()].etichetta;
}

template <class E, class P>
void GrafoList<E, P>::scriviEtichetta(Nodo n, E etichetta)
{
    arrayNodi[n.getId()].etichetta = etichetta;
}

template <class E, class P>
P GrafoList<E, P>::leggiPeso(Nodo n1, Nodo n2) const
{
    typename Linked_list<InfoArco<P>>::position p;
    p = arrayNodi[n1.getId()].archi.begin();
    while (!arrayNodi[n1.getId()].archi.end(p))
    {
        if (arrayNodi[n1.getId()].archi.read(p)._to.getId() == n2.getId())
            return arrayNodi[n1.getId()].archi.read(p).peso;
        else
            p = arrayNodi[n1.getId()].archi.next(p);
    }
    throw ArcDoesntExists();
}

template <class E, class P>
void GrafoList<E, P>::scriviPeso(Nodo n1, Nodo n2, P peso)
{
    typename Linked_list<InfoArco<P>>::position p;
    p = arrayNodi[n1.getId()].archi.begin();
    while (!arrayNodi[n1.getId()].archi.end(p))
    {
        if (arrayNodi[n1.getId()].archi.read(p)._to.getId() == n2.getId())
        {
            InfoArco<P> I;
            I.peso = peso;
            I._to = n2;
            arrayNodi[n1.getId()].archi.write(I, p);
            return;
        }
        else
            p = arrayNodi[n1.getId()].archi.next(p);
    }
    throw ArcDoesntExists();
}

template <class E, class P>
void GrafoList<E, P>::print()
{
    std::cout << "{\n";
    std::cout << "NumNodi: " << nodi << endl;
    std::cout << "\nNumArchi: " << archi << endl;
    std::cout << "\nnodi: ";
    GrafoList<E, P>::ListaNodi L = list_nodi();
    GrafoList<E, P>::ListaNodiPos p, s;
    p = L.begin();
    while (!L.end(p))
    {
        cout << leggiEtichetta(*(L.read(p))) << " ";
        p = L.next(p);
    }
    std::cout << endl;
    p = L.begin();
    while (!L.end(p))
    {
        if (!arrayNodi[L.read(p)->getId()].archi.empty())
        {
            GrafoList<E, P>::ListaNodi LAdiac = Adiacenti(*(L.read(p)));
            std::cout << "Adiacenti di " << leggiEtichetta(*(L.read(p))) << "--> ";
            s = LAdiac.begin();
            while (!LAdiac.end(s))
            {
                std::cout << leggiEtichetta(*(LAdiac.read(s))) << "["
                          << leggiPeso(*(L.read(p)), *(LAdiac.read(s))) << "] ";
                s = LAdiac.next(s);
            }
            std::cout << endl;
        }
        p = L.next(p);
    }
    std::cout << "}\n";
}
#endif

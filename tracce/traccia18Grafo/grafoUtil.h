#ifndef GRAFO_UTIL_H
#define GRAFO_UTIL_H
#include "GrafoList.h"

class grafoUtils
{
public:
    int countSame(GrafoList<int, int> &, NodoG &);
    double meanN2(GrafoList<int, int> &, NodoG &);

private:
    int countSame(GrafoList<int, int> &, NodoG &, bool *);
    double meanN2(GrafoList<int, int> &, NodoG &, bool *, int);
};

int grafoUtils::countSame(GrafoList<int, int> &G, NodoG &n1)
{
    int count = 0;
    bool visited[G.numNodi()];
    for (int i = 0; i < G.numNodi(); i++)
        visited[i] = false;
    typename GrafoList<int, int>::ListaNodi listaAdiacenti;
    typename GrafoList<int, int>::ListaNodiPos posLista;
    listaAdiacenti = G.Adiacenti(n1);
    posLista = listaAdiacenti.begin();
    while (!listaAdiacenti.end(posLista))
    {
        NodoG *current = listaAdiacenti.read(posLista);
        if (!visited[current->getId()] && G.leggiEtichetta(*(current)) == G.leggiEtichetta(n1))
        {
            count += countSame(G, *(current), visited);
        }
        posLista = listaAdiacenti.next(posLista);
    }
    return count;
}

int grafoUtils::countSame(GrafoList<int, int> &G, NodoG &n1, bool *visited)
{
    int count = 1;
    visited[n1.getId()] = true;
    typename GrafoList<int, int>::ListaNodi listaAdiacenti;
    typename GrafoList<int, int>::ListaNodiPos posLista;
    listaAdiacenti = G.Adiacenti(n1);
    posLista = listaAdiacenti.begin();
    while (!listaAdiacenti.end(posLista))
    {
        NodoG *current = listaAdiacenti.read(posLista);
        if (!visited[current->getId()] && G.leggiEtichetta(*(current)) == G.leggiEtichetta(n1))
        {
            count += countSame(G, *(current), visited);
        }
        posLista = listaAdiacenti.next(posLista);
    }
    return count;
}

double grafoUtils::meanN2(GrafoList<int, int> &G, NodoG &n1)
{
    bool visited[G.numNodi()];
    for (int i = 0; i < G.numNodi(); i++)
        visited[i] = false;
    return (meanN2(G, n1, visited, 0));
}

double grafoUtils::meanN2(GrafoList<int, int> &G, NodoG &n1, bool *visited, int h)
{
    double sum = 0, count = 0;
    double mean = 0;
    typename GrafoList<int, int>::ListaNodi listaAdiacenti;
    typename GrafoList<int, int>::ListaNodiPos posLista;
    listaAdiacenti = G.Adiacenti(n1);
    posLista = listaAdiacenti.begin();
    if (h == 1)
    {
        while (!listaAdiacenti.end(posLista))
        {
            NodoG *current = listaAdiacenti.read(posLista);
            if (!visited[current->getId()])
            {
                visited[current->getId()] = true;
                sum += G.leggiEtichetta(*(current));
                count++;
            }
            posLista = listaAdiacenti.next(posLista);
        }
        if (count != 0)
            mean = sum / count;
        return mean;
    }
    else
    {
        while (!listaAdiacenti.end(posLista))
        {
            NodoG *current = listaAdiacenti.read(posLista);
            if (!visited[current->getId()])
            {
                visited[current->getId()] = true;
                mean += meanN2(G, *(current), visited, h + 1);
            }
            posLista = listaAdiacenti.next(posLista);
        }
        return mean;
    }
}
#endif
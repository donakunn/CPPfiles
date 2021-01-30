#ifndef GRAFO_UTILS_H
#define GRAFO_UTILS_H
#include "GrafoList.h"
#include "codapt.h"
#include <string>
using namespace std;

class grafo_utils
{
public:
    bool sameColorPath(GrafoList<string, int> &G, NodoG &n1, NodoG &n2)
    {
        if (G.leggiEtichetta(n1) != G.leggiEtichetta(n2))
            return false;
        typename GrafoList<string, int>::ListaNodi adiacenti;
        typename GrafoList<string, int>::ListaNodiPos posizione;
        Coda<NodoG *> queue;
        bool visited[G.numNodi()];
        for (int i = 0; i < G.numNodi(); i++)
        {
            visited[i] = false;
        }
        queue.inCoda(&n1);
        visited[n1.getId()] = true;
        NodoG *currentNode;
        while (!queue.codaVuota())
        {
            currentNode = queue.leggiCoda();
            queue.fuoriCoda();
            adiacenti = G.Adiacenti(*(currentNode));
            posizione = adiacenti.begin();
            while (!adiacenti.end(posizione))
            {
                currentNode = adiacenti.read(posizione);
                if (currentNode->getId() == n2.getId())
                    return true;

                if (!visited[currentNode->getId()] && (G.leggiEtichetta(n1) == G.leggiEtichetta(*(currentNode))))
                {
                    queue.inCoda(currentNode);
                    visited[currentNode->getId()] = true;
                }
                posizione = adiacenti.next(posizione);
            }
        }
        return false;
    }

    bool uniformColorPath(GrafoList<string, int> &G, NodoG n1, NodoG n2)
    {
        typename GrafoList<string, int>::ListaNodi adiacenti;
        typename GrafoList<string, int>::ListaNodiPos posizione;
        Coda<NodoG *> queue;
        bool visited[G.numNodi()];
        for (int i = 0; i < G.numNodi(); i++)
        {
            visited[i] = false;
        }
        queue.inCoda(&n1);
        visited[n1.getId()] = true;
        NodoG *currentNode, *nextNode;
        while (!queue.codaVuota())
        {
            currentNode = queue.leggiCoda();
            queue.fuoriCoda();
            adiacenti = G.Adiacenti(*(currentNode));
            posizione = adiacenti.begin();
            while (!adiacenti.end(posizione))
            {
                nextNode = adiacenti.read(posizione);
                if (currentNode->getId() == n2.getId())
                    return true;

                if (!visited[nextNode->getId()] &&(G.leggiEtichetta(*(currentNode)) != G.leggiEtichetta(*(nextNode))))
                {
                    queue.inCoda(nextNode);
                    visited[currentNode->getId()] = true;
                }
                posizione = adiacenti.next(posizione);
            }
        }
        return false;
    }
};
#endif
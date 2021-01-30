#ifndef GRAFOUTILS_H
#define GRAFOUTILS_H

#include "GrafoList.h"
#include "codapt.h"

template <class T>
class grafoUtils
{
public:
    int numbersOfPaths(const GrafoList<T, int> &, NodoG &, NodoG &);
    double meanOfPaths(const GrafoList<T, int> &, NodoG &, NodoG &);

private:
    int pathLenght(const GrafoList<T, int> &, NodoG &, NodoG &);
};

template <class T>
int grafoUtils::numbersOfPaths(const GrafoList<T, int> &G, NodoG &n1, NodoG &n2)
{
    typename GrafoList<T, int>::ListaNodi ad;
    typename GrafoList<T, int>::ListaNodiPos pos;
    Coda<NodoG> queue;
    int nCammini = 0;
    std::vector < Linked_list<*NodoG>;
    bool visited[G.numNodi()];
    for (int i = 0; i < G.numNodi(); i++)
    {
        visited[i] = false;
    }
    queue.inCoda(n1);
    NodoG currentNode, nextNode;
    while (!queue.codaVuota())
    {
        currentNode = queue.leggiCoda();
        queue.fuoriCoda();
        ad = G.Adiacenti(currentNode);
        pos = ad.begin();
        while (!ad.end(pos))
        {
            nextNode = ad.read(pos);
            if (nextNode == n2)
                nCammini++;
            else if (!visited[nextNode.getId()] && G.leggiPeso(currentNode, nextNode) == 1)
            {
                queue.inCoda(nextNode);
                visited[nextNode.getId()] = true;
            }
            pos = ad.next(pos);
        }
    }
    return nCammini;
}

template <class T>
double grafoUtils::meanOfPaths(const GrafoList<T, int> &G, NodoG &n1, NodoG &n2)
{
    GrafoList<T, int> G(G.numNodi());
    typename GrafoList<T, int>::ListaNodi ad;
    typename GrafoList<T, int>::ListaNodiPos pos;
    Coda<NodoG> queue;
    int sommaCammini = 0;
    std::vector < Linked_list<*NodoG>;
    bool visited[G.numNodi()];
    for (int i = 0; i < G.numNodi(); i++)
    {
        visited[i] = false;
    }
    queue.inCoda(n1);
    G1.insNodo(n1);
    NodoG currentNode, nextNode;
    while (!queue.codaVuota())
    {
        int i = 1;
        currentNode = queue.leggiCoda();
        queue.fuoriCoda();
        ad = G.Adiacenti(currentNode);
        pos = ad.begin();
        while (!ad.end(pos))
        {
            nextNode = ad.read(pos);
            if (!visited[nextNode.getId()] && G.leggiPeso(currentNode, nextNode) == 1)
            {
                visited[nextNode.getId()] = true;
                G1.insNodo(nextNode);
                G1.insArco(currentNode, nextNode, i);
                queue.inCoda(nextNode);
            }
            pos = ad.next(pos);
        }
        i++;
    }
    typename GrafoList<T, int>::ListaNodi nodiG1;
    typename GrafoList<T, int>::ListaNodiPos posG1;

    while(!nodiG1.end(posG1)) {
        currentNode = nodiG1.read(posG1);
        if (currentNode != n2 && G1.esisteArco(currentNode,n2) {
            sommaCammini += G1.leggiPeso(currentNode,n2) 
        }
        posG1 = nodiG1.next(posG1);
    }

    return (sommaCammini / numbersOfPaths(G,n1,n2) );
}

#endif
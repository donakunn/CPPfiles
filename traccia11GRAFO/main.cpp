#include "grafo_utils.h"


int main()
{
    GrafoList<string, int> G(10);
    grafo_utils utils;

    NodoG n1, n2, n3, n4, n5, n6;

    G.insNodo(n1);
    G.scriviEtichetta(n1, "rosso");
    G.insNodo(n2);
    G.scriviEtichetta(n2, "b");
    G.insNodo(n3);
    G.scriviEtichetta(n3, "verde");
    G.insNodo(n4);
    G.scriviEtichetta(n4, "d");
    G.insNodo(n5);
    G.scriviEtichetta(n5, "e");
    G.insNodo(n6);
    G.scriviEtichetta(n6, "rosso");

    G.insArco(n1, n2, 0);
    G.insArco(n1, n3, 0);
    G.insArco(n1, n5, 0);
    G.insArco(n2, n4, 0);
    G.insArco(n2, n6, 0);
    G.insArco(n3, n4, 0);
    G.insArco(n3, n6, 0);
    G.insArco(n4, n1, 0);
    G.insArco(n5, n2, 0);
    G.insArco(n5, n3, 0);
    G.insArco(n6, n4, 0);
    G.print();

    if (utils.sameColorPath(G,n1,n6))
        cout << "esiste" << endl;
    if (utils.uniformColorPath(G,n1,n6))
        cout << "esiste" << endl;
    return 0;
}
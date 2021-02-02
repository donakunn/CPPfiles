#include "grafoUtil.h"

int main()
{
    GrafoList<int, int> G(10);
    grafoUtils utils;

    NodoG n1, n2, n3, n4, n5, n6;

    G.insNodo(n1);
    G.scriviEtichetta(n1, 1);
    G.insNodo(n2);
    G.scriviEtichetta(n2, 2);
    G.insNodo(n3);
    G.scriviEtichetta(n3, 3);
    G.insNodo(n4);
    G.scriviEtichetta(n4, 4);
    G.insNodo(n5);
    G.scriviEtichetta(n5, 5);
    G.insNodo(n6);
    G.scriviEtichetta(n6, 6);

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

    cout << "numero di nodi raggiungibili da n1 con etichetta 1 : " << utils.countSame(G,n1) << endl;
    cout << "media dei valori delle etichette dei nodi raggiungibili da n1 con cammino 2: " << utils.meanN2(G,n1) << endl;

    return 0;
}
#include<iostream>
#include "array.h"
using namespace std;



int main()
{
    Array* ar = new Array(10);
    int arrayTest[10] = {2,5,7,9,13,14,23,43,54,67};
    int k = ar->greatherThan(arrayTest,10);
    cout << "il numero di valori piu grande di 10 e: " << k << endl;
    cout << "il numero 13 e' membro? " << ar->member(arrayTest,13) << endl;
    vector<int> v = ar->largest(arrayTest);
    cout << "valore piu grande e sua posizione: " << v[0] << " " << v[1] << endl;
    ar->remove(arrayTest,13);
    cout << "array dopo rimozione 13: ";
    for (int i = 0; i<10; ++i)
{
    std::cout << arrayTest[i] << " ";
}
cout << endl;
    cout << "ordine numeri e: " << ar->ordering(arrayTest) << endl;
    ar->reverse(arrayTest); 
    cout << "array invertito: ";
    for (int i = 0; i<10; ++i)
{
    std::cout << arrayTest[i] << " ";
}
cout << endl;
delete ar;
    return 0;
}
//da sistemare
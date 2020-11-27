#include <iostream>
#include "matrice.h"
using namespace std;

int main()
{
    matrice* mat = new matrice(5,7);
    matrice* mat2 = new matrice(15,25);

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 20; j++) {
            mat->scrivimatrice(i,j,rand()%20);
        }
    }
    cout << mat->toString() << endl;
    return 0;
}
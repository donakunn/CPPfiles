#include <iostream>
#include "matrice.h"
using namespace std;

int main()
{
    matrice *mat = new matrice(4, 3);
    matrice *mat2 = new matrice(4, 4);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            mat->scrivimatrice(i, j, rand() % 20);
        }
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            mat2->scrivimatrice(i, j, rand() % 20);
        }
    }
    cout << mat->toString() << endl;
    cout << mat2->toString() << endl;

    cout << mat->toString() << endl;
    //matrice *mat3 = new matrice(mat->prodotto(*mat2));
    // cout << mat3->toString() << endl;

    delete mat;
    delete mat2;
    //delete mat3;
    
    return 0;
}
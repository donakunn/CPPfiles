#include "matrice.h"

// costruttore
matrice::matrice(const int &c, const int &r)
{
    colonne = c;
    righe = r;
    // allocazione dinamica della matrice
    int i;
    elementi = new tipoelem *[righe];
    for (i = 0; i < righe; i++)
        elementi[i] = new tipoelem[colonne];
    // inizializzazione degli elementi
    for (i = 0; i < righe; i++)
    {
        for (int j = 0; j < colonne; j++)
            elementi[i][j] = 0;
    }
}

//costruttore di copia
matrice::matrice(const matrice &)
{
}

//costruttore di assegnamento
matrice &matrice::operator=(const matrice &)
{
}
//distruttore
matrice::~matrice()
{
    for (int i = 0; i < righe; i++)
        delete elementi[i];
    delete elementi;
}

tipoelem matrice::leggimatrice(const int &r, const int &c)
{
    return elementi[r][c];
}

void matrice::scrivimatrice(const int &r, const int &c, const tipoelem &val)
{
    elementi[r][c] = val;
}

void matrice::prodottoScalare(const double &scalare)
{
    for (int i = 0; i < righe; i++)
    {
        for (int j = 0; j < colonne; j++)
            elementi[i][j] = elementi[i][j] * scalare;
    }
}
matrice matrice::trasposta()
{
    matrice trasp(righe, colonne);
    for (int i = 0; i < righe; i++)
    {
        for (int j = 0; j < colonne; j++)
            trasp.scrivimatrice(j, i, elementi[i][j]);
    }
    return trasp;
}
matrice matrice::prodotto(const matrice &mat)
{
}

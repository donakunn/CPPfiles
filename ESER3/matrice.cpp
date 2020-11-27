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
matrice::matrice(const matrice &mat)
{
    righe = mat.righe;
    colonne = mat.colonne;
    for (int i = 0; i < righe; i++)
    {
        for (int j = 0; j < colonne; j++)
            elementi[i][j] = mat.elementi[i][j];
    }
}

//costruttore di assegnamento
matrice &matrice::operator=(const matrice &mat)
{
    if (&mat == this)
        return *this;
    else
    {
        for (int i = 0; i < righe; i++)
        {
            delete elementi[i];
        }
        delete elementi;

        righe = mat.righe;
        colonne = mat.colonne;
        for (int i = 0; i < righe; i++)
        {
            for (int j = 0; j < colonne; j++)
            {
                this->elementi[i][j] = mat.elementi[i][j];
            }
        }
    }
    return *this;
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
    if ((r > righe) || (c > colonne))
        throw "Index out of bound";
    else
        return elementi[r][c];
}

void matrice::scrivimatrice(const int &r, const int &c, const tipoelem &val)
{
    if ((r > righe) || (c > colonne))
        throw "Index out of bound";
    else
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
    if (this->colonne != mat.righe)
        throw "Impossibile effettuare prodotto";
    else
    {
        matrice matProdotto(this->righe, mat.colonne);
        for (int i = 0; i < righe; i++)
        {
            for (int j = 0; j < mat.colonne; j++)
            {
                matProdotto.scrivimatrice(i, j, 0);
                for (int k = 0; k < righe; k++)
                {
                    matProdotto.elementi[i][j] +=
                        this->elementi[i][k] * mat.elementi[k][j];
                }
            }
        }
        return matProdotto;
    }
}

std::string matrice::toString()
{
    std::string matAsString;

    for (int i = 0; i < righe; i++)
    {
        for (int j = 0; j < colonne; j++)
        {
            matAsString.append("[" + std::to_string(elementi[i][j]) + "]");
        }
        matAsString.append("\n");
    }
    return matAsString;
}

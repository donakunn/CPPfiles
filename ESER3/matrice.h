#ifndef MATRICE_H
#define MATRICE_H
typedef double tipoelem;

class matrice
{
public:
    matrice(const int &, const int &); // costruttore
    matrice(const matrice&);    //costruttore di copia
    matrice& operator=(const matrice&); //costruttore di assegnamento
    ~matrice();
    tipoelem leggimatrice(const int &, const int &);
    void scrivimatrice(const int &, const int &, const tipoelem &);
    void prodottoScalare(const double &);
    matrice trasposta();
    matrice prodotto(const matrice &);
private:
    int righe;
    int colonne;
    tipoelem **elementi;
    int getRighe();
    int getColonne();
};

#endif
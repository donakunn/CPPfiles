#ifndef MATRICE_H
#define MATRICE_H
#include <string>

typedef double tipoelem;

class matrice
{
public:
    matrice(const int &, const int &);   // costruttore
    matrice(const matrice &);            //costruttore di copia
    matrice &operator=(const matrice &); //costruttore di assegnamento
    ~matrice();
    tipoelem leggimatrice(const int &, const int &);
    void scrivimatrice(const int &, const int &, const tipoelem &);
    void prodottoScalare(const double &);
    matrice trasposta();
    matrice prodotto(const matrice &);
    std::string toString(); 

private:
    int righe;
    int colonne;
    tipoelem **elementi;
};

#endif
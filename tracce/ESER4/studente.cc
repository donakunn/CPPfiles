#include "studente.h"
#include <iostream>

studente::studente()
{
    esami.reserve(5);
    esami.push_back(esame("asd"));
    esami.push_back(esame("map"));
    esami.push_back(esame("ing"));
    esami.push_back(esame("stat"));
    esami.push_back(esame("calc"));
}

studente::studente(const string &nome1, const string &nome2, const string &nome3, const string &nome4, const string &nome5)
{
    esami.reserve(5);
    esami.push_back(esame(nome1));
    esami.push_back(esame(nome2));
    esami.push_back(esame(nome3));
    esami.push_back(esame(nome4));
    esami.push_back(esame(nome5));
}
void studente::setMatricola(const string &mat)
{
    this->matricola = mat;
}
void studente::setNome(const string &nome)
{
    this->nome = nome;
}
string studente::getMatricola()
{
    return this->matricola;
}
string studente::getNome(const int &i)
{
    return esami[i].getEsame();
}
int studente::getNumEsami()
{
    return 5;
}
void studente::setEsame(const int &voto, const int &i)
{
    esami[i].setVoto(voto);
}
int studente::getVotoEsame(const int &i)
{
    return esami[i].getVoto();
}
string studente::getNomeEsame(const int &i)
{
    return esami[i].getEsame();
}
bool studente::getSostenuto(const int &i)
{
    return esami[i].isSostenuto();
}
double studente::getMedia()
{
    double media;
    int esamiPassati = 0;
    for (esame &e : esami)
    {
        int voto = e.getVoto();
        if (voto >= 18 && voto <= 30)
        {
            media += voto;
            esamiPassati++;
        }
    }
    return media / esamiPassati;
}
void studente::printStudente()
{
    cout << "nome: " << this->nome << endl;
    cout << "matricola: " << this->matricola << endl;
    for (esame &e : esami)
        cout << e.getEsame() << " " << e.getVoto() << " " << e.isSostenuto() << endl;
}
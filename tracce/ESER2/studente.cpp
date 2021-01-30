#include "studente.h"
#include <iostream>
using namespace std;

studente::studente() {

}
studente::~studente() {

}
/* funzioni per l'inserimento dei valori degli elementi della struttura */
int studente::setNome(string nome)
{
    if (nome.length() > 30) 
        return 1;
    else {
        this->nome= nome;
        return 0;
    }
}
int studente::setCognome(string cognome)
{
    if (cognome.length() > 30) 
        return 1;
    else {
        this->cognome= cognome;
        return 0;
    }
}
int studente::setMatricola(int matricola)
{
        if ((matricola < 255312) || (matricola > 499999))
            return 1;
        else {
            this->matricola= matricola;
            return 0;
        }
}
int studente::setEta(int eta) {
        if ((eta < 12) || (eta > 105))
            return 1;
        else {
            this->eta = eta;
            return 0;
    }
}

/* funzioni per ottenere i valori degli elementi della struttura */
string studente::getNome()
{
    return this->nome;
}
string studente::getCognome()
{
    return this->cognome;
}
int studente::getMatricola()
{
    return this->matricola;
}
int studente::getEta()
{
    return this->eta;
}

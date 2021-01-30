#ifndef _STUDENTE_H
#define _STUDENTE_H
#include <string>
#include <vector>
#include "esame.h"

using namespace std;

class studente
{
public:
    studente();
    studente(const string &, const string &, const string &, const string &, const string &);
    void setMatricola(const string &);
    void setNome(const string &);
    string getMatricola();
    string getNome(const int &);
    int getNumEsami();
    void setEsame(const int &, const int &);
    int getVotoEsame(const int &);
    string getNomeEsame(const int &);
    bool getSostenuto(const int &);
    double getMedia();
    void printStudente();
private: 
    string matricola;
    string nome;
    vector<esame> esami;
    const int numesami = 5; 

};
#endif // _STUDENTE_H
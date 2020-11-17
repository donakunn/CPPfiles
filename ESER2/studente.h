#ifndef _STUDENTE
#define _STUDENTE

#include <string>
using namespace std;

class studente
{
private:
    int matricola;
    string nome;
    string cognome;
    int eta;

public:
    studente();
    ~studente();
    /* funzioni per l'inserimento dei valori degli elementi della struttura */
    int setNome(string nome);
    int setCognome(string cognome);
    int setMatricola(int matricola);
    int setEta(int eta);
    /* funzioni per ottenere i valori degli elementi della struttura */
    string getNome();
    string getCognome();
    int getMatricola();
    int getEta();
};
#endif
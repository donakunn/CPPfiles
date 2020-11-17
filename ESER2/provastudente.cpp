#include "studente.h"
#include <iostream>
using namespace std;

int main() {
    studente::studente stud = new studente();
    cout << "inserisci nome: "; 
    string nome;
    cin >> nome;
    stud.setNome(nome);
    cout << "inserisci cognome: "; 
    cin >> nome;
    stud.setCognome(nome);
    cout << "inserisci eta: "; 
    int eta;
    cin >> eta;
    stud.setEta(eta);
    cout << "inserisci matricola: "; 
    cin >> eta;
    stud.setMatricola(eta);
    cout << "attributi studente inseriti: " << stud.getNome() << ", " << stud.getCognome() << ", " <<
        stud.getEta() << ", " << stud.getMatricola() << ", " << endl; 
        
    delete stud;
}
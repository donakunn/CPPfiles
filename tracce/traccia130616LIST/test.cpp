#include "eo_strings.h"

int main()
{
    eo_strings lista;
    lista.inserisci("pincopalloo");
    lista.inserisci("ciao");
    lista.inserisci("dado");
    lista.inserisci("caso");
    lista.inserisci("prova");
    lista.inserisci("tre");
    lista.inserisci("diciannove");
    lista.inserisci("sette");
    lista.inserisci("vasto");
    lista.rimuovi("prova");
    lista.rimuovi('c');
    cout << lista.freq_pari() << endl;
    lista.visualizza_dispari();
}
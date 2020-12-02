#include "studente.h"
#include <iostream>

int main() {
    studente s("A","B","C","D","E");
    s.setNome("Carlo");
    s.setMatricola("232323");
    s.setEsame(23,1);
    s.setEsame(27,3);
    s.printStudente();
    cout << s.getMedia() << endl;
}
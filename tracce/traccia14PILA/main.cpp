#include "removeStack.h"
#include <iostream>
using namespace std;
int main() 
{ 
    Pila<int> input; 
    input.inPila(34); 
    input.inPila(3); 
    input.inPila(31); 
    input.inPila(98); 
    input.inPila(92); 
    input.inPila(23); 
   stampaPila(input);
    remove_Stack util;
    util.rimuoviDaPila(input,30);
    cout << endl;
    stampaPila(input);
}
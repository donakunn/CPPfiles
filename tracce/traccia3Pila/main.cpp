#include "orderedPila.h"
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
  
    ordered_pila util;
    // This is the temporary stack 
    util.ordinaPila(input); 
    cout << "Sorted numbers are:\n"; 
    stampaPila(input);
}
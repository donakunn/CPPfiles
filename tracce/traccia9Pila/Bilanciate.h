#ifndef BILANCIATE_H
#define BILANCIATE_H

#include <iostream>
#include "pilapt.h"
#include <string>

using namespace std;

template <class T>
class Bilanciate
{
public:
    void test(string);

private:
    Pila<T> S;
};

template<>
void Bilanciate<char>::test(string s){
    char currentChar;
    char charInStack;
    for (int i = 0; i <s.length(); i++) {
        currentChar = s[i];
        if (currentChar == '(' || currentChar == '[' || currentChar == '{'){
            S.inPila(currentChar);
        }
        else if (currentChar == ')') {
            try {
                charInStack = S.leggiPila();
                if (charInStack == '[' || charInStack == '{')
                    cout << "parentesi aperta diversa da " << currentChar << " alla posizione" << i << endl; 
                S.fuoriPila();
            } catch (emptyStack const & p) {
                cout << "parentesi non bilanciata alla posizione " << i << endl;
                return;
            }
        }
        else if (currentChar == ']') {
            try {
                charInStack = S.leggiPila();
                if (charInStack == '(' || charInStack == '{')
                    cout << "parentesi aperta diversa da " << currentChar << " alla posizione" << i << endl;
                S.fuoriPila();
            } catch (emptyStack const & p) {
                cout << "parentesi non bilanciata alla posizione " << i << endl;
                return;
            }
        }
        else if (currentChar == '}') {
            try {
                charInStack = S.leggiPila();
                if (charInStack == '[' || charInStack == '[')
                    cout << "parentesi aperta diversa da " << currentChar << " alla posizione" << i << endl;
                S.fuoriPila();
            } catch (emptyStack const & p) {
                cout << "parentesi non bilanciata alla posizione " << i << endl;
                return;
            }
        }
        else { continue;}
    }
    if (!S.pilaVuota())
        cout << "parentesi non bilanciate, stack non vuoto " << endl;
                return;
}

#endif
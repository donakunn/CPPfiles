#include "Bins.h"
#include <iostream>
using namespace std;

int main()
{
    Bins code;
    code.insert(2);
    code.insert(4);
    code.insert(9);
    code.insert(1);
    code.insert(6);
    code.insert(7);
    code.insert(3);
    code.insert(8);
    code.print();
    code.deleteVal(1);
    code.print();
    cout << "media prima coda: " << code.mean(0) << endl;
    cout << "elementi 3 coda: " << code.freq(2) << endl;
    return 0;
}
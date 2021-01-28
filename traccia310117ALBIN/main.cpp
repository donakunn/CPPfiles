#include "balanced_tree.h"
#include <iostream>

using namespace std;

int main()
{
    balanced_tree<int> bal;
    Bin_treeP<int> T;
    typename Bin_treeP<int>::Nodo n1;
    T.ins_root();
    n1 = T.root();
    T.ins_sx(n1);
    n1 = T.sx(n1);
    T.ins_sx(n1);
    if (!bal.is_height_balanced(T))
        cout << "sbilanciato" << endl;
    else
        cout << "bilanciato" << endl;
    n1 = T.root();
    T.ins_dx(n1);
    if (!bal.is_height_balanced(T))
        cout << "sbilanciato" << endl;
    else
        cout << "bilanciato" << endl;
    T.print();

    if (bal.complete_nodes(T))
        cout << "completo" << endl;
    else
        cout << "non completo" << endl;

    n1 = T.sx(T.root());
    T.ins_dx(n1);
     if (bal.complete_nodes(T))
        cout << "completo" << endl;
    else
        cout << "non completo" << endl;
    return 0;

}
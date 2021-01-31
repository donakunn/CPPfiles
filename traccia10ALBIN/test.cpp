#include "util_bin_tree.h"

int main() {
    Bin_treeP<int> T;
    util_bin_tree util;
    typename Bin_treeP<int>::Nodo n1;
    T.ins_root();
    n1 = T.root();
    T.write(n1,20);
    T.ins_sx(n1);
    n1 = T.sx(n1);
    T.write(n1,15);
    n1 = T.root();
    T.ins_dx(n1);
    n1 = T.dx(n1);
    T.write(n1,4);
    n1 = T.sx(T.root());
    T.ins_sx(n1);
    n1 = T.sx(n1);
    T.write(n1,3);
    n1 = T.parent(n1);
    T.ins_dx(n1);
    n1 = T.dx(n1);
    T.write(n1,8);
    T.print();

    std::cout << "numero di nodi di livello 1 divisibili per 3: " << util.d3(T,1) << std::endl;
    std::cout << "numero di foglie con valore pari: " << util.lp(T) << std::endl;
    std::cout << "numero di foglie con genitore con valore multiplo di 5: " << util.l2p(T) << std::endl;
}
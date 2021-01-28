#include "util_n_tree.h"
#include <iostream>

using namespace std;

int main(){
    TreePtr<char> Tree;
    TreePtr<char>::node n;

    util_n_tree<char> utils;
    
    Tree.insRoot();
    Tree.writeNode(Tree.root(), 'a');

    Tree.insFirst(Tree.root(), 'b');
    Tree.insFirst(Tree.root(), 'c');

    n = Tree.root();
    n = Tree.firstChild(n);

    Tree.ins(n, 'd');

    n = Tree.root();
    n = Tree.firstChild(n);
    Tree.insFirst(n, 'e');
    Tree.insFirst(n, 'f');
    n = Tree.firstChild(n);
    Tree.insFirst(n, 'g');

    Tree.print();

    cout << "numero di foglie: " << utils.n_leaf(Tree) << endl;

    cout << "nodi a lv 0: " << utils.n_level(Tree,0) << endl;
    cout << "nodi a lv 1: " << utils.n_level(Tree,1) << endl;
    cout << "nodi a lv 2: " << utils.n_level(Tree,2) << endl;
    cout << "nodi a lv 3: " << utils.n_level(Tree,3) << endl;
    cout << "nodi a lv 4: " << utils.n_level(Tree,4) << endl;
    return 0;
}
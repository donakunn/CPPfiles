#include "MultipleIntTree.h"

int main()
{
    TreePtr<int> Tree;
    typename TreePtr<int>::node n;

    Tree.insRoot();
    Tree.writeNode(Tree.root(), 2);

    Tree.insFirst(Tree.root(), 3);
    Tree.insFirst(Tree.root(), 4);

    n = Tree.root();
    n = Tree.firstChild(n);

    Tree.ins(n, 11);

    n = Tree.root();
    n = Tree.firstChild(n);
    Tree.insFirst(n, 5);
    Tree.insFirst(n, 7);

    Tree.print();

    multipleIntTree utils;

    utils.scriviSommaSottoAlbero(Tree);

    Tree.print();
}
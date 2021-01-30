#ifndef MULTIPLEINTTREE_H
#define MULTIPLEINTREE_H

#include "TreePtr.h"
class multipleIntTree
{
public:
    void scriviSommaSottoAlbero(TreePtr<int> &);

private:
    void scriviSommaSottoAlbero(TreePtr<int> &, typename TreePtr<int>::node);
    int sommaSottoAlbero(TreePtr<int> &, typename TreePtr<int>::node);
};

void multipleIntTree::scriviSommaSottoAlbero(TreePtr<int> &T)
{
    if (!T.empty())
        scriviSommaSottoAlbero(T, T.root());
}

void multipleIntTree::scriviSommaSottoAlbero(TreePtr<int> &T, typename TreePtr<int>::node n)
{
    if (T.leaf(n))
        return;
    else
    {
        typename TreePtr<int>::node curr = T.firstChild(n);
        while (!T.lastSibling(curr))
        {
            scriviSommaSottoAlbero(T, curr);
            T.writeNode(curr, sommaSottoAlbero(T, curr));
            curr = T.nextSibling(curr);
        }
        scriviSommaSottoAlbero(T, curr);
        T.writeNode(curr, sommaSottoAlbero(T, curr));
        T.writeNode(n,sommaSottoAlbero(T,n));
    }
}

int multipleIntTree::sommaSottoAlbero(TreePtr<int> &T, typename TreePtr<int>::node n)
{
    if (T.leaf(n))
        return T.readNode(n);
    else
    {
        int somma = 0;
        typename TreePtr<int>::node curr = T.firstChild(n);
        while (!T.lastSibling(curr))
        {
            somma += sommaSottoAlbero(T, curr);
            curr = T.nextSibling(curr);
        }
        somma += sommaSottoAlbero(T, curr);
        return somma;
    }
}
#endif
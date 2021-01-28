#ifndef UTIL_N_TREE_H
#define UTIL_N_TREE_H

#include "TreePtr.h"

template <class _value_type>
class util_n_tree
{
public:
    /* Restituisce il numero di foglie presenti nell’albero n-ario T */
    int n_leaf(const TreePtr<_value_type> &);
    /* Restituisce il numero di nodi in T di livello k */
    int n_level(const TreePtr<_value_type> &, int);

private:
    int n_leaf(const TreePtr<_value_type> &, typename TreePtr<_value_type>::Node);
    int n_level(const TreePtr<_value_type> &, int, int, typename TreePtr<_value_type>::Node);
};

template <class _value_type>
int util_n_tree<_value_type>::n_leaf(const TreePtr<_value_type> &T)
{
    if (T.empty())
        return 0;
    else
        return (n_leaf(T, T.root()));
}

template <class _value_type>
int util_n_tree<_value_type>::n_leaf(const TreePtr<_value_type> &T, typename TreePtr<_value_type>::Node n)
{
    if (T.leaf(n))
        return 1;
    int leafs = 0;
    typename TreePtr<_value_type>::Node currentNode = T.firstChild(n);
    while (!T.lastSibling(currentNode))
    {
        leafs += n_leaf(T, currentNode);
        currentNode = T.nextSibling(currentNode);
    }
    leafs += n_leaf(T, currentNode);
    return leafs;
}

template <class _value_type>
int util_n_tree<_value_type>::n_level(const TreePtr<_value_type> &T, int k)
{
    if (k == 0 || T.empty())
        return 0;
    if (k == 1)
        return 1;
    else
        return n_level(T, 0, k, T.root());
}

template <class _value_type>
int util_n_tree<_value_type>::n_level(const TreePtr<_value_type> &T, int currentLevel, int k, typename TreePtr<_value_type>::Node n)
{
    int nodiLivelloK = 0;
    if (currentLevel == k)
    {
        while (!T.lastSibling(n))
        {
            nodiLivelloK++;
            n = T.nextSibling(n);
        }
        nodiLivelloK++;
        return nodiLivelloK;
    }
    else
    {
        if (T.leaf(n))
            return 0;
        else
        {
            while (!T.lastSibling(n))
            {
                if (!T.leaf(n))
                {
                    nodiLivelloK += n_level(T, currentLevel + 1, k, T.firstChild(n));
                }
                n = T.nextSibling(n);
            }
            if (!T.leaf(n))
            {
                nodiLivelloK += n_level(T, currentLevel + 1, k, T.firstChild(n));
            }
            return nodiLivelloK;
        }
    }
}
#endif
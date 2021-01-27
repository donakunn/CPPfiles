#ifndef BALANCED_TREE_H
#define BALANCED_TREE_H

#include "Bin_treeP.h"
template <class _value_type>
class balanced_tree
{
    /* Stabilisce se l’albero `e bilanciato in altezza.
* Un albero binario `e bilanciato in altezza se a) `e vuoto, o b) se per ogni nodo
* le altezze dei suoi due sottoalberi differiscono al pi`u di uno e i due sottoalberi
* sono bilanciati in altezza.
*/
public:
    bool is_height_balanced(const Bin_treeP<_value_type> &B);
    /* Stabilisce se tutti i nodi non foglia dell’albero hanno esattamente due figli */
    bool complete_nodes(const Bin_treeP<_value_type> &B);

private:
    int tree_Height(const Bin_treeP<_value_type> &B, typename Bin_treeP<_value_type>::Nodo);
    bool is_height_balanced(const Bin_treeP<_value_type> &B, typename Bin_treeP<_value_type>::Nodo);
    bool complete_nodes(const Bin_treeP<_value_type> &B, typename Bin_treeP<_value_type>::Nodo);
};

template <class _value_type>
bool balanced_tree<_value_type>::is_height_balanced(const Bin_treeP<_value_type> &B)
{
    if (B.empty())
        return true;
    else
        return (is_height_balanced(B, B.root()));
}

template <class _value_type>
bool balanced_tree<_value_type>::is_height_balanced(const Bin_treeP<_value_type> &B, typename Bin_treeP<_value_type>::Nodo n)
{
    if (B.sx_empty(n) && B.dx_empty(n))
        return true;
    if (B.sx_empty(n))
    {
        if ((tree_Height(B, B.dx(n)) == 0) && is_height_balanced(B, B.dx(n)))
            return true;
        else
            return false;
    }
    if (B.dx_empty(n))
    {
        if ((tree_Height(B, B.sx(n)) == 0) && is_height_balanced(B, B.sx(n)))
            return true;
        else
            return false;
    }
    if ((abs(tree_Height(B, B.sx(n)) - tree_Height(B, B.dx(n))) < 2) && (is_height_balanced(B, B.sx(n))) && (is_height_balanced(B, B.dx(n))))
        return true;
    else
        return false;
}

template <class _value_type>
int balanced_tree<_value_type>::tree_Height(const Bin_treeP<_value_type> &B, typename Bin_treeP<_value_type>::Nodo n)
{
    int hLeft = 0;
    int hRight = 0;
    if (B.sx_empty(n) && B.dx_empty(n))
        return 0;
    if (B.sx_empty(n))
    {
        hRight = tree_Height(B, B.dx(n)) + 1;
        return (hRight);
    }
    else if (B.dx_empty(n))
    {
        hLeft = tree_Height(B, B.sx(n)) + 1;
        return (hLeft);
    }
    else
    {
        hLeft = tree_Height(B, B.sx(n));
        hRight = tree_Height(B, B.dx(n));
        if (hLeft >= hRight)
            return (hLeft + 1);
        else
            return (hRight + 1);
    }
}

template <class _value_type>
bool balanced_tree<_value_type>::complete_nodes(const Bin_treeP<_value_type> &B)
{
    if (B.empty())
    {
        return true;
    }
    else
        return (complete_nodes(B, B.root()));
}

template <class _value_type>
bool balanced_tree<_value_type>::complete_nodes(const Bin_treeP<_value_type> &B, typename Bin_treeP<_value_type>::Nodo n)
{
    if (B.sx_empty(n) && B.dx_empty(n))
        return true;
    else if (B.sx_empty(n))
        return false;
    else if (B.dx_empty(n))
        return false;
    else
        return (complete_nodes(B, B.sx(n)) && complete_nodes(B, B.dx(n)));
}
#endif
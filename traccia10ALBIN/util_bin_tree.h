#ifndef UTIL_BIN_TREE_H
#define UTIL_BIN_TREE_H
#include "Bin_treeP.h"

class util_bin_tree
{
public:
    int d3(Bin_treeP<int> &, int); //calcola e restituisce il numero di nodi di livello k il cui valore divisibile per 3;
    int lp(Bin_treeP<int> &);      //calcola e restituisce il numero di foglie il cui valore pari;
    int l2p(Bin_treeP<int> &T);    //calcola e restituisce il numero di foglie che hanno come genitore un nodo il cui valore un multiplo di 5.
private:
    int d3(Bin_treeP<int> &, Bin_treeP<int>::Nodo, int, int);
    int lp(Bin_treeP<int> &, Bin_treeP<int>::Nodo);
    int l2p(Bin_treeP<int> &, Bin_treeP<int>::Nodo);
};

int util_bin_tree::d3(Bin_treeP<int> &T, int k)
{
    if (T.empty())
        return 0;
    return d3(T, T.root(), 0, k);
}

int util_bin_tree::d3(Bin_treeP<int> &T, Bin_treeP<int>::Nodo n, int currentLevel, int k)
{
    if (currentLevel == k)
    {
        if (T.read(n) % 3 == 0)
            return 1;
        else
            return 0;
    }
    else
    {
        int count = 0;
        if (!T.sx_empty(n))
        {
            count += d3(T, T.sx(n), currentLevel + 1, k);
        }
        if (!T.dx_empty(n))
        {
            count += d3(T, T.dx(n), currentLevel + 1, k);
        }
        return count;
    }
}

int util_bin_tree::lp(Bin_treeP<int> &T)
{
    if (T.empty())
        return 0;
    else
        return lp(T, T.root());
}

int util_bin_tree::lp(Bin_treeP<int> &T, Bin_treeP<int>::Nodo n)
{
    if (T.sx_empty(n) && T.dx_empty(n))
    {
        if (T.read(n) % 2 == 0)
            return 1;
        else
            return 0;
    }
    else
    {
        int count = 0;
        if (!T.sx_empty(n))
        {
            count += lp(T, T.sx(n));
        }
        if (!T.dx_empty(n))
        {
            count += lp(T, T.dx(n));
        }
        return count;
    }
}

int util_bin_tree::l2p(Bin_treeP<int> &T)
{
    if (T.empty())
        return 0;
    else {
        int count = 0;
            if(!T.sx_empty(T.root())) 
                count += l2p(T,T.sx(T.root()));
  
            if(!T.dx_empty(T.root())) 
                count += l2p(T,T.dx(T.root()));
            return count;
    };
}

int util_bin_tree::l2p(Bin_treeP<int> &T,Bin_treeP<int>::Nodo n)
{
    if (T.sx_empty(n) && T.dx_empty(n)) {
        if (T.read(T.parent(n)) % 5 == 0)
            return 1;
        else return 0;
    }
    else {
         int count = 0;
        if (!T.sx_empty(n))
        {
            count += l2p(T, T.sx(n));
        }
        if (!T.dx_empty(n))
        {
            count += l2p(T, T.dx(n));
        }
        return count;
    }
}

#endif
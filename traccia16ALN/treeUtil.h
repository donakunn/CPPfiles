#ifndef TREE_UTIL_H
#define TRE_UTIL_H
#include "TreePtr.h"
class treeUtil
{
public:
    int nEvenFathers(TreePtr<int> &T)
    {
        if (T.empty() || T.leaf(T.root()))
            return 0;
        else
            return nEvenFathers(T, T.root());
    }

private:
    int nEvenFathers(TreePtr<int> &T, TreePtr<int>::Node n)
    {
        if (T.leaf(n))
        {
            if (T.readNode(T.parent(n)) % 2 == 0)
                return 1;
            else
                return 0;
        }
        else
        {
            int count = 0;
            TreePtr<int>::Node current = T.firstChild(n);
            count += nEvenFathers(T, current);
            if (!(T.root() == n))
            {
                if (T.readNode(T.parent(n)) % 2 == 0)
                    count++;
            }
            while (!T.lastSibling(current))
            {
                current = T.nextSibling(current);
                count += nEvenFathers(T, current);
            }
            return count;
        }
    }
};
#endif
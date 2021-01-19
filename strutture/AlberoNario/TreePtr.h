#ifndef _TREEPTR_H_
#define _TREEPTR_H_

#include "Tree.h"
#include "exceptions.h"

template <class T>
class TreePtr;

template <class T>
class treenode
{
    friend class TreePtr<T>;

private:
    T value;
    treenode<T> *gen;
    treenode<T> *primo;
    treenode<T> *succ;
    //funzione di utility che crea una copia del nodo e di tutti i suoi figli ricorsivamente
    treenode<T> *NodeCopy(treenode<T> *src, treenode<T> *srcGen) //da sistemare
    {
        if (src == nullptr)
            return nullptr;
        else
        {
            treenode<T> *newNode = new treenode<T>;
            newNode->gen = srcGen;
            newNode->value = src->value;
            newNode->sin = NodeCopy(src->sin, src);
            newNode->des = NodeCopy(src->des, src);
            return newNode;
        }
    }
};

template <class T>
class TreePtr : public Tree<T, treenode<T> *>
{
public:
    typedef typename Tree<T, treenode<T> *>::item Item;
    typedef typename Tree<T, treenode<T> *>::node Node;
    TreePtr();
    ~TreePtr();
    TreePtr(const TreePtr<T> &);
    TreePtr<T> &operator=(const TreePtr<T> &);
    void create();
    bool empty() const;
    void insRoot();
    Node root() const;
    Node parent(Node) const;
    bool leaf(Node) const;
    Node firstChild(Node) const;
    bool lastSibling(Node) const;
    Node nextSibling(Node) const;
    void insFirst(const Node, const Item);
    void ins(const Node, const Item);
    // DA IMPLEMENTARE
    //	 void insFirstSubTree (node, Tree &) = 0;
    //	 void insSubTree (node, Tree &) = 0;
    void removeSubTree(Node);

    void writeNode(Node, item);
    item readNode(Node) const;

    //template<class V> void BFS(node);
    //template<class V> void preorder(node);
    //template<class V> void postorder(node);
private:
    treenode<T> *radice;
};

template <class T>
TreePtr<T>::TreePtr()
{
    create();
}

template <class T>
TreePtr<T>::~TreePtr()
{
    if (!empty())
    {
        removeSubTree(this->radice);
    }
}

template <class T>
TreePtr<T>::TreePtr(const TreePtr<T> &T)
{
    radice = radice->NodeCopy(T2.root(), nullptr);
}

template <class T>
TreePtr<T> &TreePtr<T>::operator=(const TreePtr<T> &T)
{
    if (this != &T)
    {
        removeSubTree(this->radice);
        radice = radice->NodeCopy(T2.root(), nullptr);
    }
    return *this;
}

template <class T>
void TreePtr<T>::create()
{
    radice = nullptr;
}

template <class T>
bool TreePtr<T>::empty() const
{
    return (radice == nullptr);
}

template <class T>
void TreePtr<T>::insRoot()
{
    if (radice == nullptr)
    {
        radice = new treenode<T>;
        radice->gen = nullptr;
        radice->primo = nullptr;
        radice->succ = nullptr;
    }
    else
        throw RootExists();
}

template <class T>
Node TreePtr<T>::root() const
{
    return (radice);
}

template <class T>
Node TreePtr<T>::parent(Node n) const
{
    if (n != radice)
        return (n->gen);
    else
        throw NullNode();
}

template <class T>
bool TreePtr<T>::leaf(Node n) const
{
    return (n->first == nullptr);
}

template <class T>
Node TreePtr<T>::firstChild(Node n) const
{
    if (!leaf(n))
        return (n->primo);
    else
        throw LeafNode();
}

template <class T>
bool TreePtr<T>::lastSibling(Node n) const
{
    return (n->next == nullptr);
}

template <class T>
Node TreePtr<T>::nextSibling(Node n) const
{
    if (!lastSibling(n))
        return (n->next);
    else
        throw NullNode();
}

template <class T>
void TreePtr<T>::insFirst(const Node n, const Item i)
{
    if (leaf(n))
    {
        n->first = new treenode<T>;
        n->first->value = i;
         n->first->first = nullptr;
          n->first->next = nullptr;
          n->first->gen = n;
    }
    else {
        treenode t = new treenode<T>;
        t->next = n->first;
        t->value = i;
        t->first = nullptr;
        t->gen = n;
        n->first = t;
    }
}
#endif /* _Bin_treeP_H_ */
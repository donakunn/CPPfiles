#ifndef _TREEPTR_H_
#define _TREEPTR_H_

#include "Tree.h"
#include "exceptions.h"
#include <iostream>

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
    treenode<T> *NodeCopy(treenode<T> *src,treenode<T> *srcGen) //da sistemare
    {
        if (src == nullptr)
            return nullptr;
        else
        {
            treenode<T> *newNode = new treenode<T>;
            newNode->gen = srcGen;
            newNode->value = src->value;
            newNode->primo = NodeCopy(src->primo,newNode);
            newNode->succ = NodeCopy(src->succ,newNode->gen);
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
    void insFirst(Node, const Item);
    void ins(Node, const Item);
    void insFirstSubTree(Node, TreePtr<T> &);
    void insSubTree(Node, TreePtr<T> &);
    void removeSubTree(Node);

    void writeNode(Node, const Item);
    Item readNode(const Node) const;
    void print() const;

    //template<class V> void BFS(node);
private:
    treenode<T> *radice;
    void printNodes(Node) const;
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
TreePtr<T>::TreePtr(const TreePtr<T> &T2)
{
    radice = radice->NodeCopy(T2.root(), nullptr);
}

template <class T>
TreePtr<T> &TreePtr<T>::operator=(const TreePtr<T> &T2)
{
    if (this != &T2)
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
typename TreePtr<T>::Node TreePtr<T>::root() const
{
    return (radice);
}

template <class T>
typename TreePtr<T>::Node TreePtr<T>::parent(Node n) const
{
    if (n != radice)
        return (n->gen);
    else
        throw NullNode();
}

template <class T>
bool TreePtr<T>::leaf(Node n) const
{
    return (n->primo == nullptr);
}

template <class T>
typename TreePtr<T>::Node TreePtr<T>::firstChild(Node n) const
{
    if (!leaf(n))
        return (n->primo);
    else
        throw LeafNode();
}

template <class T>
bool TreePtr<T>::lastSibling(Node n) const
{
    return (n->succ == nullptr);
}

template <class T>
typename TreePtr<T>::Node TreePtr<T>::nextSibling(Node n) const
{
    if (!lastSibling(n))
        return (n->succ);
    else
        throw NullNode();
}

template <class T>
void TreePtr<T>::insFirst(Node n, const Item i)
{
    if (leaf(n))
    {
        n->primo = new treenode<T>;
        n->primo->value = i;
        n->primo->primo = nullptr;
        n->primo->succ = nullptr;
        n->primo->gen = n;
    }
    else
    {
        treenode<T> *t = new treenode<T>;
        t->succ = n->primo;
        t->value = i;
        t->primo = nullptr;
        t->gen = n;
        n->primo = t;
    }
}

template <class T>
void TreePtr<T>::ins(Node n, const Item i)
{
    if (n->succ == nullptr)
    {
        treenode<T> *t = new treenode<T>;
        t->value = i;
        t->gen = n->gen;
        t->primo = nullptr;
        t->succ = nullptr;
        n->succ = t;
    }
    else
    {
        Node tmp = n->succ;
        treenode<T> *t = new treenode<T>;
        t->value = i;
        t->gen = n->gen;
        t->primo = nullptr;
        t->succ = tmp;
        n->succ = t;
    }
}

template <class T>
void TreePtr<T>::removeSubTree(Node n)
{
    if (n == nullptr)
        throw NullNode();
    while (!leaf(n))
        removeSubTree(n->primo);
    if (n->gen != nullptr)
    {
        Node p = n->gen;
        if (p->primo == n)
        {
            p->primo = n->succ;
        }
        else
        {
            Node tmp = p->primo;
            while (tmp->succ != n)
                tmp = tmp->succ;
            tmp->succ = n->succ;
        }
    }
     if (n == radice)
            radice = nullptr;
        delete n;
}

template <class T>
void TreePtr<T>::insFirstSubTree(Node n, TreePtr<T> &T2)
{
    if (this->empty() || T2.empty())
        throw EmptyTree();
    if (n == nullptr)
        throw NullNode();
    Node oldRoot = T2.root();
    if (leaf(n))
    {
        n->primo = oldRoot;
        oldRoot->gen = n;
    }
    else
    {
        Node tmp = n->primo;
        n->primo = oldRoot;
        oldRoot->gen = n;
        oldRoot->succ = tmp;
    }
}

template <class T>
void TreePtr<T>::insSubTree(Node n, TreePtr<T> &T2)
{
    if (this->empty() || T2.empty())
        throw EmptyTree();
    if (this->root() == n)
        throw rootNode();
    if (n == nullptr)
        throw NullNode();
    Node oldRoot = T2.root();
    if (n->succ == nullptr)
    {
        n->succ = oldRoot;
        oldRoot->gen = n->gen;
    }
    else
    {
        Node tmp = n->succ;
        n->succ = oldRoot;
        oldRoot->gen = n->gen;
        oldRoot->succ = tmp;
    }
}

template <class T>
void TreePtr<T>::writeNode(Node n, const Item i)
{
    if (n != nullptr)
        n->value = i;
    else
        throw NullNode();
}

template <class T>
typename TreePtr<T>::Item TreePtr<T>::readNode(const Node n) const
{
    if (n != nullptr)
        return n->value;
    else
        throw NullNode();
}

template <class T>
void TreePtr<T>::print() const
{
    std::cout << "\n{ ";
    if (this->empty())
    {
        std::cout << "}\n";
    }
    else
    {
        Node it = radice;
        std::cout << "\n"
                 << readNode(it) << ": ";
        it = it->primo;
            printNodes(it);
            std::cout <<"\n";
        while (it != nullptr)
        {   if (it->primo != nullptr) {
            std::cout << "\n"
                 << readNode(it) << ": ";
            it = it->primo;
            printNodes(it);
            std::cout <<"\n";
        }
         else it = it->succ;
        }
        std::cout << "}\n";
    }
}

template <class T>
void TreePtr<T>::printNodes(Node n) const //stampa il nodo e tutti i suoi fratelli
{
    if (n == nullptr)
        return;
    else
    {
        while(n != nullptr) {
            std::cout << n->value << " ";
            n = n->succ;
        }
    }
}

#endif /* _Bin_treeP_H_ */
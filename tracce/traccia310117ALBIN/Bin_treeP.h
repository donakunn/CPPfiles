#ifndef _Bin_treeP_H_
#define _Bin_treeP_H_

#include "Bin_tree.h"
#include "exceptions.h"

template <class T>
class Bin_treeP;

template <class T>
class treenode
{
  friend class Bin_treeP<T>;

private:
  treenode<T> *gen;
  treenode<T> *sin;
  treenode<T> *des;
  T value;
  //funzione di utility che crea una copia del nodo e di tutti i suoi figli ricorsivamente
  treenode<T> *NodeCopy(treenode<T> *src)
  {
    if (src == nullptr)
      return nullptr;
    else
    {
      treenode<T> *newNode = new treenode<T>;
      newNode->gen = src->gen;
      newNode->value = src->value;
      newNode->sin = NodeCopy(src->sin);
      newNode->des = NodeCopy(src->des);
      return newNode;
    }
  }
};

template <class T>
class Bin_treeP : public Bin_tree<T, treenode<T> *>
{
public:
  typedef typename Bin_tree<T, treenode<T> *>::value_type value_type;
  typedef typename Bin_tree<T, treenode<T> *>::Nodo Nodo;

  // costruttori e distruttori
  Bin_treeP();
  Bin_treeP(const Bin_treeP<T> &);               //costruttore di copia
  Bin_treeP<T> &operator=(const Bin_treeP<T> &); //sovraccarico assegnamento
  ~Bin_treeP();
  // operatori
  void create();
  bool empty() const;
  Nodo root() const;
  Nodo parent(Nodo) const;
  Nodo sx(Nodo) const;
  Nodo dx(Nodo) const;
  bool sx_empty(Nodo) const;
  bool dx_empty(Nodo) const;
  void erase(Nodo);
  T read(Nodo) const;
  void write(Nodo, value_type);
  void ins_root();
  void ins_sx(Nodo);
  void ins_dx(Nodo);
  void costr(Bin_treeP<T> &);

private:
  treenode<T> *radice;
};

template <class T>
Bin_treeP<T>::Bin_treeP()
{
  create();
}

template <class T>
void Bin_treeP<T>::create(){
   radice = nullptr;
}

template <class T>
Bin_treeP<T>::Bin_treeP(const Bin_treeP<T> &T2)
{
  radice = radice->NodeCopy(T2.root());
}
template <class T>
Bin_treeP<T> &Bin_treeP<T>::operator=(const Bin_treeP<T> &T2)
{
  if (this != &T2)
  {
    erase(this->radice);
    radice = radice->NodeCopy(T2.root());
  }
  return *this;
}

template <class T>
Bin_treeP<T>::~Bin_treeP()
{
  if (!empty())
  {
    erase(radice);
  }
}

template <class T>
bool Bin_treeP<T>::empty() const
{
  return (radice == nullptr);
}

template <class T>
typename Bin_treeP<T>::Nodo Bin_treeP<T>::root() const
{
  return (radice);
}

template <class T>
typename Bin_treeP<T>::Nodo Bin_treeP<T>::parent(Nodo n) const
{
  if (n != radice)
    return (n->gen);
  else
    throw NullNode();
}

template <class T>
typename Bin_treeP<T>::Nodo Bin_treeP<T>::sx(Nodo n) const
{
  if (!sx_empty(n))
    return (n->sin);
  else
    throw NullNode();
};

template <class T>
typename Bin_treeP<T>::Nodo Bin_treeP<T>::dx(Nodo n) const
{
  if (!dx_empty(n))
    return (n->des);
  else
    throw NullNode();
}

template <class T>
bool Bin_treeP<T>::sx_empty(Bin_treeP<T>::Nodo n) const
{
  return (n->sin == nullptr);
}

template <class T>
bool Bin_treeP<T>::dx_empty(Bin_treeP<T>::Nodo n) const
{
  return (n->des == nullptr);
}

template <class T>
void Bin_treeP<T>::ins_root()
{
  if (radice == nullptr)
  {
    radice = new treenode<T>;
    radice->sin = nullptr;
    radice->des = nullptr;
    radice->gen = nullptr;
  }
  else
    throw RootExists();
}

template <class T>
void Bin_treeP<T>::ins_sx(Nodo n)
{
  if (radice == nullptr)
    throw EmptyTree();
  if (n == nullptr) //da controllare
    throw NullNode();
  if (n->sin != nullptr)
    throw NodeExists();
  else
  {
    n->sin = new treenode<T>;
    n->sin->sin = nullptr;
    n->sin->des = nullptr;
    n->sin->gen = n;
  }
}

template <class T>
void Bin_treeP<T>::ins_dx(Nodo n)
{
  if (radice == nullptr)
    throw EmptyTree();
  if (n == nullptr) //da controllare
    throw NullNode();
  if (n->des != nullptr)
    throw NodeExists();
  else
  {
    n->des = new treenode<T>;
    n->des->sin = nullptr;
    n->des->des = nullptr;
    n->des->gen = n;
  }
}

template <class T>
void Bin_treeP<T>::erase(Nodo n)
{
  if (n != nullptr)
  { //da controllare
    if (!sx_empty(n))
      erase(n->sin);
    if (!dx_empty(n))
      erase(n->des);
    if ((n->gen != nullptr))
    {
      if (n == n->gen->sin)
        n->gen->sin = nullptr;
      else
        n->gen->des = nullptr;
    }
    if (n == radice)
      radice = nullptr;
    delete n;
  }
  else
    throw NullNode();
}

template <class T>
void Bin_treeP<T>::costr(Bin_treeP<T> &T2)
{
  Nodo tmp = this->radice;
  radice = new treenode<T>;
  if (tmp != nullptr)
  {
    radice->sin = tmp;
    radice->sin->gen = radice;
  }
  if (!T2.empty())
  {
    radice->des = T2.root();
    radice->des->gen = radice;
  }
}

template <class T>
T Bin_treeP<T>::read(Nodo n) const
{
  if (n != nullptr)
    return (n->value);
  else
    throw NullNode();
}

template <class T>
void Bin_treeP<T>::write(Nodo n, value_type a)
{
  if (n != nullptr)
    n->value = a;
  else
    throw NullNode();
}
#endif /* _Bin_treeP_H_ */
#ifndef _Bin_treeP_H_
#define _Bin_treeP_H_

#include "Bin_tree.h"
#include "exceptions.h"

template <class T>
class treenode{
    treenode<T> *gen;
    treenode<T> *sin;
    treenode<T> *des;
    T value;
};

template <class T>
class Bin_treeP : public Bin_tree<T, <treenode>*>{
  public:
	typedef typename Bin_tree<T, <treenode>*>::value_type value_type;
	typedef typename Bin_tree<T, <treenode>*>::Nodo Nodo;
 
    // costruttori e distruttori
    Bin_treeP();
    ~Bin_treeP();
//costruttore di copia?
    // operatori
    //void create() non implementato, si utilizza costruttore di default
    bool empty() const;

    Nodo root() const;
    Nodo parent(Nodo) const;
    Nodo sx(Nodo) const;
    Nodo dx(Nodo) const;
    bool sx_empty(Nodo) const;
    bool dx_empty(Nodo) const;

    //void costr(Bin_treec<T>);
    void erase(Nodo);

    T read(Nodo) const;
    void write(Nodo, value_type);

    void ins_root(Nodo);
    void ins_sx(Nodo);
    void ins_dx(Nodo);

  private:
    treenode<T> *root;
};

template <class T>
Bin_treeP<T>::Bin_treeP()
{
  root= nullptr; 
}

template <class T>
Bin_treeP<T>::~Bin_treeP()
{
  erase(root);
}

template <class T>
bool Bin_treeP<T>::empty() const
{
  return(root == nullptr);
}

template <class T>
typename Bin_treeP<T>::Nodo Bin_treeP<T>::root() const 
{
  return(root);
}

template <class T>
typename Bin_treeP<T>::Nodo Bin_treeP<T>::parent(Nodo n) const
{
  if (n != root)
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
void Bin_treeP<T>::ins_root(Bin_treeP<T>::Nodo n)
{
  if (root == nullptr)
    {
      root = new treenode<T>;
      root->sin = nullptr;
      root->des = nullptr;
      root->gen = nullptr;
    }
	else
		throw RootExists();
}


template <class T>
void Bin_treeP<T>::ins_sx(Nodo n)
{
	if (root == nullptr)
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
	if (root == nullptr)
		throw EmptyTree();
	if (n == nullptr) //da controllare
		throw NullNode();
	if (if n->des != nullptr)
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
  if (n != nullptr) { //da controllare
      if (!sx_empty(n))
        erase(n->sin);
      if (!dx_empty(n))
        erase(n->des);
      if (n->gen != nullptr) {
          if (n == n->gen->sin)
            n->gen->sin = nullptr;
          else
            n->gen->des = nullptr;
        }
      delete n;
    }
	else
		throw NullNode();
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

 
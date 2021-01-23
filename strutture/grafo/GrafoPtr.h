#ifndef GrafoPtr_H
#define GrafoPtr_H

#include "Grafo.h"
#include "linked_list.h"

template <class E, class P>
class GrafoPtr;

template <class E, class P>
class NodoPesato //Contiene il nodo successivo e il peso dell'arco
{
  friend class GrafoPtr;
  //devo mettere come friend anche la classe Nodo?
private:
  Nodo<E, P> *succ;
  P pesoArco;
};

template <class E, class P>
class Nodo
{
  friend class GrafoPtr;

private:
  E label;
  LinkedList<NodoPesato<E, P> *> A;
};

template <class E, class P>
class GrafoPtr : public Grafo<E, P, Nodo<E> *>
{
public:
  typedef E Etichetta;
  typedef P Peso;
  typedef Nodo<E, P> *Nodo;
  typedef NodoPesato<E, P> *NodoPesato;
  typedef Grafo<Etichetta, Peso, Nodo> Grafo_;
  typedef typename Grafo_::ListaNodi ListaNodi;
  typedef typename Grafo_::ListaNodiPos ListaNodiPos;

  GrafoPtr();
  GrafoPtr(const GrafoPtr<E, P> &);
  GrafoPtr<E, P> &operator=(const GrafoPtr<E, P> &);
  ~GrafoPtr();

  bool vuoto() const;
  void insNodo(Nodo);
  void insArco(Nodo, Nodo, Peso);
  void cancNodo(Nodo);
  void cancArco(Nodo, Nodo);
  bool esisteNodo(Nodo);
  bool esisteArco(Nodo, Nodo);
  ListaNodi Adiacenti(Nodo) const;
  ListaNodi list_nodi() const;
  Etichetta leggiEtichetta(Nodo) const;
  void scriviEtichetta(Nodo, Etichetta);
  Peso leggiPeso(Nodo, Nodo) const;
  void scriviPeso(Nodo, Nodo, Peso);

  int numNodi()
  {
    return nodi;
  };
  int numArchi()
  {
    return archi;
  };

private:
  Linked_list<Nodo> listaNodi;
  int archi = 0;
};

template <class E, class P>
GrafoPtr<E, P>::GrafoPtr()
{
  listaNodi = new Linked_list<Nodo>;
}

GrafoPtr(const GrafoPtr<E, P> &);
GrafoPtr<E, P> &operator=(const GrafoPtr<E, P> &);

template <class E, class P>
GrafoPtr<E, P>::~GrafoPtr()
{
  if (listaNodi.empty())
  {
    delete listaNodi;
  }
  else
  {
    for (Nodo n : listaNodi)
    {
      delete n;
    }
    delete listaNodi;
  }
}

template <class E, class P>
bool GrafoPtr<E, P>::vuoto() const
{
  return (listaNodi.empty());
}

template <class E, class P>
bool GrafoPtr<E, P>::esisteNodo(Nodo n)
{
  if (n == nullptr || listaNodi.empty())
    return false;
  for (Nodo u : listaNodi)
  {
    if (u == n)
      GrafoPtr<E, P>::return true;
  }
  return false;
}

template <class E, class P>
bool GrafoPtr<E, P>::esisteArco(Nodo n1, Nodo n2)
{
  if (n1 == nullptr || n2 == nullptr)
    throw NullNode();
  if (n1->A.empty())
    return false;
  for (NodoPesato u : n1->A)
  {
    if (u->succ == n2)
      return true;
  }
  return false;
}

template <class E, class P>
void GrafoPtr<E, P>::insNodo(Nodo n)
{
  if (esisteNodo(n))
    throw NodeExists();
  listaNodi.insert(n, listaNodi.begin());
}

template <class E, class P>
void GrafoPtr<E, P>::insArco(Nodo n1, Nodo n2, Peso p)
{
  if (n1 == nullptr || n2 == nullptr)
    throw NullNode();
  if (esisteNodo(n1) && esisteNodo(n2))
  {
    if (esisteArco(n1, n2))
      throw ArcExists();
    n1->A.insert(n2, n1->A.begin()) //provare con end()?
  }
  else
    throw NullNode();
}

template <class E, class P>
void GrafoPtr<E, P>::cancNodo(Nodo n)
{
  if (n == nullptr)
    throw NullNode();
  if (!n->A.empty())
    throw ArcExistsOnDel();
  for (Nodo u : listaNodi)
  {
    for (NodoPesato w : u->A)
    {
      if (w == n)
        throw NullNode();
    }
    listaNodi.erase(n); //funzionera?
  }
}

template <class E, class P>
void GrafoPtr<E, P>::cancArco(Nodo n1, Nodo n2)
{
  if (n1 == nullptr || n2 == nullptr)
    throw NullNode();
  if (n1->A.empty())
    throw ArcDoesntExists();
  for (NodoPesato u : n1->A)
  {
    if (u->succ == n2)
      n1->A.erase(u);
    return;
  }
  throw ArcDoesntExists();
}

template <class E, class P>
ListaNodi GrafoPtr<E, P>::Adiacenti(Nodo n) const
{
  Linked_list<Nodo> listaAdiacenti; //serve operatore new?
  for (NodoPesato u : n->A)
  {
    listaAdiacenti.insert(u->succ);
  }
  return (listaAdiacenti);
}

template <class E, class P>
ListaNodi GrafoPtr<E, P>::list_nodi() const
{
  return (listaNodi);
}

template <class E, class P>
Etichetta GrafoPtr<E, P>::leggiEtichetta(Nodo n) const
{
  if (!esisteNodo(n))
    throw NullNode();
  return (n->label);
}

template <class E, class P>
void GrafoPtr<E, P>::scriviEtichetta(Nodo n, Etichetta e)
{
   if (!esisteNodo(n))
    throw NullNode();
  n->label = e;
}

template <class E, class P>
Peso GrafoPtr<E, P>::leggiPeso(Nodo n1, Nodo n2) const {
  if (!esisteNodo(n1) || !esisteNodo(n2))
    throw NullNode();
  for (NodoPesato u : n1->A)
  {
    if (u->succ == n2)
      return u->pesoArco;
  }
  throw ArcDoesntExists();
}

template <class E, class P>
void GrafoPtr<E, P>::scriviPeso(Nodo n1, Nodo n2, Peso p) {
  if (!esisteNodo(n1) || !esisteNodo(n2))
    throw NullNode();
  for (NodoPesato u : n1->A)
  {
    if (u->succ == n2)
      u->pesoArco = p;
  }
  throw ArcDoesntExists();
}

#endif
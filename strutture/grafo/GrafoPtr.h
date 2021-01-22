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
  //typedef Arco_<Peso, Nodo> Arco;
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
  bool esisteArco(Nodo,Nodo);
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
bool GrafoPtr<E, P>::vuoto()
{
  return (listaNodi.empty());
}

template <class E, class P>
void GrafoPtr<E, P>::insNodo(Nodo nodo)
{
  for (Nodo n : listaNodi)
  {
    if (n == nodo)      //da cambiare con esiste nodo
      throw NodeExists();
  }
  listaNodi.insert(nodo, listaNodi.begin());
}

template <class E, class P>
void GrafoPtr<E, P>::insArco(Nodo n1, Nodo n2, Peso p)
{
  if (n1 == nullptr || n2 == nullptr)
    throw NullNode();
  for (Nodo u : listaNodi)
  {
    if (u == n1)
    {
      for (nodo v : listaNodi)
      {
        if (v == n2)
        {
          for (NodoPesato w : n1->A)
          {
            if (w->succ == n2)
              throw ArcExists();
          }
          n1->A.insert(n2, n1->A.begin());
        }
      }
      throw NullNode();
    }
  }
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
  for (NodoPesato u : n1->A) {
    if (u->succ == n2)
      n1->A.erase(u);
      return;
  }
  throw ArcDoesntExists();
}
bool esisteNodo(Nodo);
bool esisteArco(Nodo,Nodo);
ListaNodi Adiacenti(Nodo) const;
ListaNodi list_nodi() const;
Etichetta leggiEtichetta(Nodo) const;
void scriviEtichetta(Nodo, Etichetta);
Peso leggiPeso(Nodo, Nodo) const;
void scriviPeso(Nodo, Nodo, Peso);
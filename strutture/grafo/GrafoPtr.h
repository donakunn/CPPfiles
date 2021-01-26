#ifndef GrafoPtr_H
#define GrafoPtr_H

#include "Grafo.h"
#include "linked_list.h"
#include "exceptions.h"

//BROKEN!!!!!!!!!!!

template <class E, class P>
class GrafoPtr;

template <class E, class P>
class NodoG;

template <class E, class P>
class NodoCollegato //Contiene il nodo successivo e il peso dell'arco
{
  friend class GrafoPtr<E, P>;
  //devo mettere come friend anche la classe Nodo?
  NodoCollegato(NodoG<E, P> *nodoCongiunto, P pesoNuovoArco) : succ(nodoCongiunto), P(pesoNuovoArco) {}
  NodoCollegato(const NodoCollegato<E, P> &N2)
  {
    this->succ = N2->succ;
    this->pesoArco = N2->pesoArco;
  }
  NodoCollegato<E, P> &operator=(const NodoCollegato<E, P> &N2)
  {
    if (this != &N2)
    {
      this->succ = N2->succ; //da controllare
      this->pesoArco = N2->pesoArco;
    }
    return this;
  }

private:
  NodoG<E, P> *succ;
  P pesoArco;
};

template <class E, class P>
class NodoG
{
  friend class GrafoPtr<E, P>;

public:
  NodoG(){};
  NodoG(E newLabel) : label(newLabel)
  {
    A = new Linked_list<NodoCollegato<E, P>>;
  }

  NodoG(const NodoG<E, P> &N2)
  {
    this->label = N2.label;
    this->A = A;
  }

  NodoG<E, P> &operator=(const NodoG<E, P> &N2)
  {
    if (this != &N2)
    {
      delete A;
      this->label = N2.label;
      this->A = A;
    }
    return *this;
  }
  ~NodoG()
  {
    delete A;
  }

private:
  E label;
  Linked_list<NodoCollegato<E, P>> *A;
};

template <class E, class P>
class GrafoPtr : public Grafo<E, P, NodoG<E, P> *>
{
public:
  typedef E Etichetta;
  typedef P Peso;
  typedef NodoG<E, P> Nodo;
  typedef NodoCollegato<E, P> NodoColleg;
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
  Etichetta leggiEtichetta(Nodo);
  void scriviEtichetta(Nodo, Etichetta);
  Peso leggiPeso(Nodo, Nodo);
  void scriviPeso(Nodo, Nodo, Peso);

  int numNodi() const
  {
    return (listaNodi->ListLength());
  };
  int numArchi() const
  {
    return (archi);
  };

private:
  Linked_list<Nodo> *listaNodi;
  int archi = 0;
  //void clearNodesList();
};

template <class E, class P>
GrafoPtr<E, P>::GrafoPtr()
{
  listaNodi = new Linked_list<Nodo>;
}

template <class E, class P>
GrafoPtr<E, P>::GrafoPtr(const GrafoPtr<E, P> &G)
{
  this->listaNodi = G->listaNodi;
  archi = G->archi;
}

/*template <class E, class P>
void GrafoPtr<E, P>::clearNodesList()
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
}*/

template <class E, class P>
GrafoPtr<E, P> &GrafoPtr<E, P>::operator=(const GrafoPtr<E, P> &G)
{
  if (this != &G)
  {
    delete listaNodi;
    this->listaNodi = G->listaNodi;
    archi = G->archi;
  }
  return *this;
}

template <class E, class P>
GrafoPtr<E, P>::~GrafoPtr()
{
  delete listaNodi;
}

template <class E, class P>
bool GrafoPtr<E, P>::vuoto() const
{
  return (listaNodi->empty());
}

template <class E, class P>
bool GrafoPtr<E, P>::esisteNodo(Nodo n)
{
  if (n == nullptr || listaNodi->empty())
    return false;
  for (typename Linked_list<Nodo>::position it = listaNodi->begin(); !(listaNodi->end(it)); it++)
  {
    if (listaNodi->read(it) == n)
      return true;
  }
  return false;
}

template <class E, class P>
bool GrafoPtr<E, P>::esisteArco(Nodo n1, Nodo n2)
{
  if (n1 == nullptr || n2 == nullptr)
    throw NullNode();
  if (n1->A->empty())
    return false;
  for (typename Linked_list<NodoColleg>::position it = n1->A->begin(); !(n1->A->end(it)); it++)
  {
    if (n1->A->read(it)->succ == n2)
      return true;
  }
  return false;
}

template <class E, class P>
void GrafoPtr<E, P>::insNodo(Nodo n)
{
  if (esisteNodo(n))
    throw NodeExists();
  listaNodi->insert(n, listaNodi->begin());
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
    NodoColleg nodoPesato(n2, p);
    n1.A->insert(nodoPesato, n1.A->begin()); //provare con end()?
    archi++;
  }
  else
    throw NullNode();
}

template <class E, class P>
void GrafoPtr<E, P>::cancNodo(Nodo n)
{
  if (n == nullptr)
    throw NullNode();
  if (!n.A->empty())
    throw ArcExistsOnDel();
  ListaNodiPos posizioneDiN;
  for (typename Linked_list<Nodo>::position it = listaNodi->begin(); !(listaNodi->end(it)); it++)
  {
    Nodo u = listaNodi->read(it);
    if (u != n)
    {
      for (typename Linked_list<NodoColleg>::position iter = u.A->begin(); !(u.A->end(iter)); iter++)
      {
        if (u.A->read(iter).succ == n)
          throw ArcExistsOnDel();
      }
    }
    else
    {
    }
  }
  if (posizioneDiN != nullptr)
    listaNodi->erase(posizioneDiN); //funzionera?
}

template <class E, class P>
void GrafoPtr<E, P>::cancArco(Nodo n1, Nodo n2)
{
  if (n1 == nullptr || n2 == nullptr)
    throw NullNode();
  if (n1->A->empty())
    throw ArcDoesntExists();
  for (typename Linked_list<NodoColleg>::position it = n1->A->begin(); !(n1->A->end(it)); it++)
  {
    if (n1->A->read(it)->succ == n2)
    {
      n1->A->erase(it);
      archi--;
      return;
    }
  }
  throw ArcDoesntExists();
}

template <class E, class P>
typename GrafoPtr<E, P>::ListaNodi GrafoPtr<E, P>::Adiacenti(Nodo n) const
{
 ListaNodi listaAdiacenti;
  for (typename Linked_list<NodoColleg>::position it = n.A->last(); !(n.A->end(it)); it--)
  {
    listaAdiacenti.insert(n.A->read(it)->succ,listaAdiacenti.begin());
  }
  return (listaAdiacenti);
}

template <class E, class P>
typename GrafoPtr<E, P>::ListaNodi GrafoPtr<E, P>::list_nodi() const
{
  return (*listaNodi);
}

template <class E, class P>
typename GrafoPtr<E, P>::Etichetta GrafoPtr<E, P>::leggiEtichetta(Nodo n)
{
  if (!esisteNodo(n))
    throw NullNode();
  return (n.label);
}

template <class E, class P>
void GrafoPtr<E, P>::scriviEtichetta(Nodo n, Etichetta e)
{
  if (!esisteNodo(n))
    throw NullNode();
  n.label = e;
}

template <class E, class P>
typename GrafoPtr<E, P>::Peso GrafoPtr<E, P>::leggiPeso(Nodo n1, Nodo n2)
{
  if (!esisteNodo(n1) || !esisteNodo(n2))
    throw NullNode();
  for (typename Linked_list<NodoColleg>::position it = n1->A->begin(); !(n1->A->end(it)); it++)
  {
    if (n1->A->read(it)->succ == n2)
      return (n1->A->read(it)->pesoArco);
  }
  throw ArcDoesntExists();
}

template <class E, class P>
void GrafoPtr<E, P>::scriviPeso(Nodo n1, Nodo n2, Peso p)
{
  if (!esisteNodo(n1) || !esisteNodo(n2))
    throw NullNode();
  for (typename Linked_list<NodoColleg>::position it = n1->A->begin(); !(n1->A->end(it)); it++)
  {
    if (n1->A->read(it)->succ == n2)
      n1->A->read(it)->pesoArco = p;
  }
  throw ArcDoesntExists();
}

#endif
#ifndef GRAFO_H
#define GRAFO_H

#include "linked_list.h"

template <class P, class N>
class Arco_
{
public:
	N nodo1;
	N nodo2;
	P peso;
};

template <class E, class P, class N>
class Grafo
{
public:
	typedef E Etichetta;
	typedef P Peso;
	typedef N Nodo;

	typedef Arco_<Peso, Nodo> Arco;
	typedef Linked_list<Nodo *> ListaNodi;
	typedef typename Linked_list<Nodo *>::position ListaNodiPos;
	typedef Linked_list<Arco> ListaArchi;

	virtual bool vuoto() const = 0;
	virtual void insNodo(Nodo &) = 0;
	virtual void insArco(Nodo, Nodo, Peso) = 0;
	virtual void cancNodo(Nodo) = 0;
	virtual void cancArco(Nodo, Nodo) = 0;
	virtual bool esisteNodo(Nodo) = 0;
	virtual bool esisteArco(Nodo, Nodo) = 0;
	virtual ListaNodi Adiacenti(Nodo) = 0;
	virtual ListaNodi list_nodi() const = 0;
	virtual Etichetta leggiEtichetta(Nodo) const = 0;
	virtual void scriviEtichetta(Nodo, Etichetta) = 0;
	virtual Peso leggiPeso(Nodo, Nodo) const = 0;
	virtual void scriviPeso(Nodo, Nodo, Peso) = 0;
	virtual int numNodi() = 0;
	virtual int numArchi() = 0;
	//virtual void DFS(Nodo);
	//virtual void BFS(Nodo);
	virtual ~Grafo(){};
};

/*
template <class E, class P, class N>
void Grafo<E, P, N>::DFS(Nodo n)
{
	//esamina il nodo n
	ListaNodi listaAdiacenti = Adiacenti(n);
	ListaNodiPos p = listaAdiacenti.begin();
	while (!listaAdiacenti.end(p))
	{
		if (!visitato(listaAdiacenti.read(p)))
			DFS(listaAdiacenti.read(p));
		p = listaAdiacenti.next(p);
	}
}

template <class E, class P, class N>
void Grafo<E, P, N>::BFS(Nodo n)
{
	queue<Nodo> Q;
	Q.push(n);
	while (!Q.empty())
	{
		Nodo k = Q.pop();
		//esamina il nodo n
		ListaNodi listaAdiacenti = Adiacenti(n);
		ListaNodiPos p = listaAdiacenti.begin();
		while (!listaAdiacenti.end(p))
		{
			if (!Q.exists(listaAdiacenti.read(p)))
				Q.push(listaAdiacenti.read(p));
			p = listaAdiacenti.next(p);
		}
	}
*/
#endif

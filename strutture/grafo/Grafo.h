#ifndef GRAFO_H
#define GRAFO_H

#include "linked_list.h"

template<class E, class P, class N>
	class Grafo {
 public:
	typedef E Etichetta;
	typedef P Peso;
	typedef N Nodo;

	typedef Linked_list<Nodo*> ListaNodi;
	typedef typename Linked_list<Nodo*>::position ListaNodiPos;	
	virtual bool vuoto() const = 0;
	virtual void insNodo(Nodo&) = 0;
	virtual void insArco(Nodo, Nodo, Peso) = 0;
	virtual void cancNodo(Nodo) = 0;
	virtual void cancArco(Nodo, Nodo) = 0;
	virtual bool esisteNodo(Nodo) = 0;
	virtual bool esisteArco(Nodo,Nodo) = 0;
	virtual ListaNodi Adiacenti(Nodo) const = 0;
	virtual ListaNodi list_nodi() const = 0;
	virtual Etichetta leggiEtichetta(Nodo) const = 0;
	virtual void scriviEtichetta(Nodo, Etichetta) = 0;
	virtual Peso leggiPeso(Nodo, Nodo) const = 0;
	virtual void scriviPeso(Nodo, Nodo, Peso) = 0;
	
	virtual int numNodi() = 0;
	virtual int numArchi() = 0;

	virtual ~Grafo(){};

};


#endif

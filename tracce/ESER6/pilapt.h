#ifndef _PILAVT_H
#define _PILAVT_H

#include <iostream>
template <class T>
class Pila;

template <class T>
class cella
{
  friend class Pila<T>;

private:
  T e;
  cella *prev;
};

template <class T>
class Pila
{
public:
  typedef T tipoelem;
  Pila();          //corrisponde a creaPila()
  ~Pila();         //costruttore di copia
  Pila(Pila<T> &); //sovraccarico assegnamento
  Pila<T> &operator=(Pila<T> &);
  void creaPila();
  bool pilaVuota() const;
  tipoelem leggiPila() const;
  void fuoriPila();
  void inPila(tipoelem);

  //funzioni di utilità
  template <class elem>
  friend void stampaPila(Pila<elem> &);

private:
  cella<T> *testa;
};

template <class T>
Pila<T>::Pila()
{
  creaPila();
}

template <class T>
Pila<T>::~Pila()
{
  while (!pilaVuota())
    fuoriPila();
}

template <class T>
Pila<T>::Pila(Pila<T> &P)
{
  testa = nullptr;
  Pila<T> tmpPila;
  tipoelem tmpElem;

  while (!P.pilaVuota())
  {
    tmpElem = P.leggiPila();
    P.fuoriPila();
    tmpPila.inPila(tmpElem);
  }

  while (!tmpPila.pilaVuota())
  {
    tmpElem = tmpPila.leggiPila();
    tmpPila.fuoriPila();
    P.inPila(tmpElem);
    this->inPila(tmpElem);
  }
}

template <class T>
Pila<T> &Pila<T>::operator=(Pila<T> &P)
{
  if (this != &P)
  {
    while (!pilaVuota())
    {
      fuoriPila();
    }

    Pila<T> tmpPila;
    tipoelem tmpElem;

    while (!P.pilaVuota())
    {
      tmpElem = P.leggiPila();
      P.fuoriPila();
      tmpPila.inPila(tmpElem);
    }

    while (!tmpPila.pilaVuota())
    {
      tmpElem = tmpPila.leggiPila();
      tmpPila.fuoriPila();
      P.inPila(tmpElem);
      this->inPila(tmpElem);
    }
  }

  return *this;
}

template <class T>
void Pila<T>::creaPila()
{
  testa = nullptr;
}

template <class T>
bool Pila<T>::pilaVuota() const
{
  return testa == nullptr;
}

template <class T>
T Pila<T>::leggiPila() const
{
  if (!pilaVuota())
    return testa->e;
  else
    throw "Pila vuota";
}

template <class T>
void Pila<T>::fuoriPila()
{
  if (!pilaVuota())
  {
    cella<T> *tmp = testa;
    testa = testa->prev;
    delete tmp;
  }
}

template <class T>
void Pila<T>::inPila(tipoelem el)
{
  cella<T> *tmp = new cella<T>;
  tmp->e = el;
  tmp->prev = testa;
  testa = tmp;
}

template <class elem>
void stampaPila(Pila<elem> &P)
{
  if (P.pilaVuota())
    return;
  elem tmp = P.leggiPila();
  P.fuoriPila();
  stampaPila(P);
  std::cout << tmp << " ";
  P.inPila(tmp);
}
#endif // _PILAVT_H
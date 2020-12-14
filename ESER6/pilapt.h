#ifndef _PILAVT_H
#define _PILAVT_H

template <class T>
class cella{
  T e;
  cella *prev;
};

template <class Elemento>
class Pila
  {
  public:
    typedef Elemento tipoelem;
    Pila();
    ~Pila();
    void creaPila();
    bool pilaVuota() const;
    tipoelem leggiPila() const;
    void fuoriPila();
    void inPila(tipoelem);
  private:
    cella* testa;
  };

template <class Elemento>
Pila<Elemento>::Pila()
{
  testa = nullptr;
}


template <class Elemento>
Pila<Elemento>::~Pila()
{
  while (!pilaVuota())
    fuoriPila();
};

template <class Elemento>
void Pila<Elemento>::creaPila()
{
  testa=nullptr;
}

template <class Elemento>
bool Pila<Elemento>::pilaVuota() const
  {
    return testa==nullptr;
  }

template <class Elemento>
Elemento Pila<Elemento>::leggiPila() const
  {
    return testa->e;
  }

template <class Elemento>
void Pila<Elemento>::fuoriPila()
{
  if (!pilaVuota())
    {
      cella *tmp = testa;
      testa = testa->prev;
      delete tmp;
    }
}

template <class Elemento>
void Pila<Elemento>::inPila(tipoelem el)
{
  cella<Elemento> *tmp = new cella();
  tmp->e = el;
  tmp->prev = testa;
  testa = tmp;
}

#endif // _PILAVT_H
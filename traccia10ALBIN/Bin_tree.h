
#ifndef _BINTREE_H_
#define _BINTREE_H_
#include <iostream>

template <class T, class N>
class Bin_tree
{
  static const int NIL = -1;

public:
  // tipi
  typedef T value_type;
  typedef N Nodo;

  // operatori
  virtual void create() = 0;
  virtual bool empty() const = 0;
  virtual Nodo root() const = 0;
  virtual Nodo parent(const Nodo) const = 0;
  virtual Nodo sx(const Nodo) const = 0;
  virtual Nodo dx(const Nodo) const = 0;
  virtual bool sx_empty(const Nodo) const = 0;
  virtual bool dx_empty(const Nodo) const = 0;

  //virtual void costr(const Bin_tree<T,N> &) = 0;
  virtual void erase(const Nodo) = 0;

  virtual T read(const Nodo) const = 0;
  virtual void write(const Nodo, const value_type) = 0;

  virtual void ins_root() = 0;
  virtual void ins_sx(const Nodo) = 0;
  virtual void ins_dx(const Nodo) = 0;

  // funzioni di servizio da implementare qui
  virtual void previsita(const Bin_tree<T,N> &);
  virtual void previsita(const Bin_tree<T,N> &, const Bin_tree<T,N>::Nodo);
  virtual void invisita(const Bin_tree<T,N> &);
  virtual void invisita(const Bin_tree<T,N> &, const Bin_tree<T,N>::Nodo);
  virtual void postvisita(const Bin_tree<T,N> &);
  virtual void postvisita(const Bin_tree<T,N> &, const Bin_tree<T,N>::Nodo);

  virtual void print() const;

private:
  virtual void printSubTree(const Nodo) const;
};

template <class T, class N>
void Bin_tree<T, N>::print() const
{
  if (!empty())
    printSubTree(root());
  else
    std::cout << "[]" << std::endl;
  std::cout << std::endl;
}

template <class T, class N>
void Bin_tree<T, N>::printSubTree(const Nodo n) const
{
  std::cout << "[" << read(n) << ", ";
  if (!sx_empty(n))
    printSubTree(sx(n));
  else
    std::cout << "NIL";
  std::cout << ", ";
  if (!dx_empty(n))
    printSubTree(dx(n));
  else
    std::cout << "NIL";
  std::cout << " ]";
}

template <class T, class N>
std::ostream &operator<<(std::ostream &out, const Bin_tree<T, N> &t)
{
  t.print();
  return out;
}
template <class T, class N>
void Bin_tree<T,N>::previsita(const Bin_tree<T, N> &t)
{
  if (!t.empty())
    previsita(t, t.root());
}

template <class T, class N>
void Bin_tree<T,N>::previsita(const Bin_tree<T, N> &t, const typename Bin_tree<T,N>::Nodo n)
{
  //ispeziona nodo n
  if (!t.sx_empty(n))
  {
    previsita(t, t.sx(n));
  }
  if (!t.dx_empty(n))
  {
    previsita(t, t.dx(n));
  }
}

template <class T, class N>
void Bin_tree<T,N>::invisita(const Bin_tree<T, N> &t)
{
  if (!t.empty())
    invisita(t, t.root());
}

template <class T, class N>
void Bin_tree<T,N>::invisita(const Bin_tree<T, N> &t, const typename Bin_tree<T,N>::Nodo n)
{
  if (!t.sx_empty(n))
  {
    invisita(t, t.sx(n));
  }
  //ispeziona nodo n
  if (!t.dx_empty(n))
  {
    invisita(t, t.dx(n));
  }
}

template <class T, class N>
void Bin_tree<T,N>::postvisita(const Bin_tree<T, N> &t)
{
  if (!t.empty())
    postvisita(t, t.root());
}

template <class T, class N>
void Bin_tree<T,N>::postvisita(const Bin_tree<T, N> &t, const typename Bin_tree<T,N>::Nodo n)
{
  if (!t.sx_empty(n))
  {
    postvisita(t, t.sx(n));
  }
  if (!t.dx_empty(n))
  {
    postvisita(t, t.dx(n));
  }
  //ispeziona nodo n
}

#endif /* _BINALBEROC_H_ */

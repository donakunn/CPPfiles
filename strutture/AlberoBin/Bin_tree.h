
#ifndef _BINTREE_H_
#define _BINTREE_H_
#include <iostream>

template <class T, class N>
class Bin_tree {
  static const int NIL = -1;

  public:
    // tipi
    typedef T value_type;
    typedef N Nodo;

    // operatori
    //virtual void create() = 0;
    virtual bool empty() const =  0;
    virtual Nodo root() const = 0;
    virtual Nodo parent(Nodo) const =  0;
    virtual Nodo sx(Nodo) const = 0;
    virtual Nodo dx(Nodo) const = 0;
    virtual bool sx_empty(Nodo) const = 0;
    virtual bool dx_empty(Nodo) const = 0;

    //virtual void costr(const Bin_tree<T,N> &) = 0;
    virtual void erase(Nodo) = 0;

    virtual T read(Nodo) const = 0;
    virtual void write(Nodo , value_type ) = 0;

    virtual void ins_root(Nodo) = 0;
    virtual void ins_sx(Nodo) = 0;
    virtual void ins_dx(Nodo) = 0;

    // funzioni di servizio da implementare qui
    //virtual void previsit(Nodo);
    //virtual void invisita(Nodo);
    //virtual void postvisit(Nodo);

    virtual void print() const;

private:
    virtual void printSubTree(const Nodo) const;
  };

template <class T, class N>
void Bin_tree<T,N>::print() const{
	if (!empty())
		printSubTree(root());
	else 
		std::cout << "[]" << std::endl;
	std::cout << std::endl;
}

template <class T, class N>
void Bin_tree<T,N>::printSubTree(const Nodo n) const{
	std::cout << "[" << read(n) << ", ";
	if (!sx_empty(n))
		printSubTree(sx(n));
	else std::cout << "NIL";
	std::cout << ", ";
	if (!dx_empty(n))
		printSubTree(dx(n));
	else std::cout << "NIL";
	std::cout << " ]";
}

template<class T, class N>
std::ostream& operator<<(std::ostream& out, const Bin_tree<T, N>& t) {
    t.print();
    return out;
}

#endif /* _BINALBEROC_H_ */

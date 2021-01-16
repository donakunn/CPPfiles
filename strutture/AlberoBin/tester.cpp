
#include "Bin_treeP.h"
#include <iostream>

using namespace std;

int main()
{
	Bin_treeP<int> T;
	typename Bin_treeP<int>::Nodo n1, n2;

	T.ins_root(n1);
	n2 = T.root();
	T.write(T.root(), 1);
	n1 = T.root();
	T.ins_sx(n1);
	T.ins_dx(n1);
	T.write(T.sx(n1), 2);
	n1 = T.dx(n1);
	T.write(n1, 3);
	T.ins_dx(n1);
	T.write(T.dx(n1), 4);
	cout << T;
	n2 = T.root();
	T.erase(n2);
	cout << T;
}


#include "TreePtr.h"

int main()
{

	TreePtr<char> Tree;

	TreePtr<char>::node n;
	Tree.insRoot();
	Tree.writeNode(Tree.root(), 'a');

	Tree.insFirst(Tree.root(), 'b');
	Tree.insFirst(Tree.root(), 'c');

	n = Tree.root();
	n = Tree.firstChild(n);

	Tree.ins(n, 'd');

	n = Tree.root();
	n = Tree.firstChild(n);
	Tree.insFirst(n, 'e');
	Tree.insFirst(n, 'f');

	Tree.print();

	n = Tree.root();
	n = Tree.firstChild(n);

	Tree.removeSubTree(n);

	Tree.print();

	TreePtr<char> T2 = Tree;

	TreePtr<char> T3;

	T3.insRoot();
	T3.writeNode(T3.root(), 'a');

	T3.insFirst(T3.root(), 'b');
	T3.insFirst(T3.root(), 'c');

	T2 = T3;
	T2.print();
	n = Tree.root();
	n = Tree.firstChild(n);
	Tree.insSubTree(n, T2);
	Tree.print();

	return 0;
}

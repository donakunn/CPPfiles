
#include "TreePtr.h"

int main(){

	TreePtr<char> Tree;

	TreePtr<char>::node n;
	Tree.insRoot();
	Tree.writeNode(Tree.root(),'a');

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
	T2.print();

	return 0;
}

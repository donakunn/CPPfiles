#ifndef TREE_H
#define TREE_H

template <class I, class N>
class Tree
{
public:
	typedef I item;
	typedef N node;

	virtual void create() = 0;
	virtual bool empty() const = 0;
	virtual void insRoot() = 0;
	virtual node root() const = 0;
	virtual node parent(const node) const = 0;
	virtual bool leaf(const node) const = 0;
	virtual node firstChild(const node) const = 0;
	virtual bool lastSibling(const node) const = 0;
	virtual node nextSibling(const node) const = 0;
	virtual void insFirst(node, const item) = 0;
	virtual void ins(node, const item) = 0;
	//virtual void insFirstSubTree (node, Tree<I,N> &) = 0;
	//virtual void insSubTree (node, Tree<I,N> &) = 0;
	virtual void removeSubTree(node) = 0;

	virtual void writeNode(node, const item) = 0;
	virtual item readNode(const node) const = 0;
	virtual void preorder(node);
	virtual void postorder(node);
	virtual void inorder(node);
};

template <class I, class N>
void Tree<I, N>::preorder(node n)
{
	//visita il nodo
	if (!leaf(n))
	{
		node k = firstChild(n);
		while (!lastSibling(k))
		{
			preorder(k);
			k = nextSibling(k);
		}
		preorder(k);
	}
}

template <class I, class N>
void Tree<I, N>::postorder(node n)
{
	if (!leaf(n))
	{
		node k = firstChild(n);
		while (!lastSibling(k))
		{
			postorder(k);
			k = nextSibling(k);
		}
		postorder(k);
	}
	//visita il nodo
}

template <class I, class N>
void Tree<I, N>::inorder(node n)
{
	if (leaf(n))
	{
		//esamina nodo
	}
	else
	{
		node k = firstChild(n);
		inorder(k);
		//esamina nodo n
		while (!lastSibling(k))
		{
			k = nextSibling(k);
			inorder(k);
		}
	}
}

#endif

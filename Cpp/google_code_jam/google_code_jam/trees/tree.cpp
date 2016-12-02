#include <string>
#include <algorithm>
#include <map>
#include "tree.h"

using namespace std;

tree<string>::tree()
{
	root = new node<string>;
	root->data = "root node";
	root->parent = NULL;
	root->children = new vector<node<string>*>;
}

tree<string>::tree(string s)
{
	root = new node<string>;
	root->data = s;
	root->parent = NULL;
	root->children = new vector<node<string>*>;
}

tree<string>::~tree()
{
	delete root;
}

bool tree<string>::exists(string s)
{
	return (search(s) != NULL);
}

void tree<string>::insert(node<string>* ns)
{
	if (exists(ns->parent->data) && ns->parent != NULL && !(exists(ns->data)))
		ns->parent->children->push_back(ns);

	else if (exists(ns->data))
	{
		//do nothing
	}

	else
		root->children->push_back(ns);
}

node<string>* tree<string>::search(string s, node<string>* ns)
{
	if (ns->data == s) return ns;

	else
	{
		for (int i = 0; i < ns->children->size(); i++)
			return search(s, ns->children->at(i));

		return NULL;
	}
}

int tree<string>::size(node<string>* ns)
{
	int s = 0;
	
	for (int i = 0; i < ns->children->size(); i++)
		s = max(s, size(ns->children->at(i)));
	
	return s + 1;
}

int tree<string>::count_nodes(node<string>* ns)
{
	map<string, int> msi;
	for (int i = 0; i < ns->children->size(); i++)
	{
		msi.insert(make_pair(ns->data, ns->children->size()));
		count_nodes(ns->children->at(i));
	}

	for (map<string, int>::iterator it = msi.begin(); it != msi.end(); it++)
		nodes += msi.at(it->first);

	return nodes;
}

void tree<string>::insert(string s)
{
	if (root != NULL)
	{
		node<string>* ns = new node<string>(s, root);
		insert(ns);
	}

	else
	{
		root = new node<string>;
		root->data = s;
		root->parent = NULL;
		root->children = new vector<node<string>*>;
	}
}

template<>
node<string>* tree<string>::search(string s)
{
	return search(s, root);
}

int tree<string>::size()
{
	return size(root);
}

int tree<string>::count_nodes()
{
	return count_nodes(root);
}


//(not necessarily binary) tree header file
#ifndef treeh
#define treeh

#include <vector>
using namespace std;

/*
node struct for tree class

contains:
	data (type W)
	pointer to parent (node<W>*)
	pointer to children (vector<node<W>*>*)

constructor:
	default: do nothing
	overloaded: set data and parent

destructor:
	delete parent & children pointers
*/
template<typename W>
struct node
{
	W data;

	node<W>* parent = new node<W>;
	vector<node<W>*>* children = new vector<node<W>*>;

	node() :
		parent(),
		children()
	{}

	node(W w, node* parent) :
		parent(parent),
		data(w)
	{}

	~node()
	{
		delete parent;
		delete children;
	}
};

//explicit initialization: allows node<string> to work without compiler arguing
template struct node<string>;

/*
tree class

constructor:
	default: set root's parent to NULL, root's data to "root node", & allocate memory to root's children
	overloaded: set root's parent to NULL, root's data to passed data, & allocate memory to root's children

destructor:
	delete root pointer

private variables:
	root (node<T>*)
	nodes (int)

private methods:
	search: (takes data of type T & node<T>*
				checks to see if node's data = data passed
				returns node whose data = data passed
				if it can't find such a node, it returns NULL)

	size: (returns height of tree from specific node)
	count_nodes: (returns number of nodes (including the passed node as well) from that point downwards)

public variables:
	none

public methods:
	search: (takes data & searches from root)
	insert: (if root isn't null, it takes passed data, stores it into a node, and inserts it
			 if root is null, a new root node is created, with data equivalent to the passed data)

	insert (overloaded): (checks to see if parent node exists & and node's data doesn't exist
							if these criterion are true, then node's parent's children pushes the passed node
							otherwise, if the node's data exists, do nothing
							and in any other case, root's children pushes the passed node)

	size: (returns size from root)
	count_nodes: (returns number of nodes from root)

	exists: (checks to see if a node exists
				essentially if search(node) isn't NULL, it returns true)

*/
template<typename T>
class tree
{
private:
	node<T>* root;
	int nodes = 1;
	
	node<T>* search(T, node<T>*);
		
	int size(node<T>*);
	int count_nodes(node<string>*);

public:
	tree();
	tree(string);
	~tree();

	node<T>* search(T);

	void insert(T);
	void insert(node<T>*);

	int size();
	int count_nodes();

	bool exists(string s);
};

#endif
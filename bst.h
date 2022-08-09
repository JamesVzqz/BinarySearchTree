#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H



#include<functional>
#include<iostream>
#include<assert.h>

// Node implementation
template<typename Item>
struct Node
{
	Node(Item i, Node* l, Node* r) :item(i), left(l), right(r) {}
	Node() :Node(0, nullptr, nullptr) {}

	Item item;
	Node* left, *right;
};

template<typename Item>
class BinarySearchTree {

public:
	// Public Interface Functions
	BinarySearchTree();
	~BinarySearchTree();

	void	printInorder();
	void	printPostorder();
	void	printPreorder();
	void	insert(Item item);

	void	remove(Item item);

	Item	min() const;
	Item	max() const;
	int		height() const;
	bool	find(Item item) const;

	bool	empty() const;

	void	printTree() const;

private:

	// Member variable root
	Node<Item>* m_root;

	//Auxillary recursive bst functions
	//public interface functions call these

	// Tree traversal, second parameter is a "function" with 
	// return type void and parameter Node*, i.e: 
	//					void process(Node* )
	void inorder(Node<Item>* node, std::function<void(Node<Item>*)> proc);
	void preorder(Node<Item>* node, std::function<void(Node<Item>*)> proc);
	void postorder(Node<Item>* node, std::function<void(Node<Item>*)> proc);

	Node<Item>* min(Node<Item> *node) const;
	Node<Item>* max(Node<Item> *node) const;

	int   height(Node<Item>* node) const;

	bool  find(Node<Item>* node, Item item) const;

	Node<Item>* insert(Node<Item>* node, Item item);
	Node<Item>* remove(Node<Item>* node, Item item);
	
	void  printTree(Node<Item>* node, int space) const;
};




//----------------------------------------------------------
//-------------- Binary Search Tree Function Implementations 
// 
//  Public Interface functions
// 		These functions call the recursive helper functions

// Constructor
template<typename Item>
BinarySearchTree<Item>::BinarySearchTree() :m_root(nullptr) {}

// Destructor
template<typename Item>
BinarySearchTree<Item>::~BinarySearchTree() {

	//Post order traversal to delete the nodes.
	//lambda function to delete a node n: 
	//				[](Node* n) {delete n; } 
	postorder(m_root, [](Node<Item>* n) {delete n; });
}
template<typename Item>
void BinarySearchTree<Item>::printInorder() {

	//Inorder traversal to print items in a node in the tree.
	//lambda function to print the item in a node:
	//lambda to print->	"[](Node* n) {std::cout << n->item << std::endl; }"
	inorder(m_root,      [](Node<Item>* n) {std::cout << n->item << " "; });

	std::cout << std::endl;
}
template<typename Item>
void BinarySearchTree<Item>::printPreorder() {

	//Pre order traversal to print items in a node in the tree.
	//lambda function to print the item in a node:
	//lambda to print->	"[](Node* n) {std::cout << n->item << std::endl; }"
	preorder(m_root, [](Node<Item>* n) {std::cout << n->item << " "; });
	std::cout << std::endl;
}
template<typename Item>
void BinarySearchTree<Item>::printPostorder() {

	//Post order traversal to print items in a node in the tree.
	//lambda function to print the item in a node:
	//lambda to print->	"[](Node* n) {std::cout << n->item << std::endl; }"
	postorder(m_root, [](Node<Item>* n) {std::cout << n->item << " "; });
	std::cout << std::endl;
}
template<typename Item>
void BinarySearchTree<Item>::insert(Item item) {
	m_root = insert(m_root, item);
}
template<typename Item>
void BinarySearchTree<Item>::remove(Item item) {
	m_root = remove(m_root, item);
}
template<typename Item>
Item	BinarySearchTree<Item>::min() const {

	assert(m_root != nullptr);

	Node<Item>* node = min(m_root);
	return node->item;
}
template<typename Item>
Item	BinarySearchTree<Item>::max() const {

	assert(m_root != nullptr);

	Node<Item>* node = max(m_root);
	return node->item;
}
template<typename Item>
int	BinarySearchTree<Item>::height() const {

	return height(m_root);
}
template<typename Item>
bool BinarySearchTree<Item>::find(Item item) const {
	return find(m_root, item);
}
template<typename Item>
bool BinarySearchTree<Item>::empty() const {
	return (m_root == nullptr);
}
template<typename Item>
void BinarySearchTree<Item>::printTree() const {
	printTree(m_root, 0);
}

//----------------------------------------------------------
//
// Private Recursive Functions.
//

// Inorder Traversal: Passing a function into another function.  
// The second parameter, proc, is a function and we see that its return type is void and it 
// has a Node* as a parameter.  Any function of that form passed into inorder will be
// called as seen below.  
// If we assume that we use the printing lambda defined above you can imagine that proc 
// is defined as:
//		void proc(Node<Item> * n){std::cout << n->item << " "; }
template<typename Item>
void BinarySearchTree<Item>::inorder(Node<Item>* node, std::function<void(Node<Item>*)> proc) {
	if (node == nullptr)
		return;

	inorder(node->left, proc);  // process nodes in left sub-tree
	proc(node);                 // process the current node
	inorder(node->right, proc); // process nodes in right sub-tree

}

template<typename Item>
void BinarySearchTree<Item>::postorder(Node<Item>* node, std::function<void(Node<Item>*)> proc) {
	
	if (node == nullptr)
		return;

	postorder(node->left, proc);  // process nodes in left sub-tree
	postorder(node->right, proc); // process nodes in right sub-tree
	proc(node);                 // process the current node

}
template<typename Item>
void BinarySearchTree<Item>::preorder(Node<Item>* node, std::function<void(Node<Item>*)> proc) {
	
	if (node == nullptr)
		return;

	proc(node);                 // process the current node
	preorder(node->left, proc);  // process nodes in left sub-tree
	preorder(node->right, proc); // process nodes in right sub-tree

}

// BinarySearchTree:: recursively inserts into the BST according 
// to the rules of the BST.  
template<typename Item>
Node<Item>* BinarySearchTree<Item>::insert(Node<Item>* node, Item item) {

	// recursive version
	if (node == nullptr) {
		return new Node<Item>(item, nullptr, nullptr);
	}
	if (item > node->item) {
		if (node->right == nullptr) {
			node->right = insert(node->right, item);
		}
		else {
			insert(node->right, item);
		}
	}
	if (item < node->item) {
		if (node->left == nullptr) {
			node->left = insert(node->left, item);
		}
		else {
			insert(node->left, item);
		}
	}
	if (node->item == item) {
		return node;
	}

	return node;
	

	// iterative version
	/*
	if (node == nullptr) {
		return new Node<Item>(item, nullptr, nullptr);
	}
	Node<Item>* cur = node;
	for (;;) {
		if (item == cur->item)	return cur;
		if (item < cur->item) {
			if (cur->left != nullptr)
				cur = cur->left;
			else {
				cur->left = new Node<Item>(item,nullptr,nullptr); // CHECK
				return cur;
			}
		}
		else if (item > cur->item) {
			if (cur->right != nullptr)
				cur = cur->right;
			else {
				cur->right = new Node<Item>(item, nullptr, nullptr); // CHECK
				return cur;
			}
		}
	}
	*/

}

// BinarySearchTree<Item>::find recursively searches the tree for item.
template<typename Item>
bool BinarySearchTree<Item>::find(Node<Item>* node, Item item) const {

	if (node == nullptr)
		return false; //nope
	else if (item == node->item)
		return true;
	else if (item < node->item)
		return(find(node->left, item));
	else
			return(find(node->right, item));

}

// BinarySearchTree<Item>::height
// Height of a binary tree is the height of the largest subtree + 1
// An empty tree has height 0;
template<typename Item>
int	BinarySearchTree<Item>::height(Node<Item>* node) const {

	if (node == nullptr)
		return 0;

	if (m_root->left == nullptr && m_root->right == nullptr) {
		return 1;
	}

	int l_height = height(node->left) + 1;
	int r_height = height(node->right) + 1;

	if (l_height >= r_height)
		return l_height;
	else
		return r_height;

}
// BinarySearchTree<Item>::min recursively obtain the node with the minimum item
template<typename Item>
Node<Item>* BinarySearchTree<Item>::min(Node<Item>* node) const {

	if (node == nullptr)
		return nullptr;
	if (node->left == nullptr)
		return node;

	return(min(node->left));

}

// BinarySearchTree<Item>::max recursively obtain the node with the minimum item
template<typename Item>
Node<Item>* BinarySearchTree<Item>::max(Node<Item>* node) const {
	
	if (node == nullptr)
		return nullptr;
	if (node->right == nullptr)
		return node;

	return(max(node->right));

}

// BinarySearchTree<Item>::printTree
// Prints the BST in a tree format rotated -90 degrees.  Uses space to 
// signify the space between levels of the tree. Uses the inorder 
// traversal but traverses right first, rather than left. Cannot use
// any of the other travel functions because of this.
//
// parameter space determines the number of spaces needed for each level.
// Example binary shows 5 spaces between levels. 
//
// i.e. traverse right 
//		print appropriate number of spaces 
//		print item 
//		traverse left
template<typename Item>
void BinarySearchTree<Item>::printTree(Node<Item>* node, int space) const {

	if (node == nullptr)
		return;

	printTree(node->right, space + 5);
	for (int i = 0; i < space; i++)
		std::cout << " ";
	std::cout << node->item << std::endl;

	printTree(node->left, space + 5);

}


//BinarySearchTree<Item>::remove
//
// Recursively removes a node in the binary tree. The recursive algorithm will 
// be different than the iterative algorithm. The iterative algorithm conisted
// of first finding the node using two pointers so that we know how to rearrange
// the children of the deleted node. In recursion, we are passing in the sub trees
// each recursive step, so by definition we already have a handle on each subtrees'
// parents (it is the node that is passed into the previous recursive step).
// After we find the node to remove (if it is in the tree) everything else is the same, we  
// handle the three cases: leaf, one child (which consist of two cases: left vs right),
// and two children.  With iterative algorithm there were subcases regardling if the 
// node was root or not, with recursion we get that for free.  
//
// In dealing with a node with two children, we choose items from one of the appropriate 
// nodes in either subtree.  We then just want to write the subtree node's item into the 
// node to be deleted, this will result having two instances of the subtree value. So we 
// can recurse on that subtree and recursively call remove on that item (not the original) 
// to remove that redundant node.
// 
template<typename Item>
Node<Item>* BinarySearchTree<Item>::remove(Node<Item>* node, Item item) {

	if (node == nullptr)
		return node;

	if (item < node->item)
		node->left = remove(node->left, item);
	else if (item > node->item)
		node->right = remove(node->right, item);
	// Case 1 - Node is a leaf
	else if (node->left == nullptr && node->right == nullptr) {
		delete node;
		node = nullptr;
	}
	// Case 2 - Node has one child
	else if (node->left == nullptr) {
		Node<Item> *temp = node;
		node = node->right;
		delete temp;
		temp = nullptr;
	}
	// Case 3 - Node has two children
	else if (node->right == nullptr) {
		Node<Item> *temp = node;
		node = node->left;
		delete temp;
		temp = nullptr;
	}
	else {
		Node<Item> *temp = min(node->right);
		node->item = min(node->right)->item;
		node->right = nullptr;
		delete temp;
		temp = nullptr;

	}

	return node;
	
}

































































































































#endif//BINARYSEARCHTREE_H_MMXI
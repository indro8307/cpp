/*
 * BinaryTree.cpp

   Binary Tree and its functionalities

 */

#if 0
#include <iostream>

template<typename T>
class BTree
{
	class node
	{
		T val;
		node* left;
		node* right;
	};

	node* root;
	void _inorder(node*);
	void _preorder(node*);
	void _postorder(node*);
public:
	BTree(): root{nullptr} {}
	void print_inorder();
	void print_preorder();
	void print_postorder();
};

template <typename T>
void BTree<T>::_inorder(node *aroot)
{
	if(aroot != nullptr){
		_inorder(aroot->left);
		std::cout<<aroot->val<<" ";
		_inorder(aroot->right);
	}
}
template <typename T>
void BTree<T>::_preorder(node *aroot)
{
	if(aroot != nullptr){
		std::cout<<aroot->val<<" ";
		_preorder(aroot->left);
		_preorder(aroot->right);
	}
}
template <typename T>
void BTree<T>::_postorder(node *aroot)
{
	if(aroot != nullptr){
		_postorder(aroot->left);
		_postorder(aroot->right);
		std::cout<<aroot->val<<" ";
	}
}

template <typename T>
void BTree<T>::print_inorder()
{
	_inorder(root);
}
template <typename T>
void BTree<T>::print_preorder()
{
	_preorder(root);
}
template <typename T>
void BTree<T>::print_postorder()
{
	_postorder(root);
}

int main()
{
	BTree<int> btree;
	return 0;
}

#endif

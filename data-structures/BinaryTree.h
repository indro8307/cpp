/*
 * BinaryTree.h
 *
 *  Created on: 25-Sep-2020
 *      Author: indranil
 */

#ifndef DATA_STRUCTURES_BINARYTREE_H_
#define DATA_STRUCTURES_BINARYTREE_H_

#include <iostream>
#include <algorithm>
#include <queue>

template<typename T>
class BTree
{
	struct node
	{
		T val;
		node* left;
		node* right;
	};

	enum tree_side{
		left = 0,
		right = 1,
		centre = 3
	};

	node* root;
	void _inorder(node*);
	void _preorder(node*);
	void _postorder(node*);
	void _construct_btree(T iob[], T preo[], int &pindex, int ios, int ioe,
			node* root_node, tree_side s);
	void _printValuesAtLevel(node *sub_tree, int level);
public:
	BTree(): root{nullptr} {}
	void print_inorder();
	void print_preorder();
	void print_postorder();
	template<typename inorder, typename preorder>
	bool construct_btree(inorder io,preorder preo);
	int get_height();
	void printValuesAtLevel(int level);
};

template<typename T>
void BTree<T>::_printValuesAtLevel(node *sub_tree, int level)
{
	if(level<=0)
	{
		std::cout<<sub_tree->val<<" ";
		return;
	}
	if(sub_tree->left != nullptr)
		_printValuesAtLevel(sub_tree->left, level-1);
	if(sub_tree->right != nullptr)
	_printValuesAtLevel(sub_tree->right, level-1);
}
template<typename T>
void BTree<T>::printValuesAtLevel(int level)
{
	_printValuesAtLevel(root, level);
}

// To get the height traverse all the nodes of the B tree
// in Level order and add a null marker after every level
template<typename T>
int BTree<T>::get_height(){
	std::queue<node*> q;
	int level=0;
	if(root != nullptr)
	{
		q.push(root);
		q.push(nullptr);
		while(!q.empty())
		{
			node* temp = q.front();
			q.pop();
			if(temp->left != nullptr)
				q.push(temp->left);
			if(temp->right != nullptr)
				q.push(temp->right);
			if(q.front() == nullptr)
			{
				q.pop();
				if(!q.empty())
					q.push(nullptr);
				++level;
			}
		}
	}
	else
	{
		level = -1;
	}
	return level;
}


template<typename T>
void BTree<T>::_construct_btree(T iob[], T preo[], int &pindex, int ios, int ioe,
		node* root_node, tree_side s)
{
	if(ioe<ios) {--pindex; return;}
	int rootval = preo[pindex];
	node *a = new node;
	a->val = rootval;
	a->left = a->right = nullptr;
	if(root_node == nullptr)
		this->root = a;
	else{
		if(s==left)
			root_node->left = a;
		else if(s==right)
			root_node->right = a;
	}
	if(ios==ioe) return;

	//find rootval in the in-order list
	T *b = iob + ios;
	T *e = iob + ioe;
	T *l = std::find(b, e, rootval);
	// segregate the the left and the right subtree
	int left_ioe = (l-iob)-1;
	int left_ios = &iob[ios] - iob;
	int right_ios = (l+1) - iob;
	int right_ioe = &iob[ioe] - iob;
	_construct_btree(iob, preo, ++pindex, left_ios, left_ioe, a, left);
	_construct_btree(iob, preo, ++pindex, right_ios, right_ioe, a, right);

	return;
}

template<typename T>
 template<typename inorder, typename preorder>
bool BTree<T>::construct_btree(inorder io,preorder preo)
{
	//std::cout<<typeid(inorder).name();
	if(root != nullptr)
		return false;   // TODO: freeing of existing BTree nodes
	int pindex = 0;
	try{
	_construct_btree(io.data(),preo.data(),pindex,0,io.size()-1,nullptr,centre);
	}
	catch(...)
	{
		std::cout<<"caught exception here";
	}
	return true;
}

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




#endif /* DATA_STRUCTURES_BINARYTREE_H_ */

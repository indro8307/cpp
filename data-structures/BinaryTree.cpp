/*
 * BinaryTree.cpp

   Binary Tree and its functionalities

 */

#if 1
#include "BinaryTree.h"
#include <array>

int main()
{
	BTree<int> btree;
	std::array<int,8> io{40,20,50,10,30,80,70,90};
	std::array<int,8> preo{10,20,40,50,30,70,80,90};
	try{
	btree.construct_btree(io, preo);
	}
	catch(...)
	{
		std::cout<<"caught exception";
	}
	btree.print_preorder();
	std::cout<<std::endl;
	btree.print_inorder();
	std::cout<<std::endl;
	btree.print_postorder();
	std::cout<<std::endl;
	std::cout<<"height of binary tree = "<<btree.get_height()<<std::endl;
	std::cout<<"Values at level 3 = ";
	btree.printValuesAtLevel(3);
	std::cout<<std::endl;
	return 0;
}

#endif

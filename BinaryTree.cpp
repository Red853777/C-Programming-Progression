/*Title: Binary Tree
* 
* Purpose: To understand how binary trees work by creating three nodes using structures and connecting them with pointers. The program uses
*		   recursion to traverse the tree inorder sequence, printing the stored integers from smallest to largest.
* 
* Author: Nik Haas
*/
#include <stdio.h>

struct Tree		// This is the struct for the tree
{
	int data;		// This is for storing the numbers
	struct Tree* left;		// these are the directions saved within the tree in struct
	struct Tree* right;
};

void PrintTree(struct Tree* current);	// This declares PrintTree before main so the function can be called before its definition

int main()
{
	struct Tree root;	// These create three tree nodes that will be connected to form the binary tree
	struct Tree right;
	struct Tree left;
	
	root.data = 2;	// These assign an integer to each node before connecting them
	left.data = 1;
	right.data = 3;

	root.left = &left;		// These mark the end of each branch so traversal know where to stop
	root.right = &right;	
	left.left = NULL;		 
	left.right = NULL;		 
	right.left = NULL;
	right.right = NULL;

	printf("Binary Tree: "); // This prints out the, "Binary Tree", wording!
	PrintTree(&root);		// This prints out the numbers
	printf("\n");		// This creates the spacing between the very bottom and the numbers

	return 0;
}

void PrintTree(struct Tree* current)	// This 2nd function recieves the pointers from the Tree in the main
{
	if (current == NULL)	// This prevents the function from accessing a node that doesn't exist
	{
		return;
	}
	PrintTree(current->left);	// This calls the PrintTree and passes the address stored in the current node's left pointer

	printf("%d ", current->data);	// Prints the current node after exploring its left subtree
									 
	PrintTree(current->right);	// This call the PrintTree and passes the address stored in the current node's right pointer
}				
		// I've also learned that when you mess with the order of lines 42 - 46 that changes the order of which numbers get printed out first!
/*Title: Binary Tree File Reader
* 
* Purpose: Reads integers from a text file, stores them in a dynamically allocated array, and inserts them into a binary search tree.
*		   The program performs an inorder traversal to display the integers in ascending order.
* 
* Author: Nik Haas
*/
#include <stdio.h>
#include <stdlib.h>

struct Tree
{
	int data;
	struct Tree* left;
	struct Tree* right;
};

struct Tree* InsertNode(struct Tree* root, int value);
void PrintTree(struct Tree* current);
void FreeTree(struct Tree* root);

int main(void)
{
	FILE* ifp;
	int size;
	int* data;
	struct Tree* root = NULL;

	//Opens the input file so we can retrieve the integers
	fopen_s(&ifp, "C:\\Users\\nikha\\OneDrive\\Desktop\\TreeData.txt", "r");

	//Prevents the program from reading a file that failed to open
	if (ifp == NULL)
	{
		printf("Failed to open input file.\n");
		return 1;
	}

	//Ensures the file contains a valid integer for the array size
	if (fscanf_s(ifp, "%d", &size) != 1)
	{
		printf("Faild to read array size.\n");
		fclose(ifp);
		return 1;
	}

	//Prevents allocating memory for an invalid array size
	if (size <= 0)
	{
		printf("Invalid array size.\n");
		fclose(ifp);
		return 1;
	}

	data = malloc(size * sizeof(int));

	//Prevents accessing memory if allocation fails
	if (data == NULL)
	{
		printf("Memory allocation failed.\n");
		fclose(ifp);
		return 1;
	}

	//Reads each integer into the array before building the binary tree
	for (int i = 0; i < size; i++)
	{
		if (fscanf_s(ifp, "%d", &data[i]) != 1)
		{
			printf("Error reading integer from file.\n");
			free(data);
			fclose(ifp);
			return 1;
		}
	}

	//Closes the input file after all integers have been read
	fclose(ifp);

	//Inserts each array value into the binary search tree
	for (int i = 0; i < size; i++)
	{
		root = InsertNode(root, data[i]);
	}

	printf("Inorder Traversal: ");
	PrintTree(root);
	printf("\n");

	//Releases the dynamically allocated tree nodes
	FreeTree(root);

	//Releases the dynamically allocated tree nodes
	free(data);

	return 0;
}

struct Tree* InsertNode(struct Tree* root, int value)
{
	if (root == NULL)
	{
		struct Tree* newNode = malloc(sizeof(struct Tree));

		//Stops insertion if memory cannot be allocated for new node
		if (newNode == NULL)
		{
			printf("Memory allocation failed.\n");
			exit(EXIT_FAILURE);
		}

		newNode->data = value;
		newNode->left = NULL;
		newNode->right = NULL;

		return newNode;
	}

	//Places equal or larger values on the right side
	if (value < root->data)
	{
		root->left = InsertNode(root->left, value);
	}
	//Places equal or larger values on the right side
	else
	{
		root->right = InsertNode(root->right, value);
	}

	//Returns the root to preserve the tree connections
	return root;
}

void PrintTree(struct Tree* current)
{
	if (current == NULL)
	{
		return;
	}

	//Visits the left subtree before printing the current node
	PrintTree(current->left);

	printf("%d ", current->data);

	//Visits the right subtree to complete inorder traversal
	PrintTree(current->right);
}

void FreeTree(struct Tree* root)
{
	if (root == NULL)
	{
		return;
	}

	//Frees child nodes before freeing their parent
	FreeTree(root->left);
	FreeTree(root->right);

	//Release memory allocated for the current node
	free(root);
}
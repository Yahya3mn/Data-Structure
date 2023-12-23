#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>

struct node {
	int data;
	struct node* left, * right;
};


// Creating BST node
struct node* newNode(int data)
{
	struct node* p = (struct node*)malloc(sizeof(struct node));
	p->data = data;
	p->left = NULL;
	p->right = NULL;

	return p;
};


// Inserting value in BST
struct node* insertBST(struct node* root, int x)
{
	if (root != NULL)
	{
		if (x < root->data) {
			root->left = insertBST(root->left, x);
		}
		else if (x > root->data) {
			root->right = insertBST(root->right, x);
		}
	}
	else {
		root = newNode(x);
	}
	return root;
};

// Find BST size

int BSTsize(struct node* root)
{
	if (root == NULL) {
		return 0;
	}
	else {
		return BSTsize(root->left) + 1 + BSTsize(root->right);
	}
}

// Finding height of BST
int BSTheight(struct node* root)
{
	if (root == NULL)
		return -1;
	else {
		int l_height, r_height;
		l_height = BSTheight(root->left);
		r_height = BSTheight(root->right);

		if (r_height > l_height) {
			return r_height + 1;
		}
		else {
			return l_height + 1;
		}
	}
}

//Delete node function in BST

struct node* deleteBST(struct node* root, int x)
{
	struct node* p, * q;

	if (root == NULL)
		return NULL;
	if (root->data == x) {
		if (root->left == NULL) {
			p = root->right;
			free(root);
			return p;
		}
		else if (root->right == NULL) {
			p = root->left;
			free(root);
			return p;
		}
		else {
			p = q = root->right;

			while (p->left != NULL)
				p = p->left;
			p->left = root->left;
			free(root);
			return q;
		}
	}
	else if (x > root->data) {
		root->right = deleteBST(root->right, x);
	}
	else {
		root->left = deleteBST(root->left, x);
	}
	return root;
};


//Searching function in BST

struct node* searchTree(struct node* tree, int data)
{
	if (tree == NULL)
		return  NULL;
	else {
		if (tree->data == data) {
			return tree;
		}
		else if (tree->data > data) {
			searchTree(tree->left, data);
		}
		else {
			searchTree(tree->right, data);
		}
	}
};

// Finding Max value in BST

int maxValue(struct node* root)
{
	if (root == NULL)
		return 0;
	while (root->right != NULL) {
		root = root->right;
	}
	return root->data;
}


// Finding Min value in BST

int minValue(struct node* root)
{
	if (root == NULL)
		return 0;
	while (root->left != NULL) {
		root = root->left;
	}
	return root->data;
}

//Controlling whether is BST or not

bool isBST(struct node* root)
{
	if (root == NULL)
		return true;
	if (root->left != NULL && maxValue(root->left) > root->data)
		return false;
	if (root->right != NULL && minValue(root->right) <= root->data)
		return false;
	if (!isBST(root->left) || !isBST(root->right))
		return false;
	return true;
}


// Given BST comparing

int isSame(struct node* a, struct node* b)
{
	if (a == NULL && b == NULL)
		return  1;
	else if (a != NULL && b != NULL)
		return (a->data == b->data && isSame(a->left, b->left) && isSame(a->right, b->right));
	else
		return 0;
}

// Finding Path of BST

int path(struct node* root, int sum)
{
	int PathSum;

	if (root == NULL)
		return (sum == 0);
	else {
		PathSum = sum - root->data;
		return (path(root->left, PathSum) || path(root->right, PathSum));
	}
}

// Copying odd number to another BST

struct node* copyOdd(struct node* root, struct node *root2) {
	if (root != NULL) {
		if (root->data % 2 == 1)
			root2 = insertBST(root2, root->data);
		root2 = copyOdd(root->left, root2);
		root2 = copyOdd(root->right, root2);
	}
	return root2;
}

void inorder(struct node* root)
{
	if (root != NULL)
	{
		inorder(root->left);
		std::cout << root->data << " ";
		inorder(root->right);
	}
}
int main() {


	struct node* root = NULL;

	root = insertBST(root, 50);
	root = insertBST(root, 30);
	root = insertBST(root, 20);
	root = insertBST(root, 40);
	root = insertBST(root, 70);
	root = insertBST(root, 60);
	root = insertBST(root, 80);



	inorder(root);

	std::cout << "\n" << std::endl;
	BSTheight(root);
	maxValue(root);


	return 0;
}
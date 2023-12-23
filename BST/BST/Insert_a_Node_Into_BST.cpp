#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>

struct node {
	int data;
	struct node* left, * right;
};

struct node* newNode(int data) {

	struct node* p = (struct node*)malloc(sizeof(struct node));

	p->data = data;
	p->left = p->right = NULL;
	return p;
};

struct node* insert(struct node* root, int data)
{
	if (root == NULL)
		return newNode(data);
	if (data < root->data) {
		root->left = insert(root->left, data);
	}
	else if (data > root->data) {
		root->right = insert(root->right, data);
	}

	return root;

};

void inorder(struct node* root)
{
	if (root != NULL)
	{
		inorder(root->left);
		std::cout << root->data << " ";
		inorder(root->right);
	}
}
void preOrder(struct node* root)
{
	if (root != NULL) {
		std::cout << " " << root->data;
		preOrder(root->left);
		preOrder(root->right);
	}
}
void postOrder(struct node* root)
{
	if (root != NULL)
	{
		postOrder(root->left);
		postOrder(root->right);
		std::cout << " " << root->data;
	}
}
int main() {


	struct node* root = NULL;

	root = insert(root, 50);
	root = insert(root, 30);
	root = insert(root, 20);
	root = insert(root, 40);
	root = insert(root, 70);
	root = insert(root, 60);
	root = insert(root, 80);


	inorder(root);
	preOrder(root);
	postOrder(root);


	return 0;
}
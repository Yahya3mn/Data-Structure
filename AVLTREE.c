#include <stdio.h>
#include <stdlib.h>


typedef struct node{
	int data;
	int height;
	struct node *left;
	struct node *right;
}AVLTREE;

int max(int a, int b){
	return (a > b) ? a : b;
}

int height(AVLTREE *z){
	if(z == NULL){
		return -1;
	}
	else{
		int lHeight = height(z->left);
		int rHeight = height(z->right);
		return 1 + max(lHeight, rHeight);
	}
}


AVLTREE *new_Node(int data)
{
	AVLTREE *node = (AVLTREE *)malloc(sizeof(AVLTREE));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	node->height = 0;
	return node;
}

AVLTREE *rightRotate(AVLTREE *z){
	AVLTREE *temp = z->left;
	z->left = temp->right;
	temp->right = z;
	
	z->height = max(height(z->left), height(z->right)) + 1;
	temp->height = max(height(temp->left), height(temp->right)) + 1;
	return temp;
}

AVLTREE *leftRotate(AVLTREE *z){
	AVLTREE *temp = z->right;
	z->right = temp->left;
	temp->left = z;
	
	z->height = max(height(z->left), height(z->right)) + 1;
	temp->height = max(height(temp->left), height(temp->right)) + 1;
	return temp;
}

AVLTREE *leftRightRotate(AVLTREE *z)
{
	z->left = leftRotate(z->left);
	return rightRotate(z);
}

AVLTREE *rightLeftRotate(AVLTREE *z)
{
	z->right = rightRotate(z->right);
	return leftRotate(z);
}

void inOrder(AVLTREE *root){
	if(root != NULL){
		inOrder(root->left);
		printf("%d ",root->data);
		inOrder(root->right);
	}
}

AVLTREE *insertToAVL(AVLTREE *tree, int x)
{
	if(tree != NULL){
		if(x < tree->data)
			tree->left = insertToAVL(tree->left, x);
		else if(x > tree->data)
			tree->right = insertToAVL(tree->right, x);
		else
			return tree;
		
		tree->height = 1 + max(height(tree->left), height(tree->right));
		
		int balance = height(tree->left) - height(tree->right);
		
		if(balance > 1 && x < tree->left->data)
			return rightRotate(tree);
		
		if(balance > 1 && x > tree->left->data)
			return leftRightRotate(tree);
			
		if(balance < -1 && x > tree->right->data)
			return leftRotate(tree);
		
		if(balance < -1 && x < tree->right->data)
			return rightLeftRotate(tree);
	}
	else{
		tree = new_Node(x);
	}
	return tree;
}

int getBalance(AVLTREE *origin)
{
	if(origin == NULL){
		return 0;
	}
	return height(origin->left) - height(origin->right);
}

AVLTREE *minValue(AVLTREE *root)
{
	if(root == NULL){
		return NULL;
	}
	while(root->left != NULL){
		root = root->left;
	}
	return root;
}

AVLTREE *deleteNode(AVLTREE *root, int key)
{
	if(root == NULL){
		return root;
	}
	
	if(key < root->data){
		root->left = deleteNode(root->left, key);
	}
	else if(key < root->data){
		root->right = deleteNode(root->right, key);
	}
	else{
		if(root->left == NULL || root->right == NULL){
			AVLTREE *temp = root->left ? root->left : root->right;
			
			if(temp == NULL){
				temp = root;
				root = NULL;
			}else{
				*root = *temp;
			}
			free(temp);
		}else{
			AVLTREE *temp = minValue(root->right);
			root->data = temp->data;
			root->right = deleteNode(root->right, temp->data);
		}
	}
	if(root == NULL){
		return root;
	}
	
	root->height = max(height(root->left), height(root->right)) + 1;
	
	if(getBalance(root) > 1 && getBalance(root->left) >= 0){
		return rightRotate(root);
	}
	
	if(getBalance(root) > 1 && getBalance(root->left) < 0){
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}
	
	if(getBalance(root) < -1 && getBalance(root->right) <= 0){
		return leftRotate(root);
	}
	
	if(getBalance(root) < -1 && getBalance(root->right) > 0){
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}
	return root;
}


int main(int argc, char *argv[]) {
	AVLTREE *myroot = NULL;
	int i;
	
	printf("Enter value : \n");
	scanf("%d", &i);
	
	while(i != -1){
		myroot = insertToAVL(myroot,i);
		scanf("%d", &i);
	}
	
	printf("In-order tree : ");
	inOrder(myroot);
	printf("\nHeight : %d\n", myroot->height);
	
	
	int key;
	printf("\nEnter a key :");
	scanf("%d", &key);
	myroot = deleteNode(myroot, key);
	
	printf("\n Deletion: ");
	inOrder(myroot);
	printf("\n");
	return 0;
}

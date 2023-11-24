#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node *BTREE;

BTREE insert(BTREE root, int x){
    
    BTREE new = malloc(sizeof(BTREE));
    
    if(root==NULL){
        new->data = x;
        new->left = new->right = NULL;
        return new;
    }
    if(root->data < x){
        root->right = insert(root->right, x);
        return root;
    }
    else{
        root->left = insert(root->left, x);
        return root;
    }
}


int traverse(BTREE root){
    if(root == NULL)
        return 0;
    printf("%d\t",root->data);
    traverse(root->left);
    traverse(root->right);
}

int size(BTREE root){
    if(root==NULL)
        return 0;
    return size(root->left) + 1 + size(root->right);
}

int countParents(BTREE root){
    int parent_say = 0;
    if(root == NULL)
        return 0;
    if(root->left != NULL || root->right != NULL)
        parent_say++;
    parent_say += countParents(root->left);
    parent_say += countParents(root->right);
    return parent_say;
}

int ara(BTREE root,int aranan){
    if(root == NULL)
        return -1;
    if(root->data == aranan)
        return 1;
    if(ara(root->right,aranan) == 1)
        return 1;
    if(ara(root->left,aranan) == 1)
        return 1;
    return -1;
}

int main()
{
    BTREE myroot = NULL;
    myroot = insert(myroot, 25);
    
    myroot=insert(myroot,5);
    myroot=insert(myroot,23);
    myroot=insert(myroot,18);
    myroot=insert(myroot,45);
    myroot=insert(myroot,63);
    myroot=insert(myroot,31);
    
    traverse(myroot);
    printf("\nagactaki dugumlerin sayisi = %d",size(myroot));
    
    int parent = countParents(myroot);
    printf("\nagactaki parentlerin sayisi = %d",parent);
    printf("\narama fonk dönen sonuc = %d",ara(myroot,25));

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *left;
    struct node *right;
    int data;
};

typedef struct node *BTREE;

BTREE new_node(int c) {
    BTREE p = (BTREE)malloc(sizeof(struct node));
    p->data = c;
    p->left = NULL;
    p->right = NULL;

    return p;
}

BTREE insert_BST(BTREE root, int x) {
    if (root != NULL) {
        if (x < root->data) {
            root->left = insert_BST(root->left, x);
        } else {
            root->right = insert_BST(root->right, x);
        }
    } else {
        root = new_node(x);
    }
    return root;
}

int size(BTREE root) {
    if (root == NULL) {
        return 0;
    } else {
        return size(root->left) + 1 + size(root->right);
    }
}

int height(BTREE root) {
    if (root == NULL)
        return -1;
    else {
        int left_height, right_height;
        left_height = height(root->left);
        right_height = height(root->right);

        if (right_height > left_height)
            return right_height + 1;
        else
            return left_height + 1;
    }
}

BTREE delete_node(BTREE root, int x) {
    BTREE p, q;

    if (root == NULL)
        return NULL;
    if (root->data == x) {
        if (root->left == NULL) {
            p = root->right;
            free(root);
            return p;
        } else if (root->right == NULL) {
            p = root->left;
            free(root);
            return p;
        } else {
            p = q = root->right;

            while (p->left != NULL)
                p = p->left;
            p->left = root->left;
            free(root);
            return q;
        }
    } else if (x > root->data) {
        root->right = delete_node(root->right, x);
    } else {
        root->left = delete_node(root->left, x);
    }
    return root;
}

int main() {
    BTREE root = NULL;

    root = insert_BST(root, 50);
    insert_BST(root, 30);
    insert_BST(root, 20);
    insert_BST(root, 40);
    insert_BST(root, 70);
    insert_BST(root, 60);
    insert_BST(root, 80);

   

    return 0;
}

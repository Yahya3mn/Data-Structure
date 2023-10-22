#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *addfront(struct node*head, int x)
{
    if(head == NULL){
        head->data = x;
        head->next = NULL;
        head->prev = NULL;
    }
    else{
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->data = x;
        temp->next = head;
        temp->prev = NULL;
        head->prev = temp;
        head = temp;
    }
};

/*************************Adding End of Node************************************************************/

struct node *addlast(struct node *head, int x)
{
    if(head == NULL){
        head->data = x;
        head->next = NULL;
        head->prev = NULL;
    }
    else{
        struct node *temp = head;
        struct node *temp2 = (struct node *)malloc(sizeof(struct node));

        temp2->data = x;
        temp2->next = NULL;
        temp2->prev = temp;
        temp->next = temp2;
    }
};

/***************************Adding Between Nodes***********************************************************/

void addthen(struct node *other_node, struct node *list, int n)
{
    struct node *temp = list;
    int i = 1;

    while (i < n)
    {
        list = list->next;
        i++;
    }

    other_node->prev = list;
    other_node->next = list->next;

    if (list->next != NULL)
    {
        list->next->prev = other_node;
    }

    list->next = other_node;
    list = temp;
}

/********************************Deleting a node with a given key********************************************/

struct node *deleted(struct node *head, int x)
{
    struct node *temp = head;

    while (temp != NULL && temp->data != x)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        // Node not found, do nothing
        return head;
    }

    if (temp->prev != NULL)
    {
        temp->prev->next = temp->next;
    }

    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }

    if (temp == head)
    {
        head = head->next;
    }

    free(temp);
    return head;
};

/********************************************************************************************************/

void printList(struct node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}



int main()
{

    struct node *head = NULL;
    head = addfront(head, 2);
    head = addfront(head, 1);
    head = addlast(head, 3);

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = 4;
    addthen(newNode, head, 2);
    head = deleted(head,2);
    printList(head);

    /**Free Memory**/

    while(head != NULL){
        struct node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *addfront(struct node *head,int x)
{
    if(head == NULL){
        head->data = x;
        head->next = head;
    }
    else{
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        struct node *last = head;

        temp->data = x;
        while(last->next != head)
            last = last->next;
        temp->next = head;
        last->next = temp;
        head = temp;
    }
}

struct node *addlast(struct node *head, int x)
{
    if(head == NULL){
        head->data = x;
        head->next = head;
    }

    else{
        struct node *last = head;
        while(last->next != head)
            last = last->next;

        last->next = (struct node *)malloc(sizeof(struct node));
        last->next->next = head;
        last->next->data = x;
    }
};

void concatenate(struct node *list_1, struct node *list_2)
{
    if(list_1 == NULL)
        list_1 = list_2;

    else{
        struct node *last = list_1;
        while(last->next != list_1)
            last = last->next;
        last->next = list_2;

        last = list_2;
        while(last->next != list_2)
            last = last->next;
        last->next = list_2;
    }
}

struct node *deletenode(struct node *head,int x)
{
    if(head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct node *temp = head;

    if(head->data == x){
        struct node *last = head;
        while(last->next != head)
            last = last->next;
        head = head->next;
        last->next = head;
        free(temp);
    }
    else if(temp->next == NULL){
        printf("there is no data you wish to delete.\n\n");
    }
    else{
        while(temp->next->data == NULL){
            if(temp->next->next == NULL){
                printf("there is no data you wish to delete.\n\n");
                return head;
            }
            temp = temp->next;
        }

        struct node *temp2 = temp->next;
        temp->next = temp->next->next;
        free(temp2);
    }
    return head;
};


void printCircularLinkedList(struct node* head) {
    if (head == NULL) {
        printf("liste is empty.\n");
        return;
    }

    struct node *temp = head;

    /**treversal**/
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("\n");
}

int main()
{
     struct node* head = NULL;


    head = addfront(head,1);
    head->next = addfront(head,2);
    head->next->next = addfront(head,3);


    printf("Circular Linked List: ");
    printCircularLinkedList(head);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    int employeeNo;
    char name[20];
    struct node *next;
    struct node *prev;
};

void insertSorted(struct node **head, int employeeNo, const char *name){
    
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    
    newNode->employeeNo = employeeNo;
    strncpy(newNode->name, name, sizeof(newNode->name) - 1);
    newNode->name[sizeof(newNode->name) -1] = '\0';
    newNode->next = NULL;
    newNode->prev = NULL;
    
    if(*head == NULL){
        *head = newNode;
        return;
    }
    
    struct node *simdiki = *head;
    
    while(simdiki != NULL && simdiki->employeeNo < employeeNo){
        simdiki = simdiki->next;
    }
    
    if(simdiki == *head){
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
    else{
        newNode->next = simdiki;
        newNode->prev = simdiki->prev;
        simdiki->prev->next = newNode;
        simdiki->prev = newNode;
    }
}

void printList(struct node *head){
    struct node *simdiki = head;
    while(simdiki!=NULL){
        printf("EmployeeNO: %d, Name: %s\n", simdiki->employeeNo, simdiki->name);
        simdiki = simdiki->next;
    }
}

void freeList(struct node *head){
    struct node *simdiki = head;
    while(simdiki != NULL){
        struct node *nextNode = simdiki->next;
        free(simdiki);
        simdiki = nextNode;
    }
}

int main(){
    struct node *head = NULL;
    
    insertSorted(&head, 102, "John Doe");
    insertSorted(&head, 105, "Alice Smith");
    insertSorted(&head, 101, "Bob Johnson");
    insertSorted(&head, 104, "Eve Brown");
    
     printList(head);
     
     
    
    
    
    return 0;
}
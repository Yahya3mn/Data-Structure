#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 10

struct node
{
    int data;
    struct node *next;
};
typedef struct
{
    struct node *top;
    int cnt;
}stack;

void initialize(stack *stk)
{
    stk->cnt = 0;
    stk->top = NULL;
}

void push(stack *stk, int c)
{
    if(stk->cnt == STACK_SIZE)
        printf("\nStack is full\n");
    else{
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->data = c;
        temp->next = stk->top;
        stk->top = temp;
        stk->cnt++;
    }
}

int pop(stack *stk)
{
    if(stk->cnt == 0){
        printf("Stack is empty");
        return -100;
    }
    else{
        int x = stk->top->data;
        struct node *temp = stk->top;
        stk->top = stk->top->next;
        free(temp);
        stk->cnt--;
        return x;
    }
}



int main()
{
    stack n;
    initialize(&n);
    push(&n,4);
    push(&n,14);
    push(&n,41);
    push(&n,6);

    printf("\n%d",pop(&n));
    printf("\n%d",pop(&n));
    printf("\n%d",pop(&n));
    printf("\n%d",pop(&n));


    return 0;
}

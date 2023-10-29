#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 20

typedef struct
{
    int top;
    int data[STACK_SIZE];
}stack;

void reset(stack *stk)
{
    stk->top = -1;
}

void push(stack *stk, int c)
{
    if(stk->top == STACK_SIZE - 1){
        printf("\nStack is full");
        return -100;
    }
    else{
        stk->data[++stk->top] = c;
    }
}

int pop(stack *stk)
{
    if(stk->top == -1){
        printf("\nStack is empty");
        return -100;
    }
    else{
        return stk->data[stk->top--];
    }
}
int main()
{
    int x;
    stack n;

    reset(&n);

    push(&n,3);
    push(&n,2);
    x = pop(&n) * pop(&n);
    push(&n,x);
    push(&n,5);
    push(&n,6);
    x = pop(&n) * pop(&n);
    push(&n,x);

    x = pop(&n) + pop(&n);
    push(&n,x);

    printf("Result = %d", x);
    return 0;
}

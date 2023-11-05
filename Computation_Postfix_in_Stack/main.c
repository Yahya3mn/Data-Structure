#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define STACK_SIZE 20

typedef struct
{
    int data[STACK_SIZE];
    int top;
} stack;

void initialize(stack *stk)
{
    stk->top = -1;
}

void push(stack *stk, int x)
{
    if (stk->top == STACK_SIZE - 1)
    {
        printf("Stack is full\n");
    }
    else
    {
        stk->data[++stk->top] = x;
    }
}

int pop(stack *stk)
{
    if (stk->top == -1)
    {
        printf("Stack is empty\n");
        return -100;
    }
    else
    {
        return stk->data[stk->top--];
    }
}

int main()
{
    char exp[20];
    char *e;
    stack s;
    initialize(&s);

    int n1, n2, n3, number;

    printf("Enter the expression: ");
    scanf("%s", exp);

    e = exp;

    while (*e != '\0')
    {
        if (isdigit(*e))
        {
            number = *e - '0'; // Convert char digit to integer
            push(&s, number);
        }
        else
        {
            n2 = pop(&s);
            n1 = pop(&s);
            switch (*e)
            {
            case '+':
                n3 = n1 + n2;
                break;
            case '-':
                n3 = n1 - n2;
                break;
            case '*':
                n3 = n1 * n2;
                break;
            case '/':
                n3 = n1 / n2;
                break;
            }
            push(&s, n3);
        }
        e++;
    }
    printf("\nThe result of expression %s = %d\n\n", exp, pop(&s));

    return 0;
}

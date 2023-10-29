#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 20

typedef struct
{
   char data[STACK_SIZE];
   char top;
}stack;

void reset(stack *stk)
{
    stk->top = -1;
}

void push(stack *stk, char c)
{
    if(stk->top != STACK_SIZE - 1)
    {
        stk->top++;
        stk->data[stk->top] = c;
    }
    else{
        printf("\nStack is full");
    }
}

char pop(stack *stk)
{
    if(stk->top != -1)
        return stk->data[stk->top--];
        printf("\Stack is empty");
        return 0;
}


int main()
{
    char key;
    stack n;

    reset(&n);

    FILE *fptr;
    if((fptr=fopen("code.txt","r")) == NULL){
        printf("There is no file here !");
    }
    else{
        while(!feof(fptr)){
            key = getc(fptr);
            switch(key)
            {
            case '(':
                push(&n,key);
                break;
            case ')':
                if(pop(&n) == '(')
                    continue;
                else{
                    printf("\nError for () !\n");
                    exit(1);
                }
                break;
            case '{':
                push(&n,key);
                break;
            case '}':
                if(pop(&n) == '{')
                    continue;
                else{
                    printf("\nError for {} !\n");
                    exit(1);
                }
                break;
            case '[':
                push(&n,key);
                break;
            case ']':
                if(pop(&n) == '[')
                    continue;
                else{
                    printf("\nError for [] !\n");
                    exit(1);
                }
                break;
            default:
                break;
            }
        }
    }

    if(n.top == -1)
        printf("no error in code");
    else
        printf("Error there is at least one openning paranthesis which is not closed");
    fclose(fptr);
    return 0;
}

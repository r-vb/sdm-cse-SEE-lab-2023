/* 6. */

#include <stdio.h>

#define SIZE 20

struct stack
{
    int top;
    char arr[SIZE];
};

void push(struct stack *s, char str)
{
    if (s->top == SIZE-1)
        printf("Stack Overflow\n");
    else
        s->arr[++s->top] = str;    
}

char pop(struct  stack *s)
{
        char ch;
    if (s->top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else{
        ch = s->arr[s->top--];
        return ch;
    }
}

int isEmpty(struct stack *s)
{
    if ( s->top == -1 )
        return -1;
    else
        return 0;
}

int check(struct stack *s, char str[])
{
        int i, j;
    for ( i = 0; str[i] != 'C'; i++ )
    {
        if ( str[i]=='A' || str[i]=='a' || str[i]=='B' || str[i]=='b' )
        {
            push(s,str[i]);
        }
        else{
            return 0;
        }   
    }
    for ( j = i+1; str[j] != '\0'; j++ )
    {
        if ( str[j] == pop(s) )
            continue;
        else
            return 0;
    }

    if ( isEmpty(s) )
        return 1;
    else
        return 0;
}

int main()
{
        struct stack s;
        char str[SIZE];
        s.top = -1;
    printf("Enter the string: ");
    scanf("%s",str);

    int X = check(&s,str);

    if (X == 1)
        printf("%s is of the form xCy\n");
    else
        printf("%s is not of the form xCy\n");
return 0;
}
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MAX 100
char stack[MAX];
int top=-1;
void push(char ch)
{
    stack[++top]=ch;
}
char pop()
{
    return stack[top--];
}
int precedence(char ch)
{
    if (ch=='*'||ch=='/')
        return 2;
    if (ch=='+'||ch=='-')
        return 1;
    return 0;
}
int main()
{
    char infix[MAX],postfix[MAX];
    int i,j=0;
    char ch;
    printf("enter the exp:");
    scanf("%s",infix);
    for(i=0;i<strlen(infix);i++)
    {
        ch=infix[i];
        if(isalnum(ch))
        {
            postfix[j++]=ch;
        }
        else
    }
}

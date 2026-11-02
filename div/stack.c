#include<stdio.h>
int stack[50];
int top=-1;
int max=5;
void push()
{
    int value;
    if (top==max-1)
    {
        printf("stack overflow\n");
    }
    else{
        printf("enter the value:");
        scanf("%d",&value);
        top++;
        stack[top]=value;
        printf("elements pushed successfully\n");
    }
}
void pop()
{
    if(top==-1)
    {
        printf("stack underflow\n");
    }
    else
    {
        printf("the popped element:%d\n",stack[top]);
        top--;
    }
}
void display()
{
    int i;
    if (top==-1)
    {
        printf("stack is empty\n");
    }
    else
    {
        printf("stack elements:\n");
        for(i=top;i>=0;i--)
        {
            printf("%d\n",stack[i]);
        }
    }
}
int main()
{
    int choice;
    while(1)
    {
        printf("\n1.Push\n");
        printf("2.Pop\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        printf("enter your choice:");
        scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        push();
        break;
    case 2:
        pop();
        break;
    case 3:
        display();
        break;
    case 4:
        return 0;
    default:
        printf("invalid choice\n");
    }
    }
}

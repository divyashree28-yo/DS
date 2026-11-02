#include<stdio.h>
int main()
{
    int max_size=10;
    int queue[max_size];
    int front=-1;
    int rear=-1;
    int choice,value,item;
    while(1)
    {
         printf("linear queue\n");
         printf("1.insert\n");
         printf("2.delete\n");
         printf("3.display\n");
         printf("4.exit\n");
         printf("enter your choice");
         scanf("%d",&choice);
         switch(choice)
         {
         case 1:
            printf("enter the value");
            scanf("%d",&value);
            if(rear==max_size-1)
            {
                printf("queue overflow\n");
                break;
            }
            if(front==-1)
                    front=0;
            rear=rear+1;
            queue[rear]=value;
            break;
         case 2:
            if(front==-1 || front>rear)
            {
                printf("queue is empty\n");
                break;
            }
            item=queue[front];
            front=front+1;
            if(front>rear)
            {
                front=-1;
                rear=-1;
            }
            printf("the deleted item is %d\n",item);
            break;
         case 3:
            if(front==-1 || front>rear)
            {
                printf("queue is empty\n");
                break;
            }
            printf("the queue elements are:\n");
            for(int i=front;i<=rear;i++)
                printf("%d\n",queue[i]);
            break;
         case 4:
            return 0;
            break;
         default:
            printf("invalid choice");
         }
    }
}






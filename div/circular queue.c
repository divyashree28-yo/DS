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
         printf("Circular queue\n");
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
            if(front==0&&rear==max_size-1||(rear+1)%max_size==front)
            {
                printf("queue overflow\n");
                break;
            }
            if(front==-1)
            {
                 front=0;
                 rear=0;
            }
            else
                    rear=(rear+1)%max_size;
            queue[rear]=value;
            break;
         case 2:
            if(front==-1)
            {
                printf("queue is empty\n");
                break;
            }
            item=queue[front];
            printf("the deleted item is %d\n",item);
            if(front==rear)
            {
                front=-1;
                rear=-1;
            }
            else
                    front=(front+1)%max_size;
            break;
         case 3:
            if(front==-1)
            {
                printf("queue is empty\n");
                break;
            }
            int i=front;
            printf("the queue elements are:\n");
            while(1)
            {
                printf("%d\n",queue[i]);
                if(i==rear)
                    break;
                i=(i+1)%max_size;
            }
            break;
         case 4:
            return 0;
            break;
         default:
            printf("invalid choice");
         }
    }
}






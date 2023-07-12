#include <stdio.h>
#include <stdlib.h>
#define capacity 20
void insert();
void delete();
void display();
int queue_array[capacity],rear=-1,front=-1;
void main()
{
    int choice;
    while(1)
    {
        printf("\n1.Enter 1 to insert an element in queue\n");
        printf("2.enter 2 to delete an element from the queue\n");
        printf("3.enter 3 to diplay all elements from the queue\n");
        printf("4.enter 4 to quit\n");
        printf("\nenter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: insert();
                break;
            case 2: delete();
                break;
            case 3: display();
                break;
            case 4: return;
                break;
            default :printf("wrong choice\n");
        }
    }
}
void insert()
{
    int element;
    if(rear==capacity-1)
    {
        printf("queue is full\n");
    }
    else
    {
        if(front==-1)
        {
            front=0;
        }
        printf("enter the elements to be inserted\n");
        scanf("%d",&element);
        rear=rear+1;
        queue_array[rear]=element;
    }
}
void delete()
{
    if(front==-1||front>rear)
    {
        printf("queue is empty we cannot delete any elements\n");
        return;
    }
    else
    {
        printf("element deleted from the queue is %d\n",queue_array[front]);
        front=front+1;
    }
}
void display()
{
    int i;
    if(front==-1||front>rear)
    {
        printf("queue is empty\n");
    }
    else
    {
        printf("elements of the queue are:\n");
        for(i=front;i<=rear;i++)
        {
            printf("%d",queue_array[i]);
            printf("\t");
        }
        printf("\n*****************\n");
        printf("Categorization of data\n");
        printf("*****************\n");
        printf("group 1: less than 10\n");
        for(i=front;i<=rear;i++)
        {
            if(queue_array[i]<10)
            {
                printf("%d",queue_array[i]);
                printf("\t");
            }
        }
        printf("\ngroup 2: between 10 and 19\n");
        for(i=front;i<=rear;i++)
        {
            if(queue_array[i]>=10&&queue_array[i]<=19)
            {
                printf("%d",queue_array[i]); 
                printf("\t");
            }
        }
        printf("\ngroup 3: between 20 and 29\n");
        {
            if(queue_array[i]>=20&&queue_array[i]<=29)
            {
                printf("%d",queue_array[i]);
                printf("\t");
            }
        }
        printf("\ngroup 4: 30 and greater\n");
        for(i=front;i<=rear;i++)
        {
            if(queue_array[i]>=30)
            {
                printf("%d",queue_array[i]);
                printf("\t");
            }
        }
    }
printf("\n"); 
}

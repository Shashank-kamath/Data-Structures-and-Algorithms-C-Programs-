#include <stdio.h>
#include <stdlib.h>
int count;
struct node
{
    float m1, m2, m3;
    char u[10], n[20], d[20], p[15];
    struct node *llink;
    struct node *rlink;
};
typedef struct node *NODE;
NODE first = NULL;
NODE getnode()
{
    NODE x;
    x = ((NODE)malloc(sizeof(struct node)));
    return x;
}
NODE createnode()
{
    NODE temp;
    temp = getnode();
    printf("enter student detail\n");
    printf("enter USN"); 
    scanf("%s", temp->u);
    printf("enter name:\n");
    scanf("%s", temp->n);
    printf("enter department:\n");
    scanf("%s", temp->d);
    printf("enter marks1:\n");
    scanf("%f", &(temp->m1));
    printf("enter marks 2:\n");
    scanf("%f", &(temp->m2));
    printf("enter the marks 3:\n");
    scanf("%f", &(temp->m3));
    printf("enter mobile number\n");
    scanf("%s", temp->p);
    temp->llink = NULL;
    temp->rlink = NULL;
    count++;
    return temp;
}
void disp_deleted(NODE temp)
{
    printf("the following student details is deleted\n");
    printf("USN|Name|Dept|marks1|Marks2|Marks3|ph.no|\n");
    printf("--------------------------------------------\n");
    printf("%s|%s|%s|%2f|%2f|%2f|%s\n", temp->u, temp->n, temp->d, temp->m1, temp->m2, temp->m3, temp->p);
    count--;
}
void insert_front()
{
    NODE temp;
    temp = createnode();
    if (first == NULL)
    {
        first = temp;
    }
    else
    {
        temp->rlink = first;
        first->llink = temp;
        first = temp;
    }
}
void delete_front()
{
    NODE temp;
    if (first == NULL)
    {
        printf("List is empty\n");
    }
    else if (first->rlink == NULL)
    {
        disp_deleted(first);
        free(first);
        first = NULL;
    }
    else
    {
        temp = first;
        disp_deleted(temp);
        first = first->rlink;
        first->llink = NULL;
        temp->rlink = NULL;
        free(temp);
        temp = NULL;
    }
}
void insert_rear()
{
    NODE temp, cur;
    temp = createnode();
    if (first == NULL)
    {
        first = temp;
    }
    else
    {
        cur = first;
        while (cur->rlink != NULL)
        {
            cur = cur->rlink;
        }
        cur->rlink = temp;
        temp->llink = cur;
    }
}
void delete_rear()
{
    NODE cur;
    if (first == NULL)
    {
        printf("List is empty");
    }
    else if (first->rlink == NULL)
    {
        disp_deleted(first);
        free(first);
        first = NULL;
    }
    else
    {
        cur = first;
        while (cur->rlink != NULL)
        {
            cur = cur->rlink;
        }
        disp_deleted(cur);
        cur->llink->rlink = NULL;
        free(cur);
        cur = NULL;
    }
}
void display()
{
    NODE cur;
    float total, average;
    if (first == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        cur = first;
        printf("the student details is doubly linked list from beginning :\n");
        printf("USN|Name|Dept|Marks1|Marks2|Marks3|Total marks|Average|ph.no\n");
        printf("-----------------------------\n");
        while (cur != NULL)
        {
            total = cur->m1 + cur->m2 + cur->m3;
            average = total / 3;
            printf("%s|%s|%s|%2f|%2f|%2f|%2f|%2f|%s", cur->u, cur->n, cur->d, cur->m1, cur->m2, cur->m3, total, average, cur->p);
            cur = cur->rlink;
        }
        printf("-----------------------------\n");
        printf("No. of nodes=%d\n", count);
    }
}

void main()
{
    int choice, i, n;
    while (1)
    {
        choice = 0;
        printf("------------MENU--------------\n");
        printf("1.CREATE A DLL OF N STUDENTS BY USING END INSERTION\n");
        printf("2.DISPLAY STATUS AND COUNT OF NODES \n");
        printf("3.INSERTION AT REAR\n");
        printf("4.DELETION AT REAR\n");
        printf("5.INSERTION AT FRONT\n");
        printf("6.DELETION AT FRONT\n");
        printf("7.EXIT\n");
        printf("-----------------------------\n");
        printf("enter your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter number of students :\n");
            scanf("%d", &n);
            for (i = 0; i < n; i++)
            {
                insert_rear();
            }
            break;
        case 2:
            display();
            break;
        case 3:
            insert_rear();
            break;
        case 4:
            delete_rear();
            break;
        case 5:
            insert_front();
            break;
        case 6:
            delete_front();
            break;
        case 7:
            return;
        default:
            printf("invalid choice\n");
            return;
        }
    }
}

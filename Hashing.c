#include<stdio.h>
#include<stdlib.h>
int key,m,n,*ht,hi,elec;
void createhashtable()
{
    int i;
    ht=(int*)malloc(m*sizeof(int));
    if(m==0)
    {
        printf("Unable to create Hash Table");
        exit(0);
    }
    else
    {
        for(i=0;i<m;i++)
        {
            ht[i]=0;
        }
    }
}
void inserthashtable(int key)
{
    hi=key%m;
    while(ht[hi]!=0)
    {
        hi=(hi+1)%m;
        printf("Collision Detected! It is avoided by Linear Probing!\n");
    }
    ht[hi]=key;
    elec++;
}
void displayhashtable()
{
    int i;
    if(elec==0)
    {
        printf("Hash Table is empty!\n");
        return;
    }
    printf("Hash Table contents are:\n");
    for(i=0;i<m;i++)
    {
        printf("[%d]---------> %d\n",i,ht[i]);
    }
}
void main()
{
    int i;
    printf("Enter the number of Employee Records:\n");
    scanf("%d",&n);
    printf("Enter the 2 digit memory location:\n");
    scanf("%d",&m);
    createhashtable();
    printf("Enter the 4 digit Key Values of Employee Records:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&key);
        if(elec==m)
        {
            printf("Hash Table is full!\n");
            break;
        }
        inserthashtable(key);
    }
    displayhashtable();
}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
           char name[25],phno[15];
           struct node *leftchild;
           struct node *rightchild;
           };
typedef struct node*NODE;
int delflag;
NODE createnode()
{
    NODE temp;
    temp=(NODE)malloc(sizeof(struct node));
    printf("\nenter the name\n");
    scanf("%s",temp->name);
    printf("enter the phno.\n");
    scanf("%s",temp->phno);
    temp->leftchild=NULL;
    temp->rightchild=NULL;
    return temp;
}
void insertBST(NODE root, NODE newNode)
{
    if(strcmp(newNode->name,root->name)==0)
    {
        printf("Key already exists\n");
        return;
    }
    else if(strcmp(newNode->name,root->name)<0)
    {
        if(root->leftchild==NULL)
        {
            root->leftchild=newNode;
        }
        else
        {
            insertBST(root->leftchild, newNode);
        }
    }
        else
        {
            if(root->rightchild==NULL)
            {
                root->rightchild=newNode;
            }
            else
            {
                insertBST(root->rightchild, newNode);
            }
    }
}
int search(NODE root, char keyname[])
{
    if (!root)
    {
        return -1;
    }
    if(strcmp(keyname, root->name)==0)
    {
        return 1;
    }
    else if(strcmp(keyname, root->name)<0)
    {
        return search(root->leftchild, keyname);
    }
    else
    {
        return search(root->rightchild, keyname);
    }
}
NODE getRightMin(NODE root)
{
        NODE temp=root;
        while (temp->leftchild!=NULL)
        {
            temp=temp->leftchild;
        }
        return temp;
}
NODE deleteBST(NODE root, char keyname[])
{
    if(!root)
    {
        delflag=-1;
        return NULL;
    }
    if(strcmp(keyname,root->name)<0)
    {
        root->leftchild=deleteBST(root->leftchild, keyname);
    }
    else if(strcmp(keyname,root->name)>0)
    {
        root->rightchild=deleteBST(root->rightchild, keyname);
    }
    else
    {
        if(root->leftchild==NULL&&root->rightchild==NULL)
        {
            free(root);
            return NULL;
        }
        else if (root->leftchild==NULL)
        {
            NODE temp=root->rightchild;
            free(root);
            return temp;
        }
        else if (root->rightchild==NULL)
        {
            NODE temp=root->leftchild;
            free(root);
            return temp;
        }
        else
        {
            NODE RightMin= getRightMin(root->rightchild);
            strcpy(root->name,RightMin->name);
            strcpy(root->phno, RightMin->phno);
            root->rightchild=deleteBST(root->rightchild, RightMin->name);
        }
    }
    return root;
}
void inorder(NODE temp)
{
    if(temp!=NULL)
    {
        inorder(temp->leftchild);
        printf("|%s|%s|\t",temp->name,temp->phno);
        inorder(temp->rightchild);
    }
}
void preorder(NODE temp)
{
    if(temp!=NULL)
    {
        printf("|%s|%s|\t",temp->name,temp->phno);
        preorder(temp->leftchild);
        preorder(temp->rightchild);
    }
}
void postorder(NODE temp)
{
    if(temp!=NULL)
    {
        postorder(temp->leftchild);
        postorder(temp->rightchild);
        printf("|%s|%s|\t",temp->name,temp->phno);
    }
}
void main()
{
    int choice,i,n,keyfound=0;
    char keyname[25];
    NODE root=NULL,newNode;
    printf("--------------creating a BST--------------\n");
    printf("enter the number of records in the BST\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        newNode=createnode();
        if(root==NULL)
        {
            root=newNode;
        }
        else
        {
            insertBST(root, newNode);
        }
    }
        while (1)
        {
            choice=0;
            printf("\n---------------MENU------------------");
            printf("\n1.To search the list for a specified name\n");
            printf("2.Insert a new name\n");
            printf("3.Deleting existing name\n");
            printf("4.Traverse the phone number\n");
            printf("5.Exit");
            printf("\n-------------------------------------\n ");
            printf("enter choice\n");
            scanf("%d",&choice);
            switch (choice)
            {
                case 1: printf("enter the name to be searched\n");
                    scanf("%s",keyname);
                    keyfound=search(root,keyname);
                    if(keyfound==1)
                    {
                        printf("Name: %s is found in the BST\n",keyname);
                    }
                    else
                    {
                        printf("Name: %s is not found in the BST\n",keyname);
                    }
                    break;
                case 2: newNode=createnode();
                    if(root==NULL)
                    {
                        root=newNode;
                    }
                    else
                    {
                        insertBST(root, newNode);
                    }
                    break;
                case 3: if(root==NULL)
                {
                    printf("tree is empty\n");
                }
                else
                {
                    delflag=0;
                    printf("Enter the name to be deleted\n");
                    scanf("%s",keyname);
                    root=deleteBST(root,keyname);
                    if(delflag==-1)
                    {
                        printf("Name: %s is not found in the BST\n",keyname);
                    }
                    else
                    {
                        printf("Name: %s is deleted from the BST\n",keyname);
                    }
                }
                    break;
                case 4: if(root==NULL)
                {
                    printf("tree is empty\n");
                }
                    else
                    {
                        printf("BST Preorder traversal\n");
                        preorder(root);
                        printf("\nBST inorder traversal\n");
                        inorder(root);
                        printf("\nBST postorder traversal\n");
                        postorder(root);
                        printf("\n");
                    }
                    break;
                case 5: return;
                default:printf("Wrong choice..\n");
                    return;
            }
        }
}

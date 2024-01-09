#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node node;
typedef struct node *pnode;
typedef struct node **ppnode;

void insertfirst(ppnode head,int no)
{
    pnode newn = (pnode) malloc (sizeof(node));
    newn->data = no;
    newn->next = NULL;

    if(*head == NULL)
    {
        *head=newn;
    }
    else
    {
        newn->next = *head;
        *head = newn;
    }
    
}
void display(pnode head)
{
    printf("linked list is >>");
    while(head !=NULL)
    {
        printf("|%d|->",head->data);
        head=head->next;

    }
}
void insertlast(ppnode head,int no)
{
    pnode temp = *head;
    pnode newn = (pnode) malloc (sizeof(node));
    newn->data = no;
    newn->next = NULL;

    if(*head == NULL)
    {
        *head=newn;
    } 
    else
    {
        while(temp->next != NULL)
        {
            temp=temp->next;
        }
        temp->next = newn;
        
    }
}
void deletefirst(ppnode head)
{
    pnode temp=*head;
    if(*head==NULL)
    {
        return;
    }
    else if((*head)->next == NULL)
    {
        free(*head);
        *head=NULL;
        
    }
    else
    {
        *head = (*head)->next;
        free(temp);
    }
}
void deletelast(ppnode head)
{
    ppnode temp = *head;
    if(*head==NULL)
    {
        return;
    }
    else if((*head)->next == NULL)
    {
        free(*head);
        *head=NULL;
        
    }
    else
    {

        while()
        temp=(*temp)->next;
    }

}

int main()
{
    pnode first = NULL;
    int iret=0;

    insertfirst(&first,111);
    insertfirst(&first,101);
    insertfirst(&first,51);
    display(first);
    insertlast(&first,11);

}
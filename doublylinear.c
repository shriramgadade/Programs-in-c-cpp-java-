#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node*prev;
    struct node*next;
}NODE,*PNODE,**PPNODE;

void insertfirst(PPNODE head,int no)
{
    PNODE newn = (PNODE) malloc (sizeof(NODE));
    newn->prev = NULL;
    newn->next = NULL;
    newn->data = no;
    if(*head == NULL)
    {
        *head = newn;
    }
    else
    {
        (*head)->prev = newn;
        newn->next = *head;
        *head = newn;
        
    }
}
void insertlast(PPNODE head,int no)
{
    PNODE newn = (PNODE) malloc (sizeof(NODE));
    newn->prev = NULL;
    newn->next = NULL;
    newn->data = no;
    if(*head == NULL)
    {
        *head = newn;
    }
    else
    {
        PNODE temp = *head;

        while(temp->next != NULL)
        {
            temp=temp->next;
        }
        newn->prev = temp;
        temp->next = newn;
    }

}
void deletefirst(PPNODE head)
{
    //PNODE temp = *head;
    if(*head == NULL)
    {
        printf("linked list are all ready empty\n");
        return;

    }
    else if((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
    }
    else
    {
        *head = (*head)->next;
       // free(temp);
       free((*head)->prev);
        (*head)->prev = NULL;
    }
}
void deletelast(PPNODE head)
{
    PNODE temp = *head;
     if(*head == NULL)
    {
        printf("linked list are all ready empty\n");
        return;

    }
    else if((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
    }
    else
    {
    while(temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;

    }
}
void display(PNODE head)
{
    printf("linked list are:----\n");
    while(head!= NULL)
    {
        printf("<- | %d | ->",head->data);
        head = head->next;
    }
}
int count(PNODE head)
{
    int icnt=0;
    while(head!= NULL)
    {
       
        head = head->next;
        icnt++;
    }
    return icnt;
}
void insertatpos(PPNODE head,int no,int ipos)
{
    PNODE temp = *head;
    PNODE newn = (PNODE) malloc (sizeof(NODE));
    newn->prev = NULL;
    newn->next = NULL;
    newn->data = no;
    int isize=0;
    int icnt=0;
    isize = count(*head);
    if((ipos < 1) || (ipos > isize+1))
    {
        printf("inavlid position\n");
    }
    else if(ipos==1)
    {
        insertfirst(head,no);
    }
    else if(ipos == isize+1)
    {
        insertlast(head,no);
    }
    else
    {
       for(icnt=1;icnt<ipos-1;icnt++)
       {
        temp = temp->next;
       } 
       newn->next = temp->next;
       temp->next->prev = newn;
       newn->prev = temp;
       temp->next = newn;    
    }
}
void deleteatpos(PPNODE head,int ipos)
{
    PNODE temp = *head;
   // PNODE targetednode;
    int isize=0;
    int icnt=0;
    isize = count(*head);
    if((ipos < 1) || (ipos > isize+1))
    {
        printf("inavlid position\n");
    }
    else if(ipos==1)
    {
        deletefirst(head);
    }
    else if(ipos == isize+1)
    {
        deletelast(head);
    }
    else
    {
        for(icnt=1;icnt<ipos-1;icnt++)
       {
        temp = temp->next;
       }
       //targetednode = temp->next;
       temp->next = temp->next->next;
       free(temp->next->prev);
       temp->next->prev = temp;
    }
}
int main()
{
    PNODE first = NULL;

    insertfirst(&first,21);
    insertfirst(&first,51);
    insertfirst(&first,11);
    insertfirst(&first,1);
    
    int iret = 0;
    display(first);
    iret = count(first);
    printf("element of linked list are:-- %d\n",iret);
    
    insertlast(&first,101);
    insertlast(&first,111);
    display(first);
    iret = count(first);
    printf("element of linked list are:-- %d\n",iret);

    deletefirst(&first);
    display(first);
    iret = count(first);
    printf("element of linked list are:-- %d\n",iret);
    
    deletelast(&first);
    display(first);
    iret = count(first);
    printf("element of linked list are:-- %d\n",iret);

    insertatpos(&first,41,3);
    display(first);
    iret = count(first);
    printf("element of linked list are:-- %d\n",iret);

    deleteatpos(&first,3);
    display(first);
    iret = count(first);
    printf("element of linked list are:-- %d\n",iret);
    
     return 0;
}
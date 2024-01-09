#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
    
}NODE,*PNODE,**PPNODE;


void insertfirst(PPNODE head,PPNODE tail,int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->next = NULL;

    if((*head == NULL) && (*tail == NULL))
    {
        *head = newn;
        *tail=newn;
    }
    else
    {
        newn->next = *head;
        *head = newn;
        
    }
    (*tail)->next = *head;
}
void insertlast(PPNODE head,PPNODE tail,int no)
{
    
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->next = NULL;

    if((*head == NULL) && (*tail == NULL))
    {
        *head = newn;
        *tail=newn;
    }
    else
    {
       (*tail)->next= newn;
       *tail = newn;
       (*tail)->next = *head;
    }
 

}
void deletefirst(PPNODE head,PPNODE tail)
{
    if(*head == NULL && *tail == NULL)
    {
        return;
    }
    else if(*head == *tail)
    {
        free(*head);
        *head = NULL;
        *tail =NULL;
        
    }
    else
    {
        (*head )= (*head)->next;
        free((*tail)->next);
        (*tail)->next = *head;
    }
}
void deletelast(PPNODE head,PPNODE tail)
{
    PNODE temp = *head;
    if(*head == NULL && *tail == NULL)
    {
        return;
    }
    else if(*head == *tail)
    {
        free(*head);
        *head = NULL;
        *tail =NULL;
    }
    else
    {
        while(temp->next != *tail)
        {
            temp=temp->next;
        }
         free(*tail);
            *tail = temp;
            (*tail)->next = *head;
        }

    }

void display(PNODE head,PNODE tail)
{
    if(head!=NULL && tail!=NULL)
    {
        do
        {
            printf("| %d |->",head->data);
            head = head->next;

        } while(head != tail->next);
        printf("| adress of first node |\n");
    }
}
int count(PNODE head,PNODE tail)
{
    int icnt=0;
    
    if(head!=NULL && tail!=NULL)
    {
         do
        {
            
            head = head->next;
            icnt++;


        } while(head != tail->next);

        
        
    }
    return icnt;
}


void insertatpos(PPNODE head,PPNODE tail,int no,int ipos)
{
    PNODE temp = *head;
    PNODE newn = (PNODE) malloc (sizeof(NODE));
    newn->data = no;
    newn->next = NULL;
    int icnt = 0;
    int size=count(*head,*tail);
    if((ipos <1) || (ipos>size+1))
    {
        printf("poition invald");
    }

    if(ipos == 1)
    {
        insertfirst(head,tail,no);
    }
    else if(ipos == size+1)
    {
        insertlast(head,tail,no);
    }
    else
    {
        
    for(icnt=1;icnt<ipos-1;icnt++)
    {
        temp=temp->next;
    }
    newn->next = temp->next;
    temp->next = newn;
    }


}
void deleteatpos(PPNODE head,PPNODE tail,int ipos)
{
    PNODE temp = *head;
    PNODE targetednode=NULL;
     int icnt = 0;
    int size=count(*head,*tail);
     if(ipos == 1)
    {
        deletefirst(head,tail);
    }
    else if(ipos == size+1)
    {
        deletelast(head,tail);
    }
    else
    {
        for(icnt=1;icnt<ipos-1;icnt++)
        {
            temp=temp->next;
        }
        targetednode=temp->next;
        temp->next = temp->next->next;
        free(targetednode);
    }


}



   

int main()
{
    int irate = 0;
    PNODE first = NULL;
    PNODE last = NULL;
    insertfirst(&first,&last,101);
    insertfirst(&first,&last,51);
    insertfirst(&first,&last,21);
    insertfirst(&first,&last,11);
    display(first,last);
    irate = count(first,last);
    printf("nodes of linked list are :-- %d \n",irate);

     insertlast(&first,&last,201);
    insertlast(&first,&last,511);
    insertlast(&first,&last,211);
    display(first,last);
    irate = count(first,last);
    printf("nodes of linked list are :-- %d \n",irate);

    
    deletefirst(&first,&last);
   
    display(first,last);
    irate = count(first,last);
    printf("nodes of linked list are :-- %d \n",irate);

    deletelast(&first,&last);

    display(first,last);
    irate = count(first,last);
    printf("nodes of linked list are :-- %d \n",irate);

    insertatpos(&first,&last,210,2);
    irate = count(first,last);
    display(first,last);
    printf("nodes of linked list are :-- %d \n",irate);

    deleteatpos(&first,&last,2);
    display(first,last);
    irate = count(first,last);
    printf("nodes of linked list are :-- %d \n",irate);
    



}
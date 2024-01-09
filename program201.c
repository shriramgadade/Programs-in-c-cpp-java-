#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

void insertfirst(PPNODE Head,PPNODE Tail,int no)
{
    PNODE newn = (PNODE) malloc (sizeof(NODE));

    newn->data = no;
    newn->prev = NULL;
    newn->next = NULL;
    if((*Head == NULL) && (*Tail == NULL))
    {
        *Head = newn;
        *Tail = newn;


    }
    else
    {
        newn->next = *Head;
       // newn->prev = *Tail;
        (*Head)->prev = newn;
        *Head = newn;
    }
        (*Tail)->next = *Head;
        (*Head)->prev= *Tail;
}
void insertlast(PPNODE Head,PPNODE Tail,int no)
{
    PNODE newn = (PNODE) malloc (sizeof(NODE));

    newn->data = no;
    newn->prev = NULL;
    newn->next = NULL;
    if((*Head == NULL) && (*Tail == NULL))
    {
        *Head = newn;
        *Tail = newn;


    }
    else
    {
        newn->prev = *Tail;
        (*Tail) -> next = newn;
        *Tail = newn;        
       
    }
    (*Tail)->next = *Head;
    (*Head)->prev= *Tail;

}

void deletefirst(PPNODE Head,PPNODE Tail)
{
    if((*Head == NULL) && (*Tail == NULL)) // LL is empty
    {
        return;

    }
    else if(*Head == *Tail) // LL contain single node
    {
        free(*Head);
        *Head = NULL;
        *Tail = NULL;

    }
    else // LL contains more than one mode
    {
        *Head = (*Head)->next;
        free((*Tail)->next);
        (*Tail)->next = *Head;
    }
    
}
void deletelast(PPNODE Head,PPNODE Tail)
{
     if((*Head == NULL) && (*Tail == NULL)) // LL is empty
    {
        return;

    }
    else if(*Head == *Tail) // LL contain single node
    {
        free(*Head);
        *Head = NULL;
        *Tail = NULL;

    }
    else // LL contains more than one mode
    {
        *Tail = (*Tail)->prev;
        free((*Tail)->next);
        (*Head)->prev = *Tail;
        (*Tail)->next = *Head;
        
    }
    
    
}

void insertatpos(PPNODE Head,PPNODE Tail,int no,int ipos)
{
    int i,isize =0;
    PNODE newn = NULL;
    PNODE temp = *Head;
    isize = count(*Head,*Tail);
    if((ipos<1) || (ipos > isize+1))
    {
        printf("invalid position");

    }
    else if(ipos == 1)
    {
        insertfirst(Head,Tail,no);
    }
    else if(ipos == isize+1)
    {
        insertlast(Head,Tail,no);
    }
    else
    {
        newn = (PNODE) malloc (sizeof(NODE));
        newn->next = NULL;
        newn->data = no;
        newn->prev = NULL;

        for(i=1;i<ipos-1;i++)
        {
            temp=temp->next;

        }
        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
    }
    
}
void deleteatpos(PPNODE Head,PPNODE Tail,int ipos)
{
     int i,isize =0;
    PNODE newn = NULL;
    PNODE temp = *Head;
    isize = count(*Head,*Tail);
    if((ipos<1) || (ipos > isize+1))
    {
        printf("invalid position");

    }
    else if(ipos == 1)
    {
        deletefirst(Head,Tail);
    }
    else if(ipos == isize+1)
    {
        deletelast(Head,Tail);
    }
    else
    {
       
        for(i=1;i<ipos-1;i++)
        {
            temp=temp->next;

        }
        temp->next=temp->next->next;
        free(temp->next->prev);
        temp->next->prev = temp;
    }
    
}
void display(PNODE Head,PNODE Tail)
{
    do
    {
        printf("| %d | <=>",Head->data);
        Head = Head->next;
        /* code */
    } while(Head != Tail->next);
    
    

}
int count(PNODE Head,PNODE Tail)
{
    int icnt=0;
     do
    {
        printf("| %d | <=>",Head->data);
        Head = Head->next;
        icnt++;
    
    } while(Head != Tail->next);
    return icnt;

}

int main()
{

    PNODE first = NULL;
    PNODE last = NULL;
    
    insertfirst(&first,&last,51);
    insertfirst(&first,&last,21);
    insertfirst(&first,&last,11);

    insertlast(&first,&last,111);
    insertlast(&first,&last,121);
    insertlast(&first,&last,151);


    display(first,last);

    int iret = count(first,last);
    printf("number of nodes area :%d\n ",iret);

    deletefirst(&first,&last);
    display(first,last);

    int iret = count(first,last);
    printf("number of nodes area :%d\n ",iret);


    


    return 0;

}
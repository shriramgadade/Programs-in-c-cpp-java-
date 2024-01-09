#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

int dequeue(PPNODE Head)
{
    int value = 0;
    PNODE temp = *Head;
    if(*Head == NULL)
    {
        printf("queue is empty...\n");
        return value;
    }
    else
    {
        value=(*Head)->data;
        *Head = (*Head) -> next;
        free(temp);

    }
    return value;
}
//void insertlast(PPNODE Head,int no)
void enqueue(PPNODE Head,int no)
{
    PNODE newn = (PPNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->next = NULL;
    PNODE temp = *Head;

    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;

    }

}
void display(PNODE Head)
{
    printf("Element of stack are : \n");
    while(Head != NULL)
    {
        printf("| %d | \n",Head->data);
        Head = Head->next;
    }
    printf("\n");

}
int main()
{
    PNODE first=NULL;
    int iret = 0;

    enqueue(&first,11);
    enqueue(&first,21);
    enqueue(&first,51);
   enqueue(&first,101);
   enqueue(&first,111);
  
  display(first);

  iret = dequeue(&first);
  printf("removed element from queue is : %d\n",iret);

   iret = dequeue(&first);
  printf("removed element from queue is : %d\n",iret);

 iret = dequeue(&first);
  printf("removed element from queue is : %d\n",iret);


  
   

}
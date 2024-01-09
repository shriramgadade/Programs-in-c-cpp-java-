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

void push(PPNODE Head,int no)
{
    PNODE newn = (PNODE) malloc (sizeof(NODE));
    newn->data = no;
    newn->next = NULL;
    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        newn->next = *Head;
        *Head = newn;

    }

}
int pop(PPNODE Head)
{
    int value = 0;
    PNODE temp = *Head;
    if(*Head == NULL)
    {
        printf("stack is empty...\n");
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
void display(PNODE Head)
{
    printf("Element of stack are : \n");
    while(Head != NULL)
    {
        printf("| %d | \n",Head->data);
        Head = Head->next;
    }

}
int main()
{
    PNODE first=NULL;
    push(&first,101);
    push(&first,51);
    push(&first,21);
    push(&first,11);

    display(first);

    
    int iret = 0;
    iret = pop(&first);
    printf("poped element  is : %d\n",iret);

    iret = pop(&first);
    printf("poped element  is : %d\n",iret);

    iret = pop(&first);
    printf("poped element  is : %d\n",iret);

    iret = pop(&first);
    printf("poped element  is : %d\n",iret);

    iret = pop(&first);
    printf("poped element  is : %d\n",iret);



}
#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
}NODE, *PNODE, **PPNODE;

class DoublyLL
{
    private:
        PNODE first;
        int Count;

    public:
        DoublyLL();
        void InsertFirst(int no);
        void InsertLast(int no);
        void Display();
        int CountNode();
        void DeleteFirst();
        void DeleteLast();
        void InsertAtPos(int no,int ipos);
        void DeleteAtPos(int ipos);
};

DoublyLL::DoublyLL()
{
    first = NULL;
    Count = 0;
}
void DoublyLL::InsertFirst(int no)
{
    PNODE newn = NULL;
    newn = new NODE;
    newn->data=no;
    newn->next=NULL;
    newn->prev=NULL;

    newn->next = first;
    first->prev = newn;
    first=newn;
    Count++;
}
void DoublyLL::InsertLast(int no)
{
    PNODE newn = NULL;
    newn = new NODE;
    newn->data=no;
    newn->next=NULL;
    newn->prev=NULL;
    PNODE temp = first;

    while(temp->next != NULL)
    {
        temp=temp->next;
    }
    newn->prev = temp;
    temp->next = newn;
}
void DoublyLL::Display()
{
    PNODE temp = first;
    cout<<"NULL";
    while(temp!=NULL)
    {
        cout<<"<- |" <<temp->data <<"| ->";
        temp=temp->next;
    }
    cout<<"NULL";


}
int DoublyLL::CountNode()
{
    return Count;
}
void DoublyLL::DeleteFirst(){}
void DoublyLL::DeleteLast(){}
void DoublyLL::InsertAtPos(int no,int ipos){}
void DoublyLL::DeleteAtPos(int ipos){}

int main()
{
    int iret = 0;
    DoublyLL obj;

    obj.InsertFirst(11);
    obj.InsertFirst(21);
    obj.InsertFirst(51);
    obj.InsertFirst(101);

    obj.Display();
    iret = obj.CountNode();
    cout<<"elements of linked list is:--"<<iret<<"\n";

    obj.InsertLast(41);
    obj.InsertLast(61);
    obj.InsertLast(71);
    obj.Display();
    iret = obj.CountNode();
    cout<<"elements of linked list is:--"<<iret<<"\n";
 




    return 0;
}
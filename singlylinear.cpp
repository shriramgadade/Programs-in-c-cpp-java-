#include<iostream>
using namespace std;

typedef struct node 
{
    int data;
    struct node *next;
}NODE,*PNODE,**PPNODE;

class singlyLL
{
    private:
    PNODE first;
    int icnt;
    public:
    singlyLL();

    void insertfirst(int no);
    void insertlast(int no);
    void display();

    int count();

    void deletefirst();
    void deletelast();
    void deleteatpos(int ipos);
    void insertatpos(int ipos,int no);

     
};

singlyLL::singlyLL()
{
    cout<<"inside consturcter\n";

    first = NULL;
    icnt = 0;

}

void singlyLL::insertfirst(int no)
{
    PNODE newn = NULL;
    newn = new NODE;
    newn->data = no;
    newn->next = NULL;
   

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }
    icnt++;
}
void singlyLL::insertlast(int no)
{
    PNODE newn = NULL;
    newn = new NODE;
    newn->data = no;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        PNODE temp = first;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    icnt++;
}
void singlyLL::display()
{
    PNODE temp = first;
    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<"| ->";
        temp=temp->next;
    }
    cout<<"\n";
}
int singlyLL::count()
{
    return icnt;
}
void singlyLL::deletefirst()
{

    PNODE temp = first;
    first = first->next;
    delete(temp);
    
   icnt--;
}
void singlyLL::deletelast()
{
    PNODE temp = first;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
    icnt--;
}
void singlyLL::insertatpos(int ipos,int no)
{
    PNODE temp = first;
    PNODE newn = NULL;
    newn = new NODE;
    newn->data = no;
    newn->next = NULL;
    int size = icnt,i = 0;
     if(ipos < 1 || ipos > size+1)
    {
        cout<<"invalid position\n";
    }
    if(ipos == 1)
    {
        insertfirst(no);
    }
    else if(ipos == size+1)
    {
        insertlast(no);
    }
    else
    {
        for(i=1;i<ipos-1;i++)
        {
            temp=temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
        icnt++;
    }
}
void singlyLL::deleteatpos(int ipos)
{
    PNODE temp = first;
    int size = icnt,i = 0;
     if(ipos < 1 || ipos > size+1)
    {
        cout<<"invalid position\n";
    }
    if(ipos == 1)
    {
        deletefirst();
    }
    else if(ipos == size+1)
    {
        deletelast();
    }
    else
    {
         for(i=1;i<ipos-1;i++)
        {
            temp=temp->next;
        }
        PNODE targetednode = temp->next;
        temp->next = temp->next->next;
        delete targetednode;
        icnt--;
    }
}

int main()
{
    int iret = 0;
    singlyLL obj;
    //int iret = 0;
    obj.insertfirst(11);
    obj.insertfirst(21);
    obj.insertfirst(31);
    obj.insertfirst(41);
    obj.insertfirst(51);
    obj.display();
    iret = obj.count();
    cout<<"element of linked list is:--- "<<iret<<"\n";

    obj.insertlast(11);
    obj.insertlast(21);
    obj.insertlast(31);
    obj.insertlast(41);
    obj.insertlast(51);
    obj.display();
    iret = obj.count();
    cout<<"element of linked list is:--- "<<iret<<"\n";

    obj.deletefirst();
    obj.deletefirst();
    obj.deletefirst();
    obj.display();
    iret = obj.count();
    cout<<"element of linked list is:--- "<<iret<<"\n";

    obj.deletelast();
    obj.deletelast(); 
    obj.display();
    iret = obj.count();
    cout<<"element of linked list is:--- "<<iret<<"\n";

    obj.insertatpos(2,101);
    obj.display();
    iret = obj.count();
    cout<<"element of linked list is:--- "<<iret<<"\n";

    obj.deleteatpos(2);
    obj.display();
    iret = obj.count();
    cout<<"element of linked list is:--- "<<iret<<"\n";
    return 0 ;
}